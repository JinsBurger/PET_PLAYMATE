#ifndef ROTATION_H
#define ROTATION_H

#include <Arduino.h>
#include <Servo.h>
#include "./constants.h"

class Rotation {
  public:
    Rotation(int pwm);
    void rotate(int step);

  private:
    Servo servo;
};

#endif