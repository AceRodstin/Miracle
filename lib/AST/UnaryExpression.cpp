#include "AST/UnaryExpression.h"

using namespace miracle;

UnaryExpression::UnaryExpression(shared_ptr<UnaryOperator> unaryOperator, shared_ptr<Operand> operand): unaryOperator(unaryOperator), operand(operand) {}

const shared_ptr<UnaryOperator> UnaryExpression::getUnaryOperator() const {
	return unaryOperator;
}

const shared_ptr<Operand> UnaryExpression::getOperand() const {
	return operand;
}
