#include "./headers/pins.h"
#include "./headers/move.h"
#include "./headers/distance.h"
#include "./headers/bt.h"
#include "./headers/shooter.h"
#include "./headers/rotation.h"
#include "./headers/sr.h"

Move *move_impl;
Distance *distance1_impl; // Front
Distance *distance2_impl; // Back
Shooter *shooter_impl;
BT *bt_impl;
Rotation *rotation_impl;
SR *sr_impl;

void setup() {
  sr_impl = new SR(PIN_SR_DATA, PIN_SR_LATCH, PIN_SR_REG);
  move_impl = new Move(PIN_MOVE_LSPEED, PIN_MOVE_LIN, PIN_MOVE_LOUT, PIN_MOVE_RIN, PIN_MOVE_ROUT, PIN_MOVE_RSPEED, sr_impl);
  distance1_impl = new Distance(PIN_DISTANCE1_TRIG, PIN_DISTANCE1_ECHO, sr_impl);
  distance2_impl = new Distance(PIN_DISTANCE2_TRIG, PIN_DISTANCE2_ECHO, sr_impl);
  shooter_impl = new Shooter(PIN_SHOOTER_IN, PIN_SHOOTER_OUT, PIN_SHOOTER_SPEED);
  bt_impl = new BT(PIN_BT_TX, PIN_BT_RX);
  rotation_impl = new Rotation(PIN_ROTATION_PWM);
  
  Serial.begin(9600);
}

void loop() {
  int distance_front = distance1_impl -> get_distance();
  delay(12);
  int distance_back = distance2_impl -> get_distance();
  Serial.println(distance_front);

  bt_impl -> drive(move_impl, distance_front, distance_back);
  // bt_impl -> rotate(rotation_impl);
  // move_impl -> forward(distance);
  // rotation_impl -> rotate(40);

  
  // shooter_impl -> shoot();
  delay(12);
}