#include "./pins.h"
#include "./move.cpp"
#include "./distance.cpp"


Move *move_impl;
Distance *distance_impl;

void setup() {
  move_impl =  new Move(PIN_MOTOR_L1, PIN_MOTOR_L2, PIN_MOTOR_R1, PIN_MOTOR_R2);
  pinMode(PIN_MOTOR_L1, OUTPUT); pinMode(PIN_MOTOR_L2, OUTPUT); 
  pinMode(PIN_MOTOR_R1, OUTPUT); pinMode(PIN_MOTOR_R2, OUTPUT);

  distance_impl = new Distance(PIN_ULTRA_TRIG, PIN_ULTRA_ECHO);
  pinMode(PIN_ULTRA_TRIG, OUTPUT);
  pinMode(PIN_ULTRA_ECHO, INPUT); 

  Serial.begin(9600);
}

void loop() {
  move_impl->move1();
  Serial.println(distance_impl->get_distance());
  delay(1000);
}

