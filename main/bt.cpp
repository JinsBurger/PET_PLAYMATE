#include "./headers/bt.h"

/// Initialize bluetooth
BT::BT(int tx, int rx) : btSerial(tx, rx) {
  PIN_TX = tx;
  PIN_RX = rx;

  btSerial.begin(9600);
}

/// Drive car
void BT::drive(Move *move, int distance_front, int distance_back) {
  while (btSerial.available()) {
    dir = btSerial.read();
    Serial.println(dir);
  }

  switch (dir) {
    case 'w':
      move -> forward(distance_front);
      break;
    case 'a':
      move -> left();
      break;
    case 'd':
      move -> right();
      break;
    case 's':
      move -> backward(distance_back);
      break;
    default:
      move -> stop();
  }
}

/// Rotate
void BT::rotate(Rotation *rotation) {
  while (btSerial.available()) {
    rot = btSerial.read();
  }
  
  if (rot == 'o') {
    rotation -> rotate(60);
  } else if (dir == 'p') {
    rotation -> rotate(120);
  }
}