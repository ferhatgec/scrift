/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef INSTRUCTION_FUNCTION_HPP
#define INSTRUCTION_FUNCTION_HPP

#include <cstring>
#include <iostream>
#include <vector>
#include "Value.hpp"
#include "../Lexer/Tokenizer.hpp"

enum class EInstruction {
	// name, right
	ASSIGN,
	SET,

	// value
	LITERAL,

	// name
	NAME,

	// left, right, name (the operator)
	MATH,

	// left (true), right (false), center (the if-statement)
	IF,

	// Nothing, indicates an empty instruction in case of failure
	IGNORE,

	// left (the class to push), right (what comes after)
	PUSH_CLASS,

	// left (the method name), right (the parameters)
	CALL,

	// name, right
	DEFINE_CLASS,

	// right (the content)
	FUNCTION,

	// name (the name), right (the default value)
	FUNCTION_PARAMETER,

	// right
	CREATE_INSTANCE,

	// left (the condition), right (the content)
	WHILE,

	// right (the content)
	LIST_CREATE,

	// left (the list), right (what to extract)
	LIST_EXTRACT,

	// right (what to return)
	RETURN,
};


#endif //  INSTRUCTION_FUNCTION_HPP