//in1, in2, in3, in4 means motor control

int ir1 = 7;
int ir2 = 8;
int in1 = 10;
int in2 = 9;
int in3 = 6;
int in4 = 5;

void setup() {
  pinMode (ir1, INPUT);
  pinMode (ir2, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  int x = digitalRead (ir1);
  int y = digitalRead (ir2);

  

  if (x == 0 or y == 0) {
    analogWrite (in1, 0);
    analogWrite (in2, 0);
    analogWrite (in3, 0);
    analogWrite (in4, 0);
  }

  else if (x == 1 and y == 1) {
    analogWrite (in1, 150);
    analogWrite (in2, 0);
    analogWrite (in3, 150);
    analogWrite (in4, 0);
  }

  //Serial.print ("ir1_value: ");
  //Serial.print (x);
  //Serial.print ("   ");
  //Serial.print ("ir2_value: ");
  //Serial.println (y);
  //delay (500);
}
