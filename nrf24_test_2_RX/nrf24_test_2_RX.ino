#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radPin (9,8);
const byte bind [6] = "57100";

int green = 4;
int red = 6;

unsigned long Data;

void setup() {
  //Serial.begin(9600);
  radPin.begin();
  radPin.openReadingPipe (0, bind);
  radPin.setPALevel (RF24_PA_MIN);
  radPin.startListening();
  pinMode (green, OUTPUT);
  pinMode (red, OUTPUT);
}

void loop() {
  
  if (radPin.available()) {
    radPin.read (&Data, sizeof(Data));
    delay (20);

    if (Data == 656756) {
      digitalWrite (green, HIGH);
      digitalWrite (red, LOW);
    }
    
    /*Serial.print (Data);
    Serial.println ("    Receiving...");
    delay (500);*/
  }

  else {
    digitalWrite (green, LOW);
    digitalWrite (red, HIGH);
    /*Serial.println ("CONNECTION LOST");
    delay(500);*/
  }
  delay (20);
}
