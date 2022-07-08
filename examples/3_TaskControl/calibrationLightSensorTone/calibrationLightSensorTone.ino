int sensorPin = A7;
int speaker = A0;
int amp = 51;
int delayVal = 100;
int sensorVal = 0;
//int duration = 20;


void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(speaker, OUTPUT);
  pinMode(amp, OUTPUT);
  digitalWrite(amp, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  int pitch = map(sensorVal, 0, 1023, 0, 200);
  tone(speaker, pitch);
  delay(1);
}
