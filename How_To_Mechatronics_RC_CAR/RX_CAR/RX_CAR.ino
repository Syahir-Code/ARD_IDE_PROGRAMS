#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte bind [6] = "00001";
RF24 radio (8, 7);

int in1 = 10;
int in2 = 9;
int in3 = 6;
int in4 = 5;

unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

struct Data_Package {
  int j1;
  int j2;
};

Data_Package data;

void setup() {
  radio.begin ();
  radio.openReadingPipe (0, bind);
  radio.setAutoAck (false);
  radio.setDataRate (RF24_250KBPS);
  radio.setPALevel (RF24_PA_MIN);
  radio.startListening ();

  //initial value
  data.j1 = 500;
  data.j2 = 515;

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
    data.j1 = 500;
    data.j2 = 515;
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite (in4, LOW);
  }

  if (data.j1 < 500) {
    //int front = map (data.j1, 500, 0, 85, 255);
    digitalWrite  (in1, LOW);
    digitalWrite (in2, HIGH);
    digitalWrite (in3, LOW);
    digitalWrite (in4, HIGH);  
  }

  else if (data.j1 > 510) {
    //int back = map (data.j1, 510, 1023, 85, 255);
    digitalWrite (in1, HIGH);
    digitalWrite (in2, LOW);
    digitalWrite (in3, HIGH);
    digitalWrite (in4, LOW);
  }

  else {
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite (in4, LOW);
  }

  /*if (data.j2 < 515) {
    //int right = map (data.j2, 515, 0, 85, 255);
    digitalWrite (in1, LOW);
    digitalWrite (in2, HIGH);
    digitalWrite (in3, HIGH);
    digitalWrite (in4, LOW);
  }

  else if (data.j2 > 525) {
    //int left = map (data.j2, 525, 1023, 85, 255);
    digitalWrite (in1, HIGH);
    digitalWrite (in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite (in4, HIGH);
  }
  
  else {
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite (in4, LOW);
  }*/
  
}
