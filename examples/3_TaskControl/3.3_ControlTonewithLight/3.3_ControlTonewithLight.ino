/*
  Example 3.4: Using the Light Sensor to change the volume of a Tone

  This code reads the analog sensor data and plays a 500Hz tone,
  varying the volume based on light level.

  created Jun 2022
  by Lex Kravitz and Cammi Rood
*/

#define speaker A0                         //Let's give pin A0 a more useful name!  
#define lightSensor A7                     // The lightsensor is on pin A7

void setup() {
  pinMode(lightSensor, INPUT);             //Set "lightSensor" to be an output
  pinMode(speaker, OUTPUT);                //Set "speaker" to be an output
  pinMode (51, OUTPUT);                    //The PyGamer also has an audio amplifier on pin 51 that we need to activate to use the speaker
  digitalWrite (51, HIGH);                 //Turn on the audio amplifier
}

void loop() {
  int light = analogRead(lightSensor);     // analogRead from the light sensor, and save the value as "light"
  analogWrite(speaker, light*2);           // control the voltage to the speaker based on the light level
  delay(1);                                // delay for 1ms 
  analogWrite(speaker, 0);                 // set the voltage on the speaker pin to 0V
  delay(1);                                // delay for 1ms
}

/*
 
Activities:
1) Modify the code to use the joystick instead of the light sensor to change the volume of the tone
2) Modify the code to change the frequency of the tone while holding the volume constant
 
 */
