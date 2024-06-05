#ifndef MOVE_H
#define MOVE_H

#include <Arduino.h>
#include "./sr.h"

class Move {
public:
  Move(int lspeed, int lin, int lout, int rin, int rout, int rspeed, SR *sr_impl);
  void forward(int distance);
  void backward();
  void left();
  void right();
  void stop();

private:
  int PIN_LIN, PIN_LOUT, PIN_LSPEED;
  int PIN_RIN, PIN_ROUT, PIN_RSPEED;
  SR *sr;
};

#endif
