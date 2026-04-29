const int but = 8;
const int rel = 7;

void setup() {
  pinMode (but, INPUT_PULLUP);
  pinMode (rel,  OUTPUT);
  Serial.begin (9600);
}

void loop() {
  int val = digitalRead (but);

  if (val == LOW) {
    digitalWrite (rel, LOW);
  }

  else {
    digitalWrite (rel, HIGH);
  }
  
  Serial.println (val);
}
