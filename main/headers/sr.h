#ifndef SR_H
#define SR_H

#include <Arduino.h>

class SR {
  public:
    SR(int data, int latch, int reg);
    void digital_write(int pin, int val);

  private:
    int DATA, LATCH, REG;
    int PINSTATES[8];
    int CURVAL;
};

#endif