#include <Servo.h>
Servo x;
Servo y;

#include <SoftwareSerial.h>
SoftwareSerial bluetooth (2, 3); //RX, TX
char t;

const int but_1 = 9;
const int but_2 = 10;

void setup() {
  Serial.begin (9600);
  bluetooth.begin (9600);
  x.attach (5);
  y.attach (6);
  pinMode (5, OUTPUT);
  pinMode (but_1, INPUT);
  pinMode (but_2, INPUT);
}

void loop() {

if (bluetooth.available()) {
  t = bluetooth.read();

  if (t == 1) {
    x.write (153);
    delay (200);
    //x.write (180);
  }

  else {
    x.write (180);
  }

  if (t == 0) {
    y.write (153);
    delay (200);
    //y.write (180);
  }

  else {
    y.write (180);
  }
}

  int a = digitalRead (but_1);
  int b = digitalRead (but_2);
  Serial.print ("a: ");
  Serial.print (a);
  Serial.print ("   b: ");
  Serial.print (b);
  Serial.println ("");

  if (a == 1) {
    x.write (153);
    delay (200);
    //x.write (180);
  }

  else {
    x.write (180);
  }

  if (b == 1) {
    y.write (153);
    delay (200);
    //y.write (180);
  }

  else {
    y.write (180);
  }

}
