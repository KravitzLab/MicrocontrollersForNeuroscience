/*
  Example 2.5 Read Joystick position
  
  This code demostrates reading values from the PyGamer's built-in 
  joystick. The X and Y-values are read individually from two  
  separate analog pins. The resulting values are displayed via the 
  serial monitor.
  
  created Jun 2022
  by Cammi Rood
*/

int JoyStickY = A10;                                  // Read the Y position is on Analog pin 10
int JoyStickX = A11;                                  // Read the X position on Analog pin 11
int delayVal = 200;                                   // Set a sampling period

void setup() {
  Serial.begin(9600);                                 //Start Serial connection to computer
  pinMode(JoyStickY, INPUT);                          //Set JoyStickY as an input
  pinMode(JoyStickX, INPUT);                          //Set JoyStickX as an input
}

void loop() {
  int JoyStickYpos = analogRead(JoyStickY);           //Read the JoyStick Y position and store it in "JoyStickYpos"
  int JoyStickXpos = analogRead(JoyStickX);           //Read the JoyStick X position and store it in "JoyStickXpos"
  Serial.print("JoyStick X = ");                      //Print Joystick X position to serial monitor
  Serial.print(JoyStickXpos);
  Serial.print("   JoyStick Y = ");                   //Print Joystick Y position to serial monitor
  Serial.println(JoyStickYpos);
  Serial.println();                                   //Puts a line between each reading
  delay(delayVal);                                    //Wait for next sample
}
