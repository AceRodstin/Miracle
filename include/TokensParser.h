#ifndef TOKENS_PARSER_HEADER_FILE
#define TOKENS_PARSER_HEADER_FILE


#include <string>
#include <sstream>
#include <cctype>
#include <optional>
#include <algorithm>
#include "Token.h"
#include "Operator.h"

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
				numberValue = getNumber(got);
				return Token::number;
			}

			if (auto op = getOperator(got)) {
				_operator = op;
				return Token::_operator;
			}

			if (stream.eof()) {
				return Token::endOfInput;
			} else {
				return Token::unknown;
			}
		}

		double getNumberValue() const {
			return numberValue;
		}

		Operator getOperator() const {
			return _operator.value();
		}

	private:
		stringstream stream;
		double numberValue;
		optional<Operator> _operator;

		char getCharacter() {
			return stream.get();
		}

		double getNumber(char character) {
			string numberLiteral = { character, 0 };
			char got = getCharacter();

			while (isdigit(got) || got == '.') {
				numberLiteral += got;
				got = getCharacter();
			}

			auto result = stod(numberLiteral);
			return result;
		}

		optional<Operator> getOperator(char character) {
			auto predicate = [=](auto pair) {
				return pair.second == character;
			};

			auto op = find_if(operators.begin(), operators.end(), predicate);

			if (op == operators.end()) {
				return {};
			} else {
				return op->first;
			}
		}
	};
}


#endif