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

int MAX_PITCH = 180;
int MIN_PITCH = 100;
int MAX_YAW = 150;
int MIN_YAW = 0;

void setup() {
  servoPitch.attach(3);  // attaches the servo on pin 9 to the servo object
  servoYaw.attach(4);  // attaches the servo on pin 9 to the servo object
  servoPitch.write(140);
  servoYaw.write(80);
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    char servo = Serial.read();
    String valStr = Serial.readString();
    int val = atoi(valStr.c_str());
    if(servo == 'y'){
      val = val>MAX_YAW? MAX_YAW:val;
      val = val<MIN_YAW? MIN_YAW:val;
      servoYaw.write(val);
    }else if(servo == 'p'){
      val = val>MAX_PITCH? MAX_PITCH:val;
      val = val<MIN_PITCH? MIN_PITCH:val;
      servoPitch.write(val);
    }
  }
}
