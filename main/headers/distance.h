#ifndef DISTANCE_H
#define DISTANCE_H

#include <Arduino.h>
#include "./sr.h"

class Distance {
  public:
    Distance(int tp, int ep, SR *sr_impl);
    unsigned int get_distance();

  private:
    int TRIG_PIN, ECHO_PIN;
    SR *sr;

};

#endif
