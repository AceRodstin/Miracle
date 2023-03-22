#ifndef SYNTACTIC_ANALYZER_HEADER_FILE
#define SYNTACTIC_ANALYZER_HEADER_FILE


#include <memory>
#include <string>
#include <optional>
#include "TokensParser.h"
#include "AST/Expression.h"
#include "AST/UnaryExpression.h"
#include "AST/UnaryOperator.h"
#include "AST/Operand.h"

using namespace std;

namespace miracle {
	class SyntacticAnalyzer {
	public:
		SyntacticAnalyzer(TokensParser& tokensParser);

		shared_ptr<Expression> parse();

	private:
		using Precedence = int;

		TokensParser& tokensParser;

		shared_ptr<Expression> parseExpression();
		shared_ptr<Expression> parseExpression(Precedence precedence, shared_ptr<Expression> lhs, shared_ptr<BinaryOperator> binaryOperator);
		shared_ptr<Expression> parseUnaryExpression();
		shared_ptr<UnaryOperator> parseUnaryOperator(Token token);
		shared_ptr<BinaryOperator> parseBinaryOperator(Token token);
		shared_ptr<Operand> parseOperand(Token token);
		Precedence getPrecedence(Token token);
		Precedence getPrecedence(Operator op);
		Precedence getPrecedence(Punctuator punctuator);
		Token getToken();
	};
}


#endif