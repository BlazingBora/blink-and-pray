/*
crappy joystick controlled fan, im too dumb to understand why it twitches. maybe adding a bigger deadzone
servo might be under too much weight cuz i deadass just ziptied he dc on it

probably also gonna add second servo for 2 DOF and a mount
*/
#include <Servo.h>

Servo fanServo;

const int servoPin = 9;
const int motorPin = 10;

const int xJoystick = A0;
const int yJoystick = A1;

void setup() {
  fanServo.attach(servoPin);
  pinMode(motorPin, OUTPUT);
}

void loop() {

  int xValue = analogRead(xJoystick);

  int angle = map(xValue, 0, 1023, 0, 180);

  fanServo.write(angle);


  int yValue = analogRead(yJoystick);

  int speed;

  if (yValue < 512) {
    speed = map(yValue, 512, 0, 0, 255);
  }
  else {
    speed = map(yValue, 512, 1023, 0, 255);
  }

  speed = constrain(speed, 0, 255);

  analogWrite(motorPin, speed);

  delay(10);
}