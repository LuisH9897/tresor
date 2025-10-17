# Fehlerprotokoll

**Datum:** 17. Oktober 2025  
**Projekt:** Arduino-basiertes Zugangssystem mit Relais, OLED und Servomotor  
**Autor:** LH98

---

## 🧩 Problembeschreibung

Beim Testen des Projekts mit einem **9 V-Block** in Kombination mit einem **Power-Supply-Modul (Ausgang 5 V)** traten mehrere Fehlfunktionen auf.  
Das Ziel war es, den Arduino sowie angeschlossene Komponenten (OLED-Display, Servomotor und Relaismodul) aus derselben Spannungsquelle zu versorgen.

---

## ⚠️ Beobachtete Phänomene

1. **Servomotor bewegt sich nicht**  
   → keine Reaktion auf Steuerbefehle.  
2. **OLED-Display zeigt Text fehlerhaft an**  
   → unvollständige oder flackernde Zeichen, teils unlesbare Darstellung.  
3. **Relais schaltet unregelmäßig ein und aus**  
   → obwohl es halten sollte, fällt es kurz nach Aktivierung wieder ab.

---

## 🔍 Vermutung zur Fehlerursache

Die **5 V-Ausgangsspannung des Power-Supply-Moduls** reicht **nicht aus**, um den **gesamten Strombedarf** aller Komponenten zu decken.  
Eine 9 V-Blockbatterie liefert bei Belastung nur geringe Ströme (meist < 500 mA), was zu **Spannungseinbrüchen** führt.  

Diese Einbrüche verursachen folgende Kettenreaktion:

- Das Relais verliert kurzzeitig seine Haltespannung → schaltet ab.  
- Der Servomotor erhält zu wenig Strom → bleibt stehen.  
- Das OLED-Display bekommt instabile Spannung → fehlerhafte Darstellung.

---

## ✅ Empfohlene Maßnahmen

1. **Power-Supply-Modul entfernen:**  
   - Die **9 V-Batterie direkt an den VIN-Pin (über Relais) und GND des Arduino anschließen**,  
     sodass der interne Spannungsregler des Arduino die 5 V bereitstellt.  
   - Dadurch wird ein Spannungsabfall über das externe Modul vermieden.

2. **Separate Servoversorgung:**  
   - Den **Servomotor** aus einem eigenen 5 V-Regler speisen,  
     Masse (GND) mit dem Arduino verbinden, um Störungen zu vermeiden.

---

## 📈 Fazit

Die bisherige Spannungsversorgung über das Power-Supply-Modul ist **nicht ausreichend stabil**, um Arduino, OLED, Relais und Servomotor gleichzeitig zu betreiben.  
Durch den direkten Anschluss der 9 V-Batterie an den Arduino und eine getrennte Versorgung des Servos kann das Problem voraussichtlich behoben werden.

---

**Nächster Schritt:**  
Test ohne Power-Supply-Modul, direkte Batterieversorgung über VIN, und Überprüfung, ob das Relais dauerhaft halten und der Servomotor zuverlässig anlaufen kann.
