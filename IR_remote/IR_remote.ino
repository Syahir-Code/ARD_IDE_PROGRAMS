#include <IRremote.h>
#define IR_RECEIVE_PIN 11  // Your IR receiver pin
int motor = 5;
int motorspeed = 6;
int bulb = 3;
int green = 8;
int yellow = 9;
int red = 10;

void setup() {
  pinMode (motor, OUTPUT);
  pinMode (bulb, OUTPUT);
  pinMode (motorspeed, OUTPUT);
  digitalWrite (bulb, HIGH);
  digitalWrite (motor, LOW);
  for (int i=8; i<=10; i++) {
    pinMode(i, OUTPUT);
    digitalWrite (i, LOW);
  }
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start receiver
}

void LED (int g, int y, int r) {
  digitalWrite (green, g);
  digitalWrite (yellow, y);
  digitalWrite (red, r);
}

void loop() {
  uint32_t data = IrReceiver.decodedIRData.decodedRawData;
  
  if (IrReceiver.decode()) {
    switch (data) {
      case 0xBA45FF00:
      digitalWrite (motor, HIGH);
      analogWrite (motorspeed, 125);
      LED (1,0,0);
      break;

      case 0xB946FF00:
      digitalWrite (motor, HIGH);
      analogWrite (motorspeed, 170);
      LED (0,1,0);
      break;

      case 0xB847FF00:
      digitalWrite (motor, HIGH);
      analogWrite (motorspeed, 255);
      LED (0,0,1);
      break;

      case 0xE619FF00:
      digitalWrite (motor, LOW);
      LED (0,0,0);
      break;

    }

    if(data == 0xF708FF00){
      digitalWrite (bulb, LOW);
    }
    
    else if (data == 0xA55AFF00){
      digitalWrite (bulb, HIGH);
    }
    
    IrReceiver.resume(); // REQUIRED to receive next signal
  }
  
}
