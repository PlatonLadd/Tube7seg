/*

The document is publised under
GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

https://github.com/PlatonLadd/Tube7seg/blob/master/LICENSE

*/

#include "Tube7seg.h"

Tube7seg disp(2, 3, 4);
const int analogInput = A0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int value;
  uint8_t pom[4];

  // read e.g. photoresistor
  value  = analogRead(analogInput);
  
  for (int i=0; i<4; i++)
  {
    pom[i] = value % 10;
    value = value / 10;  // value /= 10;
  }
  
  disp.writeDisp(Tube7seg::DIGIT[pom[3]],
                 Tube7seg::DIGIT[pom[2]],
                 Tube7seg::DIGIT[pom[1]],
                 Tube7seg::DIGIT[pom[0]]);

}


