/*
  Example 2.5 Button Press
  
  This code uses externally wired buttons to demonstrate the use 
  of buttons with microcontrollers. The serial monitor produces  
  feedback via "if" statements.
  
  created Jun 2022
  by Cammi Rood and Kevin Chávez López
*/

int blueButton = 2;                                 // Blue button will be plugged into digital pin 2
int redButton = 3;                                  // Red button will be plugged into digital pin 3

int delayVal = 100;                                 // Set the sampling interval
int lastBlueState = LOW;                            // Store the last state of the blue button
int lastRedState = LOW;                             // Store the last state of the red button

void setup() {
  Serial.begin(9600);                               // This will allow us to write data to the computer using the Serial port
  pinMode(blue, INPUT);                             // Set blue to be an input
  pinMode(red, INPUT);                              // Set red to be an input
}

void loop() {
  int blue = digitalRead(blueButton);               // Read the state of the blue button and store it as "blue"
  if (blue != lastBlueState) {                      // If "blue" is NOT the same as "lastBlueState"
    Serial.println("Blue Button State Changed");    // Print "Blue Button State Changed"
  }
  lastBlueState = blue;                             // Store the last state of blue

  int red = digitalRead(redButton);                 // Read the state of the red button and store it as "red"
  if (red != lastRedState) {                        // If "red" is NOT the same as "lastRedState"
    Serial.println("Red Button State Changed");     // Print "Red Button State Changed"
  }
  lastRedState = red;                               // Store the last state of red

  delay(delayVal);                                  // A short delay helps slow down multiple triggers
}
