void setup() {
  Serial.begin (9600);
  pinMode (8, OUTPUT);
}

void loop() {
  if (Serial.available() >0) {
    char data = Serial.read();

    switch (data) {
      case '1':
      digitalWrite (8, HIGH); break;

      case '0':
      digitalWrite (8, LOW); break;

      default : break;
    }
    Serial.println (data);
  }
  delay (50);
}
