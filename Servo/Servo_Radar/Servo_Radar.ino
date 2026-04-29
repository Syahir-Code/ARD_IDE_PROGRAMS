#include <Servo.h>.
Servo s;

void setup() {
  s.attach (5);
  s.write (10);
  delay (500);
}

void loop() {

  for (int x=10; x <= 64; x++) {
    s.write (x);
    delay (15);
  }

  for (int y=64; y >= 10; y--) {
    s.write (y);
    delay (15);
  }
  
}
