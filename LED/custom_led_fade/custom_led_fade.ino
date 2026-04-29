int led1 = 9;
int led2 = 10;
float brightness = 0;

void setup() {
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
}

void loop() {
  for (int i=1; i<=255; i+=2){
    analogWrite (led1, i);
    analogWrite (led2, i);
    delay (20);
  }

  for (int i=255; i>=0; i-=2){
    analogWrite (led1, i);
    analogWrite (led2, i);
    delay (20);
  }

  for (int x=1; x<=255; x+=2){
    analogWrite (led2, x);
    delay (20);
  }

  for (int x=255; x>=0; x-=2){
    analogWrite (led2, x);
    delay (20);
  }

}
