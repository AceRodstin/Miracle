//
//  TokensParser.cpp
//  Miracle
//
//  Created by Ace Rodstin on 3/22/23.
//  Copyright © 2023 Ace Rodstin. All rights reserved.
//

#include "Services/TokensParser.h"

using namespace miracle;

TokensParser::TokensParser(string source) {
	stream = stringstream { source };
}

Token TokensParser::getToken() {
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

char TokensParser::getCharacter() {
	return stream.get();
}

double TokensParser::getNumber(char character) {
	string numberLiteral;
	numberLiteral += character;

	char peeked = stream.peek();

	while (isdigit(peeked) || peeked == '.') {
		auto got = getCharacter();
		numberLiteral += got;
		peeked = stream.peek();
	}

	auto result = stod(numberLiteral);
	return result;
}

optional<Operator> TokensParser::getOperator(char character) {
	if (operators.contains(character)) {
		return operators[character];
	} else {
		return {};
	}
}

optional<Punctuator> TokensParser::getPunctuator(char character) {
	if (punctuators.contains(character)) {
		return punctuators[character];
	} else {
		return {};
	}
}