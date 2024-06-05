#include "./headers/bt.h"

/// Initialize bluetooth
BT::BT(int tx, int rx) : btSerial(tx, rx) {
  PIN_TX = tx;
  PIN_RX = rx;

  btSerial.begin(9600);
  Serial.begin(9600);
}

/// Drive car
void BT::drive(Move *move, int distance) {
  while (btSerial.available()) {
    dir = btSerial.read();
    Serial.println(dir);
  }

  switch (dir) {
    case 'w':
      move -> forward(distance);
      break;
    case 'a':
      move -> left();
      break;
    case 'd':
      move -> right();
      break;
    case 's':
      move -> backward();
      break;
    default:
      move -> stop();
  }
}