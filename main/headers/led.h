#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
  public:
    LED(int auto_pin, int shoot);
    void auto_mode(int val);
    void shoot_mode(int val);

  private:
    int AUTO_PIN, SHOOTER_PIN;
};

#endif
