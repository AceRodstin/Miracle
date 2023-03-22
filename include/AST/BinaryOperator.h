//
//  BinaryOperator.h
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef BINARY_OPERATOR_HEADER_FILE
#define BINARY_OPERATOR_HEADER_FILE


#include "AST.h"
#include "Models/Operator.h"

namespace miracle {
	class BinaryOperator: public AST {
	public:
		BinaryOperator(Operator op);

		Operator getOperator() const;

	private:
		Operator _operator;
	};
}


#endif