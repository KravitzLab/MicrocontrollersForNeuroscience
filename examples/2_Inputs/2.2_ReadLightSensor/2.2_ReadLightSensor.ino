/*
  Example 2.2: Read from the light sensor

  This code demonstrates the use of the built-in light sensor on the PyGamer.
  It reads from the analog sensor and displays the relative light level on the
  serial monitor.

  created Jun 2022
  by Cammi Rood

*/

int lightSensor = A7                            // The lightsensor is on pin A7
int delayVal = 100;                         // Set our sampling period to 100ms

void setup() {
  Serial.begin(9600);                             // This will allow us to write data to the computer using the Serial port
}

void loop() {
  int light = analogRead(lightSensor);            // analogRead from the light sensor, and save the value as "light"
  Serial.print ("Light:");                        // Print to the serial port (open the Serial Monitor in the Arduino IDE to view this readout)
  Serial.println (light);                         // Print to the serial port
  delay (delayVal);                         // Delay until next sample
}

/*

  Activities:
  1. Open the Serial Monitor and watch the data. Now close this and open the Serial Plotter. Cool, huh?
  2. Change the delay to 1s, note the difference in sampling rate on the Serial Plotter
  3. What is the highest light value the sensor can detect? (try using your cell phone flashlight)
  4. What is the lowest light value the sensor can detect? (cover it with your finger)

*/
