/*
   Day 1 Project - build a simple pulse generator for controlling optogenetic stimulation!
   Blink a pin at a set frequency whenever button 2 is pressed

   created Jun 2022
   by Lex Kravitz and Kevin Chavez
*/

int freq = 5;                                                   // This is our pulsing frequency, start at 5Hz
#define LED 13                                                  // Assign the name "LED" to pin 13

void setup() {
  pinMode(LED, OUTPUT);                                         // Set pin 13 (the LED) to be an output
  ///////////////////////////////////////////////////////
  //Task 1: Set up the button on pin 2 as an input
  ///////////////////////////////////////////////////////


}

void loop() {

  ///////////////////////////////////////////////////////
  //Task 2: Use a "while loop" to only pulse when a button on pin 2 is pressed
  ///////////////////////////////////////////////////////

  //Pulse pin D13 at the set frequency
  digitalWrite (LED, HIGH);                                     // Light up LED on D13
  delay(1000 / freq / 2);                                       // Delay for light ON period
  digitalWrite (LED, LOW);                                      // Turn off LED on D13
  delay(1000 / freq / 2);                                       // Delay for light OFF period

  ///////////////////////////////////////////////////////
  //Task 3: Bring in your code in from Project1.3 to update the frequency with the joystick
  ///////////////////////////////////////////////////////

}
