#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte bind [6] = "00001";
RF24 radio (3, 4);

void setup() {
  radio.begin ();
  radio.openWritingPipe (bind);
  radio.setAutoAck (false);
  radio.setDataRate (RF24_250KBPS);
  radio.setPALevel (RF24_PA_MIN);
  radio.stopListening ();
}

void loop() {
  const char text[] = "Hi";
  radio.write(&text, sizeof(text));
}
