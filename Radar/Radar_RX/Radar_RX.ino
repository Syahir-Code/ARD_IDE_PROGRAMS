//Nrf24
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00002";

int sensorState = 0;
int buzzer = 3;
int green = 4;
int yellow = 5;
int red = 6;

void setup() { 
  //Nrf24
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);

  pinMode (red, OUTPUT);
  pinMode (yellow, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (buzzer, OUTPUT);
}

void loop() {
  //Starting Nrf24 as receiver
  radio.startListening();
  while (!radio.available());
  radio.read(&sensorState, sizeof(sensorState));

  if (sensorState == 1)
  { digitalWrite (red, HIGH);
    digitalWrite (yellow, LOW);
    digitalWrite (green, LOW);
    tone (buzzer, 3000); 
    }

  else if (sensorState == 2)
  { digitalWrite (red, LOW); 
    digitalWrite (yellow, HIGH);
    digitalWrite (green, LOW);
    noTone (buzzer); 
    }

  else if (sensorState == 3)
  { digitalWrite (red, LOW); 
    digitalWrite (yellow, LOW);
    digitalWrite (green, HIGH);
    noTone (buzzer); 
   }

}

/*digitalWrite (red, HIGH);
  digitalWrite (yellow, LOW);
  digitalWrite (green, LOW);
  delay (500);
  digitalWrite (red, LOW);
  digitalWrite (yellow, HIGH);
  digitalWrite (green, LOW);
  delay (500);
  digitalWrite (red, LOW);
  digitalWrite (yellow, LOW);
  digitalWrite (green, HIGH);
  delay (500); 
  digitalWrite (red, LOW);
  digitalWrite (yellow, LOW);
  digitalWrite (green, LOW);*/
