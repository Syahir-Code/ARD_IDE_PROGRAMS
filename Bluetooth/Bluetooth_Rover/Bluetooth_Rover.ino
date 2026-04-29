// #include <SoftwareSerial.h>
// SoftwareSerial bluetooth (8, 3); // RX, TX

char t;

int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;

void dirControl (int a, int b, int c, int d) {
  analogWrite (in1, a);
  analogWrite (in2, b);
  analogWrite (in3, c);
  analogWrite (in4, d);
}

int motorspeed (char x) {
  int y = x-'0';
  int spd = map (y, 0, 9, 100, 255);
  return spd;
}

void setup() {
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  Serial.begin(9600);
  dirControl (0,0,0,0);
}


void loop() {

  while (Serial.available()>0){
    t = Serial.read();
    int x;
    
    if (t>='0' && t<='9') {
      x = motorspeed (t);
    }
  
    else if (t == 'F') {
      dirControl (x,0,x,0);
    }
  
    else if (t == 'B') {
      dirControl (0,x,0,x);
    }
  
    else if (t == 'R') {
      dirControl (x,0,0,x);
    }
  
    else if (t == 'L') {
      dirControl (0,x,x,0);
    }
  
    else if (t == 'S') {
      dirControl (0,0,0,0);
    }
  
   
  delay(10);
  
 }
}
