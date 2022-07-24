/*
  Example 1.2: Playing a tone
  
  In Example 1.1 we "blinked" the LED, meaning we pulled the voltage on the LED pin high 
  and low in an alternating pattern. If we do this on a pin that is connected to a speaker
  this will create a tone, although we'll need to "blink" the speaker much faster to hear the tone.

  The PyGamer's speaker is attached to pin A0. In this example we will start by alternating the voltage
  on pin A0 to create a 500Hz tone.
  
  We will also introduce the concept of naming variables in this example. "A0" is the pin name, but 
  things might get confusing if we're also using A1, A2, and A3 for other things. You can type #define 
  to assign a more useful name to A0 (see line 20 below).  #define is a compiler directive that 
  substitutes a name (in this case "speaker") for a value (in this case "A0") 
  
  created Jun 2022
  by Lex Kravitz
*/

#define speaker A0             //Let's give pin A0 a more useful name!  

// put your setup code here, to run once:
void setup() {
  pinMode(speaker, OUTPUT);    //Set "speaker" to be an output
  pinMode (51, OUTPUT);        //The PyGamer also has an audio amplifier on pin 51 that we need to activate to use the speaker
  digitalWrite (51, HIGH);     //Turn on the audio amplifier
}

// put your main code here, to run repeatedly:
void loop() {
  digitalWrite(speaker, HIGH); //Pull speaker pin high
  delay (1);                   //delay 1ms (1ms HIGH/LOW will createa  500Hz tone)
  digitalWrite(speaker, LOW);  //Pull speaker pin low
  delay (1);                   //Delay 1ms
}

/*

Activities:
1. Can you make a 1000Hz tone?
2. Does anything change if you pull the speaker LOW in line 26 and then HIGH in line 28?  Make your prediction before trying this.
2. Changing the delay changes the tone frequency, how might you change the volume of the tone?  
   (Hint: Arduino also has an analogWrite function - Google it!)

*/
