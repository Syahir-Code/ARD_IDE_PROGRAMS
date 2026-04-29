#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke (KEY_R, MOD_GUI_LEFT);
  delay (500);
  DigiKeyboard.print ("cmd");
  DigiKeyboard.sendKeyStroke (KEY_ENTER);
  delay (2000);
  DigiKeyboard.print ("powercfg /hibernate off");
  DigiKeyboard.sendKeyStroke (KEY_ENTER);
  DigiKeyboard.print ("RUNDLL32.EXE powrprof.dll,SetSuspendState 0,1,0");
  DigiKeyboard.sendKeyStroke (KEY_ENTER);
}

void loop() {
  // put your main code here, to run repeatedly:

}
