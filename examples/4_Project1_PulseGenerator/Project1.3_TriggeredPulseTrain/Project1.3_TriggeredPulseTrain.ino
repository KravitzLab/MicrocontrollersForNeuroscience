/*
   Day 1 Project - build a simple pulse generator for controlling optogenetic stimulation!
   Blink a pin at a set frequency whenever button 2 is pressed

   Lex Kravitz and Kevin Chavez
   alexxai@wustl.edu
   June 2022
*/

int freq = 5;                                                   // This is our pulsing frequency, start at 5Hz

void setup() {
  pinMode(13, OUTPUT);                                          // Set pin 13 (the LED) to be an output
  ///////////////////////////////////////////////////////
  //Task 1: Set up  pin 2 as an input
  ///////////////////////////////////////////////////////


}

void loop() {

  ///////////////////////////////////////////////////////
  //Task 2: Use an if statement to detect when the button on pin 2 is pressed
  ///////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////
  //Task 3: Use a for loop to pulse for 2 seconds and then stop each time the button is pressed
  ///////////////////////////////////////////////////////

  //Pulse pin D13 at the set frequency
  digitalWrite (13, HIGH);                                      // Light up LED on D13
  delay(1000 / freq / 2);                                       // Delay for light ON period
  digitalWrite (13, LOW);                                       // Turn off LED on D13
  delay(1000 / freq / 2);                                       // Delay for light OFF period

  ///////////////////////////////////////////////////////
  //Task 4: Bring your code in from Project1.1 to update the frequency
  ///////////////////////////////////////////////////////

}
