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

		double execute(shared_ptr<UnaryExpression> unaryExpression) {
			double value;
			auto operand = unaryExpression->getOperand();

			if (auto expression = operand->getExpression()) {
				value = execute(expression);
			} else {
				auto number = operand->getNumber();
				value = number.value();
			}

			if (auto unaryOperator = unaryExpression->getUnaryOperator()) {
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
	};
}


#endif