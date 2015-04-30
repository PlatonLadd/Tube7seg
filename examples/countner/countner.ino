
#include "Tube7seg.h"

/* Arduino output pins */
Tube7seg disp(2, 3, 4);

const int msec = 500;
int oldTime = 0;
int now;
int countner = 0;

void setup() {
  // no setup
}

void loop() {
  uint8_t digs[4];
  int tmp = countner;

  /* split countner to digits
   * using by tmp
   */
  for(int i=0; i<4; i++)
  {
    digs[i] = Tube7seg::DIGIT[tmp % 10];
    tmp /= 10;
  }

  // display digits
  disp.writeDisp( digs );

  // control delaying
  if (((now=millis())-oldTime)>=msec)
  {
    countner = (countner + 1) % 10000;
    oldTime = now;
  }

}

