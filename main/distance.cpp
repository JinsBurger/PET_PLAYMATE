#import <Arduino.h>

class Distance {
  public:
    /// Initialize ultrasonic related pins
    Distance(int tp, int ep) {
      TRIG_PIN = tp;
      ECHO_PIN = ep;

      pinMode(TRIG_PIN, OUTPUT);
      pinMode(ECHO_PIN, INPUT); 
    }

    /// Returns distance calculated using ultrasonic
    unsigned int get_distance() {
      digitalWrite(TRIG_PIN, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIG_PIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG_PIN, LOW);
      return pulseIn(ECHO_PIN, HIGH) * 17 / 1000;
    }

  private:
    int TRIG_PIN;
    int ECHO_PIN;
};