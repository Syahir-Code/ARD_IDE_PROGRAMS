#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int rel1 = 3;
const int rel2 = 4; 
const int buz = 6;

char text[32] = "";
const byte bind [6] = "00001";
RF24 radio (8, 9);

unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

int del1 = 200;
int del2 = 100;
int del3 = 1500;
int del4 = 40000;

void beep (int del1, int del2) {
  digitalWrite (buz, HIGH);
  delay (del1);
  digitalWrite (buz, LOW);
  delay (del2);
}

void setup() {
  pinMode (rel1, OUTPUT);
  pinMode (rel2, OUTPUT);
  pinMode (buz, OUTPUT);
  digitalWrite (rel1, HIGH);
  digitalWrite (rel2, HIGH);
  digitalWrite (buz, LOW);
  radio.begin ();
  radio.openReadingPipe (0, bind);
  radio.setAutoAck (false);
  radio.setDataRate (RF24_250KBPS);
  radio.setPALevel (RF24_PA_MIN);
  radio.startListening ();
}

void loop() {

  if (radio.available()) {
    radio.read (&text, sizeof (text));
    lastReceiveTime = millis ();
    digitalWrite (rel1, LOW);
    digitalWrite (rel2, LOW);

    beep (1000, 30000);
  }

  
  

  /*currentTime = millis ();
  if (currentTime - lastReceiveTime > 100) {
    digitalWrite (rel1, HIGH);
    digitalWrite (rel2, HIGH);
  }*/
  
  
}

  
