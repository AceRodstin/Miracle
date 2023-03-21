#ifndef EXECUTOR_HEADER_FILE
#define EXECUTOR_HEADER_FILE


#include "Tree/AST.h"
#include <memory>

using namespace std;

namespace miracle {
	class Executor {
	public:
		Executor(shared_ptr<Expression> expression): expression(expression) {}

		double execute() {
			return execute(expression);
		}

	private:
		shared_ptr<Expression> expression;

		double execute(shared_ptr<Expression> expression) {
			if (auto unaryExpression = expression->getUnaryExpression()) {
				return execute(unaryExpression);
			}

			auto lhs = execute(expression->getLhs());
			auto binaryOperator = expression->getBinaryOperator();
			auto op = binaryOperator->getOperator();
			auto rhs = execute(expression->getRhs());

			switch (op) {
			case Operator::add:
				return lhs + rhs;
			case Operator::subtruct:
				return lhs - rhs;
			case Operator::multiply:
				return lhs * rhs;
			case Operator::divide:
				return lhs / rhs;
			}
		}

		double execute(shared_ptr<UnaryExpression> unaryExpression) {
			auto operand = unaryExpression->getOperand();

			if (auto expression = operand->getExpression()) {
				return execute(expression);
			}

			auto number = operand->getNumber();
			return number.value();
		}
	};
}


#endif