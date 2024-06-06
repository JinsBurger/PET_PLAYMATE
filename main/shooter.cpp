#include "./headers/shooter.h"

/// Initialize shooter
Shooter::Shooter(int motorIn, int motorOut, int speed, SR *sr_impl) {
  PIN_MOTOR_IN = motorIn; 
  PIN_MOTOR_OUT = motorOut;
  PIN_MOTOR_SPEED = speed;
  
  sr = sr_impl;
  
  pinMode(PIN_MOTOR_SPEED, OUTPUT);
}

/// Start shooting balls
void Shooter::shoot() {
  analogWrite(PIN_MOTOR_SPEED, 255);
  sr -> digital_write(PIN_MOTOR_IN, HIGH);
  sr -> digital_write(PIN_MOTOR_OUT, LOW);
}

/// Stop shooting 
void Shooter::stop() {
  analogWrite(PIN_MOTOR_SPEED, 0);
  sr -> digital_write(PIN_MOTOR_IN, LOW);
  sr -> digital_write(PIN_MOTOR_OUT, LOW);
}