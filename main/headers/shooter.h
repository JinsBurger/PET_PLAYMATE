#ifndef SHOOTER_H
#define SHOOTER_H

#include <Arduino.h>

class Shooter {
  public:
    Shooter(int motorIn, int motorOut, int speed);
    void shoot();
    void stop();

  private:
    int PIN_MOTOR_IN, PIN_MOTOR_OUT, PIN_MOTOR_SPEED;
};

#endif