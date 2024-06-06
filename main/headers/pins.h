#ifndef _PIN_INCLUDE
#define _PIN_INCLUDE

/* Shift Register */
#define PIN_SR_DATA 4
#define PIN_SR_LATCH 3
#define PIN_SR_REG 2

/* MOVE */ 
#define PIN_MOVE_LSPEED A2
#define PIN_MOVE_LIN 1 // SR
#define PIN_MOVE_LOUT 0 // SR
#define PIN_MOVE_RIN 3 // SR
#define PIN_MOVE_ROUT 2 // SR
#define PIN_MOVE_RSPEED A1

/* SHOOTER */
#define PIN_SHOOTER_SPEED A5 
#define PIN_SHOOTER_IN 6 // SR
#define PIN_SHOOTER_OUT 7 // SR

/* DISTANCE */
#define PIN_DISTANCE1_TRIG 4 // SR
#define PIN_DISTANCE1_ECHO A3
#define PIN_DISTANCE2_TRIG 5 // SR
#define PIN_DISTANCE2_ECHO A4

/* BLUETOOTH */
#define PIN_BT_TX 13
#define PIN_BT_RX 12

/* ROTATION */
#define PIN_ROTATION_PWM 0

#endif