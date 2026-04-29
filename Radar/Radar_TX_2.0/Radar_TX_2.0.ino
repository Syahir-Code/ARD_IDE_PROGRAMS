//Nrf24 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00002";

//HC-SR04
#define echoPin 3
#define trigPin 2
long duration, distance;
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
  s.write (3);
  delay (500);
}

void loop() {

  //distance calculation and data transmission from 10 to 64 degrees
  for(int i=3; i<=75; i++) {  
  s.write(i);
  delay(10);
  distance = calculateDistance();
  transmitData (); 
  }

  //distance calculation and data transmission from 64 to 10 degrees
  for(int i=75; i>=3; i--){  
  s.write(i);
  delay(10);
  distance = calculateDistance();
  transmitData (); 
  }  
}


int calculateDistance () { 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

int transmitData () {
  
  if (distance <= 10)
  { sensorState = 1; }

  else if (distance >= 11 and distance <= 30)
  { sensorState = 2; }

  else if (distance >= 31)
  { sensorState = 3; }

  radio.write(&sensorState, sizeof(sensorState));
}
