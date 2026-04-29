int ldr = A1;

void setup() {
  Serial.begin (9600);
  pinMode (ldr, INPUT);
}

void loop() {
  int x = analogRead (ldr);
  Serial.println (x);
  delay (200);

}
