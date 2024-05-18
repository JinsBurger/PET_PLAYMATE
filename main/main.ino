#include "./pins.h"
#include "./move.cpp"
#include "./distance.cpp"


Move *move_impl;
Distance *distance_impl;

void setup() {
    Serial.begin(9600);

  move_impl =  new Move(2, 3, 4, 5);
 // distance_impl = new Distance(PIN_ULTRA_TRIG, PIN_ULTRA_ECHO);


}

void loop() {
  move_impl->move1();
  //Serial.println(distance_impl->get_distance());
 // delay(1000);
}

