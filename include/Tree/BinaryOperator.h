#ifndef BINARY_OPERATOR_HEADER_FILE
#define BINARY_OPERATOR_HEADER_FILE


#include "AST.h"
#include "Operator.h"

using namespace std;

namespace miracle {
	class BinaryOperator: public AST {
	public:
		BinaryOperator(Operator op): _operator(op) {}

		Operator getOperator() const {
			return _operator;
		}

	private:
		Operator _operator;
	};
}


#endif
