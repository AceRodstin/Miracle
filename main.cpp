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
#include "Tools.h"
#include "Services/Calculator.h"

using namespace miracle;

string format(double value) {
	stringstream stream;
	stream.precision(2);
	stream << value;
	return stream.str();
}

int main() {
	tools::initializeHost();
	Calculator calculator;

	while (true) {
		cout << "Enter the expression> ";
		string expression;
		getline(cin, expression);

		if (cin.eof()) {
			break;
		}

		auto result = calculator.calculate(expression);
		auto formattedResult = format(result);
		cout << "Result: " << formattedResult << endl;
	}
	
	return 0;
}
