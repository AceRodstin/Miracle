//
//  Operand.h
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef OPERAND_HEADER_FILE
#define OPERAND_HEADER_FILE


#include "AST.h"
#include "Expression.h"
#include <optional>

namespace miracle {
	class Operand: private AST {
	public:
		Operand(optional<double> number);
		Operand(shared_ptr<Expression> expression);

		optional<double> getNumber() const;
		const shared_ptr<Expression> getExpression() const;

	private:
		optional<double> number;
		shared_ptr<Expression> expression;
	};
}


#endif