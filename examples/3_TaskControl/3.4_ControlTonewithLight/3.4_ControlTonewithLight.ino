/**************************************************************************
  Light Sensor and Tone on Adafruit PyGamer
  June 2022
  Lex Kravitz & Cammi Rood
 **************************************************************************/
 
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
