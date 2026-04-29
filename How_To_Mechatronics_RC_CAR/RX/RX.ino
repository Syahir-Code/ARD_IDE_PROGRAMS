#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte bind [6] = "00001";
RF24 radio (2, 4);

unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

struct Data_Package {
  int j1;
  int j2;
  int but_val;
};

Data_Package data;

void setup() {
  Serial.begin (9600);
  radio.begin ();
  radio.openReadingPipe (0, bind);
  radio.setAutoAck (false);
  radio.setDataRate (RF24_250KBPS);
  radio.setPALevel (RF24_PA_MIN);
  radio.startListening ();
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);

  //initial value
  data.j1 = 505;
  data.j2 = 520;
  data.but_val = 0;
}

void loop() {

  if (radio.available()) {
    radio.read (&data, sizeof (Data_Package));
    lastReceiveTime = millis ();
  }

  currentTime = millis ();
  if (currentTime - lastReceiveTime > 200) {
    //data.j1 = 505;
    //data.j2 = 520;
    data.but_val = 0;
  }

  if (data.but_val == 1){
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
  }

  else {
    digitalWrite (5, LOW);
    digitalWrite (6, LOW);
  }

  Serial.println (data.but_val);
  
}
