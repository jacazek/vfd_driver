#include "digit.h"
#include "digitUtils.h"

segment digitValueMap[10] = {
  VALUE_0,
  VALUE_1,
  VALUE_2,
  VALUE_3,
  VALUE_4,
  VALUE_5,
  VALUE_6,
  VALUE_7,
  VALUE_8,
  VALUE_9
};

grid digitGridMap[4] = {
  GRID1,
  GRID2,
  GRID4,
  GRID5
};

static const uint8_t divisor = 10;

uint8_t getIndex(number value) {
	return value % divisor;
}

void convertNumberToDigits(number value, digit digits[], uint8_t size) {
	uint8_t i = 0;
	
	for (i = 0; i < size; i++) {
		digits[i].segments = digitValueMap[getIndex(value)];
		digits[i].grid = digitGridMap[i];
		value /= divisor;
	}
}

segment mergeDigitSegments(digit digits[], uint8_t size) {
	segment retval = 0;
	uint8_t i = 0;
	for (i = 0; i < size; i++) {
		retval |= digits[i].segments;
	}
	return retval;
}