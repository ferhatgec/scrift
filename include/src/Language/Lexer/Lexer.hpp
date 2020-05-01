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
#include "../../main.h"
class FLexer {
public:
    std::unordered_map<std::string, boolean> keyword;
    std::string row;
    size_t index;
    fchar current_index;
};






#endif // LEXER_HPP