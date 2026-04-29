// motor A
#define enA 10
#define in1 9
#define in2 8

// motor B
#define enB 3
#define in3 4
#define in4 5

void setup() {
  // set all the motor control pins to outputs
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
}

void demoOne() {
  // this function wil run the motors in both directions at a fixed speed
  
  // turn on motor A
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  // set speed to 200 out of possible range 0-255
  analogWrite (enA, 255);

  //turn on motor B
  digitalWrite (in3, HIGH);
  digitalWrite (in4, LOW);
  //set speed to 200 out of possible range 0-255
  analogWrite (enB, 255);

  delay (2000);



  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
  analogWrite (enA, 255);

  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);
  analogWrite (enB, 255);

  delay (2000);

  //now turn off motors
  digitalWrite (in1, LOW);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
  delay (2000);
}

void demoTwo() {
  // this function wil run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible by your hardware

  //turn on motors
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  digitalWrite (in3, HIGH);
  digitalWrite (in4, LOW);
  
  // accelerate from zero to maximum speed
  for (int i=50; i<=255; i++) {
    analogWrite (enA, i);
    analogWrite (enB, i);
    delay (20);
  }

  // decelerate from maximum speed to zero 
  for (int i=255; i>=50; --i) {
    analogWrite (enA, i);
    analogWrite (enB, i);
    delay (20);
  }

  //now turn off motors
  digitalWrite (in1, LOW);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
  delay (2000);
}

void loop() {
  demoOne();
  
  demoTwo ();
  
}
