#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 rc (9,8);
const byte bind [6] = "18200";
char Data [32] = "";

String joy1, joy2;

void setup() {
  rc.begin ();
  rc.openWritingPipe (bind);
  rc.setPALevel (RF24_PA_MIN);
  rc.stopListening ();
}

void loop() {
  int x = analogRead (A1);
  int y = analogRead (A2);

  joy1 = map (x, 500, 0, 0, 180);
  joy2 = map (y, 520, 0, 0, 180);

  joy1.toCharArray (Data, 4);
  rc.write (&Data, sizeof(Data));
  joy2.toCharArray (Data, 4);
  rc.write (&Data, sizeof(Data));
  delay (20);

}
