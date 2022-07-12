/*
  Example 2.1: Read from the light sensor
*/

int sensorPin = A7;                                   // The lightsensor is on pin A7
int delayVal = 200;                                   // Set our sampling period to 200ms

void setup() {
  Serial.begin(9600);                                 // This will allow us to write data to the computer using the Serial port
}

void loop() {
  int sensorVal = analogRead(sensorPin);              // analogRead from the light sensor, and save the value as "sensorVal"
  Serial.print ("sensorVal = ");                      // Print to the serial port (open the Serial Monitor in the Arduino IDE to view this readout)
  Serial.println (sensorVal);                         // Print to the serial port
  delay (delayVal);                                   // Delay until next sample
}
