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

int Button1 = 3;                                     // let's call digital pin 2 "button1"
int Button2 = 2;                                     // let's call digital pin 3 "button2"
int delayVal = 500;                                  // Set the sampling period for buttong presses (in ms)

void setup() {
  Serial.begin(9600);                                 // Start the serial connection to allow communication with the computer using the Serial port
  pinMode(Button1, INPUT);                            // Set button1 as an input
  pinMode(Button2, INPUT);                            // Set button2 as an input
}

void loop() {
  if (digitalRead(Button1) == LOW) {                  // If button1 has been pressed...
    Serial.println("Button1 Pressed");                // Print "Button1 Pressed"
    delay(delayVal);                                  // A short delay helps prevent multiple triggers
  }
  if (digitalRead(Button2) == LOW) {                  // If button2 has been pressed...
    Serial.println("Button2 Pressed");                // Print "Button2 Pressed"
    delay(delayVal);                                  // A short delay helps prevent multiple triggers
  }
}

/*

  Activities:
  1. What do you see on the Serial Monitor if you hold down each button?  Why does this happen?
  2. Change the code to report to the Serial monitor when the buttons are released instead of pressed
  3. Now report both press and release events to the Serial monitor

*/
