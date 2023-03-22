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

		Token(Kind kind);
		Token(Kind kind, double value);
		Token(Operator op);
		Token(Punctuator punctuator);

		Kind getKind() const;
		double getNumber() const;
		Operator getOperator() const;
		Punctuator getPunctuator() const;

	private:
		Kind kind;
		optional<double> number;
		optional<Operator> _operator;
		optional<Punctuator> punctuator;
	};
}


#endif