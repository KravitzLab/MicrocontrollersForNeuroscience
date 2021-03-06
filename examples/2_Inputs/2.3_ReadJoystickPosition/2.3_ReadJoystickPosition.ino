/*
  Example 2.3 Read the Joystick X and Y positions
  
  This code demostrates reading values from the PyGamer's built-in 
  joystick. The X and Y-values are read individually from two  
  separate analog pins, A10 and A11. 
  
  created Jun 2022
  by Cammi Rood
*/

int JoyStickX = A11;                                 // Read the X position on Analog pin 11
int JoyStickY = A10;                                 // Read the Y position is on Analog pin 10
int delayVal = 100;                             // Set a sampling period

void setup() {
  Serial.begin(9600);                                 //Start Serial connection to computer
  pinMode(JoyStickX, INPUT);                          //Set JoyStickX as an input
  pinMode(JoyStickY, INPUT);                          //Set JoyStickY as an input
}

void loop() {
  int JoyStickXpos = analogRead(JoyStickX);           //Read the JoyStick X position and store it in "JoyStickXpos"
  int JoyStickYpos = analogRead(JoyStickY);           //Read the JoyStick Y position and store it in "JoyStickYpos"
  Serial.print("X: ");                                 //Print Joystick X position to the serial monitor
  Serial.print(JoyStickXpos);
  Serial.print(", ");                                  //Print a "," to the serial monitor
  Serial.print("Y: ");                                 //Print Joystick Y position to the serial monitor
  Serial.println(JoyStickYpos);
  delay(delayVal);                              //Wait for next sample
}

/*

Activities:
1. Open the Serial Monitor. When you are not touching the joystick, what are the X and Y-values?
2. What are the min and maximum range of the X and Y position?
3. Open the Serial Plotter to see plots of the X and Y positions. Cool, huh?  Could you use this type of input for an experiment?

*/
