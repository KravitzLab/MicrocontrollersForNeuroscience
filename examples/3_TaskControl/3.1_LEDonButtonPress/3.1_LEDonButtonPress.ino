/*
  Example 3.1 - Button Press LED
  
  This code introduces task control by using an externally wired button
  to turn on the built-in LED.
  
  created Jun 2022
  by Lex Kravitz
*/

int button = 2;                                                  // Choose a button to control the LED
int LED = 13;                                                    // LED is on pin 13

void setup() {
  pinMode(button, INPUT);                                        // Set button to be an input
  pinMode(LED, INPUT);                                           // Set LED to be an input
}

void loop() {
  if (digitalRead(button) == LOW) {                              // If button is pressed...
    digitalWrite (13, HIGH);                                     // Turn on LED
  } else {                                                       // Otherwise...
    digitalWrite (13, LOW);                                      // Turn off LED
  }
}

/*

Activities:
1) Make the other button turn on the LED
2) When you push the button, leave the LED on for 1s before turning it off
3) (Review from Module 2) When you push the button, also print "Button pushed" to the Serial monitor

/*
