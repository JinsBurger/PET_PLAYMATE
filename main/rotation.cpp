#include "./headers/rotation.h"

/// Initialize rotation
Rotation::Rotation(int pwm) {
  servo.attach(pwm);
  // servo.write(90); // Initialize to center position
}

/// Rotate
void Rotation::rotate(int deg) {
  // if (deg > MAX_ROTATION) {
  //   deg = MAX_ROTATION;
  // }
  // if (deg < -MAX_ROTATION) {
  //   deg = -MAX_ROTATION;
  // }

  servo.write(deg);
}