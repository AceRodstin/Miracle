#ifndef TOKENS_PARSER_HEADER_FILE
#define TOKENS_PARSER_HEADER_FILE


#include <string>
#include <sstream>
#include <cctype>
#include <optional>
#include <algorithm>
#include <map>
#include "Token.h"
#include "Operator.h"
#include "Punctuator.h"

using namespace std;

namespace miracle {
	class TokensParser {
	public:
		TokensParser(string source) {
			stream = stringstream { source };
		}

		Token getToken() {
			char got = getCharacter();

			while (isspace(got)) {
				got = getCharacter();
			}

			if (isdigit(got)) {
				auto value = getNumber(got);
				return { Token::Kind::number, value };
			}

			if (auto op = getOperator(got)) {
				return { op.value() };
			}

			if (auto punctuator = getPunctuator(got)) {
				return { punctuator.value() };
			}

			if (stream.eof()) {
				return { Token::Kind::endOfInput };
			} else {
				return { Token::Kind::unknown };
			}
		}

	private:
		stringstream stream;

		map<char, Operator> operators {
			{ '+', Operator::add },
			{ '-', Operator::subtruct },
			{ '*', Operator::multiply },
			{ '/', Operator::divide }
		};

		map<char, Punctuator> punctuators {
			{ '(', Punctuator::left_parenthesis },
			{ ')', Punctuator::right_parenthesis }
		};

		char getCharacter() {
			return stream.get();
		}

		double getNumber(char character) {
			string numberLiteral = { character, 0 };
			char peeked = stream.peek();

			while (isdigit(peeked) || peeked == '.') {
				auto got = getCharacter();
				numberLiteral += got;
				peeked = stream.peek();
			}

			auto result = stod(numberLiteral);
			return result;
		}

		optional<Operator> getOperator(char character) {
			if (operators.contains(character)) {
				return operators[character];
			} else {
				return {};
			}
		}

		optional<Punctuator> getPunctuator(char character) {
			if (punctuators.contains(character)) {
				return punctuators[character];
			} else {
				return {};
			}
		}
	};
}


#endif