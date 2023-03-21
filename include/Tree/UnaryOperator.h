#ifndef UNARY_OPERATOR_HEADER_FILE
#define UNARY_OPERATOR_HEADER_FILE


#include "AST.h"

using namespace std;

namespace miracle {
	class UnaryOperator: public AST {
	public:
		UnaryOperator(Operator op): _operator(op) {}

		Operator getOperator() const {
			return _operator;
		}

	private:
		Operator _operator;
	};
}


#endif
