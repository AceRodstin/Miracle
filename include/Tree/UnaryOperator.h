#ifndef UNARY_OPERATOR_HEADER_FILE
#define UNARY_OPERATOR_HEADER_FILE


#include "Node.h"

using namespace std;

namespace miracle {
	class UnaryOperator: public Node {
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
