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

// определить target machine +
// создать JIT +
// Create module, context, builder
// Generate code
// Add module to jit
// выполнить расчет
// вывести результат

// Создать контекст
// Создать модуль
// Создать билдер
// Сгенерировать код
// Добавить модуль в JIT
// Найти в JIT метод и считать возвращенное значение
// Вывести результат

string requestExpression() {
	cout << "Enter the expression> ";
	string expression;
	getline(cin, expression);
	return expression;
}

int main() {
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();

	auto jit = JIT::create();
	auto dataLayout = jit->getDataLayout();

	auto expression = requestExpression();

	TokensParser tokensParser { expression };

	SyntacticAnalyzer syntacticAnalyzer { tokensParser };
	auto tree = syntacticAnalyzer.parse();
		
	CodeGenerator codeGenerator { dataLayout };
	string functionName = "calculate";
	auto module = codeGenerator.generate(functionName, tree);

	jit->addModule(move(module));

	auto symbol = jit->lookup(functionName);
	auto address = symbol.getAddress();
	auto calculate = jitTargetAddressToFunction<double (*)()>(address);
	auto result = calculate();

	cout << "Result: " << result << endl;
	return 0;
}
