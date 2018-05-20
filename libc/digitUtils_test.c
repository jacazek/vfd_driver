#include "digitUtils.h"
#include "unity.h"

void setUp() {
}

void tearDown() {
	
}

void TEST_ASSERT_EQUAL_DIGIT(digit expected, digit actual) {
	TEST_ASSERT_EQUAL_UINT8_MESSAGE(expected.segments, actual.segments, "segments were not equal");
	TEST_ASSERT_EQUAL_UINT8_MESSAGE(expected.grid, actual.grid, "grids were not equal");
}

void TEST_ASSERT_EQUAL_DIGIT_ARRAY(digit expected[], digit actual[], int elem) {
	TEST_ASSERT_EQUAL_DIGIT(expected[elem - 1], actual[elem - 1]);
}

void GivenANumber_WhenConvertToDigits_ThenArrayIsPopulated() {
	digit actualOutput[1] = { 
		{ .segments = 0, .grid = 0 } 
	};
	digit expectedOutput[1] = { 
		{ .segments = VALUE_2, .grid = GRID1 } 
	};
	convertNumberToDigits(2, actualOutput, 1);
	TEST_ASSERT_EQUAL_DIGIT_ARRAY(expectedOutput, actualOutput, 1);
}

void GivenA4DigitNumber_WhenConvertToDigits_ThenArrayIsPopulatedWithAllDigits() {
	digit output[4] = {
		{ .segments = 0, .grid = 0 },
		{ .segments = 0, .grid = 0 },
		{ .segments = 0, .grid = 0 },
		{ .segments = 0, .grid = 0 }
	};
	digit expectedOutput[4] = { 
		{ .segments = VALUE_4, .grid = GRID1 },
		{ .segments = VALUE_2, .grid = GRID2 },
		{ .segments = VALUE_0, .grid = GRID4 }, 
		{ .segments = VALUE_1, .grid = GRID5 }
	};
	convertNumberToDigits(1024, output, 4);
	TEST_ASSERT_EQUAL_DIGIT_ARRAY(expectedOutput, output, 1);
	TEST_ASSERT_EQUAL_DIGIT_ARRAY(expectedOutput, output, 2);
	TEST_ASSERT_EQUAL_DIGIT_ARRAY(expectedOutput, output, 3);
	TEST_ASSERT_EQUAL_DIGIT_ARRAY(expectedOutput, output, 4);
}

void GivenSomeSegemnts_WhenMergeDigitSegments_AllDigitBitsORed() {
	digit input[2] = { 
		{ .segments = 1, .grid = GRID1 },
		{ .segments = 1<<3, .grid = GRID2 },
	};
	TEST_ASSERT_EQUAL_UINT8(9, mergeDigitSegments(input, 2));
}

void GivenNoDigits_WhenMergeDigitSegments_AllBitsAreZero() {
	digit input[0];
	TEST_ASSERT_EQUAL_UINT8(0, mergeDigitSegments(input, 0));
}

void Given2DigitsThatAreZero_WhenMergeDigitSegments_AllBitsAreZero() {
	digit input[2] = { 
		{ .segments = 0, .grid = GRID1 },
		{ .segments = 0, .grid = GRID2 }
	};
	TEST_ASSERT_EQUAL_UINT8(0, mergeDigitSegments(input, 2));
}

void GivenAllOnes_AndAllZeros_WhenMergeDigitSegments_AllBitsAreOne() {
	digit input[2] = { 
		{ .segments = 255, .grid = GRID1 },
		{ .segments = 0, .grid = GRID2 }
	};
	TEST_ASSERT_EQUAL_UINT8(255, mergeDigitSegments(input, 2));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(GivenANumber_WhenConvertToDigits_ThenArrayIsPopulated);
	RUN_TEST(GivenA4DigitNumber_WhenConvertToDigits_ThenArrayIsPopulatedWithAllDigits);
	RUN_TEST(GivenSomeSegemnts_WhenMergeDigitSegments_AllDigitBitsORed);
	RUN_TEST(GivenNoDigits_WhenMergeDigitSegments_AllBitsAreZero);
	RUN_TEST(Given2DigitsThatAreZero_WhenMergeDigitSegments_AllBitsAreZero);
	RUN_TEST(GivenAllOnes_AndAllZeros_WhenMergeDigitSegments_AllBitsAreOne);
	return UNITY_END();
};