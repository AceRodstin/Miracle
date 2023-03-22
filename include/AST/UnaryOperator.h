#ifndef UNARY_OPERATOR_HEADER_FILE
#define UNARY_OPERATOR_HEADER_FILE


#include "AST.h"
#include "Models/Operator.h"

namespace miracle {
	class UnaryOperator: public AST {
	public:
		UnaryOperator(Operator op);

		Operator getOperator() const;

	private:
		Operator _operator;
	};
}


#endif