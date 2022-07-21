/*
  Example 3.4: Light Sensor and Tone
  
  This code demonstrates the control of a tone by the built-in light
  sensor. The code reads the analog sensor data and plays a tone.
  
  created Jun 2022
  by Lex Kravitz and Cammi Rood
*/
 
int sensorPin = A7;
int speaker = A0;
int amp = 51;
int delayVal = 100;
int sensorVal = 0;
int volume = 1000;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(speaker, OUTPUT);
  pinMode(amp, OUTPUT);
  digitalWrite(amp, HIGH);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  analogWrite(speaker, volume);
  delay(sensorVal/100);
  analogWrite(speaker, 0);
  delay(sensorVal/100);
}
