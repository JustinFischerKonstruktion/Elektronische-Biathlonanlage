# Elektronische-Biathlonanlage
Das Projekt Elektronische Biathlonanlage ist ein Umbau für Luftgewehr Biathlonanlagen, welcher dafür sorgt, dass die Scheiben nach 5 Treffern oder nach einer eingestellten Zeit ohne Treffer "gezogen" werden. Zur Datenerfassung werden die einzelnen Treffer mit der Position innerhalb eines ESP-NOW Netzwerkes versendet. 

Die Automatisierung der Anlage erfolgt mithilfe von Endschaltern und einem 12V DC motor, gesteuert von einem ESP32-D1mini auf einer eigens gestalteten Platine. Hier werden dei Endschalter so verkabelt, dass die Scheibenposition im Programm übereinstimmt also Scheibe 1-5.


Die 3D-gedruckten Komponenten werden zerstörungsfrei an den bestehenden Anlagen angebracht. Getestete Anlagen: Rika und Hora
Link zu den 3D-Modellen inkl. Druckeinstellungen (Makerworld) (STEP und STL Dateien findet ihr hier)

Gesamte Anlage:

Motorhalter:

Endschalterhalter:

Platinenhalter:

Zur einhaltung der Schießstandrichtlinien wurde ein Blech an dem Motorhalter angebracht. Dieses wurde bei Blexon bestellt.

STEP-Datei Blech: 

Blexon Link:

Zur Verkablung der Anlage wurde eine eigens geplanten Platine angefertigt. Hier die Schaltlogik:

<img width="1073" height="567" alt="Verkabelung" src="https://github.com/user-attachments/assets/d1e27411-412c-41c5-96f0-8fc841993d70" />

Überblick der Verkabelung:

Alle Endschalter sind beim COM Anschluss mit Ground verbunden
Das Relaismodul wird mit 5V betrieben und verbindet den Motor über den Normaly Open (NO) Anschluss mit +12V
Der Informationsanschluss des Relaismoduls wird mit Pin 25 des ESP32 verbunden.
Der Endschalter beim Motor wird über den NO Anschluss mit Pin 16 des ESP32 verbunden.

Die Endschalter der Klappen werden ber die NO Anschlüsse an folgende Pins angeschlossen:
Klappe 1: Pin 23
Klappe 2: Pin 5
Klappe 3: 26
Klappe 4: 18
Klappe 5: 19

Fertige Platine bestellen: (Link zu JLCPCB)

Hier die Liste der Zukaufteile:

Platinengehäuse:
Motor:
Stromkabel:
DC-DC Wandler:
JST-Secker:
Einschmelzgewinde:
Schrauben:

Kabelschutz:
Kabel zur Verkabelung:




<img width="945" height="831" alt="Netzwerkaufbau" src="https://github.com/user-attachments/assets/8d163abd-0a4f-481d-bdbc-63dafceb2500" />
Bild erstellt mit Inkscape


Das Netzwerk besteht aus einem Master un bis zu 20 Slaves (Einschränkung durch ESP-NOW Netzwerk). Die Anlagen sind die Slaves, der MAster ist ein eigenständiges Gerät. Intern werden Variablen versendet für die verschiedenen Befehle und Daten:
hits = Treffer
Anlage = Die Nummer der Anlage
reset = 0-n Die Nummer der Anlage die "gezogen" werden soll, 0 steht für alle Anlagen.
target = 0-n Die Nummer der Anlage die in den Target Modus wechseln soll (Standardmäßig 20s), 0 steht für alle Anlagen.
normal = 0-n Die Nummer der Anlage die in den Magazin / normalen Modus wechseln soll (Standardmäßig 10s), 0 steht für alle Anlagen.
customtarget = Die eigene Zeiteinstellung für den Targetmodus in Sekunden
customnormal= Die eigene Zeiteinstellung für den Magazinmodus in Sekunden

Der Master bietet die Möglichkeit sich mit einem Handy zu verbinden hier werden die Daten der Anlagen und die Befehle im Textformat gesendet und von der Android App verarbeitet. Diese wurde mit MIT App Inventor entworfen.
Hier der Link zur App: 

