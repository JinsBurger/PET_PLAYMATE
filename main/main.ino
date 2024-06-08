#include "./headers/pins.h"
#include "./headers/constants.h"
#include "./headers/move.h"
#include "./headers/distance.h"
#include "./headers/shooter.h"

Move *move_impl;
Distance *distance_front_impl; // Front
Distance *distance_back_impl;  // Back
Shooter *shooter_impl;

void setup() {
  move_impl = new Move(PIN_MOVE_LSPEED, PIN_MOVE_LIN, PIN_MOVE_LOUT, PIN_MOVE_RIN, PIN_MOVE_ROUT, PIN_MOVE_RSPEED);
  distance_front_impl = new Distance(PIN_DISTANCE1_TRIG, PIN_DISTANCE1_ECHO);
  distance_back_impl = new Distance(PIN_DISTANCE2_TRIG, PIN_DISTANCE2_ECHO);
  shooter_impl = new Shooter(PIN_SHOOTER_IN, PIN_SHOOTER_OUT, PIN_SHOOTER_SPEED);

  Serial.begin(9600);
}

void loop() {
  // Calculate front/back distance using ultrasonic
  int distance_front = distance_front_impl -> get_distance();
  delay(12);
  int distance_back = distance_back_impl -> get_distance();
  delay(12);

  // move_impl -> forward(distance_front);

  // Read command input fron raspberry
  int command = Serial.read();

  if (command == 1) {
    move_impl->forward(distance_front);
  } else if (command == 2) {
    move_impl->backward(distance_back);
  } else if (command == 3) {
    move_impl->left();
  } else if (command == 4) {
    move_impl->right();
  } else if (command == 5) {
    move_impl->stop();
  } else if (command == 6) {
    shooter_impl->shoot();
  } else if (command == 7) {
    shooter_impl->stop();
  } else if (command == 8) {
    move_impl->forward(STOP_DISTANCE + 1);
  } else if (command == 9) {
    move_impl->backward(STOP_DISTANCE + 1);
  }
}
