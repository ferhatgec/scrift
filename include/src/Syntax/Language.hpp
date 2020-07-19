/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#include <pwd.h>
#include <vector>

#include "Settings.hpp"
#include "CommandFunc.h"
#include "Log.hpp"
#include "RunFunction.hpp"
#include "FileFunction.hpp"
#include "../Lexer/Lexer.hpp"
#include "../synflang.hpp"
#include "../Scrift.hpp"

// Library
#include "../../../Library/Colorized.hpp"

class FLanguage {
	FCommand *command = new FCommand();
        FRunFunction *run = new FRunFunction();  
        LexerKeywords keyword;
public:
    // Keywords
    std::string name;

    std::string EraseAllSubString(std::string & mainString, const std::string & erase) {
    size_t pos = std::string::npos;
    while((pos = mainString.find(erase)) != std::string::npos) {
        mainString.erase(pos, erase.length());
    }
    return mainString;
    }

    void ReadFunc(std::string filename) {
    if(filename.rfind("#") == 0) {
    	std::string new_name(getenv(EraseAllSubString(filename, "#").c_str()));
    	filename = new_name;
    }
    std::string line;
    
    // For Float function
    float floatvar;

    // Path
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(filename);
    
    std::ifstream readfile(path);
    
    // For Input function
    std::string inputcommand;
    
    integer finteger = 0;
    integer f;
    
    if(readfile.is_open()) {

    while (std::getline(readfile, line)) {
        if(line.find(keyword.PrintSlashn, 0) == 0) {
            slashn
        }

	if(line == keyword.Printlnf + keyword.Whitespace + keyword.ArrowType + keyword.Date) {
		printlnf(__DATE__);	
	} 
	
        if(line.find(keyword.Integer, 0) == 0) {
            finteger = std::atoi(line.erase(0, 8).c_str());
        }
        
        if(line.rfind(keyword.Input, 0) == 0) {
            std::cin >> inputcommand;
        }

        if(line.find(keyword.WhitespaceInput, 0) == 0) {
            std::getline(std::cin, inputcommand);
        }

        if(line == keyword.PrintInput) {
            printlnf(inputcommand.c_str());
        }

        if(line.find(keyword.FirstPlus + keyword.BracketsBegin, 0) == 0) {
            std::string test = EraseAllSubString(line, keyword.FirstPlus + keyword.BracketsBegin);
            test = EraseAllSubString(test, keyword.BracketsEnd + keyword.Semicolon);
            f = std::atoi(test.c_str());
        }

        if(line.find(keyword.SecondPlus + keyword.BracketsBegin, 0) == 0) {
            std::string test = EraseAllSubString(line, keyword.SecondPlus + keyword.BracketsBegin);
            test = EraseAllSubString(test, keyword.BracketsEnd + keyword.Semicolon);
            f = f + std::atoi(test.c_str());
        }

        if(line == keyword.PrintPl) {
            std::cout << f;
        }

        if(line == keyword.Return) {
            return;
        }

        if(line.find(keyword.String, 0) == 0) {
            name = line.erase(0, keyword.String.length());
        }
	
	if(line.find(keyword.BracketsBegin + keyword.GreenColor + keyword.BracketsEnd + keyword.Printlnf + keyword.BracketsBegin, 0) == 0) {
           std::string test = EraseAllSubString(line, keyword.BracketsBegin + keyword.GreenColor + keyword.BracketsEnd + keyword.Printlnf + keyword.BracketsBegin + keyword.QuotationMarks);
           std::cout << WBOLD_GREEN_COLOR << EraseAllSubString(test, keyword.QuotationMarks + keyword.BracketsEnd + keyword.Semicolon) << WBLACK_COLOR;
	}
	
	
	if(line.find(keyword.BracketsBegin + keyword.RedColor + keyword.BracketsEnd + keyword.Printlnf + keyword.BracketsBegin, 0) == 0) {
           std::string test = EraseAllSubString(line, keyword.BracketsBegin + keyword.RedColor + keyword.BracketsEnd + keyword.Printlnf + keyword.BracketsBegin + keyword.QuotationMarks);
           std::cout << WBOLD_RED_COLOR << EraseAllSubString(test, keyword.QuotationMarks + keyword.BracketsEnd + keyword.Semicolon) << WBLACK_COLOR;
	}
		
		
	if(line.find(keyword.ChangeShell + keyword.Whitespace, 0) == 0) {
		std::string chsh = "sudo chsh -s /bin/";
		chsh.append(EraseAllSubString(line, keyword.ChangeShell + keyword.Whitespace));
		chsh.append(" ");
		chsh.append(getenv("USER"));
		system(chsh.c_str());
	}	
		
        if(line.find(keyword.Printlnf + keyword.BracketsBegin + keyword.QuotationMarks, 0) == 0) {
           std::string test = EraseAllSubString(line, keyword.Printlnf + keyword.BracketsBegin + keyword.QuotationMarks);
           std::cout << EraseAllSubString(test, keyword.QuotationMarks + keyword.BracketsEnd + keyword.Semicolon);
        }
							
        if (line == keyword.PrintFloat) {
            std::cout << floatvar;
        }

        if (line.rfind(keyword.PrintInteger, 0) == 0) {
            std::cout << finteger;
        }

        if (line.find(keyword.System, 0) == 0) {
            std::string test = EraseAllSubString(line, keyword.System + keyword.BracketsBegin + keyword.QuotationMarks);
            test = EraseAllSubString(test, keyword.QuotationMarks + keyword.BracketsEnd + keyword.Semicolon);
            run->RunFunction(test);
        }
        if(line.rfind(keyword.PrintString, 0) == 0)
            std::cout << name << "\n";
        }
    }

}

};

#endif // LANGUAGE_HPP

