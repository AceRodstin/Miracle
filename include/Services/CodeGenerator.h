//
//  CodeGenerator.h
//  Miracle
//
//  Created by Ace Rodstin on 3/23/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef CODE_GENERATOR_HEADER_FILE
#define CODE_GENERATOR_HEADER_FILE


#include "AST/Expression.h"
#include "AST/UnaryExpression.h"
#include "AST/Operand.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"

using namespace llvm;
using namespace orc;

namespace miracle {
	class CodeGenerator {
	public:
		CodeGenerator(DataLayout& dataLayout);

		ThreadSafeModule generate(string functionName, shared_ptr<Expression> expression);

	private:
		unique_ptr<LLVMContext> context;
		unique_ptr<Module> module;
		IRBuilder<> builder;

		Value* generate(shared_ptr<Expression> expression);
		Value* generate(shared_ptr<UnaryExpression> unaryExpression);
	};
}


#endif