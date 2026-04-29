int enA = 10;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enB = 5;

void setup() {
  pinMode (enA, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enB, OUTPUT);
}

void loop() {
  
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);

  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);

  analogWrite (enA, 100);
  analogWrite (enB, 100);

}
