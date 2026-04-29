
const int one = 300; //variable for 1 time unit delay (300 ms) for dot
const int thr = 900; //variable for 3 time unit delay (900 ms) for dash

void setup() {
  //this section of code runs once
  //set each led's digital pin as output
  pinMode (12, OUTPUT); //1st led
  pinMode (11, OUTPUT); //2nd led
  pinMode (10, OUTPUT); //3rd led
  pinMode (9, OUTPUT);  //4th led
  pinMode (8, OUTPUT);  //5th led
}

void loop() {
  //this section of code runs in a loop
  //gap between each led and number is 3 time unit
  
  //morse code for digit 1  
  //blink the 1st led as dot
  digitalWrite (12, HIGH);
  delay (one);
  digitalWrite (12, LOW);
  delay (thr);

  //blink the 2nd until 5th led as dash 
  for (int x=11; x>=8; x--) {
    digitalWrite (x, HIGH);
    delay (thr);
    digitalWrite (x, LOW);
    delay (thr);
  }

  //3 time unit gap before next digit
  delay (thr);

  //morse code for digit 7
  //blink the 1st and 2nd led as dash
  for (int y=12; y>=11; y--) {
    digitalWrite (y, HIGH);
    delay (thr);
    digitalWrite (y, LOW);
    delay (thr);
  }

  //blink the 3rd until 5th led as dot
  for (int z=10; z>=8; z--) {
    digitalWrite (z, HIGH);
    delay (one);
    digitalWrite (z, LOW);
    delay (thr);
  }
  
  //3 time unit gap before next digit
  delay (thr);
}
