/*
  Example 1.1: Re-mix of the famous Blink sketch
  
  The PyGamer has an on-board LED you can control. This red LED is connected to pin 13, 
  but you may use LED_BUILTIN. LED_BUILTIN is set to the correct LED pin independent 
  of which board is used.

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  modified 11 Jul 2022
  by Lex Kravitz

  This example code is in the public domain.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// put your setup code here, to run once:
void setup() {
  pinMode(13, OUTPUT);               //Set pin 13 as an output (this pin is connected to the red LED on the PyGamer
}

// put your main code here, to run repeatedly:
void loop() {
  digitalWrite(13, HIGH);            // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // You can change how many ms the LED is on
  digitalWrite(13, LOW);             // turn the LED off by making the voltage LOW
  delay(1000);                       // You can change how many ms the LED is off
}
