#include <Servo.h>
Servo myservo;
int Position ;

void setup() 
{  
  myservo.attach(11);  
  Serial.begin(9600);  
}

void loop()
{
 if(Serial.available()>0)
 { 
  Position = Serial.read();
  Position = map(Position, 0, 180, 180, 0); 
  myservo.write(Position);        
 }
}          
