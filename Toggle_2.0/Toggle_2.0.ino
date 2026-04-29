//2 push button as toggle switch (on / off led)

const int button1 = 4;
const int button2 = 5;
const int led = 6;

int button1Old = LOW;
int button1New;
int button2Old = LOW;
int button2New;

void setup() {
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {

  ON ();

  OFF ();
  
}

void ON () {
  button1New = digitalRead (button1);

  if (button1New == HIGH and button1Old == LOW) 
  {
    digitalWrite (led, HIGH);
  }

  button1Old = button1New;
  delay (50);
}

void OFF () {
  button2New = digitalRead (button2);
  
  if (button2New == HIGH and button2Old == LOW) 
  {
  digitalWrite (led, LOW);
   }

  button2Old = button2New;
  delay (50);
  
}

//void Blink () {
//  digitalWrite (led, LOW);
//  delay (200);
//  digitalWrite (led, HIGH);
//  delay (200);
//}
