unsigned long myTime;

int but = 11;

void setup() {
  Serial.begin(9600);
  pinMode (but,INPUT_PULLUP);
  /*char Data [] [6] = {"00001", "00002"};
  Serial.print (Data [1]);
  
  int x = 29;
  String y;
  y = map (x, 0, 50, 0, 100);
  Serial.print (y);
  
  char Data [] = {"43274819810"};
  Serial.print (&Data[7]);
  
  String x;
  String y;
  x = 392;
  y = 816;
  
  char Data1 [] = "";
  char Data2 [] = {};
  x.toCharArray (Data1, 4);
  y.toCharArray (Data2, 4);
  
  Serial.println (Data1 [0]);
  Serial.println (Data1 [1]);
  Serial.println (Data1 [2]);
  Serial.println ("");
  Serial.println (Data2 [0]);
  Serial.println (Data2 [1]);
  Serial.println (Data2 [2]);
  
  String x;
  x = 100;

  if  (x == "100") {
    Serial.println ("True");
  }

  else {
    Serial.println ("False");
  }

  String x = "123";
  int value = x.toInt();
  if (value == 123) {
    Serial.println ("true");
  }

  else {Serial.println("false");}*/
  
}

void loop() {
  int x = digitalRead (but);
  Serial.println (x);
  delay (200);
  /*Serial.print ("Time: ");
  myTime = millis ();

  Serial.println (myTime);
  delay (1000);*/
}
