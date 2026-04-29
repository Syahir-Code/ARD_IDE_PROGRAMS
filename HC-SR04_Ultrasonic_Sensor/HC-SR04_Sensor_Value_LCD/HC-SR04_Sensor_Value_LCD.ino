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
  
  // distance (cm) display
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.setCursor(10, 0); 
  lcd.print(cm); // Prints the distance value from the sensor
  if (cm <= 9) {
   lcd.setCursor(11, 0); 
   lcd.print("   "); }
  if (cm >= 10 and cm <= 99) {
   lcd.setCursor(12, 0); 
   lcd.print("  "); }
  if (cm >= 100) {
   lcd.setCursor(13, 0); 
   lcd.print(" "); }
  lcd.setCursor(14, 0);
  lcd.print("cm");
  delay(10);
}
