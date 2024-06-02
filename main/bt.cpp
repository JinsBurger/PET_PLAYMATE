#include "./constants.h"

#import <Arduino.h>
#import <SoftwareSerial.h>

class BT {
  public:
    // Initialize Bluetooth
    BT(int tx, int rx) : HM10(tx, rx) {
      PIN_TX = tx;
      PIN_RX = rx;
      
      Serial.begin(9600);
      HM10.begin(9600);
      Serial.print("BT Connected");
    }

    // Move car
    void drive() {
      while (HM10.available()) {
        byte c = HM10.read();
        Serial.write(c);
      }

      while (Serial.available()) {
        byte c = Serial.read();
        HM10.write(c);
      }
    }

  private:
    SoftwareSerial HM10;
    int PIN_TX, PIN_RX;
};
