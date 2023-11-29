#include <Arduino.h>
#include "CRC.h"

// put function declarations here:
int myFunction(int, int);
CRC_8 eee;


void setup() {
  // put your setup code here, to run once:
  eee.setup_CRC_table();
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}