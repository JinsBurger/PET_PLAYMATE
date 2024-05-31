#include "./pins.h"
#include "./move.cpp"
#include "./distance.cpp"
#include "./shooter.cpp"

Move *move_impl;
Distance *distance_impl;
Shooter *shooter_impl;

void setup() {
  Serial.begin(9600);

  move_impl = new Move(PIN_MOVE_LSPEED, PIN_MOVE_LIN, PIN_MOVE_LOUT, PIN_MOVE_RIN, PIN_MOVE_ROUT, PIN_MOVE_RSPEED);
  distance_impl = new Distance(PIN_DISTANCE_TRIG, PIN_DISTANCE_ECHO);
  shooter_impl = new Shooter(PIN_SHOOTER_IN, PIN_SHOOTER_OUT, PIN_SHOOTER_SPEED);
}

void loop() {
  // int distance = distance_impl -> get_distance();
  // move_impl -> forward(distance);

  shooter_impl -> shoot();
  
  delay(12);
}