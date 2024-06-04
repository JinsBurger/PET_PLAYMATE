#ifndef ROTATION_H
#define ROTATION_H

#include <Arduino.h>

class Rotation {
  public:
    Rotation(int pwm);
    void rotate_left(int angle);
    void rotate_right(int angle);

  private:
    int PIN_PWM;
};

#endif