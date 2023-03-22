//
//  BinaryOperator.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "AST/BinaryOperator.h"

using namespace miracle;

BinaryOperator::BinaryOperator(Operator op): _operator(op) {}

Operator BinaryOperator::getOperator() const {
	return _operator;
}
