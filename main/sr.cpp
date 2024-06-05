#include "./headers/sr.h"

/// Initialize shift register
SR::SR(int data, int latch, int reg) {
  DATA = data;
  LATCH = latch;
  REG = reg;

  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(REG, OUTPUT);
}

/// Digital write for shift register
void SR::digital_write(int pin, int val) {
  // Update pin state
  PINSTATES[pin] = val;
  for (int i = 7; i >= 0; i--) {
    CURVAL = (CURVAL << 1) | PINSTATES[i];
  }

  digitalWrite(LATCH, LOW);
  shiftOut(DATA, REG, MSBFIRST, CURVAL);
  digitalWrite(LATCH, HIGH);
}