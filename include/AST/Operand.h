#ifndef OPERAND_HEADER_FILE
#define OPERAND_HEADER_FILE


#include "AST.h"
#include "Expression.h"
#include <optional>

namespace miracle {
	class Operand: private AST {
	public:
		Operand(optional<double> number);
		Operand(shared_ptr<Expression> expression);

		optional<double> getNumber() const;
		const shared_ptr<Expression> getExpression() const;

	private:
		optional<double> number;
		shared_ptr<Expression> expression;
	};
}


#endif