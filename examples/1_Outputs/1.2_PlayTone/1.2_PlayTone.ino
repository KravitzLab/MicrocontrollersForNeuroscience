/**************************************************************************
  Playing a tone on Adafruit PyGamer
  June 2022
  Lex Kravitz
 **************************************************************************/

int jack = A0;                 //Let's give pin A0 a more useful name!

// put your setup code here, to run once:
void setup() {
  pinMode(jack, OUTPUT);       //Set "jack" to be an output
  pinMode (51, OUTPUT)         //The PyGamer also has an audio amplifier on pin 51 that we need to activate to use the speaker
  digitalWrite (51, HIGH);     //Turn on the audio amplifier
}

// put your main code here, to run repeatedly:
void loop() {
  digitalWrite(jack, HIGH);    //Pull speaker pin high
  delay (1);                   //delay 1ms (1ms HIGH/LOW will createa  500Hz tone)
  digitalWrite(jack, LOW);     //Pull speaker pin low
  delay (1);                   //Delay 1ms
}
