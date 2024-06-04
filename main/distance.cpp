#include "./headers/distance.h"

/// Initialize ultrasonic
Distance::Distance(int tp, int ep) {
    TRIG_PIN = tp;
    ECHO_PIN = ep;

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT); 
}

/// Returns distance calculated using ultrasonic
unsigned int Distance::get_distance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH) * 17 / 1000;
}
