//Nrf24 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00002";

//HC-SR04
#define echoPin 3
#define trigPin 2
long duration, cm;
int sensorState = 0;

//SG90
#include <Servo.h>
Servo s;

void setup() {
  //Nrf24
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  //HC-SR04
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);

  //SG90
  s.attach (5);
  s.write (37);
  delay (500);
  s.write (10);
  delay (500);
}

void loop() {

  radar (); 
  
  //Distance measuring & data transmission
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration * 0.034 / 2 + 1;

  if (cm <= 10)
  { sensorState = 1; }

  else if (cm >= 11 and cm <= 30)
  { sensorState = 2; }

  else if (cm >= 31)
  { sensorState = 3; }

  radio.write(&sensorState, sizeof(sensorState));
  
}

void radar () {

  for (int x=3; x <= 75; x++) {
    s.write (x);
    delay (15);
  }

  for (int y=75; y >= 3; y--) {
    s.write (y);
    delay (15);
  }
  
}
