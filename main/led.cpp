#include "./headers/led.h"

/// Initialize led
LED::LED(int auto_pin, int shoot) {
    AUTO_PIN = auto_pin;
    SHOOTER_PIN = shoot;

    pinMode(AUTO_PIN, OUTPUT); 
    pinMode(SHOOTER_PIN, OUTPUT);
}

/// Trigger auto mode led - green
void LED::auto_mode(int val) {
    digitalWrite(AUTO_PIN, val);
}

/// Trigger shooter led - red
void LED::shoot_mode(int val) {
    digitalWrite(SHOOTER_PIN, val);
}