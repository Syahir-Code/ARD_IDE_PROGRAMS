int but = 0;
int led = LED_BUILTIN;

void setup() {
  Serial.begin (9600);
  pinMode (but, INPUT_PULLUP);
  pinMode (led, OUTPUT);
}

void loop() {

  int but_val = digitalRead (but);
 // Serial.println (but_val);
  
  if (but_val == 0) {
    digitalWrite (led, HIGH);
  }

  else {
    digitalWrite (led, LOW);
  }

}
