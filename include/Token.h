#ifndef TOKEN_HEADER_FILE
#define TOKEN_HEADER_FILE


#include <optional>
#include "Operator.h"
#include "Punctuator.h"

using namespace std;

namespace miracle {
	class Token {
	public:
		enum class Kind {
			number,
			_operator,
			punctuator,
			endOfInput,
			unknown
		};

		Token(Kind kind): kind(kind) {}
		Token(Kind kind, double value): kind(kind), number(value) {}
		Token(Operator op): kind(Kind::_operator), _operator(op) {}
		Token(Punctuator punctuator): kind(Kind::punctuator), punctuator(punctuator) {}

		Kind getKind() const {
			return kind;
		}

		double getNumber() const {
			return number.value();
		}

		Operator getOperator() const {
			return _operator.value();
		}

		Punctuator getPunctuator() const {
			return punctuator.value();
		}

	private:
		Kind kind;
		optional<double> number;
		optional<Operator> _operator;
		optional<Punctuator> punctuator;
	};
}


#endif