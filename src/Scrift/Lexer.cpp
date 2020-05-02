/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <fstream>
#include <iostream>
#include <string>
#include <Scrift/Lexer.hpp>
#include <main.h>

FLexer::FLexer() {
	// Initialize all operators and keywords
	operators["+"] = true;
	operators["-"] = true;
	operators["*"] = true;
	operators["/"] = true;
	operators["%"] = true;
	operators["**"] = true;
	operators["="] = true;
	operators["=="] = true;
	operators[">"] = true;
	operators[">="] = true;
	operators["<"] = true;
	operators["<="] = true;
	operators["&&"] = true;
	operators["|"] = true;
	operators["||"] = true;
	operators["..."] = true;
	operators[".."] = true;
	operators["."] = true;
	operators["{"] = true;
	operators["}"] = true;
	operators[":"] = true;
	operators["++"] = true;
	operators["--"] = true;

	keywords["if"] = true;
	keywords["else"] = true;
	keywords["var"] = true;
	keywords["class"] = true;
	keywords["static"] = true;
	keywords["return"] = true;
	keywords["for"] = true;
	keywords["in"] = true;
}

std::vector<Token> FLexer::parse_file() {
	std::vector<Token> result;
    
	std::ifstream file("test.scr"); // For testing

    while (std::getline(file, this->row)) // GetLine input.
    {
    	std::cout << this->row << std::endl;

    	this->index = 0;

    	while (true) {
        	Token tok = this->next(); 
        	tok.print();
        	this->index++;

        	if (tok.type == FType::T_EOF) {
        		break;
        	}
        }
    }

    return result;
}

char FLexer::char_at_pos(integer index) {
	if (index >= this->row.size()) {
		return '\0';
	}

	return this->row[index];
}

Token FLexer::next() { 
	this->current = this->char_at_pos(this->index);

	std::cout << "next(): " << this->current;
    slashn

	if (this->current == '\0') {
		return Token::T_EOF();
	}

	// Line endings
	if (this->current == '\n' || this->current == '\r') {
		return Token::T_EOL();
	}

	// Ignore Whitespace
	if (this->current == ' ') {
		return Token::IGNORE();
	}

	// Comments
	if (this->current == '/' && this->char_at_pos(this->index+1) == '/') {
		return this->comment();
	}

	// Names
	// Begins with a char a-Z
	if ((this->current >= 'a' && this->current <= 'z') || (this->current >= 'A' && this->current <= 'Z')) {
		return this->name();
	}

	// Numbers
	if (this->current >= '0' && this->current <= '9') {
		return this->number();
	}

	// Strings
	if (this->current == '\"') {
		return this->string();
	}

	return Token::IGNORE();
}

Token FLexer::comment() { // Comment Line
	while(true) {
		this->index += 1;
		fchar current = this->char_at_pos(this->index + 1);

		if (current == '\n' || current == '\r') {
			break; // or exit
		}
	}

	return Token::T_EOL(); 
}

Token FLexer::name() {  // Will support UTF-8 
	std::string s = &this->current;

	while (true) {
		fchar c = this->char_at_pos(this->index + 1);

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_') {
			s += c;
			this->index += 1;
		} else {
			break;
		}
	}

	if (s == "true" || s == "false") { // True and False boolean
		return Token::BOOL(s);
	}

	return Token::NAME(s);
}


Token FLexer::number() { // Number Function
	std::string s = &this->current;

	while(true) {
		fchar c = this->char_at_pos(this->index + 1);

		if ((c < '0' || c > '9') && c != '.') {
			break;
		}


		if (c == '.') {
			char cc = this->char_at_pos(this->index + 2);

			if (cc < '0' || cc > '9') {
				break;
			}
		}

		this->index += 1;
		s += c;
	}

    // TODO: Decimals

	return Token::NUMBER(s);
}

Token FLexer::string() {
	std::string s = &this->current;

	this->index += 1;

	while(true) {

		// End of string
		if (this->char_at_pos(this->index) == '"') {
			break;
		}

		// Escaping function variable
		if (this->char_at_pos(this->index) == '\\') {
			this->index += 1;
		}
        // CharAtPos
		s += this->char_at_pos(this->index);
		this->index += 1;
	}

	return Token::STRING(s);
}

Token FLexer::oper() {
	std::string s = &this->current;

	while(true) {

		fchar next = this->char_at_pos(this->index + 1);

		// EOF
		if (next == '\0') {
			break;
		}

		std::string combined = s + next;

		s += next;
		this->index += 1;
	}

	return Token::OPERATOR(s);
}