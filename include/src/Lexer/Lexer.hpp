/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef LEXER_HPP
#define LEXER_HPP

#include "../Scrift.hpp"
#include "../Syntax/Colors.hpp"
#include "../synflang.hpp"

struct LexerKeywords {
public:
	// Comments
	std::string CommentLines = "#";
	std::string MultiLineCommentLinesBegin = "#*";
	std::string MultiLineCommentLinesEnd = "*#";
	
	// Printlnf
	std::string Printlnf = "printlnf";
	
	// Colors
	std::string RedColor = "red";
	std::string GreenColor = "green";
	std::string BlueColor = "blue";
	
	// Input 
	std::string Input = "input";
	
	// Variable
	std::string Integer = "integer";
	
	// Arrow Type
	std::string ArrowType = "->";
	
	// Date
	std::string Date = "DATE";
	
	// Print Input
	std::string PrintInput = "inputpr";
	std::string PrintPl = "plpr";
	std::string PrintFloat = "floatpr";
	std::string PrintInteger = "intpr";
	std::string PrintString = "strpr";
	std::string WhitespaceInput = "wsinput";
	
	// Plus 
	std::string FirstPlus = "fplus";
	std::string SecondPlus = "splus";
	
	// Semicolon
	std::string Semicolon = ";";
	
	// Return
	std::string Return = "return";
	
	// System Integration
	std::string System = "system";
	std::string ChangeShell = "changesh";
	
	// Brackets
	std::string BracketsBegin = "(";
	std::string BracketsEnd = ")";
	
	// String
	std::string String = "string";
	
	
	// Output
	std::string PrintSlashn = "slashn";
	
	// Quotation Marks
	std::string QuotationMarks = "\"";
	
	// Whitespace
	std::string Whitespace = " ";
};

class Lexer {
	LexerKeywords keywords;
public:
	std::string FCommentLines() {
		return keywords.CommentLines;
	}
	
	std::string FMultiLineCommentLinesBegin() {
		return keywords.MultiLineCommentLinesBegin;	
	}
	std::string FMultiLineCommentLinesEnd() {
		return keywords.MultiLineCommentLinesEnd;
	}
	std::string FPrintlnf() {
		return keywords.Printlnf;
	}
	std::string FBracketsBegin() {
		return keywords.BracketsBegin;
	}
	std::string FBracketsEnd() {
		return keywords.BracketsEnd;
	}
	std::string FQuotationMarks() {
		return keywords.QuotationMarks;
	}
};




#endif // LEXER_HPP
