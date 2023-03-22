//
//  TokensParser.h
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#ifndef TOKENS_PARSER_HEADER_FILE
#define TOKENS_PARSER_HEADER_FILE


#include <string>
#include <sstream>
#include <cctype>
#include <optional>
#include <algorithm>
#include <map>
#include "Models/Token.h"
#include "Models/Operator.h"
#include "Models/Punctuator.h"

using namespace std;

namespace miracle {
	class TokensParser {
	public:
		TokensParser(string source);

		Token getToken();

	private:
		stringstream stream;

		map<char, Operator> operators {
			{ '+', Operator::plus },
			{ '-', Operator::minus },
			{ '*', Operator::multiplication },
			{ '/', Operator::division }
		};

		map<char, Punctuator> punctuators {
			{ '(', Punctuator::left_parenthesis },
			{ ')', Punctuator::right_parenthesis }
		};

		char getCharacter();
		double getNumber(char character);
		optional<Operator> getOperator(char character);
		optional<Punctuator> getPunctuator(char character);
	};
}


#endif