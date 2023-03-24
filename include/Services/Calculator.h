//
//  Calculator.h
//  Miracle
//
//  Created by Ace Rodstin on 3/24/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef CALCULATOR_HEADER_FILE
#define CALCULATOR_HEADER_FILE


#include <string>
#include <memory>
#include "Services/JIT.h"

using namespace std;

namespace miracle {
	class Calculator {
	public:
		Calculator();

		double calculate(string expression);

	private:
		unique_ptr<JIT> jit;
	};
}


#endif