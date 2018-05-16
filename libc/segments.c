#include "segments.h"
#include "util.h"

static const uint8_t divisor = 10;
static segment digits[10] = {
	D0,
	D1,
	D2,
	D3,
	D4,
	D5,
	D6,
	D7,
	D8,
	D9
};

uint8_t getIndex(number value) {
	return value % divisor;
}

void convertValueToSegments(number value, segment segments[], uint8_t size) {
	uint8_t i = 0;
	for (i = 0; i < size; i++) {
		segments[i] = digits[getIndex(value)];
		value /= divisor;
	}
}

segment mergeSegments(segment segments[], uint8_t size) {
	segment retval = 0;
	uint8_t i = 0;
	for (i = 0; i < size; i++) {
		retval |= segments[i];
	}
	return retval;
}