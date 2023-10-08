int alarm_buzzer = 13;
int laserLight = 12;
void setup() {
  pinMode (laserLight, OUTPUT);
  pinMode (alarm_buzzer, OUTPUT);
  digitalWrite (laserLight, HIGH);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int laserSensorValue = analogRead(A0);

  if (nightSensorValue >= 600 && nightSensorValue <= 1100 ){
      // Serial.print ("it is dark - ");
      digitalWrite (alarm_buzzer, LOW); // Alarm Buzzer on
      delay(1000);

  } else {
      // Serial.print ("it is bright - ");
      digitalWrite (alarm_buzzer, HIGH); // Alarm Buzzer off
  }
}
