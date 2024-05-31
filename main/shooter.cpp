#import <Arduino.h>

class Shooter {
  public:
    /// Initizlize shooter related pins
    Shooter(int motorIn, int motorOut, int speed) {
      PIN_MOTOR_IN = motorIn; PIN_MOTOR_OUT = motorOut, PIN_MOTOR_SPEED = speed;
      
      pinMode(PIN_MOTOR_IN, OUTPUT); 
      pinMode(PIN_MOTOR_OUT, OUTPUT);
      pinMode(PIN_MOTOR_SPEED, OUTPUT);
    }

    /// Start shooting balls
    void shoot() {
      analogWrite(PIN_MOTOR_SPEED, 255);
      digitalWrite(PIN_MOTOR_IN, HIGH);
      digitalWrite(PIN_MOTOR_OUT, LOW);
    }

    /// Stop shooting
    void stop() {
      analogWrite(PIN_MOTOR_SPEED, 0);
      digitalWrite(PIN_MOTOR_IN, LOW);
      digitalWrite(PIN_MOTOR_OUT, LOW);
    }

  private:
    int PIN_MOTOR_IN, PIN_MOTOR_OUT, PIN_MOTOR_SPEED;
};