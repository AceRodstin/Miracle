//
//  UnaryOperator.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "AST/UnaryOperator.h"

using namespace miracle;

UnaryOperator::UnaryOperator(Operator op): _operator(op) {}

Operator UnaryOperator::getOperator() const {
	return _operator;
}
