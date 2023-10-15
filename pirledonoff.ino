# define S 3
int c=0;
int state=0;
int lstate=0;
unsigned long lasttriggertime=0;
unsigned long time=1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state=digitalRead(S);
  
  if(state!=lstate){
    if(state==1){
      Serial.println('H');
      digitalWrite(7,HIGH);
      lasttriggertime=millis();
    }
    else{
      
      if(millis()-lasttriggertime>=time){
        Serial.println('L');
        digitalWrite(7,LOW);
      }
    }
    lstate=state;
  }
}
