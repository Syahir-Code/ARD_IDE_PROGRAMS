#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte bind [6] = "00001";
RF24 radio (2, 4);

int enA = 5;
int in1 = 6;
int in2 = 9;
int in3 = 7;
int in4 = 8;
int enB = 10;

unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

struct Data_Package {
  int j1;
  int j2;
};

Data_Package data;

int steering, throttle;
int motorspeedA = 0;
int motorspeedB = 0;

void setup() {
  radio.begin ();
  radio.openReadingPipe (0, bind);
  radio.setAutoAck (false);
  radio.setDataRate (RF24_250KBPS);
  radio.setPALevel (RF24_PA_MIN);
  radio.startListening ();

  //initial value
  data.j1 = 518;
  data.j2 = 503;

  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
}

void loop() {

  if (radio.available()) {
    radio.read (&data, sizeof (Data_Package));
    lastReceiveTime = millis ();
  }

  currentTime = millis ();
  if (currentTime - lastReceiveTime > 1000) {
    data.j1 = 518;
    data.j2 = 503;
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite (in4, LOW);
  }

  throttle = data.j1;
  steering = data.j2;

  //front
  if (throttle  > 518) {
    digitalWrite (in1, HIGH);
    digitalWrite (in2, LOW);
    digitalWrite (in3, HIGH);
    digitalWrite (in4, LOW);
    motorspeedA = map(throttle, 518, 1023, 85, 255);
    motorspeedB = map(throttle, 518, 1023, 85, 255);
  }

  //back
  else if (throttle < 518) {
    digitalWrite (in1, LOW);
    digitalWrite (in2, HIGH);
    digitalWrite (in3, LOW);
    digitalWrite (in4, HIGH);
    motorspeedA = map(throttle, 518, 0, 85, 255);
    motorspeedB = map(throttle, 518, 0, 85, 255);
  }

  else {
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite (in4, LOW);
    motorspeedA = 0;
    motorspeedB = 0;
  }

  //right
  if (steering < 503) {
    int r_mapped = (503, 0, 0, 255);
    motorspeedA = motorspeedA + r_mapped;
    motorspeedB = motorspeedB - r_mapped;

    if (motorspeedA > 255) {
      motorspeedA = 255;
    }

    if (motorspeedB < 0) {
      motorspeedB = 0;
    }   
  }

  //left
  else if (steering > 503) {
    int l_mapped = (503, 1023, 0, 255);
    motorspeedA = motorspeedA - l_mapped;
    motorspeedB = motorspeedB + l_mapped;

    if (motorspeedA < 0) {
      motorspeedA = 0;
    }

    if (motorspeedB > 255) {
      motorspeedB = 255;
    }
  }

  if (motorspeedA < 85) {
    motorspeedA = 0;
  }

  if (motorspeedB < 85) {
    motorspeedB = 0;
  }
  
  analogWrite (enA, motorspeedA);
  analogWrite (enB, motorspeedB);
  
}
