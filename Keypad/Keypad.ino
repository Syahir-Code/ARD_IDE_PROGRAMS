 /*keypad tutorial.
  Serial monitor readings.
  created by the SriTu Tech team.
  Read the code below and use it for any of your creation
*/

#include <Keypad.h>//Include library(library link in my blog)
const byte rows[4] = {2, 3, 4, 5};//connect to the row pinouts of the keypad
const byte cols[4] = {6, 7, 8, 9};//connect to the column pinouts of the keypad 

char keys[4][4] = { //create 2D arry for keys
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'},

};

Keypad mykeypad = Keypad(makeKeymap(keys), rows, cols, 4, 4);

void setup() {
  Serial.begin(9600);//enable serial monitor
}

void loop() {
  char myKey = mykeypad.getKey();//get key and put in to the veriable

  if (myKey) { //check condition
    Serial.println(myKey);//print key   
  }
}
