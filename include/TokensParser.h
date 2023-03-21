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
				numberValue = getNumber(got);
				return Token::number;
			}

			if (auto op = getOperator(got)) {
				_operator = op;
				return Token::_operator;
			}

			if (auto punctuator = getPunctuator(got)) {
				this->punctuator = punctuator;
				return Token::punctuator;
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

		Punctuator getPunctuator() const {
			return punctuator.value();
		}

	private:
		stringstream stream;
		double numberValue; // TODO: move to token
		optional<Operator> _operator; // TODO: move to token
		optional<Punctuator> punctuator; // TODO: move to token

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
			char got = getCharacter();

			while (isdigit(got) || got == '.') {
				numberLiteral += got;
				got = getCharacter();
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