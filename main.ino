#include "./pins.h"
#include "./move.cpp"
#include "./distance.cpp"

Move *move_impl;
Distance *distance_impl;

void setup() {
  Serial.begin(9600);

  move_impl =  new Move(PIN_MOTOR_LSPEED, PIN_MOTOR_LIN, PIN_MOTOR_LOUT, PIN_MOTOR_RIN, PIN_MOTOR_ROUT, PIN_MOTOR_RSPEED);
  // distance_impl = new Distance(PIN_ULTRA_TRIG, PIN_ULTRA_ECHO)
}

void loop() {
  move_impl -> forward();
  // Serial.println(distance_impl->get_distance());
  // delay(1000);
}

