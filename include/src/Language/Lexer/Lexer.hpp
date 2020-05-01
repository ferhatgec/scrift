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
#include "Tokenizer.hpp"

class FLexer {
    std::unordered_map<std::string, boolean> keyword;
    std::string row;
    size_t index;
    fchar current_index;
    TokenizerType next(void);
    fchar charatpos(size_t);

    TokenizerType* Comment(void);
    TokenizerType* Name(void);
    TokenizerType* Number(void);
    TokenizerType* String(void);
    TokenizerType* Open(void);
    public:
        FLexer();
        std::vector<Token*> parsefile(std::string);
        static void Print(std::vector<Token*>);
};






#endif // LEXER_HPP