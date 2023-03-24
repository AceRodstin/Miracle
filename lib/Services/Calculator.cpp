//
//  Calculator.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/24/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/Calculator.h"
#include "Services/TokensParser.h"
#include "Services/SyntacticAnalyzer.h"
#include "Services/CodeGenerator.h"

using namespace miracle;

Calculator::Calculator(): jit(JIT::create()) {}

double Calculator::calculate(string expression) {
	TokensParser tokensParser { expression };

	SyntacticAnalyzer syntacticAnalyzer { tokensParser };
	auto tree = syntacticAnalyzer.parse();
	
	auto dataLayout = jit->getDataLayout();
	CodeGenerator codeGenerator { dataLayout };
	string functionName = "calculate";
	auto module = codeGenerator.generate(functionName, tree);

	jit->addModule(move(module));
	auto symbol = jit->lookup(functionName);
	auto address = symbol.getAddress();
	auto calculate = jitTargetAddressToFunction<double (*)()>(address);
	auto result = calculate();
	jit->remove(functionName);

	return result;
}