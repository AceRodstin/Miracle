#ifndef BINARY_OPERATOR_HEADER_FILE
#define BINARY_OPERATOR_HEADER_FILE


#include "Node.h"
#include "Operator.h"

using namespace std;

namespace miracle {
	class BinaryOperator: public Node {
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
