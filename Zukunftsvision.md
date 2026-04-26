# Zukunftsvision – Die Elektronische Biathlonanlage 2.0

Im Verein nutzen wir aktuell seit knapp einem Jahr acht aufgerüstete Biathlonanlagen und sind sehr zufrieden. Daher erfolgt nun auch die Veröffentlichung als Open-Source-Projekt.

Der aktuelle Aufbau ist jedoch recht zeitintensiv (ca. 2 Stunden pro Anlage) und benötigt Fachkenntnisse im Löten, Programmieren und 3D-Drucken. Nicht jeder Verein hat jemanden, der diese Fähigkeiten besitzt und gewillt ist, die Zeit dafür zu opfern. Daher möchte ich den Umbausatz zu einem echten „Plug-and-Play“-System weiterentwickeln.

#### Geplante Hardware-Änderungen:
* **Steckverbindungen:** Umstieg auf genormte Kabel mit M8- oder M12-Schraubverbindungen.
* **Sensorik:** Umstieg auf Induktivsensoren für die Treffererfassung (ebenfalls mit Standard-M12-Verbindung).
* **Antrieb:** Umstieg auf Servomotoren, um zusätzliche Endschalter zu vermeiden.
* **Platinen-Design:** * Eigene Platine speziell für Sensoren.
    * Neue Steuerplatine.
    * Neue Platine für die Stromversorgung mit Schaltlogik für den kombinierten Betrieb von Solar und Netzteil.
* **Kommunikation:** Anschluss eines M8- oder M12-Ethernet-Kabels ermöglichen, um eine reibungslose Kommunikation auch bei vielen Anlagen zu gewährleisten.
* **Mechanik:** Neue Halterungen für Sensoren, Platinen und Motoren sowie die Anpassung an weitere Anlagentypen.
* **Fertigung:** 3D-Druckteile per Link bestellbar machen (für Vereine ohne eigenen 3D-Drucker).

#### Begleitende Inhalte:
* YouTube-Tutorials für den Aufbau, die Software-Installation und die Bedienung der App.
* Eine YouTube-Entscheidungshilfe für interessierte Vereine.
* Eventuell eine eigene Projektwebsite sowie ein Discord-Kanal zur direkten Kommunikation.

### Kosten der Weiterentwicklung
Diese Entwicklung benötigt Zeit und finanziellen Einsatz. Die geplanten Entwicklungskosten belaufen sich auf:

| Teil | Preis |
| :--- | ---: |
| Testanlage leihen/kaufen | 350,00 € |
| Neue Steuerplatine | 25,00 € |
| Neue Sensorplatine | 30,00 € |
| Neue Stromverteilungsplatine | 20,00 € |
| Servomotor | 20,00 € |
| Induktivsensoren (5 Stück) | 70,00 € |
| 3D-Druckteile (Zukauf testen) | 120,00 € |
| Filament (Testdrucke) | 40,00 € |
| Kabel und Schrauben | 50,00 € |
| Netzgerät | 15,00 € |
| ESP32 D1 Mini (2x) | 30,00 € |
| Sonstige Teile | 30,00 € |
| **Gesamt** | **800,00 €** |

Ziel ist eine Plug-and-Play-Lösung, die einfach und schnell installiert werden kann. Die Kosten pro Umbausatz werden sich schätzungsweise auf ca. 250 € bis 350 € belaufen (abhängig von Stückzahl und Ausführung).

### Laufzeiterfassung
Aktuell arbeite ich zudem an einem Prototypen zur Laufzeiterfassung. Dieser ist momentan über ein einfaches NFC-Zeitnahmesystem umgesetzt, soll aber in naher Zukunft auf Kameratechnik umgestellt werden. Mithilfe von Google Sheets und App Script werden die Daten erfasst, sortiert und für jeden Athleten eine individuelle Übersicht erstellt. Da der erste Prototyp derzeit ausgiebig getestet wird, gibt es hier noch keine konkreten Kostenpläne; die Schätzung für das Gesamtsystem liegt bei ca. 500 €.

Sollten Ihnen diese Ideen gefallen, können Sie mich gerne bei der Umsetzung unterstützen. Bei gofundme sammle ich die 800€ für die Weiterentwicklung: https://gofund.me/d172d4579

Vielen Dank für Ihr Interesse und Ihre Unterstützung!
