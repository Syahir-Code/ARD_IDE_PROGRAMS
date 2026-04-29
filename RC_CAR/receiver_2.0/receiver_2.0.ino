#include <SPI.h>          // Include SPI Library
#include <nRF24L01.h>     // Include RF24 Library
#include <RF24.h>         // Include RF24 Library
int enA = 6;
int enB = 3;
int in1 = 8;
int in2 = 7;
int in3 = 5;
int in4 = 4;
RF24 radio(10,9);       // CE, CSN Pins
const byte address[6] = "00001";  // Address for communication
char joyData[32] = "";    // Data to be sent over radio
int joy1, joy2;         // Joystick data
int front_v;
int back_v;
int left_v;
int right_v;


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);

  Serial.begin (9600);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  
  
  if (radio.available()) {
    radio.read(&joyData, sizeof(joyData));
    joy1 = atoi(&joyData[0]);
    delay(10);
    radio.read(&joyData, sizeof(joyData));
    joy2 = atoi(&joyData[0]);
    delay(10);
    Serial.print ("Front/Back: ");
    Serial.print (joy1);
    Serial.print ("Left/Right: ");
    Serial.println (joy2); 
 } 

 if (joy1 > 500) {        // condition when joystick is UP
    front_v = map(joy1, 500, 1023, 100, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, front_v);
    analogWrite(enB, front_v);
  }
  
  else if (joy1 < 500) {   // condition when joystick is DOWN
    back_v = map(joy1, 500, 0, 100, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, back_v);
    analogWrite(enB, back_v);
  }

  else {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }

  if (joy2 < 532) {         // condition when joystick is LEFT
    left_v = map(joy2, 532, 0, 100, 255);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(enA, left_v);
    analogWrite(enB, left_v);    
  }
  
  else if (joy2 > 532) {    // condition when joystick is RIGHT
    right_v = map(joy2, 532, 1023, 100, 255);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enA, right_v);
    analogWrite(enB, right_v);   
  }
  
  else {   // set signal to 0 to avoid noise
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);  
  }

 /*else {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
 }*/

}
