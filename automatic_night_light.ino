int nightLight = 13;
void setup() {
  pinMode (nightLight, OUTPUT); 
  // initialize serial communication at 9600 bits per second: for LDR Sensor
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int nightSensorValue = analogRead(A0); // LDR PhotoResistor

  // you can adjust the value as per your usecase
  if (nightSensorValue >= 600 && nightSensorValue <= 1100 ){
      Serial.print ("it is dark - ");
      digitalWrite (nightLight, LOW); // light on

  } else {
      Serial.print ("it is bright - ");
      digitalWrite (nightLight, HIGH); // light off    
  }
}
