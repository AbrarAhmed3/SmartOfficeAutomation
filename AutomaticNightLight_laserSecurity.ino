const int laserPin = 2;     // Pin connected to the laser module
const int ldrPin1 = A0;     // Pin connected to the first LDR
const int ldrPin2 = A1;     // Pin connected to the second LDR
const int ledPin = 13;      // Pin connected to the night light LED
const int buzzerPin = 12;   // Pin connected to the Buzzer
const int threshold = 300;  // LDR threshold value for detecting darkness
const int threshold2 = 200;  // LDR threshold value for detecting darkness of laser security system

void setup() {
  pinMode(laserPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(laserPin, HIGH);  // Turn on the laser by default
  Serial.begin(9600);
}

void loop() {
  int ldrValue1 = analogRead(ldrPin1);
  int ldrValue2 = analogRead(ldrPin2);

  if (ldrValue1 > threshold) {   // It's dark
    digitalWrite(ledPin, HIGH);  // Turn on the night light
    Serial.println(" dark");
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the night light
    Serial.println("light");
  }
  if(ldrValue2 > threshold2){
    digitalWrite(buzzerPin, HIGH);
    Serial.println(ldrValue2);
    Serial.println("Security Breach Detected!");
  }else{
    digitalWrite(buzzerPin, LOW);
    Serial.println(" Tight Security!");
  }
}
