// Declare variables and pin numbers for LEDs and button
// (LED colour)T --> Traffic light LED
// (LED colour)P --> Pedestrian light LED
const int redT = 2;
const int yellowT = 3;
const int greenT = 4;
const int redP = 5;
const int greenP = 6;
const int but = 12;
int val; // button's digital input value variable
int i;   // for loop variable

// Custom function to blink redP LED and 
// to turn ON yellowT LED 
void red_b () {
  digitalWrite (redP, LOW);
  digitalWrite (yellowT, HIGH);
  delay (500);
  digitalWrite (redP, HIGH);
  digitalWrite (yellowT, HIGH);
  delay (500);    
}

// Custom function to blink greenP LED and 
// to turn ON yellowT LED 
void green_b () {
  digitalWrite (greenP, LOW);
  digitalWrite (yellowT, HIGH);
  delay (500);
  digitalWrite (greenP, HIGH);
  digitalWrite (yellowT, HIGH);
  delay (500);    
}

void setup() {
  Serial.begin (9600); // Initialize serial communication
  pinMode (but, INPUT_PULLUP); // Set button pin as input
  
  // Set all LED pins as output
  for (i=2; i<=6; i++) {
    pinMode (i, OUTPUT);
  }
  
}

void loop() {

  // Read digital input value from button
  val = digitalRead (but);
  
  //Day time traffic condition (many pedestrians)
  if (val == 0)  {
    digitalWrite (greenP, LOW);
    digitalWrite (yellowT, LOW);
    digitalWrite (greenT, HIGH);
    digitalWrite (redP, HIGH);
    delay (5000);
    
    digitalWrite (greenT, LOW);
    for (i=1; i<=3; i++) {
      red_b (); 
    }

    digitalWrite (redP, LOW);
    digitalWrite (yellowT, LOW);
    digitalWrite (redT, HIGH);
    digitalWrite (greenP, HIGH);
    delay (10000);
    
    digitalWrite (redT, LOW);
    for (i=1; i<=3; i++) {
      green_b (); 
    }
   
  } 

  //Night time traffic condition (less pedestrians)
  else if (val == 1) {
    digitalWrite (greenP, LOW);
    digitalWrite (yellowT, LOW);
    digitalWrite (greenT, HIGH);
    digitalWrite (redP, HIGH);
    delay (10000);
    
    digitalWrite (greenT, LOW);
    for (i=1; i<=3; i++) {
      red_b (); 
    }

    digitalWrite (redP, LOW);
    digitalWrite (yellowT, LOW);
    digitalWrite (redT, HIGH);
    digitalWrite (greenP, HIGH);
    delay (5000);
    
    digitalWrite (redT, LOW);
    for (i=1; i<=3; i++) {
      green_b (); 
    }
  }
}
