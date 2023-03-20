#include <iostream>
#include <string>
#include "TokensParser.h"
#include "SyntacticAnalyzer.h"

using namespace miracle;
using namespace std;

// Задача - написать JIT калькулятор с учетом граматики языка

string calculate(string expression) {
	TokensParser tokensParser { expression };

	SyntacticAnalyzer syntacticAnalyzer { tokensParser };
	auto tree = syntacticAnalyzer.parse();

	return "";

	// Executor executor { tree };
	// double result = executor.execute();

	// Format result as 1.00
	// return formattedResult;
}

int main() {
	while (true) {
		cout << "Enter the expression> ";

		string expression;
		cin >> expression;

		if (cin.eof()) {
			break;
		} else {
			auto result = calculate(expression);
			cout << "Result: " << result << endl;
		}
	}

	return 0;
}