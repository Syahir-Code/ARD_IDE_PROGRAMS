#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

int joy1, joy2;
Servo servo1, servo2;
const byte bind [6] = "18200";
RF24 rc  (9,8);
char Data [32] = "";

void setup() {
  servo1.attach (3);
  servo2.attach (4);
  rc.begin ();
  rc.openReadingPipe (0, bind);
  rc.setPALevel (RF24_PA_MIN);
  rc.startListening ();
}

void loop() {
  if (rc.available ())  {
    rc.read (&Data, sizeof(Data));
    joy1 = atoi (&Data[0]);
    delay (5);
    rc.read (&Data, sizeof(Data));
    joy2 = atoi (&Data[0]);
    delay (5);
  }

  servo1.write (joy1);
  servo2.write (joy2);
  
}
