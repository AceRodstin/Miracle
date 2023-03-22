//
//  Calculator.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/Calculator.h"
#include "Services/TokensParser.h"
#include "Services/SyntacticAnalyzer.h"
#include "Services/Executor.h"

using namespace miracle;

double Calculator::calculate(string expression) {
	TokensParser tokensParser { expression };

	SyntacticAnalyzer syntacticAnalyzer { tokensParser };
	auto tree = syntacticAnalyzer.parse();

	Executor executor { tree };
	double result = executor.execute();

	return result;
}