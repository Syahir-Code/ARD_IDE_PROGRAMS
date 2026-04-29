
#include <Servo.h>. 
Servo x; 
Servo y;

const int pot = A1;
int in_val;
int out_val;

void setup() {
  x.attach (0);
  y.attach (1);
  //Serial.begin (9600);
}
void loop() {
  in_val = analogRead (pot);
  out_val = map (in_val, 0, 1023, 0, 180);
  x.write (out_val);
  y.write (out_val);
  //delay (15);

  /*Serial.print ("Pot_Value: ");
  Serial.print (in_val);
  Serial.print ("   ");
  Serial.print ("Servo_Value: ");
  Serial.print (out_val);
  Serial.println ("");*/
}
