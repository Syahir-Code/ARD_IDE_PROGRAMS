//1 push button as toggle switch (on / off led)

const int button = 5;
const int led = 6;

int buttonOld = LOW;
int buttonNew;
int ledState = LOW;

void setup() {
  pinMode (button, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  buttonNew = digitalRead (button);

  if (buttonNew == HIGH and buttonOld == LOW) 
  {
    if (ledState == LOW) {
      ledState = HIGH;
    }

    else {
      ledState = LOW;
    } 
  }

  digitalWrite (led, ledState);
  buttonOld = buttonNew;
  delay (50);

}
