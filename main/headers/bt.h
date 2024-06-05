#ifndef BT_H
#define BT_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "./move.h"

class BT {
  public:
    BT(int tx, int rx);
    void drive(Move *move, int distance);

  private:
    SoftwareSerial btSerial;
    int PIN_TX, PIN_RX;
    char dir;
};

#endif
