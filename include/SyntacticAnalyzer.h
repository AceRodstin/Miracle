#ifndef SYNTACTIC_ANALYZER_HEADER_FILE
#define SYNTACTIC_ANALYZER_HEADER_FILE


#include <memory>
#include <string>
#include <optional>
#include "TokensParser.h"
#include "Tree/Expression.h"
#include "Tree/Operand.h"

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
		using Precedence = int;

		TokensParser& tokensParser;
		Token token = Token::endOfInput;

		shared_ptr<Expression> parseExpression() {
			auto unaryExpression = parseUnaryExpression();

			if (auto binaryOperator = parseBinaryOperator()) {
				auto lhs = make_shared<Expression>(unaryExpression);
				return parseExpression(0, lhs, binaryOperator);
			} else {
				auto result = make_shared<Expression>(unaryExpression);
				return result;
			}
		}

		shared_ptr<Expression> parseExpression(Precedence precedence, shared_ptr<Expression> lhs, shared_ptr<BinaryOperator> binaryOperator) {
			auto tokenPrecedence = getPrecedence();

			if (tokenPrecedence < precedence) {
				return lhs;
			}

			auto unaryExpression = parseUnaryExpression();
			auto rhs = make_shared<Expression>(unaryExpression);

			if (auto nextBinaryOperator = parseBinaryOperator()) {
				auto nextTokenPrecedence = getPrecedence();

				if (tokenPrecedence < nextTokenPrecedence) {
					auto right = parseExpression(nextTokenPrecedence, rhs, nextBinaryOperator);
					return make_shared<Expression>(lhs, binaryOperator, right);
				} else {
					advance();
					return make_shared<Expression>(lhs, binaryOperator, rhs);
				}
			} else {
				advance();
				return make_shared<Expression>(lhs, binaryOperator, rhs);
			}




			// У токена есть приоритет
			// Распознание выполняется по одному токену, не нужно просматривать весь stream

			// Что такое приоритет выражения? 
			// Чем он отличается от приоритета токена?
			// Можно ли их сравнивать
			// Вопросы безопасности и ханинга
			// Почему возвращается lhs в зависимости от приоритета токена

			// Существует понятие приоритета выражения
			// В качестве выражения может быть lhs
			// Если есть еще токен, входящий в это выражение, то парсинг данного выражения продолжается,
			// Иначе выражение сформировано, возвращается результат
			// Рекурсия!

			
			// Если приоритет токена ниже приоритета выражения, то парсинг выражения завершен
			// Иначе 

			// Ввести понятие приоритета токена

			// 1 + 2 -> null  1 2 1
			// 1 + 2 + 3 -> 1  1 2 1 2 1
			// 1 + 2 * 3 -> 2 1 2 1 3 1
			// 1 + (2 + 3) -> null
			// 1 + (2 * 3) + 4 -> 1





			// Объявить метод, который возвращает опциональный следующий оператор
			// Если оператор существует
			// Если порядок следующего оператора выше, то вернуть lhs + (lhs * rhs)
			// Иначе вернуть lhs + rhs
			// Если оператор отсутсвует, то вернуть lhs
		}

		shared_ptr<UnaryExpression> parseUnaryExpression() {
			auto unaryOperator = parseUnaryOperator();
			auto operand = parseOperand();
			auto unaryExpression = make_shared<UnaryExpression>(unaryOperator, operand);
			advance();
			return unaryExpression;
		}

		shared_ptr<UnaryOperator> parseUnaryOperator() {
			if (token != Token::_operator) {
				return nullptr;
			}

			auto op = tokensParser.getOperator();
			shared_ptr<UnaryOperator> result;

			switch (op) {
			case Operator::add:
			case Operator::subtruct:
				result = make_shared<UnaryOperator>(op);
				break;
			default:
				result = nullptr;
				break;
			}

			advance();
			return result;
		}

		shared_ptr<BinaryOperator> parseBinaryOperator() {
			if (token == Token::_operator) {
				auto result = make_shared<BinaryOperator>(tokensParser.getOperator());
				advance();
				return result;
			} else {
				return nullptr;
			}
		}

		shared_ptr<Operand> parseOperand() {
			shared_ptr<Operand> operand;

			switch (token) {
			case Token::number:
				operand = make_shared<Operand>(tokensParser.getNumberValue());
				break;
			case Token::punctuator: {
				advance(); // Skip left parenthesis
				auto expression = parseExpression();
				operand = make_shared<Operand>(expression);
				break;
			}
			default:
				break;
			}

			advance();
			return operand;
		}

		Precedence getPrecedence() {
			Precedence precedence;

			switch (token) {
			case Token::number:
				precedence = 1;
				break;
			case Token::_operator:
				precedence = getPrecedence(tokensParser.getOperator());
				break;
			case Token::punctuator:
				precedence = getPrecedence(tokensParser.getPunctuator());
				break;
			default:
				break;
			}

			return precedence;
		}

		Precedence getPrecedence(Operator op) {
			switch (op) {
			case Operator::add:
				return 2;
			case Operator::subtruct:
				return 2;
			case Operator::multiply:
				return 3;
			case Operator::divide:
				return 3;
			}
		}

		Precedence getPrecedence(Punctuator punctuator) {
			Precedence precedence;

			switch (punctuator) {
			case Punctuator::left_parenthesis:
			case Punctuator::right_parenthesis:
				precedence = 1;
				break;
			}

			return precedence;
		}

		void advance() {
			token = tokensParser.getToken();
		}
	};
}


#endif