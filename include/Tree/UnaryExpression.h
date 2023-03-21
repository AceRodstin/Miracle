#ifndef UNARY_EXPRESSION_HEADER_FILE
#define UNARY_EXPRESSION_HEADER_FILE


#include "AST.h"
#include "UnaryOperator.h"
#include "Operand.h"

using namespace std;

namespace miracle {
	class UnaryExpression: private AST {
	public:
		UnaryExpression(shared_ptr<UnaryOperator> unaryOperator, shared_ptr<Operand> operand): unaryOperator(unaryOperator), operand(operand) {}

		const shared_ptr<UnaryOperator> getUnaryOperator() const {
			return unaryOperator;
		}

		const shared_ptr<Operand> getOperand() const {
			return operand;
		}

	private:
		shared_ptr<UnaryOperator> unaryOperator;
		shared_ptr<Operand> operand;
	};
}


#endif
