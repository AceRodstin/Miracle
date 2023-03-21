#ifndef OPERAND_HEADER_FILE
#define OPERAND_HEADER_FILE


#include "AST.h"
#include "Expression.h"
#include <optional>

using namespace std;

namespace miracle {
	class Operand: private AST {
	public:
		Operand(optional<double> number): number(number), expression(nullptr) {}
		Operand(shared_ptr<Expression> expression): number(0), expression(expression) {}

		optional<double> getNumber() const {
			return number;
		}

		const shared_ptr<Expression> getExpression() const {
			return expression;
		}

	private:
		optional<double> number;
		shared_ptr<Expression> expression;
	};
}


#endif
