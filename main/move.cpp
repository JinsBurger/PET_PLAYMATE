#import <Arduino.h>

class Move {
  public:
    /// Initialize move related pins
    Move(int lspeed, int lin, int lout, int rin, int rout, int rspeed) { 
      PIN_LIN = lin; PIN_LOUT = lout; PIN_LSPEED = lspeed;
      PIN_RIN = rin; PIN_ROUT = rout; PIN_RSPEED = rspeed;
      
      pinMode(PIN_LSPEED, OUTPUT);
      pinMode(PIN_LIN, OUTPUT); 
      pinMode(PIN_LOUT, OUTPUT); 
      pinMode(PIN_RIN, OUTPUT);
      pinMode(PIN_ROUT, OUTPUT);
      pinMode(PIN_RSPEED, OUTPUT);
    }

    /// Drive forward
    void forward() {
      // Speed
      analogWrite(PIN_RSPEED, 180);
      analogWrite(PIN_LSPEED, 180);

      // Left wheels - front
      digitalWrite(PIN_LIN, HIGH);
      digitalWrite(PIN_LOUT, LOW);
      
      // Right wheels - front
      digitalWrite(PIN_RIN, HIGH);
      digitalWrite(PIN_ROUT, LOW);
    }

    /// Drive backward
    void backward() {
      // Speed
      analogWrite(PIN_RSPEED, 255);
      analogWrite(PIN_LSPEED, 255);

      // Left wheels - back
      digitalWrite(PIN_LIN, LOW);
      digitalWrite(PIN_LOUT, HIGH);
      
      // Right wheels - back
      digitalWrite(PIN_RIN, LOW);
      digitalWrite(PIN_ROUT, HIGH);
    }

    /// Turn left
    void left() {
      // Speed
      analogWrite(PIN_RSPEED, 255);
      analogWrite(PIN_LSPEED, 255);

      // Left wheels - back
      digitalWrite(PIN_LIN, LOW);
      digitalWrite(PIN_LOUT, HIGH);
      
      // Right wheels - front
      digitalWrite(PIN_RIN, HIGH);
      digitalWrite(PIN_ROUT, LOW);
    }

    /// Turn right
    void right() {
      // Speed
      analogWrite(PIN_RSPEED, 255);
      analogWrite(PIN_LSPEED, 255);

      // Left wheels - front
      digitalWrite(PIN_LIN, HIGH);
      digitalWrite(PIN_LOUT, LOW);
      
      // Right wheels - back
      digitalWrite(PIN_RIN, LOW);
      digitalWrite(PIN_ROUT, HIGH);
    }

    /// Stop
    void stop() {
      // Speed
      analogWrite(PIN_RSPEED, 0);
      analogWrite(PIN_LSPEED, 0);

      // Left wheels - front
      digitalWrite(PIN_LIN, LOW);
      digitalWrite(PIN_LOUT, LOW);
      
      // Right wheels - back
      digitalWrite(PIN_RIN, LOW);
      digitalWrite(PIN_ROUT, LOW);
    }

  private:
    int PIN_LIN, PIN_LOUT, PIN_LSPEED;
    int PIN_RIN, PIN_ROUT, PIN_RSPEED;
};
