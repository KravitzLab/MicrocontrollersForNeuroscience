int blue = 3; //Blue button on left, in digital pin 3
int red = 2; //Red button on left, in digital pin 3
int delayVal = 100; 
int lastButtonStateBlue = LOW; 
int lastButtonStateRed = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Initiate Serial Monitor
  pinMode(blue, INPUT);
  pinMode(red, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(delayVal);
  int blueB = digitalRead(blue); //Tells program to "read" whether or not a button is pressed
  int redB = digitalRead(red);
  if (blueB != lastButtonStateBlue){
    delay(delayVal);
    Serial.println("Blue Button State Changes");
  } 
  lastButtonStateBlue = blueButt; //Resets the button state at the end of the loop

 
  if (redB != lastButtonStateRed){
    delay(delayVal);
    Serial.println("Red Button State Changes");
  } 
  lastButtonStateRed = redB;
}
