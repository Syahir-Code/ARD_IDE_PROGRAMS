#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte bind [6] = "00001";
RF24 radio (5, 6);

//int but = 3;

struct Data_Package {
  int throttle;
  int steering;
  //int but_val;
};

Data_Package data;

void setup() {
  radio.begin ();
  radio.openWritingPipe (bind);
  radio.setAutoAck (false);
  radio.setDataRate (RF24_250KBPS);
  radio.setPALevel (RF24_PA_MIN);
  radio.stopListening ();

  //pinMode (but, INPUT_PULLUP);

  //initial value
  data.throttle = 518;
  data.steering = 503;
}

void loop() {
  data.throttle = analogRead (A0);
  data.steering = analogRead (A2);
  //data.but_val = digitalRead (but);

  radio.write (&data, sizeof(Data_Package));

}
