#ifndef EXPRESSION_HEADER_FILE
#define EXPRESSION_HEADER_FILE


#include "AST.h"
#include "UnaryExpression.h"
#include "BinaryOperator.h"

using namespace std;

namespace miracle {
	class Expression: public AST {
	public:
		Expression(shared_ptr<UnaryExpression> unaryExpression):
			unaryExpression(unaryExpression),
			lhs(nullptr),
			binaryOperator(nullptr),
			rhs(nullptr) {}

		Expression(shared_ptr<Expression> lhs, shared_ptr<BinaryOperator> binaryOperator, shared_ptr<Expression> rhs):
			unaryExpression(nullptr),
			lhs(lhs),
			binaryOperator(binaryOperator),
			rhs(rhs) {}

		const shared_ptr<UnaryExpression> getUnaryExpression() const {
			return unaryExpression;
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
