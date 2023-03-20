#ifndef UNARY_EXPRESSION_HEADER_FILE
#define UNARY_EXPRESSION_HEADER_FILE


#include "Node.h"

using namespace std;

namespace miracle {
	class UnaryExpression: public Node {
	public:
		UnaryExpression(double value): value(value) {}

		double getValue() const {
			return value;
		}

	private:
		double value;
	};
}


#endif
