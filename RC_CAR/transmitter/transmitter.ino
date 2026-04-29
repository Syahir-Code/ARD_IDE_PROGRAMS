#include <SPI.h>        // Include SPI Library
#include <nRF24L01.h>   // Include RF24 Library
#include <RF24.h>       // Include RF24 Library

RF24 radio(10,9); // CE, CSN Pins
const byte address[6] = "00001";   // Address for communication
char joyData[32] = "";    // Data to be sent over radio

String joy1, joy2;

void setup() {
  radio.begin();   // Initiate Radio
  radio.openWritingPipe(address); // Set address
  radio.setPALevel(RF24_PA_MIN);  // Set Power Amplification Level
  radio.stopListening();
}

void loop() {


  
  joy1 = analogRead(A1);  // Read Joystick Data
  joy2 = analogRead(A2);
  

  joy1.toCharArray(joyData, 6);
  radio.write(&joyData, sizeof(joyData)); // send data over radio
 

  joy2.toCharArray(joyData, 6);
  radio.write(&joyData, sizeof(joyData));
  delay(20);
  
}
