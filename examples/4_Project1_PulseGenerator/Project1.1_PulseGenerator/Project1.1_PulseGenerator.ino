/*
   Day 1 Project - build a simple pulse generator for controlling optogenetic stimulation!
   Blinks D13 at set frequency
   The goal here is to change the value assigned to "freq" with the buttons or joystick

   Lex Kravitz
   alexxai@wustl.edu
   June 2022
*/

int freq = 5;                                                   // This is our pulsing frequency, start at 5Hz

void setup() {
  pinMode(13, OUTPUT);                                          // Set pin 13 (the LED) to be an output
}

void loop() {
  Serial.println(freq);                                         //Send pulsing frequency to the Serial Monitor (good for debugging)

  //Pulse pin D13 at the set frequency
  digitalWrite (13, HIGH);                                      // Light up LED on D13
  delay(1000 / freq / 2);                                       // Delay for light ON period
  digitalWrite (13, LOW);                                       // Turn off LED on D13
  delay(1000 / freq / 2);                                       // Delay for light OFF period

  ///////////////////////////////////////////////////////
  //Write your code below here to update the value of "freq"
  ///////////////////////////////////////////////////////






}
