int sensorPin = A7; //Analog pins allow us to use intermediate voltage values.
int delayVal = 200;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print ("sensorVal = ");
  Serial.println (sensorVal);
  delay (delayVal);
}
