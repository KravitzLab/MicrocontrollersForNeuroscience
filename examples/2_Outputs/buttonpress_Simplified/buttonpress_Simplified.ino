int button1 = 2;
int button2 = 3;
int delayVal = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Starts the Serial monitor. The Serial monitor allows us to read text from the input we are giving to the Arduino board.
 
  //  input = receiving information from selected device
  //  output = sending information to selected device
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(button1) == LOW) {
    digitalWrite(button1, HIGH);
    Serial.println("Blue has been pressed!");
    delay(delayVal);
   }
   
if (digitalRead(button2) == LOW) {                     
    digitalWrite(button2, HIGH);
    Serial.println("Yellow has been pressed!");
    delay(delayVal);   
   }
   
}
