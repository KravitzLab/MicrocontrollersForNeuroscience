/*
  Example 2.1 Button Press

  This code uses externally wired buttons to demonstrate how we can detect button presses.
  We will use these buttons: https://www.adafruit.com/product/4431
  Start by plugging two buttons into the ports on the bottom of the PyGamer using 3 pin STEMMA wires.

  We will also learn a new concept in this example, which is using the Serial monitor
  to provide feedback from the microcontroller to the user (you!) via your computer screen.

  created Jun 2022
  by Kevin Chávez López
*/

int Button = 3;                                      // let's call digital pin 3 "Button"

void setup() {
  Serial.begin(9600);                                // Start the serial connection to allow communication with the computer using the Serial port
  pinMode(Button, INPUT);                            // Set Button as an input
}

void loop() {
  if (digitalRead(Button) == LOW) {                  // If Button has been pressed...
    Serial.println("Button Pressed");                // Print "Button Pressed"
    delay(200);                                      // A short delay helps prevent multiple triggers
  }
}

/*

  Activities:
  1. What do you see on the Serial Monitor if you hold down the button?  Why does this happen?  
  2. Change the code to report to the Serial monitor when the button is released instead of pressed
  3. Now report both press and release events to the Serial monitor
  4. (Advanced) Can you make it print "Button Pressed" only one time per button press, even if you hold the button down?

*/
