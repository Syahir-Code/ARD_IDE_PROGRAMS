int in1 = 11;
int in2 = 10;
int in3 = 9;
int in4 = 6;

int x_Axis = A1;
int y_Axis = A2;
int pot = A3;

void setup() {
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
}

void loop() {
  int y;
  int x;
  int x_val = analogRead (x_Axis);
  int y_val = analogRead (y_Axis);
  int motor_speed = analogRead (pot);

  //forward
  if (y_val > 550) {
    y = map (motor_speed, 0, 1023, 100, 255);
    analogWrite (in1, 0);
    analogWrite (in2, y);
    analogWrite (in3, 0);
    analogWrite (in4, y);
  }

  //reverse
  else if (y_val < 470) {
    y = map (motor_speed, 0, 1023, 100, 255);
    analogWrite (in1, y);
    analogWrite (in2, 0);
    analogWrite (in3, y);
    analogWrite (in4, 0);
  }

  //right
  else if (x_val > 550) {
    x = map (motor_speed, 0, 1023, 100, 255);
    analogWrite (in1, 0);
    analogWrite (in2, x);
    analogWrite (in3, x);
    analogWrite (in4, 0);
  }

  //left
  else if (x_val < 470) {
    x = map (motor_speed, 0, 1023, 100, 255);
    analogWrite (in1, x);
    analogWrite (in2, 0);
    analogWrite (in3, 0);
    analogWrite (in4, x);
  }

  //stop (joystick center)
  /*else if (x_val == 501 or 502 and y_val == 516 or 517) {
    analogWrite (in1, 0);
    analogWrite (in2, 0);
    analogWrite (in3, 0);
    analogWrite (in4, 0);
  }*/

  else {
    analogWrite (in1, 0);
    analogWrite (in2, 0);
    analogWrite (in3, 0);
    analogWrite (in4, 0);
  }

  
 
}
