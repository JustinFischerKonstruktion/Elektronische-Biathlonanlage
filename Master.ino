#include <WiFi.h>
#include <esp_now.h>
#include <Preferences.h>
#include <Wire.h>
#include "RTClib.h"

//Bluetooth Modul und Real Time Clock Modul
HardwareSerial SerialBT(2); // Bluetooth an Pins 16 (RX), 17 (TX)
RTC_DS3231 rtc;
Preferences preferences;

//ausgehende Variablen
typedef struct { 
    int online; 
    int customtarget; 
    int customnormal; 
    int reset; 
    int target; 
    int normal; 
} msgSent;

//Eingehende Variablen
typedef struct { 
    int hits; 
    int anlage; 
    int position; 
    char ergebnis[32]; 
} msgRecv;

//Eintragung für Ergebnissliste
struct ScoreEntry { 
    int anlage; 
    int hits; 
    uint32_t timestamp; 
    char muster[32]; 
};

ScoreEntry scoreList[100];
int currentEntryIndex = 0;
msgSent myMessageToBeSent = {0, 10000, 20000, 666, 666, 666};
msgRecv myReceivedMessage;
uint8_t receiverAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }; //Senden an alle im ESP NOW Netzwerk Broadcast Addresse

//Daten empfangen
void messageReceived(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
    memcpy(&myReceivedMessage, incomingData, sizeof(myReceivedMessage));

    esp_now_send(receiverAddress, (uint8_t *)&myMessageToBeSent, sizeof(myMessageToBeSent));

    //Live Rückmeldung für die Anzeige in der App
    String live = "a" + String(myReceivedMessage.anlage) + "p" + String(myReceivedMessage.position) + 
                  "h" + String(myReceivedMessage.hits) + "m" + String(myReceivedMessage.ergebnis);
    SerialBT.println(live);

    //Speichern bei position 6 (reset)
    if (myReceivedMessage.position == 6) {
        DateTime now = rtc.now();
        scoreList[currentEntryIndex].anlage = myReceivedMessage.anlage;
        scoreList[currentEntryIndex].hits = myReceivedMessage.hits;
        scoreList[currentEntryIndex].timestamp = (uint32_t)now.unixtime();
        strncpy(scoreList[currentEntryIndex].muster, myReceivedMessage.ergebnis, 31);
        
        currentEntryIndex = (currentEntryIndex + 1) % 100;
        preferences.putBytes("score_list", scoreList, sizeof(scoreList));
        preferences.putInt("score_idx", currentEntryIndex);
    }
}

// Ergebnisliste an App senden
void sendeTextListe() {
    SerialBT.println("SYNC_START"); //startmarkierung
    delay(300); 
    //Aufbau der Liste
    for (int i = 0; i < 100; i++) {
        int idx = (currentEntryIndex - 1 - i + 100) % 100;
        if (scoreList[idx].timestamp > 1000000) { 
            DateTime dt(scoreList[idx].timestamp);
            char buffer[120];
            sprintf(buffer, "%02d.%02d.%04d %02d:%02d | Anlage: %d | Treffer: %d | %s", 
                    dt.day(), dt.month(), dt.year(), dt.hour(), dt.minute(), 
                    scoreList[idx].anlage, scoreList[idx].hits, scoreList[idx].muster);
            SerialBT.println(buffer);
            delay(150); 
        }
    }
    delay(300);
    SerialBT.println("SYNC_ENDE");//Endmarkierung
}

void setup() {
    Serial.begin(115200);
    SerialBT.begin(9600, SERIAL_8N1, 16, 17); 
    Wire.begin(21, 22);

    // RTC initialisieren & Zeit prüfen
    if (!rtc.begin()) Serial.println("RTC nicht gefunden!");
    if (rtc.lostPower()) {
        Serial.println("RTC Zeit-Fix angewendet");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    // ESP-NOW Setup
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) return;
    esp_now_register_recv_cb(messageReceived);
    
    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, receiverAddress, 6);
    peerInfo.channel = 0; peerInfo.encrypt = false;
    esp_now_add_peer(&peerInfo);

    // Datenbank laden
    preferences.begin("schuss_db", false); 
    preferences.getBytes("score_list", scoreList, sizeof(scoreList));
    currentEntryIndex = preferences.getInt("score_idx", 0);
}

// Bluetooth Befehle empfangen.
void loop() {
    if (SerialBT.available()) {
        String msg = SerialBT.readStringUntil('\n');
        msg.trim();
        
        if (msg == "Sync") {
            sendeTextListe();
        }
        else if (msg == "Listelöschen") {
            memset(scoreList, 0, sizeof(scoreList));
            currentEntryIndex = 0;
            preferences.putBytes("score_list", scoreList, sizeof(scoreList));
            preferences.putInt("score_idx", 0);
            Serial.println("!!! DATENBANK GELÖSCHT !!!");
            SerialBT.println("Liste wurde gelöscht");
        }
        else if (msg.startsWith("reset")) {
            myMessageToBeSent.reset = msg.substring(5).toInt();
            esp_now_send(receiverAddress, (uint8_t *)&myMessageToBeSent, sizeof(myMessageToBeSent));
            myMessageToBeSent.reset = 666;
        }
        else if (msg.startsWith("target")) {
            myMessageToBeSent.target = msg.substring(6).toInt();
            esp_now_send(receiverAddress, (uint8_t *)&myMessageToBeSent, sizeof(myMessageToBeSent));
            myMessageToBeSent.target = 666;
        }
        else if (msg.startsWith("normal")) {
            myMessageToBeSent.normal = msg.substring(6).toInt();
            esp_now_send(receiverAddress, (uint8_t *)&myMessageToBeSent, sizeof(myMessageToBeSent));
            myMessageToBeSent.normal = 666;
        }
        else if (msg.startsWith("online")) {
            myMessageToBeSent.online = msg.substring(6).toInt();
            esp_now_send(receiverAddress, (uint8_t *)&myMessageToBeSent, sizeof(myMessageToBeSent));
            myMessageToBeSent.online = 0;
        }
        else if (msg.startsWith("customtarget")) {
            myMessageToBeSent.customtarget = msg.substring(12).toInt();
        }
        else if (msg.startsWith("customnormal")) {
            myMessageToBeSent.customnormal = msg.substring(12).toInt();
        }
    }
}
