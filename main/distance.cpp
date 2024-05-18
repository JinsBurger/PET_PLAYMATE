#import <Arduino.h>

class Distance {
  public:
    Distance(int tp, int ep) {
      trig_pin = tp;
      echo_pin = ep;
      pinMode(trig_pin, OUTPUT);
      pinMode(echo_pin, INPUT); 
    }

    unsigned int get_distance() {
      digitalWrite(trig_pin, LOW);
      delayMicroseconds(2);
      digitalWrite(trig_pin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig_pin, LOW);
      return pulseIn(echo_pin, HIGH) * 17 / 1000;  ;
    }

  private:
    int trig_pin;
    int echo_pin;
};