#include "DigiKeyboard.h"
void setup() {
  
}

void loop() {
  DigiKeyboard.print("S7@k$)0&");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){/*empty*/}
}
