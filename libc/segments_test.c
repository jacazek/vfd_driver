#include "segments.h"
#include "../Unity/unity.h"

void setUp() {
}

void tearDown() {
	
}

void GivenANumber_WhenConvertToSegments_ThenArrayIsPopulated() {
	segment output[1] = { 0 };
	segment expectedOutput[1] = { D2 };
	TEST_ASSERT_EQUAL_UINT8(0, output[0]);
	convertValueToSegments(2, output, 1);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedOutput, output, 1);
}

void GivenA4DigitNumber_WhenConvertToSegments_ThenArrayIsPopulatedWithAllDigits() {
	segment output[4] = { 0, 0, 0, 0};
	segment expectedOutput[4] = { D4, D2, D0, D1 };
	convertValueToSegments(1024, output, 4);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedOutput, output, 1);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedOutput, output, 2);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedOutput, output, 3);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedOutput, output, 4);
}

void GivenSomeSegemnts_WhenMergeSegments_AllSegmentBitsORed() {
	segment input[2] = { 1, 1<<3 };
	TEST_ASSERT_EQUAL_UINT8(9, mergeSegments(input, 2));
}

void GivenNoSegments_WhenMergeSegments_AllBitsAreZero() {
	segment input[0];
	TEST_ASSERT_EQUAL_UINT8(0, mergeSegments(input, 0));
}

void Given2SegmentsThatAreZero_WhenMergeSegments_AllBitsAreZero() {
	segment input[2] = { 0, 0 };
	TEST_ASSERT_EQUAL_UINT8(0, mergeSegments(input, 2));
}

void GivenAllOnes_AndAllZeros_WhenMergeSegments_AllBitsAreOne() {
	segment input[2] = { 255, 0 };
	TEST_ASSERT_EQUAL_UINT8(255, mergeSegments(input, 2));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(GivenANumber_WhenConvertToSegments_ThenArrayIsPopulated);
	RUN_TEST(GivenA4DigitNumber_WhenConvertToSegments_ThenArrayIsPopulatedWithAllDigits);
	RUN_TEST(GivenSomeSegemnts_WhenMergeSegments_AllSegmentBitsORed);
	RUN_TEST(GivenNoSegments_WhenMergeSegments_AllBitsAreZero);
	RUN_TEST(Given2SegmentsThatAreZero_WhenMergeSegments_AllBitsAreZero);
	RUN_TEST(GivenAllOnes_AndAllZeros_WhenMergeSegments_AllBitsAreOne);
	return UNITY_END();
};