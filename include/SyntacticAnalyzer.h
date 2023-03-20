#ifndef SYNTACTIC_ANALYZER_HEADER_FILE
#define SYNTACTIC_ANALYZER_HEADER_FILE


#include <memory>
#include <string>
#include "TokensParser.h"
#include "Tree/Node.h"
#include "Tree/Expression.h"

using namespace std;

namespace miracle {
	class SyntacticAnalyzer {
	public:
		SyntacticAnalyzer(TokensParser& tokensParser): tokensParser(tokensParser) {}

		shared_ptr<Expression> parse() {
			auto result = parseExpression();
			return move(result);
		};

	private:
		TokensParser& tokensParser;
		Token token = Token::endOfInput;

		shared_ptr<UnaryExpression> parseUnaryExpression() {
			auto value = tokensParser.getNumberValue();
			auto result = make_shared<UnaryExpression>(value);
			advance();
			return result;
		}

		shared_ptr<Expression> parseExpression() {
			auto unaryExpression = parseUnaryExpression();
			auto result = make_shared<Expression>(unaryExpression, nullptr, nullptr, nullptr);
			return result;










			// Объявить метод, который возвращает опциональный следующий оператор
			// Если оператор существует
			// Если порядок следующего оператора выше, то вернуть lhs + (lhs * rhs)
			// Иначе вернуть lhs + rhs
			// Если оператор отсутсвует, то вернуть lhs
		}



		void advance() {
			token = tokensParser.getToken();
		}
	};
}


#endif