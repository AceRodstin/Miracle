//
//  UnaryExpression.h
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef UNARY_EXPRESSION_HEADER_FILE
#define UNARY_EXPRESSION_HEADER_FILE


#include "AST.h"
#include "UnaryOperator.h"
#include "Operand.h"

namespace miracle {
	class UnaryExpression: public Expression {
	public:
		UnaryExpression(shared_ptr<UnaryOperator> unaryOperator, shared_ptr<Operand> operand);

		const shared_ptr<UnaryOperator> getUnaryOperator() const;
		const shared_ptr<Operand> getOperand() const;

	private:
		shared_ptr<UnaryOperator> unaryOperator;
		shared_ptr<Operand> operand;
	};
}


#endif