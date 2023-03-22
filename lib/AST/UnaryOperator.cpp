#include "AST/UnaryOperator.h"

using namespace miracle;

UnaryOperator::UnaryOperator(Operator op): _operator(op) {}

Operator UnaryOperator::getOperator() const {
	return _operator;
}
