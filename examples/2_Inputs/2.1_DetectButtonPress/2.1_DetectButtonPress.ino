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

#define button1 2                                     // let's call digital pin 2 "button1"
#define button2 3                                     // let's call digital pin 3 "button2"
int delayVal = 200;                                   // Set the delay between button sampling

void setup() {
  Serial.begin(9600);                                 // Start the serial connection to allow communication with the computer using the Serial port
  pinMode(button1, INPUT);                            // Set button1 as an input
  pinMode(button2, INPUT);                            // Set button2 as an input
}

void loop() {
  int button1State = digitalRead(button1);            // Read the state of button1 and store it as "button1State"
  int button2State = digitalRead(button2);            // Read the state of button2 and store it as "button2State"
  if (button1State == LOW) {                          // If button1 has been pressed...
    Serial.println("Button1 Pressed");                // Print "Button1 Pressed"
    delay(delayVal);                                  // A short delay helps prevent multiple triggers
  }
  if (button2State == LOW) {                          // If button2 has been pressed...
    Serial.println("Button2 Pressed");                // Print "Button2 Pressed"
    delay(delayVal);                                  // A short delay helps prevent multiple triggers
  }
}

/*

Activities:
1. Change the code to report when the buttons are released (and not pressed) to the Serial monitor
2. Now report both press and release to the Serial monitor
3. Instead of writing to the Serial monitor, light up the red LED on pin 13 when button1 is pressed 

*/
