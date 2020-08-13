/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo servoPitch;  // create servo object to control a servo
Servo servoYaw;  // create servo object to control a servo

void setup() {
  servoPitch.attach(2);  // attaches the servo on pin 9 to the servo object
  servoYaw.attach(3);  // attaches the servo on pin 9 to the servo object

  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    char servo = Serial.read();
    String valStr = Serial.readString();
    int val = atoi(valStr.c_str());
    if(servo == 'y'){
      servoYaw.write(val);
    }else if(servo == "p"){
      servoPitch.write(val);
    }
  }
}
