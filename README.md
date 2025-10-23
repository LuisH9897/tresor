# 🔐 Arduino-Tresor mit Relais, Servo, OLED-Anzeige und Starttaster


Dieses Projekt realisiert einen kleinen elektronischen Tresor auf Basis eines Arduino Uno.  
Die Eingabe eines vierstelligen Zahlencodes erfolgt über ein 4x4-Keypad.  
Ein OLED-Display zeigt den Eingabestatus und Rückmeldungen an.  
Nach der korrekten Codeeingabe wird ein Servomotor angesteuert, um den „Riegel“ zu öffnen.  
Ein Relais sorgt für die Selbsthaltung der Stromversorgung – der Arduino bleibt nach dem Einschalten aktiv, bis das Relais wieder abschaltet.  
Ein **Taster** dient als initialer Einschalter, der den Arduino kurzzeitig mit Spannung versorgt, bis das Relais die Selbsthaltung übernimmt.

---

## 🧰 Verwendete Komponenten

| Komponente | Beschreibung |
|-------------|--------------|
| Arduino Uno | Hauptcontroller |
| 4x4-Keypad | Eingabe des Zahlencodes |
| OLED-Display (SSD1306) | Anzeige von Statusmeldungen |
| Relaismodul (KY-019) | Selbsthaltung der Stromversorgung |
| Servomotor | Öffnungsmechanismus |
| Taster | Initialer Einschalter für das System |
| 9V-Batterie oder Netzteil (≥1A empfohlen) | Spannungsversorgung |
| Verbindungskabel & Steckbrett | Aufbau der Schaltung |

---

## ⚙️ Aufbau und Funktionsweise

1. Durch Drücken des **Tasters** wird der Arduino kurzzeitig mit Spannung versorgt.
2. Der Arduino startet und aktiviert sofort das Relais, wodurch die Selbsthaltung greift.  
   → Das System bleibt jetzt dauerhaft eingeschaltet.
3. Über das Keypad wird ein vierstelliger Code eingegeben.
4. Nach korrekter Eingabe:
   - Das Display zeigt **„korrekt“** an.
   - Der Servomotor fährt in die Öffnungsposition.
5. Bei falscher Eingabe:
   - Das Display zeigt **„falsch“** an.
   - Das Relais wird abgeschaltet, der Arduino verliert die Versorgung.
6. Mit der Taste `*` kann nach erfolgreicher Öffnung ein **neuer Code** gespeichert werden.
7. Mit der Taste `#` kann das System manuell abgeschaltet werden.

---

## 🧩 Besonderheit bei der Erstinbetriebnahme

Für die **erste Anwendung** muss der Startcode **„0000“** initial im EEPROM gespeichert werden.  
Dazu sind im Sketch die Kommentarzeichen bei **Zeile 47 und 48** zu entfernen:

```cpp
//for(byte i = 0; i<4; i++)
//  EEPROM.write(i, '0');
