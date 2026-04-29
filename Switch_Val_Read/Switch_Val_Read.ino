int but1 = 7;
int but2 = 4;

void setup() {
  Serial.begin (9600);
  pinMode (but1, INPUT_PULLUP);
  pinMode (but2, INPUT_PULLUP);
}

void loop() {
  
  int but1_val = digitalRead (but1);
  int but2_val = digitalRead (but2);

  Serial.print ("but1: ");
  Serial.print (but1_val);
  Serial.print ("    ");
  Serial.print ("but2: ");
  Serial.println (but2_val);
}
