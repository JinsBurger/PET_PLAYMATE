#ifndef DISTANCE_H
#define DISTANCE_H

#include <Arduino.h>

class Distance {
  public:
    Distance(int tp, int ep);
    unsigned int get_distance();

  private:
    int TRIG_PIN;
    int ECHO_PIN;
};

#endif
