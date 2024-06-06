#ifndef SHOOTER_H
#define SHOOTER_H

#include <Arduino.h>
#include "./sr.h"

class Shooter {
  public:
    Shooter(int motorIn, int motorOut, int speed, SR *sr_impl);
    void shoot();
    void stop();

  private:
    int PIN_MOTOR_IN, PIN_MOTOR_OUT, PIN_MOTOR_SPEED;
    SR *sr;
};

#endif