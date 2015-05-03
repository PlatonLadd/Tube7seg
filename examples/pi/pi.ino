/*

The document is publised under
GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

https://github.com/PlatonLadd/Tube7seg/blob/master/LICENSE

*/

/* show pi = 3.14 on display */

#include "Tube7seg.h"

/* use DARK and DOT */
#define DARK Tube7seg::DIGIT[16]
#define DOT Tube7seg::DIGIT[17]

/* Arduino output pins */
Tube7seg disp(2, 3, 4);

void setup() {
  // no setup
}

void loop() {
  // write to display "3.14" repeatedly
  disp.writeDisp(DARK,
                 Tube7seg::DIGIT[3] & DOT,
                 Tube7seg::DIGIT[1],
                 Tube7seg::DIGIT[4]);
}


