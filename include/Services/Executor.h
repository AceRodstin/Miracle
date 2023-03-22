//
//  Executor.h
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef EXECUTOR_HEADER_FILE
#define EXECUTOR_HEADER_FILE


#include "AST/Expression.h"
#include "AST/UnaryExpression.h"
#include <memory>

using namespace std;

namespace miracle {
	class Executor {
	public:
		Executor(shared_ptr<Expression> expression);

		double execute();

	private:
		shared_ptr<Expression> expression;

		double execute(shared_ptr<Expression> expression);
		double execute(shared_ptr<UnaryExpression> unaryExpression);
	};
}


#endif