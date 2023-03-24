//
//  main.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "llvm/Support/TargetSelect.h"
#include "llvm/IR/IRBuilder.h"
#include "Services/JIT.h"
#include "Services/TokensParser.h"
#include "Services/SyntacticAnalyzer.h"
#include "Services/CodeGenerator.h"

using namespace miracle;

string requestExpression() {
	cout << "Enter the expression> ";
	string expression;
	getline(cin, expression);
	return expression;
}

double run(JIT& jit, string functionName) {
	auto symbol = jit.lookup(functionName);
	auto address = symbol.getAddress();
	auto calculate = jitTargetAddressToFunction<double (*)()>(address);
	auto result = calculate();
	return result;
}

string format(double value) {
	stringstream stream;
	stream.precision(2);
	stream << value;
	return stream.str();
}

int main() {
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();

	auto jit = JIT::create();
	auto dataLayout = jit->getDataLayout();

	while (true) {
		auto expression = requestExpression();

		if (cin.eof()) {
			break;
		}

		TokensParser tokensParser { expression };

		SyntacticAnalyzer syntacticAnalyzer { tokensParser };
		auto tree = syntacticAnalyzer.parse();
			
		CodeGenerator codeGenerator { dataLayout };
		string functionName = "calculate";
		auto module = codeGenerator.generate(functionName, tree);

		jit->addModule(move(module));
		auto result = run(*jit, functionName);
		jit->remove(functionName);
		auto formattedResult = format(result);

		cout << "Result: " << formattedResult << endl;
	}
	
	return 0;
}
