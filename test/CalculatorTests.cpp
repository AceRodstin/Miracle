#include "gtest/gtest.h"
#include "Services/Calculator.h"
#include <string>

using namespace std;
using namespace miracle;

TEST(CalculatorTests, whenSimpleAdditionThenResultCorrect) {
	// Given
	string expression = "1 + 2";
	double expected = 3.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenMultipleAdditionsThenResultCorrect) {
	// Given
	string expression = "1 + 2 + 3 + 4";
	double expected = 10.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}