#import <Arduino.h>

class Shooter {
  public:
    /// Initizlize shooter related pins
    Shooter(int motorIn, int motorOut) {
      PIN_MOTOR_IN = motorIn; PIN_MOTOR_OUT = motorOut;
      
      pinMode(PIN_MOTOR_IN, OUTPUT); 
      pinMode(PIN_MOTOR_OUT, OUTPUT);
    }

    /// Start shooting balls
    void shoot() {
      digitalWrite(PIN_MOTOR_IN, HIGH);
      digitalWrite(PIN_MOTOR_OUT, LOW);
    }

    /// Stop shooting
    void stop() {
      digitalWrite(PIN_MOTOR_IN, LOW);
      digitalWrite(PIN_MOTOR_OUT, LOW);
    }

  private:
    int PIN_MOTOR_IN, PIN_MOTOR_OUT;
};