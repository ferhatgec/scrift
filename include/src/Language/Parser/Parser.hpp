/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <unordered_map>
#include <vector>
#include <cstring>
#include "../Lexer/Tokenizer.hpp"

enum class ParserONConf {
    DEFAULT,
    MATH_CONTINUATION,
    MATH_NEG, 
    PUSH_CLASS,
    FUNCTION_PARAMETER_LIST,
};

class Parser {
public:
    std::vector<lexer::TokenizerType*> token;
    integer index, length;
    boolean advance;
};







#endif // PARSER_HPP