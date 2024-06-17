// Define pins
const int mainsPin = 2;
const int inverterPin = 4;
const int mainsCommandPin = A6;
const int inverterCommandPin = A7;

void setup() {
  pinMode(mainsPin, INPUT);
  pinMode(inverterPin, INPUT);
  pinMode(mainsCommandPin, OUTPUT);
  pinMode(inverterCommandPin, OUTPUT);
  digitalWrite(mainsCommandPin, LOW);
  digitalWrite(inverterCommandPin, LOW);
}

void loop() {
  bool mainsAvailable = digitalRead(mainsPin);
  bool inverterAvailable = digitalRead(inverterPin);

  if (mainsAvailable) {
    digitalWrite(mainsCommandPin, HIGH);
    digitalWrite(inverterCommandPin, LOW);
  } else if (inverterAvailable) {
    digitalWrite(mainsCommandPin, LOW);
    digitalWrite(inverterCommandPin, HIGH);
  } else {
    digitalWrite(mainsCommandPin, LOW);
    digitalWrite(inverterCommandPin, LOW);
  }
  delay(10);
}
