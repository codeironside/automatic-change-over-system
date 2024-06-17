#include <LiquidCrystal.h> //library for LCD

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int Main_Check = A0;
const int Inverter_Check = A3;
const int Gen_Check = A5;
const int Main_Relay = A1;
const int Gen_Relay = A2;
const int Inverter_Relay = A4;
const int Gen_Start = 7;

void setup() {
  pinMode(Gen_Start, OUTPUT);
  pinMode(Main_Relay, OUTPUT);
  pinMode(Gen_Relay, OUTPUT);
  pinMode(Inverter_Relay, OUTPUT);

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
}

void loop() {
  int mainVoltage = analogRead(Main_Check) * 5.0 / 1023.0 * 5;
  int genVoltage = analogRead(Gen_Check) * 5.0 / 1023.0 * 5;
  int inverterVoltage = analogRead(Inverter_Check) * 5.0 / 1023.0 * 5;

  if (mainVoltage >= 8) {
    // Mains is available
    digitalWrite(Main_Relay, HIGH);
    digitalWrite(Gen_Relay, LOW);
    digitalWrite(Inverter_Relay, LOW);
    digitalWrite(Gen_Start, LOW);
   lcd.setCursor(0,0);
     lcd.print("TOBI PROJECT     ");
     lcd.setCursor(0,1);
  lcd.print("MAINS: ON  ");
  lcd.setCursor(0,2);
  lcd.print("GEN: OFF");
  lcd.setCursor(0,3);
  lcd.print("INVERTER: OFF ");
  } else if (genVoltage >= 8) {
    // Mains is not available, but generator is available
    digitalWrite(Main_Relay, LOW);
    digitalWrite(Gen_Relay, HIGH);
    digitalWrite(Inverter_Relay, LOW);
    digitalWrite(Gen_Start, HIGH);
   lcd.setCursor(0,0);
     lcd.print("TOBI PROJECT     ");
     lcd.setCursor(0,1);
  lcd.print("MAINS: OFF  ");
  lcd.setCursor(0,2);
  lcd.print("GEN: ON");
  lcd.setCursor(0,3);
  lcd.print("INVERTER: OFF ");

 
  } else if (inverterVoltage >= 8) {
    // Neither mains nor generator is available, but inverter is available
    digitalWrite(Main_Relay, LOW);
    digitalWrite(Gen_Relay, LOW);
    digitalWrite(Inverter_Relay, HIGH);
    digitalWrite(Gen_Start, LOW);
   lcd.setCursor(0,0);
     lcd.print("TOBI PROJECT     ");
     lcd.setCursor(0,1);
  lcd.print("MAINS: OFF  ");
  lcd.setCursor(0,2);
  lcd.print("GEN: OFF");
  lcd.setCursor(0,3);
  lcd.print("INVERTER: ON ");
  } else {
    // No power source is available
    digitalWrite(Main_Relay, LOW);
    digitalWrite(Gen_Relay, LOW);
    digitalWrite(Inverter_Relay, LOW);
    digitalWrite(Gen_Start, LOW);
   lcd.setCursor(0,0);
     lcd.print("TOBI PROJECT     ");
     lcd.setCursor(0,1);
  lcd.print("MAINS: OFF  ");
  lcd.setCursor(0,2);
  lcd.print("GEN: 0FF");
  lcd.setCursor(0,3);
  lcd.print("INVERTER: OFF ");
  }
}

