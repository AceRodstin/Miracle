#include "AST/BinaryOperator.h"

using namespace miracle;

BinaryOperator::BinaryOperator(Operator op): _operator(op) {}

Operator BinaryOperator::getOperator() const {
	return _operator;
}
