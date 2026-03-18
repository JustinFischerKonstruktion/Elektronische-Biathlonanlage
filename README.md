# Elektronische-Biathlonanlage
Das Projekt Elektronische Biathlonanlage ist ein Umbau für Luftgewehr Biathlonanlagen, welcher dafür sorgt, dass die Scheiben nach 5 Treffern oder nach einer eingestellten Zeit ohne Treffer "gezogen" werden. Zur Datenerfassung werden die einzelnen Treffer mit der Position innerhalb eines ESP-NOW Netzwerkes versendet. 

Die Automatisierung der Anlage erfolgt mithilfe von Endschaltern und einem 12V DC motor, gesteuert von einem ESP32-D1mini auf einer eigens gestalteten Platine. Hier werden dei Endschalter so verkabelt, dass die Scheibenposition im Programm übereinstimmt also Scheibe 1-5.


Die 3D-gedruckten Komponenten werden zerstörungsfrei an den bestehenden Anlagen angebracht. Getestete Anlagen: Rika und Hora

Motorhalter:
Endschalterhalter:
Platinenhalter:



Innerhalb dieses Netzwerkes werden auch Befehle an die Anlagen zur Steuerung gesendet.

(Bild Aufbau Netzwerk)

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

