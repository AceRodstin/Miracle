//
//  CodeGenerator.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/24/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/CodeGenerator.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/IR/Verifier.h"

using namespace miracle;

CodeGenerator::CodeGenerator(DataLayout& dataLayout):
	context(make_unique<LLVMContext>()),
	module(make_unique<Module>("<module>", *context)),
	builder(*context),
	passManager(make_unique<legacy::FunctionPassManager>(module.get())) {
		module->setDataLayout(dataLayout);
  		passManager->add(createInstructionCombiningPass());
  		passManager->add(createReassociatePass());
  		passManager->add(createGVNPass());
  		passManager->doInitialization();
}

ThreadSafeModule CodeGenerator::generate(string functionName, shared_ptr<Expression> expression) {
	FunctionType* functionTy = FunctionType::get(Type::getDoubleTy(*context), false);
	Function* function = Function::Create(functionTy, Function::ExternalLinkage, functionName, *module);

	BasicBlock* basicBlock = BasicBlock::Create(*context, "entry", function);
	builder.SetInsertPoint(basicBlock);

	auto value = generate(expression);
	builder.CreateRet(value);
	
	verifyFunction(*function);
	passManager->run(*function);

	return { move(module), move(context) };
}

Value* CodeGenerator::generate(shared_ptr<Expression> expression) {
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

Value* CodeGenerator::generate(shared_ptr<UnaryExpression> unaryExpression) {
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
