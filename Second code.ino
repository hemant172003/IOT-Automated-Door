////PIR
#include<Servo.h>
int sensor = 5; //signal pin of sensor to digital pin 5. 
int state = LOW; 
int val = 0; 
int servo1=9;
int pos=0;
Servo myServo;
////
void setup() {
  myServo.attach(servo1);
  myServo.write(pos);
  
  Serial.begin(9600);
  ///PIR
  pinMode(13, OUTPUT); // Led is determined as an output here. 
  pinMode(sensor, INPUT); // PIR motion sensor is determined is an input here. 
}
void loop() {  
  val = digitalRead(sensor); 

  Serial.println("Digital Value : ");
  Serial.println(val);
  
  if (val == HIGH) { 
    digitalWrite(13, HIGH); 
    delay(500); // Delay of led is 500  
    if (state == LOW) {
      Serial.println(" Motion detected"); 
      ServosOpen();
      state = HIGH; 
      }
    }
 else {
  digitalWrite(13, LOW);
  delay(500); 
  if (state == HIGH){
    Serial.println("The action/ motion has stopped");
    ServosClose();
  state = LOW; 
  }
 }
}

void ServosOpen()
{
  for(;pos<=180;pos+=10)
  {
    myServo.write(pos);
    delay(400);
    
  }
}
void ServosClose()
{
  for(;pos>=0;pos-=10)
  {
    myServo.write(pos);
    delay(400);
   
  }
}
