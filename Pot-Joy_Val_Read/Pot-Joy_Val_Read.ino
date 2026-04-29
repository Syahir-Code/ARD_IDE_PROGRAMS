

void setup() {
  Serial.begin (115200);

}

void loop() {
  int joy1 = analogRead (A1);
  int joy2 = analogRead (A2);
  int joy3 = analogRead (A3);
  int joy4 = analogRead (A4);

  Serial.print ("joy1: ");
  Serial.print (joy1);
  Serial.print ("   ");
  Serial.print ("joy2: ");
  Serial.print (joy2);
  Serial.print ("   ");
  Serial.print ("joy3: ");
  Serial.print (joy3);
  Serial.print ("   ");
  Serial.print ("joy4: ");
  Serial.print (joy4);
  Serial.println ("   ");
  delay (500);

}
