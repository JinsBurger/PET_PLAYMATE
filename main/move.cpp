#import <Arduino.h>

class Move {
  public:
    Move(int l1, int l2, int r1, int r2) { 
      PIN_L1 = l1; PIN_L2 = l2;
      PIN_R1 = r1; PIN_R2 = r2;
      
      pinMode(PIN_L1, OUTPUT); 
      pinMode(PIN_L2, OUTPUT); 
      pinMode(PIN_R1, OUTPUT);
      pinMode(PIN_R2, OUTPUT);
      pinMode(11, OUTPUT);
      pinMode(6, OUTPUT);
    }

    void move1() {
      analogWrite(11, 255);
      digitalWrite(PIN_L1, LOW);
      digitalWrite(PIN_L2, HIGH);
      
      digitalWrite(PIN_R1, HIGH);
      digitalWrite(PIN_R2, LOW);

      analogWrite(6, 255);
    }

  private:
    int PIN_L1, PIN_L2;
    int PIN_R1, PIN_R2;
};
