#ifndef EXPRESSION_HEADER_FILE
#define EXPRESSION_HEADER_FILE


#include "Node.h"
#include "UnaryExpression.h"
#include "BinaryOperator.h"

using namespace std;

namespace miracle {
	class Expression: public Node {
	public:
		Expression(
			shared_ptr<UnaryExpression> unaryExpression,
			shared_ptr<Expression> lhs,
			shared_ptr<BinaryOperator> binaryOperator,
			shared_ptr<Expression> rhs
		):
		unaryExpression(unaryExpression),
		lhs(lhs),
		binaryOperator(binaryOperator),
		rhs(rhs) {}

		const UnaryExpression* getUnaryExpression() const {
			return unaryExpression.get();
		}

		const shared_ptr<Expression> getLhs() const {
			return lhs;
		}

		const shared_ptr<BinaryOperator> getBinaryOperator() const {
			return binaryOperator;
		}

		const shared_ptr<Expression> getRhs() const {
			return rhs;
		}

	private:
		shared_ptr<UnaryExpression> unaryExpression;

		shared_ptr<Expression> lhs;
		shared_ptr<BinaryOperator> binaryOperator;
		shared_ptr<Expression> rhs;
	};
}


#endif
