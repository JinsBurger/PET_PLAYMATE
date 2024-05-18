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
    }

    void move1() {
      digitalWrite(PIN_L1, HIGH);
      digitalWrite(PIN_L2, LOW);   //앞으로 회전
      digitalWrite(PIN_R1, HIGH);
      digitalWrite(PIN_R2, LOW);   //앞으로 회
    }

  private:
    int PIN_L1, PIN_L2;
    int PIN_R1, PIN_R2;
};
