#include "./pins.h"
#include "./move.cpp"
#include "./distance.cpp"


Move *move_impl;
Distance *distance_impl;

void setup() {
  // Move Motor
  move_impl =  new Move(PIN_MOTOR_L1, PIN_MOTOR_L2, PIN_MOTOR_R1, PIN_MOTOR_R2);
  // Distance Motor
  distance_impl = new Distance(PIN_ULTRA_TRIG, PIN_ULTRA_ECHO);
  
  Serial.begin(9600);
}

void loop() {
  move_impl->move1();
  Serial.println(distance_impl->get_distance());
  delay(1000);
}

