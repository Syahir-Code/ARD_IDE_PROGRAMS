#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radPin (2,3);
const byte bind [6] = "57100";

void setup() {
  radPin.begin();
  radPin.openWritingPipe (bind);
  radPin.setPALevel (RF24_PA_MIN);
  radPin.stopListening();
}

void loop() {
  unsigned long Data;
  Data = 656756;

  radPin.write (&Data, sizeof(Data));
  delay (20);
}
