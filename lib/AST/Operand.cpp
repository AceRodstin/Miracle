//
//  Operand.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "AST/Operand.h"

using namespace miracle;

Operand::Operand(optional<double> number): number(number), expression(nullptr) {}
Operand::Operand(shared_ptr<Expression> expression): number(0), expression(expression) {}

optional<double> Operand::getNumber() const {
	return number;
}

const shared_ptr<Expression> Operand::getExpression() const {
	return expression;
}
