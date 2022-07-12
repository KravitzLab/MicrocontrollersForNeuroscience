/**************************************************************************
  Example 3.1 - Button Press turn on LED
  June 2022
  Lex Kravitz
 **************************************************************************/

int button = 2;                                                  // Choose a button to control the LED
int LED = 13;                                                    // LED is on pin 13

void setup() {
  pinMode(button, INPUT);                                        // Set button to be an input
  pinMode(LED, INPUT);                                           // Set LED to be an input
}

void loop() {
  int buttonState = digitalRead(button);                         // Read the button state and store as "buttonState"
  if (buttonState == LOW) {                                      // If button is pressed...
    digitalWrite (13, HIGH);                                     // Turn on LED
  } else {                                                       // Otherwise...
    digitalWrite (13, LOW);                                     // Turn off LED
  }
}
