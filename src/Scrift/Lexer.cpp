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
