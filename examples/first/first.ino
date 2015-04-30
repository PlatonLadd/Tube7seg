#include <Arduino.h>
#include "Tube7seg.h"

/* Arduino output pins */
Tube7seg disp(2, 3, 4);

void setup() {
  // no setup
}

void loop() {
  // write to display "1357" repeatedly
  disp.writeDisp(Tube7seg::DIGIT[1],
                 Tube7seg::DIGIT[3],
                 Tube7seg::DIGIT[5],
                 Tube7seg::DIGIT[7]);
}

