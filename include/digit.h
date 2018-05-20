#include "display.h"

#ifndef _DIGIT_H_
#define _DIGIT_H_

// Values composed of individual segments
#define VALUE_0 SEGMENT_TOP | SEGMENT_TOPLEFT | SEGMENT_BOTTOMLEFT | SEGMENT_BOTTOM | SEGMENT_BOTTOMRIGHT | SEGMENT_TOPRIGHT
#define VALUE_1 SEGMENT_TOPRIGHT | SEGMENT_BOTTOMRIGHT
#define VALUE_2 SEGMENT_TOP | SEGMENT_TOPRIGHT | SEGMENT_CENTER | SEGMENT_BOTTOMLEFT | SEGMENT_BOTTOM
#define VALUE_3 SEGMENT_TOP | SEGMENT_TOPRIGHT | SEGMENT_CENTER | SEGMENT_BOTTOMRIGHT | SEGMENT_BOTTOM
#define VALUE_4 SEGMENT_TOPLEFT | SEGMENT_CENTER | SEGMENT_TOPRIGHT | SEGMENT_BOTTOMRIGHT
#define VALUE_5 SEGMENT_TOP | SEGMENT_TOPLEFT | SEGMENT_CENTER | SEGMENT_BOTTOMRIGHT | SEGMENT_BOTTOM
#define VALUE_6 SEGMENT_TOP | SEGMENT_TOPLEFT | SEGMENT_CENTER | SEGMENT_BOTTOMLEFT | SEGMENT_BOTTOM | SEGMENT_BOTTOMRIGHT
#define VALUE_7 SEGMENT_TOP | SEGMENT_TOPRIGHT | SEGMENT_BOTTOMRIGHT
#define VALUE_8 VALUE_0 | SEGMENT_CENTER
#define VALUE_9 SEGMENT_TOP | SEGMENT_TOPLEFT | SEGMENT_CENTER | SEGMENT_TOPRIGHT | SEGMENT_BOTTOMRIGHT

typedef struct digit {
  grid grid;
  segment segments;
} digit;

#endif