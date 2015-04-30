/* */

#include <Arduino.h>
#include "Tube7seg.h"

#define LACHT_LOW digitalWrite(_lacht, LOW)
#define LACHT_HIGH digitalWrite(_lacht, HIGH)


Tube7seg::Tube7seg(uint8_t d, uint8_t l, uint8_t c)
{
  _datain = d;
  _lacht = l;
  _clock = c;

  pinMode(d, OUTPUT);
  pinMode(l, OUTPUT);
  pinMode(c, OUTPUT);

}


const uint8_t DIGIT_pom[] = {
  0xff - (1+2+32+16+4+8), /* zero */
  0xff - B0000110, /* one */
  0xff - (1+2+64+16+8), /* two */
  0xff - (1+2+64+4+8), /* three */
  0xff - (32+64+2+4), /* four */
  0xff - (1+32+64+4+8), /* five */
  0xff - (1+32+64+16+4+8), /* six */
  0xff - (1+2+4), /* seven */
  0xff - B01111111, /* eight */
  0xff - (1+2+64+32+4+8), /* nine */
  0xff - (1+32+2+64+16+4), /* A */
  0xff - (32+64+16+4+8), /* b */
  0xff - (64+16+8), /* c */
  0xff - (2+64+16+4+8), /* d */
  0xff - (1+32+64+16+8), /* E */
  0xff - (1+32+64+16), /* F */
  0xff - 0, /* 0x10,16: dark -- all off */
  0xff - 128, /* 0x11,17: dot */
  0xff - 64, /* 0x12, 18: minus */
  0xff - (64+16), /* 0x13,19: r */
  0xff - (64+16+4+8) /* 0x14, 20: a */
};
const uint8_t *Tube7seg::DIGIT = DIGIT_pom;


void Tube7seg::writeDisp(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
   LACHT_LOW;
   shiftOut(_datain, _clock, MSBFIRST, a);
   shiftOut(_datain, _clock, MSBFIRST, B1000);
   LACHT_HIGH;

   LACHT_LOW;
   shiftOut(_datain, _clock, MSBFIRST, b);
   shiftOut(_datain, _clock, MSBFIRST, B0100);
   LACHT_HIGH;

   LACHT_LOW;
   shiftOut(_datain, _clock, MSBFIRST, c);
   shiftOut(_datain, _clock, MSBFIRST, B0010);
   LACHT_HIGH;

   LACHT_LOW;
   shiftOut(_datain, _clock, MSBFIRST, d);
   shiftOut(_datain, _clock, MSBFIRST, B0001);
   LACHT_HIGH;

};

const uint8_t POSITION_pom[] = {
  B0001,
  B0010,
  B0100,
  B1000
};
const uint8_t *Tube7seg::POSITION = POSITION_pom;

void Tube7seg::writeDisp(uint8_t *digs)
{
    writeDisp(digs[3], digs[2], digs[1], digs[0]);
};


