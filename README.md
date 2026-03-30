# Elektronische Biathlonanlage
## Allgemeines
Das Projekt **"Elektronische Biathlonanlage"** ist ein Umbau für Luftgewehr-Biathlonanlagen. Dieser sorgt dafür, dass die Scheiben nach 5 Treffern oder nach einer eingestellten Zeit ohne Treffer automatisch "gezogen" werden. Zur Datenerfassung werden die einzelnen Treffer zusammen mit der Position innerhalb eines **ESP-NOW Netzwerkes** versendet.    

Das System bringt einige Vorteile mit sich, durch das Fehlen von den klassischen Seilen der Biathlonanlagen ist kein Auf- und Abwickeln im Training mehr nötig, einfach Strom einschalten und lostrainieren!  
Auch die Gefahr dass sich die Seile verknoten oder spannen, wodurch das Fallen der Scheiben verhindert wird, sinkt deutlich. Durch das automatische "ziehen" der Anlagen ist ein reibungsloser Ablauf des Trainings möglich. Keiner kann vergessen die Scheibe zu ziehen und es kann kein "unvollständiges ziehen" geben. Durch das offene System können Trainingsdaten erfasst werden, hier ist für die Zukunft eine Weiterentwicklung mit einer Laufzeitmessung geplant (siehe Zukunftsvision). Durch die zerstörungsfreie Anbringung der 3D-Druckteile geht die Anlage nicht kaputt, die Garantie des Anlagenherstellers wird also nicht verletzt. Die Platine kann sowohl an der Anlage direkt als auch am Stand angebracht werden, somit kann die Anlage flexibel an verschiedenen Standorten eingesetzt werden. Das Wasserabweisende und größtenteils auch Wasserfeste Design ist auf den Außeneinsatz angepasst.

