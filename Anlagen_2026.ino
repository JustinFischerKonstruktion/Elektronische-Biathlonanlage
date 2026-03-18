#include <esp_now.h>
#include <WiFi.h>

// Variablen definieren
int anlage = 1;      //Nummer der Anlage      
int zeit = 20000;    //Standardzeit in ms 10sek. für Normal 20sek. für Target     
//Anschlüsse der Komponenten
int motor = 25;            
int endPin = 16;           
int sensor[5] = { 23, 5, 26, 18, 19 }; 

// Variablen für die Logik
byte sensorflag[5] = { 0, 0, 0, 0, 0 };    
byte lastsensorstate[5] = { 1, 1, 1, 1, 1 }; 
unsigned long startzeit = 0;               
int start = 0;                             

uint8_t receiverAddress[] = { 0x5c, 0x01, 0x3b, 0x87, 0x4f, 0x08 };  //Adresse für den Master FF überall sendet an alle
// uint8_t receiverAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }; //Nur für Testzwecke
// Mac Adresse des Masters: 5c:01:3b:87:4f:08

esp_now_peer_info_t peerInfo;

//Alle Variablen zum senden
typedef struct messageToBeSent {
    int hits = 0;     
    int anlage;       
    int position;     
    char ergebnis[32]; 
} messageToBeSent;

//Alle Variablen zum Empfangen
typedef struct receivedMessage {
    int online = 0;   
    int customtarget = 10000;
    int customnormal = 20000; 
    int reset = 666;  
    int target = 666;
    int normal = 666;
} receivedMessage;

messageToBeSent myMessageToBeSent; 
receivedMessage myReceivedMessage; 

//Erstellen des Trefferbilds
void erstelleErgebnisString() {
    String visual = "";
    for (int i = 0; i < 5; i++) {
        visual += (sensorflag[i] == 1) ? "○" : "●";
    }
    visual.toCharArray(myMessageToBeSent.ergebnis, 32);
}

void messageReceived(const esp_now_recv_info_t *info, const uint8_t* incomingData, int len) {
    memcpy(&myReceivedMessage, incomingData, sizeof(myReceivedMessage));
}

void messageSent(const wifi_tx_info_t *tx_info, esp_now_send_status_t status) {}

//Reset Funktion
void goal() {
    digitalWrite(motor, HIGH); 

    if (digitalRead(endPin) == LOW) {
        delay(150); 
        digitalWrite(motor, LOW); 
        delay(300); 

        // 1. Abschluss-Paket senden
        myMessageToBeSent.anlage = anlage;
        erstelleErgebnisString();
        myMessageToBeSent.position = 6; 
        esp_now_send(receiverAddress, (uint8_t *) &myMessageToBeSent, sizeof(myMessageToBeSent));
        
        // 2. Variablen für die nächste Runde zurücksetzen
        for (int i = 0; i < 5; i++) {
            sensorflag[i] = 0;
            lastsensorstate[i] = 1;
        }
        
        myMessageToBeSent.hits = 0;    
        myMessageToBeSent.position = 0; 
        myMessageToBeSent.anlage = anlage; //zur Sicherheit
        startzeit = 0;
        start = 1; 

        // 3. Reset-Paket senden
        erstelleErgebnisString();
        esp_now_send(receiverAddress, (uint8_t *) &myMessageToBeSent, sizeof(myMessageToBeSent));
    }
}

//Vorbereitungen treffen
void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(); 

    if (esp_now_init() != ESP_OK) return;

    esp_now_register_send_cb(messageSent);
    esp_now_register_recv_cb(messageReceived);

    memcpy(peerInfo.peer_addr, receiverAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
    esp_now_add_peer(&peerInfo);

    pinMode(motor, OUTPUT);
    pinMode(endPin, INPUT_PULLUP);
    for (int i = 0; i < 5; i++) pinMode(sensor[i], INPUT_PULLUP);
    
    myMessageToBeSent.anlage = anlage; 
    Serial.println("System bereit.");
}

void loop() {
    // Falls ein Paket von außen anlage auf 0 setzt, hier im Loop immer wieder erzwingen:
    myMessageToBeSent.anlage = anlage;
    //Onlineabfrage
    if (myReceivedMessage.online == 1) {  
        myMessageToBeSent.anlage = anlage; 
        esp_now_send(receiverAddress, (uint8_t *) &myMessageToBeSent, sizeof(myMessageToBeSent));
        myReceivedMessage.online = 0;
    }
    //Reset starten
    if (start == 0) goal();
    //manueller Reset verarbeiten
    if (myReceivedMessage.reset == 0 || myReceivedMessage.reset == anlage) {
        start =0;
        myReceivedMessage.reset = 666; 
    }
    //Targetmodus
    if (myReceivedMessage.target == 0 || myReceivedMessage.target == anlage){
        zeit = myReceivedMessage.customtarget;
    }
    //Normaler Modus
    if (myReceivedMessage.normal == 0 || myReceivedMessage.normal == anlage){
        zeit = myReceivedMessage.customnormal;
    }

    //prüft ob ein Endschalter ausgelöst wurde und setzt die passende Flag und sendet alle Informationen zum Master
    for (int i = 0; i < 5; i++) {
        int reading = digitalRead(sensor[i]);
        if (reading == LOW && lastsensorstate[i] == HIGH) {
            delay(20); 
            if (digitalRead(sensor[i]) == LOW && sensorflag[i] == 0) {
                sensorflag[i] = 1; 
                if (startzeit == 0) startzeit = millis();
                
                myMessageToBeSent.hits++; 
                myMessageToBeSent.position = i + 1;
                myMessageToBeSent.anlage = anlage;
                erstelleErgebnisString();
                esp_now_send(receiverAddress, (uint8_t *) &myMessageToBeSent, sizeof(myMessageToBeSent));
            }
        }
        lastsensorstate[i] = reading;
    }
    //startet den Reset wenn 5 treffer erzielt sind oder die Zeit abgelaufen ist
    if (myMessageToBeSent.hits == 5 || (startzeit > 0 && millis() > (startzeit + zeit))) { 
        goal();
    }
}