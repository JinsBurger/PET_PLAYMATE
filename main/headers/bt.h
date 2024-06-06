#ifndef BT_H
#define BT_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "./move.h"
#include "./rotation.h"

class BT {
  public:
    BT(int tx, int rx);
    void drive(Move *move, int distance_front, int distance_back);
    void rotate(Rotation *rotation);

  private:
    SoftwareSerial btSerial;
    int PIN_TX, PIN_RX;
    char dir, rot;
};

#endif
