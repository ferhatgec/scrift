/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <Scrift/Tokenizer.hpp>
#include <Scrift/Lexer.hpp>
#include <iostream>
#include <synflang.hpp>
#include <main.h>


Token Token::T_EOF() {
	Token tok;
	tok.type = FType::T_EOF;
	return tok;
}

Token Token::T_EOL() {
	Token tok;
	tok.type = FType::T_EOL;
	return tok;
}

Token Token::IGNORE() {
	Token tok;
	tok.type = FType::IGNORE;
	return tok;
}

Token Token::STRING(std::string val) {
	Token tok;
	tok.type = FType::STRING;
	tok.value = val;
	return tok;
}

Token Token::NUMBER(std::string val) {
	Token tok;
	tok.type = FType::NUMBER;
	tok.value = val;
	return tok;
}

Token Token::KEYWORD(std::string val) {
	Token tok;
	tok.type = FType::KEYWORD;
	tok.value = val;
	return tok;
}

Token Token::OPERATOR(std::string val) {
	Token tok;
	tok.type = FType::OPERATOR;
	tok.value = val;
	return tok;
}

Token Token::NAME(std::string val) {
	Token tok;
	tok.type = FType::NAME;
	tok.value = val;
	return tok;
}

Token Token::BOOL(std::string val) {
	Token tok;
	tok.type = FType::BOOL;
	tok.value = val;
	return tok;
}

void Token::print() {
    printlnf(this->value.c_str());
    slashn
}

