void setup() {
  Serial.begin (9600); 
  pinMode (2, INPUT_PULLUP);
  pinMode (4, INPUT_PULLUP);
}

void loop() {
  int but1 = digitalRead (2);
  int but2 = digitalRead (4);
  Serial.print ("but1: ");
  Serial.print (but1);
  Serial.print ("   ");
  Serial.print ("but2: ");
  Serial.println (but2);
}
