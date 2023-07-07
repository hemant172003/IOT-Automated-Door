#include<Servo.h>
int led = 13;                // the pin that the LED is atteched to
int servo2=8;
int sensor = 9;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int pos = 0;
Servo myServo1;
void setup() {
  myServo1.attach(servo2);
  myServo1.write(pos);
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    ServosOpen();
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      ServosClose();
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}

void ServosOpen()
{
  for(;pos<=180;pos+=10)
  {
    myServo1.write(pos);
    delay(400);
    
  }
}
void ServosClose()
{
  for(;pos>=0;pos-=10)
  {
    myServo1.write(pos);
    delay(400);
   
  }
}
