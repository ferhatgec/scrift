/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>

enum class FType {
	T_EOF, // eof
	T_EOL, // eol
	IGNORE, // ignore
	STRING, // str
	NUMBER, // number
	KEYWORD, // keyword
	OPERATOR, // operator
	NAME, // name
	BOOL // boolean
};

struct Token {
	public:
		FType type; // Type
		std::string value; // Value

		static Token T_EOF(); // Enum T_EOF
		static Token T_EOL(); // Enum T_EOL
		static Token IGNORE(); 
		static Token STRING(std::string);
		static Token NUMBER(std::string);
		static Token KEYWORD(std::string);
		static Token OPERATOR(std::string);
		static Token NAME(std::string);
		static Token BOOL(std::string);
		void print();
};







#endif // TOKENIZER_HPP