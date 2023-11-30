#include <Arduino.h>
#include "CRC.h"
#include "CRSF.h"

HardwareSerial Serial(PA9);

void setup() {

  Serial.begin(SERIAL_BAUDRATE);

  for(int i = 0 ; i < CRSF_MAX_CHANNEL ; i++){
    rc_channels[i] = CRSF_CHANNEL_VALUE_MIN;
  }
}

void loop() {
  
}

