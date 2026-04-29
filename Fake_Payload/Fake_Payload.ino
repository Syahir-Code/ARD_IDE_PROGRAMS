#include "DigiKeyboard.h"
void setup() {
  
}

void loop() {
  //DigiKeyboard.delay(2000);
  //DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("https://geekprank.com/blue-death/");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F11);
  for(;;){/*empty*/}

}
