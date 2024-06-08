#ifndef PINS_H
#define PINS_H

/* Shift Register */
// #define PIN_SR_DATA 4
// #define PIN_SR_LATCH 3
// #define PIN_SR_REG 2

/* MOVE */ 
#define PIN_MOVE_LSPEED A2
#define PIN_MOVE_LIN 11
#define PIN_MOVE_LOUT 10
#define PIN_MOVE_RIN 9
#define PIN_MOVE_ROUT 8
#define PIN_MOVE_RSPEED A1

/* SHOOTER */
#define PIN_SHOOTER_SPEED A5 
#define PIN_SHOOTER_IN 6
#define PIN_SHOOTER_OUT 7

/* DISTANCE */
#define PIN_DISTANCE1_TRIG 13 // Front
#define PIN_DISTANCE1_ECHO A3
#define PIN_DISTANCE2_TRIG 12 // Back
#define PIN_DISTANCE2_ECHO A4

#endif