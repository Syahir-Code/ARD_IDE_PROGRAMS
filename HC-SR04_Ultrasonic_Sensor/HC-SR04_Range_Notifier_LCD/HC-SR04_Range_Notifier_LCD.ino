#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int cm;

void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration * 0.034 / 2 + 1;

  
  if (cm <= 20) {
   lcd.setCursor(0, 0); 
   lcd.print("     ");
   
   lcd.setCursor(5, 0); 
   lcd.print("MAMPOS");
   
   lcd.setCursor(11, 0); 
   lcd.print("     ");
   
   lcd.setCursor(0, 1);
   lcd.print("      ");
   
   lcd.setCursor(5,1);
   lcd.print("BODO!!!");
   
   lcd.setCursor(12,1);
   lcd.print("    ");
   }
   
  else if (cm >= 21 and cm <= 50) {
   lcd.setCursor(0, 0);
   lcd.print("   ");
   
   lcd.setCursor(3, 0); 
   lcd.print("BOLEH LAH");

   lcd.setCursor(12, 0);
   lcd.print("    ");

   lcd.setCursor(0,1);
   lcd.print(" ");
   
   lcd.setCursor(1,1);
   lcd.print("BUT BE CAREPUL");

   lcd.setCursor(15,1);
   lcd.print(" "); }
   
  else if (cm >= 51) {
   lcd.setCursor(0, 0); 
   lcd.print("    ");
   
   lcd.setCursor(4, 0); 
   lcd.print("RILEK AH");

   lcd.setCursor(12, 0); 
   lcd.print("    ");

   lcd.setCursor(0, 1); 
   lcd.print("    ");
   
   lcd.setCursor(4,1);
   lcd.print("JAUH AGI");

   lcd.setCursor(12, 1); 
   lcd.print("    ");
   }
   
  delay(10);
}
