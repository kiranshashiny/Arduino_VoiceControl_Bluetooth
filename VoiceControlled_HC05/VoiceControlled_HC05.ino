/* Code for Voice Controlled module communicating to the Arduino.
 *  Here, I have a Bluetooth HC05 connected to Arduino, and 
 *  using the Smart phone which identified the Bluetooth module, was 
 *  able to issue verbal commands like "lights on" and "lights off" and
 *  was able to see LED connected to the Arduino to turn ON and OFF.
 *  
 *  The LED was connected to Pin 13 of the Arduino.
 *  The smartphone has to first connect to the HC05 module for this 
 *  experiment to work.
 *  Downloaded the "BT Voice Control for Arduino" app on the Smartphone.
 *  This Arduino code is programmed to understand commands like 
 *  "lights on", "lights off".
 *  On recognizing these commands - the Arduino sends appropriate 
 *  commands to Pin 13.
 * 
 * As an enhancement, 
 * This can be used in conjunction with a relay and control a 240 V light(s).
 * 
 */

String voice;
int relay = 13;

void setup() {
  // put your setup code here, to run once:
   Serial.begin ( 9600);
   pinMode ( relay, OUTPUT );
   
}

void loop() {
  
  while (Serial.available() ){
       delay (10);
       char c  = Serial.read();
       if ( c== '#' ) {break;}
       voice += c;
  }
  
  if ( voice.length () > 0) {
    Serial.println (voice );
    if ( voice == "*lights on" ) {
      Serial.println ("Turning on lights ");
      digitalWrite ( 13, HIGH );
    }
    else if ( voice == "*lights off") {
      Serial.println ("Turning off lights ");
      digitalWrite (13, LOW );
    }
    voice = "";
  }
}
