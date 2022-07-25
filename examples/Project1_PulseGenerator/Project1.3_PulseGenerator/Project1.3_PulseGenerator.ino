/*
   Day 1 Project - build a simple pulse generator for controlling optogenetic stimulation!
   
   created Jun 2022
   by Lex Kravitz and Kevin Chavez
*/

int freq = 5;                                                   // This is our pulsing frequency, start at 5Hz

void setup() {
  pinMode(13, OUTPUT);                                          // Set pin 13 (the LED) to be an output
}

void loop() {
  //Pulse pin D13 at the set frequency
  digitalWrite (13, HIGH);                                      // Light up LED on D13
  delay(1000 / freq / 2);                                       // Delay for light ON period
  digitalWrite (13, LOW);                                       // Turn off LED on D13
  delay(1000 / freq / 2);                                       // Delay for light OFF period

  ///////////////////////////////////////////////////////
  //Task 1: Write your code below here to update the value of "freq" using the joystick.  If it's updating too fast, how can you slow it down? 
  ///////////////////////////////////////////////////////
  Serial.println(freq);                                         //Send pulsing frequency to the Serial Monitor (good for debugging)



  
  ///////////////////////////////////////////////////////
  //Task 2: When the pulse goes below 0, the program will crash - how can you stop this from happening?
  ///////////////////////////////////////////////////////




}
