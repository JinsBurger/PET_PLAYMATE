#include "./headers/bt.h"

/// Initialize bluetooth
BT::BT(int tx, int rx) : HM10(tx, rx) {
  PIN_TX = tx;
  PIN_RX = rx;
  HM10.begin(9600);
}

/// Drive car
void BT::drive(Move *move, int distance) {
  while (HM10.available()) {
    dir = HM10.read();
  }

  switch (dir) {
    case 'w':
      move->forward(distance);
      break;
    case 'a':
      move->left();
      break;
    case 'd':
      move->right();
      break;
    case 's':
      move->backward();
      break;
    default:
      move->stop();
  }
}