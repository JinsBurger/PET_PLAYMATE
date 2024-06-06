#include "./headers/move.h"
#include "./headers/constants.h"

/// Initialize Move
Move::Move(int lspeed, int lin, int lout, int rin, int rout, int rspeed, SR *sr_impl) {
  PIN_LIN = lin; PIN_LOUT = lout; PIN_LSPEED = lspeed;
  PIN_RIN = rin; PIN_ROUT = rout; PIN_RSPEED = rspeed;

  sr = sr_impl;

  pinMode(PIN_RSPEED, OUTPUT);
  pinMode(PIN_LSPEED, OUTPUT);
}

/// Drive forward
void Move::forward(int distance) {
  // Only move forward if there is enough space
  if (distance > STOP_DISTANCE) {
      // Speed
      analogWrite(PIN_RSPEED, 180);
      analogWrite(PIN_LSPEED, 180);

      // Left wheels - front
      sr -> digital_write(PIN_LIN, HIGH);
      sr -> digital_write(PIN_LOUT, LOW);
      
      // Right wheels - front
      sr -> digital_write(PIN_RIN, HIGH);
      sr -> digital_write(PIN_ROUT, LOW);
  } else {
      stop();
  }
}

/// Drive backward
void Move::backward(int distance) {
  if (distance > STOP_DISTANCE) {
    // Speed
    analogWrite(PIN_RSPEED, 180);
    analogWrite(PIN_LSPEED, 180);

    // Left wheels - back
    sr -> digital_write(PIN_LIN, LOW);
    sr -> digital_write(PIN_LOUT, HIGH);
    
    // Right wheels - back
    sr -> digital_write(PIN_RIN, LOW);
    sr -> digital_write(PIN_ROUT, HIGH);
  } else {
    stop();
  }
}

/// Turn left
void Move::left() {
  // Speed
  analogWrite(PIN_RSPEED, 180);
  analogWrite(PIN_LSPEED, 180);

  // Left wheels - back
  sr -> digital_write(PIN_LIN, HIGH);
  sr -> digital_write(PIN_LOUT, LOW);
  
  // Right wheels - front
  sr -> digital_write(PIN_RIN, LOW);
  sr -> digital_write(PIN_ROUT, HIGH);
}

/// Turn right
void Move::right() {
  // Speed
  analogWrite(PIN_RSPEED, 180);
  analogWrite(PIN_LSPEED, 180);

  // Left wheels - front
  sr -> digital_write(PIN_LIN, LOW);
  sr -> digital_write(PIN_LOUT, HIGH);
  
  // Right wheels - back
  sr -> digital_write(PIN_RIN, HIGH);
  sr -> digital_write(PIN_ROUT, LOW);
}

/// Stop
void Move::stop() {
  // Speed
  analogWrite(PIN_RSPEED, 0);
  analogWrite(PIN_LSPEED, 0);

  // Left wheels - front
  sr -> digital_write(PIN_LIN, LOW);
  sr -> digital_write(PIN_LOUT, LOW);
  
  // Right wheels - back
  sr -> digital_write(PIN_RIN, LOW);
  sr -> digital_write(PIN_ROUT, LOW);
}