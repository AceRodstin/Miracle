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

using namespace llvm;

namespace miracle {
	class CodeGenerator {
	public:
		CodeGenerator(DataLayout& dataLayout): context(make_unique<LLVMContext>()), module(make_unique<Module>("<module>", *context)), builder(*context) {
			module->setDataLayout(dataLayout);
		}

		ThreadSafeModule generate(string functionName, shared_ptr<Expression> expression) {
			FunctionType* functionTy = FunctionType::get(Type::getDoubleTy(*context), false);
			Function* function = Function::Create(functionTy, Function::ExternalLinkage, functionName, *module);

			BasicBlock* basicBlock = BasicBlock::Create(*context, "entry", function);
			builder.SetInsertPoint(basicBlock);

			auto value = generate(expression);
			builder.CreateRet(value);

			return { move(module), move(context) };
		}

	private:
		unique_ptr<LLVMContext> context;
		unique_ptr<Module> module;
		IRBuilder<> builder;

		Value* generate(shared_ptr<Expression> expression) {
			if (auto expr = expression->getUnaryExpression()) {
				auto unaryExpression = static_cast<UnaryExpression*>(expr.get());
				return generate(make_shared<UnaryExpression>(*unaryExpression));
			}

			auto lhs = generate(expression->getLhs());
			auto binaryOperator = expression->getBinaryOperator();
			auto op = binaryOperator->getOperator();
			auto rhs = generate(expression->getRhs());

			switch (op) {
			case Operator::plus:
				return builder.CreateFAdd(lhs, rhs);
			case Operator::minus:
				return builder.CreateFSub(lhs, rhs);
			case Operator::multiplication:
				return builder.CreateFMul(lhs, rhs);
			case Operator::division:
				return builder.CreateFDiv(lhs, rhs);
			}
		}

		Value* generate(shared_ptr<UnaryExpression> unaryExpression) {
			auto unaryOperator = unaryExpression->getUnaryOperator();
			auto operand = unaryExpression->getOperand();
			auto number = operand->getNumber();

			if (!number.has_value()) {
				return generate(operand->getExpression());	
			}

			auto numberValue = number.value();

			if (unaryOperator != nullptr) {
				auto op = unaryOperator->getOperator();

				if (op == Operator::minus) {
					numberValue = -numberValue;
				}
			}

			return ConstantFP::get(*context, APFloat(numberValue));
		}
	};
}


#endif