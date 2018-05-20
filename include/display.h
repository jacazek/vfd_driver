#include "util.h"
#include <stdint.h>
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

typedef uint8_t segment;
typedef uint8_t grid;
typedef uint16_t number;

// Individual segments
#define SEGMENT_CENTER SHIFT(0)
#define SEGMENT_TOPLEFT SHIFT(1)
#define SEGMENT_BOTTOMLEFT SHIFT(2)
#define SEGMENT_BOTTOM SHIFT(3)
#define SEGMENT_TOPRIGHT SHIFT(4)
#define SEGMENT_BOTTOMRIGHT SHIFT(5)
#define SEGMENT_TOP SHIFT(6)

#define GRID1 SHIFT(0)
#define GRID2 SHIFT(1)
#define GRID3 SHIFT(2)
#define GRID4 SHIFT(3)
#define GRID5 SHIFT(4)
#define GRID6 SHIFT(5)

#endif