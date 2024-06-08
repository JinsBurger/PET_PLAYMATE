#include "./headers/shooter.h"

/// Initialize shooter
Shooter::Shooter(int motorIn, int motorOut, int speed) {
  PIN_MOTOR_IN = motorIn; 
  PIN_MOTOR_OUT = motorOut;
  PIN_MOTOR_SPEED = speed;
  
  pinMode(PIN_MOTOR_SPEED, OUTPUT);
}

/// Start shooting balls
void Shooter::shoot() {
  analogWrite(PIN_MOTOR_SPEED, 255);
  digitalWrite(PIN_MOTOR_IN, HIGH);
  digitalWrite(PIN_MOTOR_OUT, LOW);
}

/// Stop shooting 
void Shooter::stop() {
  analogWrite(PIN_MOTOR_SPEED, 0);
  digitalWrite(PIN_MOTOR_IN, LOW);
  digitalWrite(PIN_MOTOR_OUT, LOW);
}