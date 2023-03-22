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

TEST(CalculatorTests, whenSimpleSubstractionThenResultCorrect) {
	// Given
	string expression = "1 - 2";
	double expected = -1.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenLargeNumberThenResultCorrect) {
	// Given
	string expression = "100";
	double expected = 100.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenNegationThenResultCorrect) {
	// Given
	string expression = "-10";
	double expected = -10.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenPositivThenResultCorrect) {
	// Given
	string expression = "+10";
	double expected = 10.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenMultiplicationThenResultCorrect) {
	// Given
	string expression = "2 * 2";
	double expected = 4.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenDivisionThenResultCorrect) {
	// Given
	string expression = "3 / 2";
	double expected = 1.5;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenAdditionAndMultiplicationThenResultCorrect) {
	// Given
	string expression = "1 + 2 * 3";
	double expected = 7.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenMultiplicationAndAdditionThenResultCorrect) {
	// Given
	string expression = "1 * 2 + 3";
	double expected = 5.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenNoSpacesThenResultCorrect) {
	// Given
	string expression = "1+2";
	double expected = 3.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenParenthesisThenResultCorrect) {
	// Given
	string expression = "1 + (2 - 3)";
	double expected = 0.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}

TEST(CalculatorTests, whenMultipleParenthesisThenResultCorrect) {
	// Given
	string expression = "2 * (1 - (3 + 4))";
	double expected = -12.0;

	// When
	Calculator calculator;
	auto result = calculator.calculate(expression);

	// Then
	ASSERT_EQ(result, expected);
}