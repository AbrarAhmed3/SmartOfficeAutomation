#include <Ultrasonic.h> // Library for ultrasonic sensor

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200 // Maximum distance (in cm) to consider for water level

const int pumpPin = 8; // Pin connected to the relay module to control the pump
const int buzzerPin = 6; // Pin connected to the buzzer

// LED lights
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

bool isPumpOn = false; // Variable to track the pump state
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN); // Create an ultrasonic sensor object

void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); // Initially, turn off the pump
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as OUTPUT
  noTone(buzzerPin); // Turn off the buzzer initially
  pinMode(led1, OUTPUT); // Set LED pins as OUTPUT
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float distance = ultrasonic.read(); // Measure the distance from the sensor to the water surface in cm

  if (distance == 0.0 || distance >= MAX_DISTANCE) {
    Serial.println("Error: No measurement or out of range"); // If there's an error in measurement, print an error message
  } 
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Check the water level and control the pump accordingly
    if (distance <= 3.0) {
      // Tank is full, turn on all LEDs and turn off the pump
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(pumpPin, LOW);
      if (isPumpOn) {
        noTone(buzzerPin); // Turn off the buzzer when the pump turns off
        isPumpOn = false; // Update the pump state
      }
      Serial.println("Tank is full. Pump is OFF.");
    } 
    else if (distance <= 5.0) {
      // Tank is 75% full
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    } 
    else if (distance <= 7.0) {
      // Tank is 50% full
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    } 
    else if (distance <= 9.0) {
      // Tank is 25% full
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    } 
    else {
      // Tank is empty, turn off all LEDs and turn on the pump
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      
      if (!isPumpOn) {
        digitalWrite(pumpPin, HIGH); // Turn on the pump when the tank is not full and the pump is not already on
        isPumpOn = true; // Update the pump state
        tone(buzzerPin, 1000); // Turn on the buzzer when the pump turns on
        Serial.println("Tank is not full. Pump is ON.");
      }
    }

    // Add a delay here before turning off the buzzer
    delay(500); // Wait for a second before turning off the buzzer
    noTone(buzzerPin); // Turn off the buzzer
  }
  delay(500); // Delay for a second before taking the next measurement
}
