// Define the GPIO pins
________________________
________________________

bool ledState = LOW; // Variable to hold the LED state
int buttonState = 0; // variable for storing the push-button status

void setup() {
  _________________ // initialize the LED pin as an output
  _________________ // initialize the push-button pin as an input
}

void loop() {
  _________________ // read the state of the push-button
  // If the button is pressed (the button state is HIGH)
  if (buttonState == ____) {
    delay(100); // wait 0.1s
    _________________ // read the state of the push-button
    // Check if the button is released (the button state is LOW)
    if (buttonState == ____) {
      // If LOW, toggle the state of the LED
      if (ledState == LOW)
        ___________________ // set ledState to HIGH
      else
       ___________________ // set ledState to LOW
      // Write ledState to the LED
      digitalWrite(________, _________);
    }
  } else {
_________________ // wait 0.1s
  }
}
