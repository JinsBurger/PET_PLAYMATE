#include "./pins.h"
#include "./move.cpp"


Move *moveMotor;

void setup() {
  moveMotor =  new Move(PIN_MOTOR_L1, PIN_MOTOR_L2, PIN_MOTOR_R1, PIN_MOTOR_R2);
  

  pinMode(PIN_MOTOR_L1, OUTPUT); 
  pinMode(PIN_MOTOR_L2, OUTPUT); 
  pinMode(PIN_MOTOR_R1, OUTPUT);
  pinMode(PIN_MOTOR_R2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  moveMotor->move1();
}

