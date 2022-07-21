/*
  Example 2.2 Button Press
  
  This code uses externally wired buttons to demonstrate the use 
  of buttons with microcontrollers. The serial monitor produces  
  feedback via "if" statements.
  
  created Jun 2022
  by Cammi Rood
*/

int button1 = 2;                                      // button1 will be plugged into digital pin 2
int button2 = 3;                                      // button2 will be plugged into digital pin 3
int delayVal = 200;                                   // Set the sampling interval

void setup() {
  Serial.begin(9600);                                 // This will allow us to write data to the computer using the Serial port
  pinMode(button1, INPUT);                            // Set button1 as an input
  pinMode(button2, INPUT);                            // Set button2 as an input
}

void loop() {
  int button1State = digitalRead(button1);            // Read the state of button1 and store it as "button1State"
  int button2State = digitalRead(button2);            // Read the state of button2 and store it as "button2State"
  
  if (button1State == LOW) {                          // If button 1 is pressed....
    Serial.println("Button1 Pressed");                // Print "Button1 Pressed"
  } else if (button1State == HIGH) {
    Serial.println("Button1 Released");               // Print "Button1 Released"
  }
  
  if (button2State == LOW) {
    Serial.println("Button2 Pressed");                // Print "Button2 Pressed"
  } else if (button2State == HIGH) {
    Serial.println("Button2 Released");               // Print "Button2 Released"
  }
  delay(delayVal);                                    // A short delay helps slow down multiple triggers
}
