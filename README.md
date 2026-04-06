# Elektronische Biathlonanlage

## Allgemeines
Das Projekt **"Elektronische Biathlonanlage"** ist ein Umbau für Luftgewehr-Biathlonanlagen. Dieser sorgt dafür, dass die Scheiben nach 5 Treffern oder nach einer eingestellten Zeit ohne Treffer automatisch "gezogen" werden. Zur Datenerfassung werden die einzelnen Treffer zusammen mit der Position innerhalb eines **ESP-NOW Netzwerkes** versendet.

Das System bringt einige Vorteile mit sich: Durch das Fehlen der klassischen Seile der Biathlonanlagen ist kein Auf- und Abwickeln im Training mehr nötig – einfach Strom einschalten und lostrainieren! Auch die Gefahr, dass sich die Seile verknoten oder spannen, wodurch das Fallen der Scheiben verhindert wird, sinkt deutlich. Durch das automatische „Ziehen“ der Anlagen ist ein reibungsloser Ablauf des Trainings möglich. Keiner kann vergessen, die Scheibe zu ziehen, und es kann kein „unvollständiges Ziehen“ geben. Durch das offene System können Trainingsdaten erfasst werden; hier ist für die Zukunft eine Weiterentwicklung mit einer Laufzeitmessung geplant (siehe Zukunftsvision). Durch die zerstörungsfreie Anbringung der 3D-Druckteile geht die Anlage nicht kaputt, die Garantie des Anlagenherstellers wird also nicht verletzt. Die Platine kann sowohl an der Anlage direkt als auch am Stand angebracht werden, somit kann die Anlage flexibel an verschiedenen Standorten eingesetzt werden. Das wasserabweisende und größtenteils auch wasserfeste Design ist auf den Außeneinsatz angepasst.

