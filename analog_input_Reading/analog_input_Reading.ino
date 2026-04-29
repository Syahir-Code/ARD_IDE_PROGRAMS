void setup() {
  Serial.begin (9600);

}

void loop() {
  int x = analogRead (A0);
 // int y = analogRead (A2);

  Serial.println (x);
  //Serial.print ("    ");
  //Serial.println (y);
  //delay (1000);
}
