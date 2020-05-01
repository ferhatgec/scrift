/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <cstring>
#include "Lexer.hpp"


enum class TokenizerType {
        T_EOF,
		T_EOL,

		IGNORE,

		STRING,
		NUMBER,
		NAME,

		BOOL,
		BOOL_TRUE,
		BOOL_FALSE,

		KEYWORD,
		KEYWORD_CLASS,
		KEYWORD_FN,
		KEYWORD_IF,
		KEYWORD_ELSE,
		KEYWORD_NEW,
		KEYWORD_WHILE,
		KEYWORD_RETURN,

		OPERATOR,
	
		OPERATOR_COMMA,         // ,
		OPERATOR_COLON,         // :
		OPERATOR_DOUBLE_COLON,  // :: (OPERATOR_PAAMAYIM_NEKUDOTAYIM)
		OPERATOR_SEMICOLON,     // ;
		OPERATOR_EQ,            // =
		OPERATOR_NOT_EQ,        // !=
		OPERATOR_EQEQ,          // ==
		OPERATOR_GT,            // >
		OPERATOR_GTEQ,          // >=
		OPERATOR_LT,            // <
		OPERATOR_LTEQ,          // <=
		OPERATOR_DOUBLE_AND,    // &&
		OPERATOR_DOUBLE_OR,     // ||
		OPERATOR_PLUS_PLUS,     // ++
		OPERATOR_MINUS_MINUS,   // --
		OPERATOR_PLUS,          // +
		OPERATOR_MINUS,         // -
		OPERATOR_MUL,           // *
		OPERATOR_DIV,           // /
		OPERATOR_DOT,           // .
		OPERATOR_PAREN_L,       // (
		OPERATOR_PAREN_R,       // )
		OPERATOR_CURLYPAREN_L,  // {
		OPERATOR_CURLYPAREN_R,  // }
		OPERATOR_COLON_EQ,      // :=
		OPERATOR_NOT,           // !

		// Ranges
		OPERATOR_2DOT,          // ..
		OPERATOR_3DOT,          // ...

		// List operations
		OPERATOR_SQUARE_PAREN_LEFT,  // [
		OPERATOR_SQUARE_PAREN_RIGHT, // ]
};

typedef struct {
    template <typename Hash>
    std::size_t operator()(Hash h) const
    {
            return static_cast<std::size_t>(h);
    }
} enum_class_hash_function;

typedef struct {
public:
        TokenizerType type;
        TokenizerType subt;
        std::string value;

        TokenizerType(TokenizerType);
        TokenizerType(TokenizerType, std::string);

        TokenizerType();
        static TokenizerType T_EOF();
        static TokenizerType T_EOL();
        static TokenizerType IGNORE();
        static TokenizerType STRING(std::string);
        static TokenizerType NUMBER(std::string);
        static TokenizerType KEYWORD(std::string);
        static TokenizerType OPERATOR(std::string);
        static TokenizerType NAME(std::string);
        static TokenizerType BOOL(std::string);


        std::string PrintFunction();
        static std::string PrintFunction(TokenizerType);
        static TokenizerType Transf(std::string);

} tokenizer_function;

#endif // TOKENIZER_HPP