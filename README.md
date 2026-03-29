# Elektronische-Biathlonanlage
Das Projekt "Elektronische Biathlonanlage" ist ein Umbau für Luftgewehr Biathlonanlagen, welcher dafür sorgt, dass die Scheiben nach 5 Treffern oder nach einer eingestellten Zeit ohne Treffer "gezogen" werden. Zur Datenerfassung werden die einzelnen Treffer mit der Position innerhalb eines ESP-NOW Netzwerkes versendet. 

Die Automatisierung der Anlage erfolgt mithilfe von Endschaltern und einem 12V DC motor, gesteuert von einem ESP32-D1mini auf einer eigens gestalteten Platine. Hier werden dei Endschalter so verkabelt, dass die Scheibenposition im Programm übereinstimmt also Scheibe 1-5.


Die 3D-gedruckten Komponenten werden zerstörungsfrei an den bestehenden Anlagen angebracht.  
Getestete Anlagen: Rika und Hora  
Link zu den 3D-Modellen inkl. Druckeinstellungen (Makerworld):   
(STEP-Dateien findet ihr hier auf Github)  
Gesamte Anlage:

Motorhalter:

Endschalterhalter:

Platinenhalter:

Zur einhaltung der Schießstandrichtlinien wurde ein Blech an dem Motorhalter angebracht. Dieses wurde bei Blexon bestellt.

STEP-Datei Blech: 

Blexon Link:

Zur Verkablung der Anlage wurde eine eigens geplanten Platine angefertigt. Hier die Schaltlogik:

<p align="center">
  <img width="1073" height="567" alt="Verkabelung" src="https://github.com/user-attachments/assets/d1e27411-412c-41c5-96f0-8fc841993d70" />
  <br>
  <em style="color: grey;">Abbildung 1: Schaltlogik (erstellt mit Inkscape)</em>
</p>

**Überblick der Verkabelung:**

Alle Endschalter sind beim COM Anschluss mit Ground verbunden
Das Relaismodul wird mit 5V betrieben und verbindet den Motor über den Normaly Open (NO) Anschluss mit +12V
Der Informationsanschluss des Relaismoduls wird mit Pin 25 des ESP32 verbunden.
Der Endschalter beim Motor wird über den NO Anschluss mit Pin 16 des ESP32 verbunden.

Die Endschalter der Klappen werden über die NO Anschlüsse an folgende Pins angeschlossen:  
Klappe 1: Pin 23  
Klappe 2: Pin 5  
Klappe 3: 26  
Klappe 4: 18  
Klappe 5: 19  

Fertige Platine bestellen: (Link zu JLCPCB)

Der Master hat die folgenden Anbauteile:  
Real time clock:  
SCL an Pin 22  
SDA an Pin 21  

JDY-31 Bluetooth-serielles Modul:  
RX an Pin 16  
TX an Pin 17

**Hier die Stückliste für eine Anlage:**

| Bezeichnung | Stückzahl pro Anlage |
| :--- | :---: |
|**3D-Gedruckte Teile**|
| Endschalterhalter (2 Varianten) | 5 |
| Motorgehäuse | 1 |
| Scheibe | 1 |
| Gehäusehalterungen | 1 |
| Gehäusehalterungen für außerhalb der Anlage (optional) | (1) |
|**Zukaufteile**|
| Edelstahlbleche | 1 |
| ESP32 D1 Mini | 1 |
| Step Down Converter | 1 |
| 12V DC Motor | 1 |
| Platine (optional) | (1) |
| Gehäuse für Platine | (1) |
| Endschalter für Motor | 5 |
| Endschalter für Klappen | 1 |
| Kabel (Ausgang Stromversorgung) | 1 |
| Kugellager | 1 |
| Schrauben M3x10 | 8 |
| Schrauben M5x10 | 2 |
| Einschmelzmutter M3 | 4 |
| Schrauben zur Befestigung der Platine | 4 |
| Wasserdichte Kabeldurchführungen | 8 |
| Radialwellendichtring (optional) | 1 |

**Stückliste des Masters:**
| Bezeichnung | Stückzahl pro Anlage |
| :--- | :---: |
| ESP32 D1 Mini | 1 |
| Bluetooth Modul | 1 |
| Real time Clock Modul | 1 |
| Gehäuse für ESP32 | (1) |
| Lötplatine | (1) |


Sonstige Zukaufteile:  
Kabel:  
Verteilerdosen:  
Solarmodul inkl. Akku:  
12V-Netzteil für Betrieb ohne Solar:  
DC-Backup Schaltmodul für den Betrieb von Solar+Netzteil:  


## Software
Die Software der Anlagen sowie des Masters wurden mit der Arduinio IDE geschrieben. Ihr findet die Ino Dateien zum Download im Ordner Software.
Bei Inbetriebname müsst ihr die MAC-Adresse eures Masters herausfinden und euch aufschreiben.  
Bei den Anlagen müsst ihr folgende 3 Variablen anpassen, alle drei findet ihr ganz oben im Code.    

Anlage: Die Nummer eurer Anlage, beachtet hierbei dass es von oben nach unten und dann von links nach rechts geht. Das heißt Stehend Anlage links ist Nummer 1; die Liegend Anlage ist Nummer 2, die zweite Stehend Anlage von links ist 3 usw.  

uint8_t receiverAddress[]: Die Mac Adresse eures Masters  

Mit der Variable zeit könnt ihr die Zeit einstellen die fest bei der Anlage hinterlegt ist. Bei unseren Anlagen haben wir für die Liegend Anlagen standardmäßig 10 Sekunden (zeit=10000). Für unsere Stehend Anlagen sind es 20 Sekunden (zeit=20000). Die Angabe ist in Millisekunden (Drei Nullen hinzufügen).  

## Netzwerk
<p align="center">
  <img width="945" height="831" alt="Netzwerkaufbau" src="https://github.com/user-attachments/assets/8d163abd-0a4f-481d-bdbc-63dafceb2500" />
  <br>
  <em style="color: grey;">Abbildung 2: Netzwerkaufbau (erstellt mit Inkscape)</em>
</p>

Das Netzwerk besteht aus einem Master und bis zu 20 Slaves (Einschränkung durch ESP-NOW Netzwerk). Die Anlagen sind die Slaves, der Master ist ein eigenständiges Gerät. Intern werden Variablen versendet für die verschiedenen Befehle und Daten:  
hits = Treffer  
Anlage = Die Nummer der Anlage  
reset = 0-n Die Nummer der Anlage die "gezogen" werden soll, 0 steht für alle Anlagen.  
target = 0-n Die Nummer der Anlage die in den Target Modus wechseln soll (Standardmäßig 20s), 0 steht für alle Anlagen.  
normal = 0-n Die Nummer der Anlage die in den Magazin / normalen Modus wechseln soll (Standardmäßig 10s), 0 steht für alle Anlagen.  
customtarget = Die eigene Zeiteinstellung für den Targetmodus in Sekunden  
customnormal= Die eigene Zeiteinstellung für den Magazinmodus in Sekunden

Das Netzwerk wurde von uns nur mit einem Master und 8 Slaves getestet und sind sehr zufrieden.

Der Master bietet die Möglichkeit sich mit einem Handy zu verbinden hier werden die Daten der Anlagen und die Befehle im Textformat gesendet und von der Android App verarbeitet. Diese wurde mit MIT App Inventor entworfen.
Hier der Link zur App: 


## Referenzen
Bilder und Videos der Anlage.


