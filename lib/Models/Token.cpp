//
//  Token.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Models/Token.h"

using namespace miracle;

Token::Token(Kind kind): kind(kind) {}

Token::Token(Kind kind, double value): kind(kind), number(value) {}

Token::Token(Operator op): kind(Kind::_operator), _operator(op) {}

Token::Token(Punctuator punctuator): kind(Kind::punctuator), punctuator(punctuator) {}

Token::Kind Token::getKind() const {
	return kind;
}

double Token::getNumber() const {
	return number.value();
}

Operator Token::getOperator() const {
	return _operator.value();
}

Punctuator Token::getPunctuator() const {
	return punctuator.value();
}
