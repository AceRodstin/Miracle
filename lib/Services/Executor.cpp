//
//  Executor.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/Executor.h"
#include "Models/Operator.h"

using namespace miracle;

Executor::Executor(shared_ptr<Expression> expression): expression(expression) {}

double Executor::execute() {
	return execute(expression);
}

double Executor::execute(shared_ptr<Expression> expression) {
	if (auto expr = expression->getUnaryExpression()) {
		auto unaryExpression = dynamic_cast<UnaryExpression*>(expr.get());
		return execute(*unaryExpression);
	}

	auto lhs = execute(expression->getLhs());
	auto binaryOperator = expression->getBinaryOperator();
	auto op = binaryOperator->getOperator();
	auto rhs = execute(expression->getRhs());

	switch (op) {
	case Operator::plus:
		return lhs + rhs;
	case Operator::minus:
		return lhs - rhs;
	case Operator::multiplication:
		return lhs * rhs;
	case Operator::division:
		return lhs / rhs;
	}
}

double Executor::execute(UnaryExpression& unaryExpression) {
	double value;
	auto operand = unaryExpression.getOperand();

	if (auto expression = operand->getExpression()) {
		value = execute(expression);
	} else {
		auto number = operand->getNumber();
		value = number.value();
	}

	if (auto unaryOperator = unaryExpression.getUnaryOperator()) {
		auto op = unaryOperator->getOperator();

		switch (op) {
		case Operator::minus:
			value = -value;
			break;
		default:
			break;
		}
	}

	return value;
}
