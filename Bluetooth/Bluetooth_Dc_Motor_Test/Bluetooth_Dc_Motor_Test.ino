char t;
int enA = 10;
int in1 = 9;
int in2 = 8;
 
void setup() {
pinMode (enA, OUTPUT);
pinMode (in1, OUTPUT);
pinMode (in2, OUTPUT);
Serial.begin(9600);
}
 
void loop() {
  
if(Serial.available()){
  t = Serial.read();
}
 
switch (t) {
    case '0':
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      analogWrite (enA, 0);
      break;

    case '1':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 50);
      break;

    case '2':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 75);
      break;

    case '3':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 100);
      break;

    case '4':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 125);
      break;

    case '5':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 150);
      break;

    case '6':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 175);
      break;

    case '7':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 200);
      break;

    case '8':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 225);
      break;

    case '9':
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      analogWrite (enA, 255);
      break;
  }

delay(10);
}
