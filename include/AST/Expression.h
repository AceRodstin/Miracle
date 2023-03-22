//
//  Expression.h
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef EXPRESSION_HEADER_FILE
#define EXPRESSION_HEADER_FILE


#include "AST.h"
#include "BinaryOperator.h"

namespace miracle {
	class Expression: public AST {
	public:
		Expression() = default;
		Expression(shared_ptr<Expression> unaryExpression);
		Expression(shared_ptr<Expression> lhs, shared_ptr<BinaryOperator> binaryOperator, shared_ptr<Expression> rhs);

		const shared_ptr<Expression> getUnaryExpression() const;
		const shared_ptr<Expression> getLhs() const;
		const shared_ptr<BinaryOperator> getBinaryOperator() const;
		const shared_ptr<Expression> getRhs() const;

	private:
		shared_ptr<Expression> unaryExpression;
		shared_ptr<Expression> lhs;
		shared_ptr<BinaryOperator> binaryOperator;
		shared_ptr<Expression> rhs;
	};
}


#endif