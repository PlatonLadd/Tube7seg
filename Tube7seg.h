/*

The document is publised under
GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

https://github.com/PlatonLadd/Tube7seg/blob/master/LICENSE

*/



#ifndef _TUBE7SEG_H_
#define _TUBE7SEG_H_

#include <Arduino.h>
#include <stdint.h>

class Tube7seg
{
  public:
    static const uint8_t *DIGIT;
    Tube7seg(uint8_t d, uint8_t l, uint8_t c);
    void writeDisp(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
    void writeDisp(uint8_t *digs);

  private:
    static const uint8_t *POSITION;
    uint8_t _datain; // data input
    uint8_t _lacht;  // lacht
    uint8_t _clock;  // clock signal for 595
};

#endif // _TUBE7SEG_H_
