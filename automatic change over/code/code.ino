// Define pins
const int mainsPin = 2;
const int inverterPin = 4;
// Change these to appropriate digital pins
const int mainsCommandPin = 5; // Example pin
const int inverterCommandPin = 6; // Example pin

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize pin modes
  pinMode(mainsPin, INPUT);
  pinMode(inverterPin, INPUT);
  pinMode(mainsCommandPin, OUTPUT);
  pinMode(inverterCommandPin, OUTPUT);
  
  // Initialize outputs to LOW
  digitalWrite(mainsCommandPin, LOW);
  digitalWrite(inverterCommandPin, LOW);
}

void loop() {
  bool mainsAvailable = digitalRead(mainsPin);
  bool inverterAvailable = digitalRead(inverterPin);

  // Check if mains power is available
  if (mainsAvailable) {
    digitalWrite(mainsCommandPin, HIGH);
    digitalWrite(inverterCommandPin, LOW);
    Serial.println("Mains power is available.");
  }
  // If mains is not available, check if inverter power is available
  else if (!mainsAvailable && inverterAvailable) {
    digitalWrite(mainsCommandPin, LOW);
    digitalWrite(inverterCommandPin, HIGH);
    Serial.println("Inverter power is available on uno.");
  }
  // If neither power source is available
  else {
    digitalWrite(mainsCommandPin, LOW);
    digitalWrite(inverterCommandPin, LOW);
    Serial.println("No power source is available.");
  }

  delay(350);
}

