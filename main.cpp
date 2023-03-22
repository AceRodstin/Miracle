#include <iostream>
#include <string>
#include "Services/TokensParser.h"
#include "Services/SyntacticAnalyzer.h"
#include "Services/Executor.h"
#include <sstream>

using namespace miracle;
using namespace std;

string format(double value) {
	stringstream stream;
	stream.precision(2);
	stream << value;
	return stream.str();
}

string calculate(string expression) {
	TokensParser tokensParser { expression };

	SyntacticAnalyzer syntacticAnalyzer { tokensParser };
	auto tree = syntacticAnalyzer.parse();

	Executor executor { tree };
	double result = executor.execute();

	return format(result);
}

int main() {
	while (true) {
		cout << "Enter the expression> ";

		string expression;
		getline(cin, expression);

		if (cin.eof()) {
			break;
		} else {
			auto result = calculate(expression);
			cout << "Result: " << result << endl;
		}
	}

	return 0;
}