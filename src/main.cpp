#include <Arduino.h>
#include <EEPROM.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Keypad.h>
#include <Servo.h>

//Variablendeklarationen
const byte relaisPin = 3;
const byte servoPin = 4;
const int ausschaltzeit = 30000; //Automatische Abschaltung nach 30 000 ms (=30 s) ohne Tastendruck
const byte zeilenzahl = 4;        //Zeilenzahl des Tastenfeldes
const byte spaltenzahl = 4;       //Spaltenzahl des Tastenfeldes
char tasten [zeilenzahl][spaltenzahl] = { //Array stellt Zuordnung der Tasten zu Symbolen dar
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte zeilenPins [zeilenzahl] = {12, 11, 10, 9}; //Tastatur-Instanz wird 
byte spaltenPins [spaltenzahl] = {8, 7, 6, 5};  //mit den Pin-Nummern und
Keypad tastatur = Keypad(makeKeymap(tasten),    //den Tastenwerten verknuepft
zeilenPins, spaltenPins, zeilenzahl, spaltenzahl);

char code [4];                          //4-Byte-Array speichert den Code
char eingabe[4] = {'_', '_', '_', '_'}; //4-Byte-Array speichert die Eingabe
byte cursor = 0;                        //Cursor (Eingabemarke)
boolean codeSetzen = false;             //ist wahr, wenn gerade eine neuer Code programmiert wird
unsigned long autoAus;
const byte schliessposition = 0;        //Schliessposition des Servos. Hier 0 Grad

//Instanzierungen
Servo servomotor;
Adafruit_SSD1306 display(1); //Die Instanz display erwartet zwingend einen Wert. Wert willkuerlich gewaehlt


//Funktionsdeklarationen
int myFunction(int, int);

void setup() {
  servomotor.attach(servoPin);        //Verbindet unseren servomotor an servoPin (Pin 4). Initialisierung
  servomotor.write(schliessposition); //Servomotor faehrt auf Schliessposition

  pinMode(relaisPin, OUTPUT);
  digitalWrite(relaisPin, HIGH);

  //for(byte i = 0; i<4; i++)         //Bei der ersten Benutzung des Tresors wird ein anderer Wert in die
  //  EEPROM.write(i, '0');           //EEPROM-Speicherzellen geschrieben. Nur so kann er oeffnen.
                                      //Das Einstellen eines neuen Codes ist erst nach dem Oeffnen moeglich
                                      //Es reicht, die Kommentarzeichen am Zeilenanfang zu entfernen, den
                                      //Sketch hochzuladen und einmal laufen lassen. Anschliessend werden
                                      //die Kommentarzeichen gesetzt und der Sketch erneut hochgeladen
  for(byte i = 0; i<4; i++) {
    code[i] = EEPROM.read(i);         //Code aus Speicher lesen
  }

  display.begin(SSD1306_SWITCHCAPVCC, 60);  //Display-Verbindung initialisieren (mit Standard-I2C-Adresse 60)
  display.clearDisplay();                   //Display loeschen
  display.setTextSize(3);                   //Textgroesse setzen
  display.setTextColor(WHITE);              //Textfarbe setzen
  display.setCursor(15,8);                  //Einfuegmarke an Position setzen
  display.print("Code?");                   //Text eingefuegt
  display.display();                        //Displayausgabe

  autoAus = millis() + ausschaltzeit;

}

void loop() {
  servomotor.write(90);  //Ueberpruefung fur Bewegung des Motors
  delay(1000);
  servomotor.write(180);
  delay(1000);
}

//Fiunktionsdefinitionen
int myFunction(int x, int y) {
  return x + y;
}