Der Schützenverein Wolfartsweiler (https://www.sv-wolfartsweiler.de) hat seit über einem Jahr 8 umgebaute Anlagen im Betrieb. Pro Anlage kostete uns der Umbau ca. 210€. Pro Anlage kann man mit ca. 2 Arbeitsstunden für die Installation rechnen, zusätzlich zu der Installation von Kabeln im Schießstand. Außerdem testet der Schützenverein aktuell einen Prototypen zur autonomen Laufzeiterfassung und Laufzeitauswertung.  

Mit dem Wettbewerb NMH Makes Heroes (https://nmh-makes-heroes.nmh.de) unterstütze mich die Firma NMH (https://www.nmh.de) mit einer Fördersumme und technischer Beratung. Während der kurzen Wettbewerbszeit (ca. 6 Wochen) entstand aus einem Prototypen ein fertiges, einsatzfähiges System welches ich bei allen 8 Anlagen installieren konnte. Vielen Dank an dieser Stelle an NMH!  

Wenn Sie mein Projekt interressiert und Sie sich für die Zukunft des Projektes interrisieren, können Sie sich gerne die Zukunftsvision anschauen, hier werden mögliche Weiterentwicklungen aufgezeigt. Wenn Sie mich unterstützen wollen, können Sie das gerne über das Github Sponsorprogramm machen.


## Hardware  

Die Automatisierung der Anlage erfolgt mithilfe von Endschaltern und einem **12V DC Motor**, gesteuert von einem **ESP32-D1 mini** auf einer eigens entworfenen Platine. Hier werden die Endschalter so verkabelt, dass die Scheibenposition im Programm (Scheibe 1-5) mit der mechanischen Position übereinstimmt.

Die 3D-gedruckten Komponenten werden zerstörungsfrei an den bestehenden Anlagen angebracht.  
**Getestete Anlagen:** Rika und Hora  
**Link zu den 3D-Modellen inkl. Druckeinstellungen (Makerworld):**  
*(STEP-Dateien findet ihr hier auf GitHub)*

**Hora:**
*   Gesamte Anlage:
*   Motorhalter:
*   Endschalterhalter:
*   Halter:
*   Halter mit Kabel:

**Rika:**
*   Gesamte Anlage:
*   Motorhalter:
*   Endschalterhalter:
*   Platinenhalter:

**Zubehör für beide Typen:**
*   Platinenhalter außen:
*   Scheibe:
*   Adapter Platine zu Gehäuse:

Zur Einhaltung der Schießstandrichtlinien wurde eine Verkleidung aus Blech an dem Motorhalter angebracht. Dieses wurde bei Blexon bestellt. Die entsprechende **STEP-Datei des Blechs** findet ihr ebenfalls hier bei GitHub. 

**Blexon Link:** https://blexon.com

---

## Hardware & Verkabelung

Zur Verkabelung der Anlage wurde eine selbst entworfene Platine angefertigt. 

<p align="center">
  <img width="1073" height="567" alt="Verkabelung" src="https://github.com/user-attachments/assets/d1e27411-412c-41c5-96f0-8fc841993d70" />
  <br>
  <em style="color: grey;">Abbildung 1: Schaltlogik (erstellt mit Inkscape)</em>
</p>

### Überblick der Verkabelung:

*   Alle Endschalter sind über den **COM Anschluss** mit Ground (GND) verbunden.
*   Das Relaismodul wird mit **5V** betrieben und verbindet den Motor über den **Normally Open (NO)** Anschluss mit +12V.
*   Der Informationsanschluss des Relaismoduls wird mit **Pin 25** des ESP32 verbunden. 
*   Der Endschalter beim Motor wird über den **NO Anschluss** mit **Pin 16** des ESP32 verbunden.

Die Endschalter der Klappen werden über die **NO Anschlüsse** an folgende Pins angeschlossen:  
*   Klappe 1: **Pin 23**  
*   Klappe 2: **Pin 5**  
*   Klappe 3: **Pin 26**  
*   Klappe 4: **Pin 18**  
*   Klappe 5: **Pin 19**  

**Fertige Platine bestellen:** (Link zu JLCPCB)

---

### Der Master

Der Master verfügt über folgende Anbauteile:

**Real time clock (RTC):**  
*   SCL an **Pin 22**  
*   SDA an **Pin 21**  

**JDY-31 Bluetooth-serielles Modul:**  
*   RX an **Pin 16**  
*   TX an **Pin 17**

---

### Stücklisten

#### Stückliste für eine Anlage:

| Bezeichnung | Stückzahl pro Anlage | Link |
| :--- | :---: | :--- |
| **3D-Gedruckte Teile** | |
| Endschalterhalter (2 Varianten) | 5 |
| Motorgehäuse | 1 |
| Scheibe | 1 |
| Gehäusehalterungen | 1 |
| Gehäusehalterungen für außerhalb der Anlage (optional) | (1) |
| **Zukaufteile** | |
| Edelstahlbleche | 1 |
| ESP32 D1 Mini | 1 | [Amazon](https://www.amazon.de/AZDelivery-Bluetooth-Entwicklungsboard-Anschluss-kompatibel/dp/B0DHY5C3Q3/ref=sr_1_1_pp?__mk_de_DE=ÅMÅŽÕÑ&crid=3G27NZ7NFXGJA&dib=eyJ2IjoiMSJ9.fSPDNIu22e7D0m9a5o1wA5lt-69fzrOzSSVbpjepEo7NE6N-GI7q-aMGJPGA5-4RT4leLSNRjCEQzlV9Za3PcW-csD_PGM41K-H7Tz-Ijfe2TKqcQzuc5-hdEvgfumyhFzzk39CJi3T8j0VnBtao0r1axcT8jCYRd9_Q6RsGaSmAugo5oenjCcaT94MzEGL7d_QfhLijRroj1i-4aia8rtOEyGlhY2i8jQylf0_xV5suC4OfYcDTnZCUXsgoXn7OYk8WrPmoR9cE1aRhx2buSXOCyckIRECHaAwrrO_GDV4.ZxecHkuZATFtUk2H4oQdUl-2A3XOx3sczMAwzpoFosw&dib_tag=se&keywords=esp32%2Bd1%2Bmini&qid=1774862687&sprefix=esp32%2Bd1%2Bmini%2B%2Caps%2C105&sr=8-1&th=1) |
| Step Down Converter | 1 | [Amazon](https://www.amazon.de/dp/B0B92ZDK6T?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)|
| 12V DC Motor | 1 | [Amazon](https://www.amazon.de/dp/B0B92ZDK6T?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)|
| Platine (optional) | (1) | siehe unten|
| Gehäuse für Platine | (1) | [Amazon](https://www.amazon.de/dp/B0747RGBFF?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_3)|
| Endschalter für Motor | 5 | [Amazon](https://www.amazon.de/dp/B0DX27MVWB?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)|
| Endschalter für Klappen | 1 | [Reichelt](https://www.reichelt.de/de/de/shop/produkt/snap-action-mikroschalter_1x_um_rollenhebel-191380)|
| Kabel (Ausgang Stromversorgung) | 1 | [Amazon](https://www.amazon.de/dp/B07DPND6NG?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)|
| Kugellager | 1 | [Amazon](https://www.amazon.de/dp/B0CL4ZN6BV?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)|
| Schrauben M3x8 | 8 | [Amazon](https://www.amazon.de/dp/B073ZY19VS?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_12&th=1)|
| Schrauben M2x10 | 2 | [Amazon](https://www.amazon.de/dp/B015A3ISUA?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_14)|
| Schrauben M5x10 | 2 | [Amazon](https://www.amazon.de/dp/B015A3ISUA?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_14)|
| Selbstschneidende Schrauben | 4| [Amazon](https://www.reichelt.de/de/de/shop/produkt/snap-action-mikroschalter_1x_um_rollenhebel-191380)|
| Einschmelzmutter M3 | 4 | [Amazon](https://www.amazon.de/dp/B0CRHMB248?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_4)|
| Wasserdichte Kabeldurchführungen | 8 | [Amazon](https://www.amazon.de/dp/B0CXPSG55G?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1&th=1)|
| Radialwellendichtring (optional) | 1 | [Amazon](https://www.amazon.de/dp/B0CXPSG55G?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1&th=1)|

#### Stückliste des Masters:

| Bezeichnung | Stückzahl | Link |
| :--- | :---: | :--- |
| ESP32 D1 Mini | 1 | [Amazon](https://www.amazon.de/AZDelivery-Bluetooth-Entwicklungsboard-Anschluss-kompatibel/dp/B0DHY5C3Q3/ref=sr_1_1_pp?__mk_de_DE=ÅMÅŽÕÑ&crid=3G27NZ7NFXGJA&dib=eyJ2IjoiMSJ9.fSPDNIu22e7D0m9a5o1wA5lt-69fzrOzSSVbpjepEo7NE6N-GI7q-aMGJPGA5-4RT4leLSNRjCEQzlV9Za3PcW-csD_PGM41K-H7Tz-Ijfe2TKqcQzuc5-hdEvgfumyhFzzk39CJi3T8j0VnBtao0r1axcT8jCYRd9_Q6RsGaSmAugo5oenjCcaT94MzEGL7d_QfhLijRroj1i-4aia8rtOEyGlhY2i8jQylf0_xV5suC4OfYcDTnZCUXsgoXn7OYk8WrPmoR9cE1aRhx2buSXOCyckIRECHaAwrrO_GDV4.ZxecHkuZATFtUk2H4oQdUl-2A3XOx3sczMAwzpoFosw&dib_tag=se&keywords=esp32%2Bd1%2Bmini&qid=1774862687&sprefix=esp32%2Bd1%2Bmini%2B%2Caps%2C105&sr=8-1&th=1)
| Bluetooth Modul | 1 | [Amazon](https://www.amazon.de/dp/B0FFZ43YCC?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)
| Real time Clock Modul | 1 | [Amazon](https://www.amazon.de/WINGONEER-DS3231-AT24C32-Precision-Arduino/dp/B01H5NAFUY/ref=sr_1_9?__mk_de_DE=ÅMÅŽÕÑ&crid=2HPPZ6K5755G5&dib=eyJ2IjoiMSJ9.s0vhN-VkJrGlmMQSPCOU7o7Xg1J0LFOspirK2x3d4bzdkUYj6tomziq1BCi5bFN7JYnAaiHWBonPJIUrRnmgQb88jS7LYOj6N00jG1gtYw0dBViVN8Hf9XPuEBDRCDthW2smwgyT2ObKuiXfiEX4QXWSv3uDP2csYk5yIWbJnHFtLAPxOaTmpOOzDSPRvbJKkWxJQxXDlQJGCyPcL0-7nCjn94w1hTRX4AB-IoTDVvERxrjdTCFIsOnB_EEiMoiqmAqlDSMOdpdvg-D3HZ6EQINlctP07pFPCP5X0XZlnII.kBILRI0EZFuDpCngz_KItytw753qo77qMuSNZh_pVsU&dib_tag=se&keywords=real%2Btime%2Bclock&qid=1774863852&sprefix=real%2Btime%2Bclock%2Caps%2C120&sr=8-9&th=1)
| Gehäuse für ESP32 | (1) | [Amazon](https://www.amazon.de/dp/B0747RGBFF?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_3)
| Lötplatine | (1) | [Amazon](https://www.amazon.de/dp/B07DK2S1XG?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_3)

**Sonstige Zukaufteile:**  
*   Kabel:  [Amazon](https://www.amazon.de/dp/B07DK2S1XG?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_3)|
*   Verteilerdosen:  [Amazon](https://www.amazon.de/dp/B09D3XP1Z1?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_3&th=1)|
*   Solarmodul inkl. Akku:  [Amazon](https://www.amazon.de/dp/B09D3XP1Z1?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_3&th=1)|
*   12V-Netzteil für Betrieb ohne Solar:  [Amazon](https://www.amazon.de/dp/B07GFFG1BQ?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_5)|
*   DC-Backup Schaltmodul (bei Betrieb mit Solar + Netzteil):  [Amazon](https://www.amazon.de/dp/B07B4D73K9?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1)|

---

## Software

Die Software der Anlagen sowie des Masters wurde mit der **Arduino IDE** geschrieben. Ihr findet die `.ino` Dateien zum Download im Ordner `Software`.

Bei Inbetriebnahme müsst ihr die MAC-Adresse eures Masters herausfinden und notieren. In den Skripten der Anlagen müssen folgende drei Variablen ganz oben im Code angepasst werden:

1.  **Anlage:** Die Nummer eurer Anlage (von oben nach unten, dann von links nach rechts). Beispiel: Stehende Anlage links = Nr. 1; liegende Anlage = Nr. 2; zweite stehende Anlage von links = Nr. 3 usw.
2.  **uint8_t receiverAddress[]:** Die MAC-Adresse eures Masters.
3.  **Variable `zeit`:** Hier wird die Zeit eingestellt, nach der die Anlage automatisch zieht. Standardmäßig nutzen wir für liegende Anlagen 10 Sekunden (`zeit=10000`) und für stehende Anlagen 20 Sekunden (`zeit=20000`). Die Angabe erfolgt in Millisekunden.

### Handy App

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

Hier könnt ihr eine Liste der letzten Ergebnisse abfragen. Da die Übertragung via Bluetooth Zeit benötigt, ist diese Funktion bei begrenzter Leistung nicht immer zu 100% zuverlässig.  

**Link zur App:**

---

## Netzwerk

<p align="center">
  <img width="800" alt="Netzwerkaufbau" src="https://github.com/user-attachments/assets/8d163abd-0a4f-481d-bdbc-63dafceb2500" />
  <br>
  <em style="color: grey;">Abbildung 5: Netzwerkaufbau (erstellt mit Inkscape)</em>
</p>

Das Netzwerk besteht aus einem Master und bis zu 20 Slaves (bedingt durch die ESP-NOW Einschränkung). Die Anlagen fungieren als Slaves, der Master als eigenständige Zentrale. Folgende Variablen werden intern für Befehle und Daten genutzt:

*   `hits`: Anzahl der Treffer  
*   `Anlage`: Nummer der sendenden Anlage  
*   `reset`: 0-n (Nummer der zu ziehenden Anlage; 0 = alle)  
*   `target`: 0-n (Wechsel in den Target-Modus; 0 = alle)  
*   `normal`: 0-n (Wechsel in den Magazin-Modus; 0 = alle)  
*   `customtarget`: Eigene Zeiteinstellung für den Targetmodus (in Sekunden)  
*   `customnormal`: Eigene Zeiteinstellung für den Magazinmodus (in Sekunden)

Wir haben das Netzwerk erfolgreich mit einem Master und 8 Slaves getestet und sind sehr zufrieden. Der Master verbindet sich per Bluetooth mit dem Handy; Daten und Befehle werden im Textformat gesendet und von der Android App (erstellt mit **MIT App Inventor**) verarbeitet.

---

## Referenzen

*Hier folgen Bilder und Videos der Anlage.*
