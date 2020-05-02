/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <unordered_map> 
#include <vector>
#include "Tokenizer.hpp"

class FLexer {
	std::unordered_map<std::string, bool> keywords;
	std::unordered_map<std::string, bool> operators;
	std::string row;
	int index;
	char current;

	Token next(void);
	char char_at_pos(int);

	Token comment(void);
	Token name(void);
	Token number(void);
	Token string(void);
	Token oper(void);

	public:
		Lexer();
		std::vector<Token> parse_file(void);
};









#endif // LEXER_HPP