Der Schützenverein Wolfartsweiler ([sv-wolfartsweiler.de](https://www.sv-wolfartsweiler.de)) hat seit über einem Jahr 8 umgebaute Anlagen im Betrieb. Pro Anlage kostete uns der Umbau ca. 210 €. Pro Anlage kann man mit ca. 2 Arbeitsstunden für die Installation rechnen, zusätzlich zur Installation von Kabeln im Schießstand. Außerdem testet der Schützenverein aktuell einen Prototypen zur autonomen Laufzeiterfassung und Laufzeitauswertung.

Mit dem Wettbewerb NMH Makes Heroes ([nmh-makes-heroes.nmh.de](https://nmh-makes-heroes.nmh.de)) unterstützte mich die Firma NMH ([nmh.de](https://www.nmh.de)) mit einer Fördersumme und technischer Beratung. Während der kurzen Wettbewerbszeit (ca. 6 Wochen) entstand aus einem Prototypen ein fertiges, einsatzfähiges System, welches ich bei allen 8 Anlagen installieren konnte. Vielen Dank an dieser Stelle an NMH!

Wenn Sie mein Projekt interessiert und Sie sich für die Zukunft des Projektes interessieren, können Sie sich gerne die Zukunftsvision anschauen; hier werden mögliche Weiterentwicklungen aufgezeigt. Wenn Sie mich unterstützen wollen, können Sie das gerne über das GitHub-Sponsorprogramm machen. Sollten Sie Anregungen, Fehler oder Wünsche haben, können Sie hier Issues erstellen oder einfach eine Diskussion starten. Auch auf Instagram können Sie gerne Kontakt zu mir aufnehmen: [@justin_fischer_konstruktion](https://www.instagram.com/justin_fischer_konstruktion/)

## Hardware

Die Automatisierung der Anlage erfolgt mithilfe von Endschaltern und einem **12V DC Motor**, gesteuert von einem **ESP32-D1 mini** auf einer eigens entworfenen Platine. Hier werden die Endschalter so verkabelt, dass die Scheibenposition im Programm (Scheibe 1–5) mit der mechanischen Position übereinstimmt.

Die 3D-gedruckten Komponenten werden zerstörungsfrei an den bestehenden Anlagen angebracht.
**Getestete Anlagen:** Rika und Hora
**Link zu den 3D-Modellen inkl. Druckeinstellungen (MakerWorld):**
*(STEP-Dateien findet ihr hier auf GitHub)*

**Hora:**
* Gesamte Anlage:
* Motorhalter:
* Endschalterhalter:
* Halter:
* Halter mit Kabel:

**Rika:**
* Gesamte Anlage:
* Motorhalter:
* Endschalterhalter:
* Platinenhalter:

**Zubehör für beide Typen:**
* Platinenhalter außen:
* Scheibe:
* Adapter Platine zu Gehäuse:

Zur Einhaltung der Schießstandrichtlinien wurde eine Verkleidung aus Blech an dem Motorhalter angebracht. Diese wurde bei Blexon bestellt. Die entsprechende **STEP-Datei des Blechs** findet ihr ebenfalls hier bei GitHub. Wir haben ein 2 mm Edelstahlblech verwendet, um den Schießstandrichtlinien gerecht zu werden und um Rost und Abnutzung vorzubeugen.

**Blexon Link:** [blexon.com](https://blexon.com)

---

## Verkabelung

Zur Verkabelung der Anlage wurde eine selbst entworfene Platine angefertigt.

<p align="center">
  <img width="1000" height="1589" alt="Verkabelung_Steckplatine" src="https://github.com/user-attachments/assets/fe40b8bf-6f43-41b8-a28f-9342cb104fb9" />
  <br>
  <em style="color: grey;">Abbildung 1: Schaltlogik (erstellt mit Fritzing)</em>
</p>

### Überblick der Verkabelung:

* Alle Endschalter sind über den **COM-Anschluss** mit Ground (GND) verbunden.
* Das Relaismodul wird mit **5V** betrieben und verbindet den Motor über den **Normally Open (NO)** Anschluss mit +12V.
* Der Informationsanschluss des Relaismoduls wird mit **Pin 25** des ESP32 verbunden.
* Der Endschalter beim Motor wird über den **NO-Anschluss** mit **Pin 16** des ESP32 verbunden.

Die Endschalter der Klappen werden über die **NO-Anschlüsse** an folgende Pins angeschlossen:
* Klappe 1: **Pin 23**
* Klappe 2: **Pin 5**
* Klappe 3: **Pin 26**
* Klappe 4: **Pin 18**
* Klappe 5: **Pin 19**

**Meine Platine bei OSHWLab:** (Link zu OSHWLAB)

---

### Der Master

Der Master verfügt über folgende Anbauteile:

**Real time clock (RTC):**
* SCL an **Pin 22**
* SDA an **Pin 21**

**JDY-31 Bluetooth-serielles Modul:**
* RX an **Pin 16**
* TX an **Pin 17**

---

### Stücklisten

#### Stückliste für eine Anlage:

| Bezeichnung | Stückzahl pro Anlage | Link |
| :--- | :---: | :--- |
| **3D-Gedruckte Teile** | | |
| Endschalterhalter (2 Varianten) | 5 | |
| Motorgehäuse | 1 | |
| Scheibe | 1 | |
| Gehäusehalterungen | 1 | |
| Gehäusehalterungen (optional) | (1) | |
| **Zukaufteile** | | |
| Edelstahlbleche | 1 | |
| ESP32 D1 Mini | 1 | [Amazon](https://www.amazon.de/dp/B0DHY5C3Q3) |
| Step Down Converter | 1 | [Amazon](https://www.amazon.de/dp/B0B92ZDK6T) |
| 12V DC Motor | 1 | [Amazon](https://www.amazon.de/dp/B0D9JTQWVB) |
| Platine (optional) | (1) | siehe unten |
| Gehäuse für Platine | (1) | [Amazon](https://www.amazon.de/dp/B0747RGBFF) |
| Endschalter für Motor | 5 | [Amazon](https://www.amazon.de/dp/B0DX27MVWB) |
| Endschalter für Klappen | 1 | [Reichelt](https://www.reichelt.de/de/de/shop/produkt/snap-action-mikroschalter_1x_um_rollenhebel-191380) |
| Kabel (Stromversorgung) | 1 | [Amazon](https://www.amazon.de/dp/B07DPND6NG) |
| Kugellager | 1 | [Amazon](https://www.amazon.de/dp/B0CL4ZN6BV) |
| Schrauben M3x8 | 8 | [Amazon](https://www.amazon.de/dp/B073ZY19VS) |
| Schrauben M2x10 | 2 | [Amazon](https://www.amazon.de/dp/B015A3ISUA) |
| Schrauben M5x10 | 2 | [Amazon](https://www.amazon.de/dp/B015A3ISUA) |
| Selbstschneidende Schrauben | 4 | [Amazon](https://www.amazon.de/dp/B0D9JTQWVB) |
| Einschmelzmutter M3 | 4 | [Amazon](https://www.amazon.de/dp/B0CRHMB248) |
| Kabeldurchführungen | 8 | [Amazon](https://www.amazon.de/dp/B0CXPSG55G) |
| Radialwellendichtring (opt.) | (1) | [Amazon](https://www.amazon.de/dp/B0DVJ32JPS) |

#### Stückliste des Masters:

| Bezeichnung | Stückzahl | Link |
| :--- | :---: | :--- |
| ESP32 D1 Mini | 1 | [Amazon](https://www.amazon.de/dp/B0DHY5C3Q3) |
| Bluetooth Modul | 1 | [Amazon](https://www.amazon.de/dp/B0FFZ43YCC) |
| Real time Clock Modul | 1 | [Amazon](https://www.amazon.de/dp/B01H5NAFUY) |
| Gehäuse für ESP32 | (1) | [Amazon](https://www.amazon.de/dp/B0747RGBFF) |
| Lötplatine | (1) | [Amazon](https://www.amazon.de/dp/B07DK2S1XG) |

**Sonstige Zukaufteile:**
* Kabel: [Amazon](https://www.amazon.de/dp/B07DK2S1XG)
* Verteilerdosen: [Amazon](https://www.amazon.de/dp/B09D3XP1Z1)
* Solarmodul inkl. Akku: [Amazon](https://www.amazon.de/dp/B09D3XP1Z1)
* 12V-Netzteil: [Amazon](https://www.amazon.de/dp/B07GFFG1BQ)
* DC-Backup Schaltmodul: [Amazon](https://www.amazon.de/dp/B07B4D73K9)
* Dichtungsstreifen: [Amazon](https://www.amazon.de/dp/B0CWNCHX7T)

---

## Software

Die Software der Anlagen sowie des Masters wurde mit der **Arduino IDE** geschrieben. Ihr findet die `.ino`-Dateien zum Download im Ordner `Software`.

Bei Inbetriebnahme müsst ihr die MAC-Adresse eures Masters herausfinden und notieren. In den Skripten der Anlagen müssen folgende drei Variablen ganz oben im Code angepasst werden:

1. **Anlage:** Die Nummer eurer Anlage (von oben nach unten, dann von links nach rechts). Beispiel: Stehende Anlage links = Nr. 1; liegende Anlage = Nr. 2; zweite stehende Anlage von links = Nr. 3 usw.
2. **uint8_t receiverAddress[]:** Die MAC-Adresse eures Masters.
3. **Variable `zeit`:** Hier wird die Zeit eingestellt, nach der die Anlage automatisch zieht. Standardmäßig nutzen wir für liegende Anlagen 10 Sekunden (`zeit=10000`) und für stehende Anlagen 20 Sekunden (`zeit=20000`). Die Angabe erfolgt in Millisekunden.

### Handy-App

Hier auf GitHub findet ihr im Ordner `Software` die Biathlon-App sowohl als APK zum Installieren auf Android-Handys als auch die AIA-Datei zum Öffnen in App Inventor für die Anpassung an eure Bedürfnisse. Hierfür braucht ihr einen Account beim MIT App Inventor.
App Inventor: [appinventor.mit.edu](https://appinventor.mit.edu)

<p align="center">
  <img width="800" alt="App Startseite" src="https://github.com/user-attachments/assets/47ca7d34-4326-413d-babb-7705d5df84e0" />
  <br>
  <em style="color: grey;">Abbildung 2: Handy App Startseite</em>
</p>

Auf der Startseite der App könnt ihr links oben die Seiten wechseln. Mit dem Button links neben der Mitte könnt ihr verfügbare Bluetooth-Geräte abfragen und euch verbinden. Danach werden euch die Treffer der Anlagen angezeigt. Mit den Schiebereglern wechselt ihr den Modus, mit den Reset-Knöpfen löst ihr den Ziehvorgang manuell aus (für alle Anlagen gleichzeitig oder einzeln).

<p align="center">
  <img width="800" alt="App Einstellungen" src="https://github.com/user-attachments/assets/97cacae5-d696-4696-84ea-24b96fb4d09d" />
  <br>
  <em style="color: grey;">Abbildung 3: Handy App Einstellungsseite</em>
</p>

Auf der Einstellungsseite könnt ihr eigene Zeiten für die Modi eingeben und per Senden-Button an den Master übertragen.

<p align="center">
  <img width="800" alt="App Ergebnisse" src="https://github.com/user-attachments/assets/f69861b0-ebb7-42f9-a03a-ae8f918f8027" />
  <br>
  <em style="color: grey;">Abbildung 4: Handy App Ergebnisseite</em>
</p>

Hier könnt ihr eine Liste der letzten Ergebnisse abfragen. Da die Übertragung via Bluetooth Zeit benötigt, ist diese Funktion bei begrenzter Leistung nicht immer zu 100 % zuverlässig.

---

## Netzwerk

<p align="center">
  <img width="800" alt="Netzwerkaufbau" src="https://github.com/user-attachments/assets/8d163abd-0a4f-481d-bdbc-63dafceb2500" />
  <br>
  <em style="color: grey;">Abbildung 5: Netzwerkaufbau (erstellt mit Inkscape)</em>
</p>

Das Netzwerk besteht aus einem Master und bis zu 20 Slaves (bedingt durch die ESP-NOW Einschränkung). Die Anlagen fungieren als Slaves, der Master als eigenständige Zentrale. Wir haben unseren Master aktuell in der Nähe der Schützen platziert; der Abstand zu den Anlagen beträgt 10 m. Auf diese Distanz haben wir die Anlagen getestet und bisher keine Probleme festgestellt.

Folgende Variablen werden intern für Befehle und Daten genutzt:
* `hits`: Anzahl der Treffer
* `position`: Position des Treffers 1–5 (6 für Reset der Anzeige)
* `Anlage`: Nummer der sendenden Anlage
* `reset`: 0–n (Nummer der zu ziehenden Anlage; 0 = alle)
* `target`: 0–n (Wechsel in den Target-Modus; 0 = alle)
* `normal`: 0–n (Wechsel in den Magazin-Modus; 0 = alle)
* `customtarget`: Eigene Zeiteinstellung für den Targetmodus (in Sekunden)
* `customnormal`: Eigene Zeiteinstellung für den Magazinmodus (in Sekunden)

Wir haben das Netzwerk erfolgreich mit einem Master und 8 Slaves getestet und sind sehr zufrieden. Der Master verbindet sich per Bluetooth mit dem Handy; Daten und Befehle werden im Textformat gesendet und von der Android-App (erstellt mit **MIT App Inventor**) verarbeitet.

---

## Referenzen

Video, das die aktuellen Probleme von Seilzuganlagen aufzeigt:
<p align="center">
  <a href="https://youtu.be/Kdan_EM31K0">
    <img src="https://github.com/user-attachments/assets/f8575da7-089a-447b-b70b-edb5b22d0004" width="400" alt="Video Thumbnail">
    <br>
  <b>Video: Probleme der aktuellen Seilzuganlagen</b>
  </a>
</p>
<img src="https://github.com/user-attachments/assets/0c14c4b4-c107-462a-aca5-a7d12a3ddcb7" width="400">
<img src="https://github.com/user-attachments/assets/c909ff09-8767-4794-b4bb-1c864c927277" width="400">
<img src="https://github.com/user-attachments/assets/10c0255a-439f-4142-9c50-8d826d887a67" width="400">
<img src="https://github.com/user-attachments/assets/31de276d-30ea-4a18-8976-fa7888015f8f" width="400">
<img src="https://github.com/user-attachments/assets/fc2ac1d7-bee0-4d05-aaaf-0a5aeb2df61d" width="400">
<img src="https://github.com/user-attachments/assets/d71a1f6d-0343-4de1-ba15-a3c1aafdb4f2" width="400">
<img src="https://github.com/user-attachments/assets/648aee1d-6b51-4e1e-a3e6-d2a2dfa7e547" width="400">
<img src="https://github.com/user-attachments/assets/3031ae92-63bf-4ff2-8a93-eed38afb3ca9" width="400">
<img src="https://github.com/user-attachments/assets/ce45db39-87ec-4b92-bc14-da7535b7ba67" width="400">
<img src="https://github.com/user-attachments/assets/1c8d085c-5fb7-4f58-8baa-5e3210d04d6f" width="400">
<img src="https://github.com/user-attachments/assets/944a05ce-a78e-451c-93ec-82c05614c5a3" width="400">


## Haftungsausschluss (Disclaimer)

**Die Nutzung dieser Anleitung, der Software und der Hardware-Designs erfolgt auf eigene Gefahr.**

* **Keine Garantie:** Dieses Projekt wird "wie besehen" (as-is) zur Verfügung gestellt. Ich übernehme keine Garantie für die Funktion, Vollständigkeit oder Richtigkeit der bereitgestellten Informationen.
* **Haftungsausschluss:** Ich hafte nicht für Schäden an Hardware (z. B. Kurzschlüsse, defekte Motoren), Verletzungen oder sonstige Folgeschäden, die durch den Nachbau oder Betrieb dieser Anlage entstehen.
* **Eigenverantwortung:** Der Nutzer ist selbst dafür verantwortlich, dass der Umbau den geltenden Sicherheitsregeln und Schießstandrichtlinien entspricht.
