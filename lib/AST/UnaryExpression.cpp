//
//  UnaryExpression.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "AST/UnaryExpression.h"

using namespace miracle;

UnaryExpression::UnaryExpression(shared_ptr<UnaryOperator> unaryOperator, shared_ptr<Operand> operand): unaryOperator(unaryOperator), operand(operand) {}

const shared_ptr<UnaryOperator> UnaryExpression::getUnaryOperator() const {
	return unaryOperator;
}

const shared_ptr<Operand> UnaryExpression::getOperand() const {
	return operand;
}
