//
//  Expression.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "AST/Expression.h"

using namespace miracle;

Expression::Expression(shared_ptr<Expression> unaryExpression):
		unaryExpression(unaryExpression),
		lhs(nullptr),
		binaryOperator(nullptr),
		rhs(nullptr) {}

Expression::Expression(shared_ptr<Expression> lhs, shared_ptr<BinaryOperator> binaryOperator, shared_ptr<Expression> rhs):
		unaryExpression(nullptr),
		lhs(lhs),
		binaryOperator(binaryOperator),
		rhs(rhs) {}

const shared_ptr<Expression> Expression::getUnaryExpression() const {
	return unaryExpression;
}

const shared_ptr<Expression> Expression::getLhs() const {
	return lhs;
}

const shared_ptr<BinaryOperator> Expression::getBinaryOperator() const {
	return binaryOperator;
}

const shared_ptr<Expression> Expression::getRhs() const {
	return rhs;
}
