#include "./headers/pins.h"
#include "./headers/move.h"
#include "./headers/distance.h"
#include "./headers/bt.h"
#include "./headers/shooter.h"
#include "./headers/rotation.h"

Move *move_impl;
Distance *distance_impl;
Shooter *shooter_impl;
BT *bt_impl;
Rotation *rotation_impl;

void setup() {
  move_impl = new Move(PIN_MOVE_LSPEED, PIN_MOVE_LIN, PIN_MOVE_LOUT, PIN_MOVE_RIN, PIN_MOVE_ROUT, PIN_MOVE_RSPEED);
  distance_impl = new Distance(PIN_DISTANCE_TRIG, PIN_DISTANCE_ECHO);
  shooter_impl = new Shooter(PIN_SHOOTER_IN, PIN_SHOOTER_OUT, PIN_SHOOTER_SPEED);
  bt_impl = new BT(PIN_BT_TX, PIN_BT_RX);
  rotation_impl = new Rotation(0);
}

void loop() {
  int distance = distance_impl -> get_distance();
  bt_impl -> drive(move_impl, distance);

  // shooter_impl -> shoot();
  delay(12);
}