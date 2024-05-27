#include "./pins.h"
#include "./move.cpp"
#include "./distance.cpp"
#include "./shooter.cpp"

Move *move_impl;
Shooter *shooter_impl;
Distance *distance_impl;

void setup() {
  Serial.begin(9600);

  // move_impl = new Move(PIN_MOVE_LSPEED, PIN_MOVE_LIN, PIN_MOVE_LOUT, PIN_MOVE_RIN, PIN_MOVE_ROUT, PIN_MOVE_RSPEED);
  // shooter_impl = new Shooter(PIN_SHOOTER_IN, PIN_SHOOTER_OUT);
  // distance_impl = new Distance(PIN_DISTANCE_TRIG, PIN_DISTANCE_ECHO);
}

void loop() {
  // move_impl -> forward();
  // Serial.println(distance_impl -> get_distance());
  // delay(1000);
}