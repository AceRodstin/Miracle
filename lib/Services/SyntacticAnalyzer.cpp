//
//  SyntacticAnalyzer.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/SyntacticAnalyzer.h"

using namespace miracle;

SyntacticAnalyzer::SyntacticAnalyzer(TokensParser& tokensParser): tokensParser(tokensParser) {}

shared_ptr<Expression> SyntacticAnalyzer::parse() {
	auto result = parseExpression();
	return move(result);
};

shared_ptr<Expression> SyntacticAnalyzer::parseExpression() {
	auto unaryExpression = parseUnaryExpression();
	auto token = getToken();
	auto precedence = getPrecedence(token);

	if (auto binaryOperator = parseBinaryOperator(token)) {
		auto lhs = make_shared<Expression>(unaryExpression);
		return parseExpression(precedence, lhs, binaryOperator);
	} else {
		return make_shared<Expression>(unaryExpression);
	}
}

shared_ptr<Expression> SyntacticAnalyzer::parseExpression(Precedence precedence, shared_ptr<Expression> lhs, shared_ptr<BinaryOperator> binaryOperator) {
	auto unaryExpression = parseUnaryExpression();
	auto rhs = make_shared<Expression>(unaryExpression);
	auto token = getToken();

	if (auto nextBinaryOperator = parseBinaryOperator(token)) {
		auto nextPrecedence = getPrecedence(token);

		if (precedence < nextPrecedence) {
			auto right = parseExpression(nextPrecedence, rhs, nextBinaryOperator);
			return make_shared<Expression>(lhs, binaryOperator, right);
		} else {
			auto left = make_shared<Expression>(lhs, binaryOperator, rhs);
			return parseExpression(nextPrecedence, left, nextBinaryOperator);
		}
	} else {
		return make_shared<Expression>(lhs, binaryOperator, rhs);
	}
}

shared_ptr<Expression> SyntacticAnalyzer::parseUnaryExpression() {
	shared_ptr<UnaryExpression> unaryExpression;
	auto token = getToken();

	if (auto unaryOperator = parseUnaryOperator(token)) {
		auto nextToken = getToken();
		auto operand = parseOperand(nextToken);
		unaryExpression = make_shared<UnaryExpression>(unaryOperator, operand);
	} else {
		auto operand = parseOperand(token);
		unaryExpression = make_shared<UnaryExpression>(nullptr, operand);
	}

	return unaryExpression;
}

shared_ptr<UnaryOperator> SyntacticAnalyzer::parseUnaryOperator(Token token) {
	auto kind = token.getKind();

	if (kind != Token::Kind::_operator) {
		return nullptr;
	}

	auto op = token.getOperator();
	shared_ptr<UnaryOperator> result;

	switch (op) {
	case Operator::plus:
	case Operator::minus:
		result = make_shared<UnaryOperator>(op);
		break;
	default:
		result = nullptr;
		break;
	}

	return result;
}

shared_ptr<BinaryOperator> SyntacticAnalyzer::parseBinaryOperator(Token token) {
	auto kind = token.getKind();

	if (kind == Token::Kind::_operator) {
		auto op = token.getOperator();
		return make_shared<BinaryOperator>(op);
	} else {
		return nullptr;
	}
}

shared_ptr<Operand> SyntacticAnalyzer::parseOperand(Token token) {
	shared_ptr<Operand> operand;
	auto kind = token.getKind();

	switch (kind) {
	case Token::Kind::number: {
		auto number = token.getNumber();
		operand = make_shared<Operand>(number);
		break;
	}
	case Token::Kind::punctuator: {
		auto expression = parseExpression();
		operand = make_shared<Operand>(expression);
		break;
	}
	default:
		break;
	}

	return operand;
}

SyntacticAnalyzer::Precedence SyntacticAnalyzer::getPrecedence(Token token) {
	Precedence precedence;
	auto kind = token.getKind();

	switch (kind) {
	case Token::Kind::number:
		precedence = 1;
		break;
	case Token::Kind::_operator:
		precedence = getPrecedence(token.getOperator());
		break;
	case Token::Kind::punctuator:
		precedence = getPrecedence(token.getPunctuator());
		break;
	default:
		break;
	}

	return precedence;
}

SyntacticAnalyzer::Precedence SyntacticAnalyzer::getPrecedence(Operator op) {
	switch (op) {
	case Operator::plus:
		return 2;
	case Operator::minus:
		return 2;
	case Operator::multiplication:
		return 3;
	case Operator::division:
		return 3;
	}
}

SyntacticAnalyzer::Precedence SyntacticAnalyzer::getPrecedence(Punctuator punctuator) {
	Precedence precedence;

	switch (punctuator) {
	case Punctuator::left_parenthesis:
	case Punctuator::right_parenthesis:
		precedence = 1;
		break;
	}

	return precedence;
}

Token SyntacticAnalyzer::getToken() {
	return tokensParser.getToken();
}
