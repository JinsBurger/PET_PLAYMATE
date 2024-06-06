#include "./headers/distance.h"

/// Initialize ultrasonic
Distance::Distance(int tp, int ep, SR *sr_impl) {
    TRIG_PIN = tp;
    ECHO_PIN = ep;

    sr = sr_impl;

    // pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT); 
}

/// Returns distance calculated using ultrasonic
unsigned int Distance::get_distance() {
    sr -> digital_write(TRIG_PIN, LOW);
    delayMicroseconds(2);
    sr -> digital_write(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    sr -> digital_write(TRIG_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH) * 17 / 1000;
}
