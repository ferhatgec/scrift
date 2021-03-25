/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <string>
#include <sstream>

#include <src/Scrift.hpp>
#include <src/Syntax/Alias.hpp>

#include <StringTools.h>
#include <FileSystemPlusPlus.h>

/* syntax:
   * command='whatever you want to execute'
   *
*/
std::string
FAlias::Parse(std::string inputted_command) {
    Init();

    std::string data = fsplusplus::FindStringWithReturn(STR(getenv("HOME")) + "/.scrift_aliases",
        (stringtools::GetFirstArg(inputted_command) + "='"));

    data = stringtools::GetBetweenString(data, stringtools::GetFirstArg(inputted_command)    + "='", "'");

    if(data.find("#<<")) {
        stringtools::replaceAll(data, "#<<",
            inputted_command.erase(0, stringtools::GetFirstArg(inputted_command).length() + 1));
    }

    return data;
}

void
FAlias::AddAlias(std::string name, std::string replacement) {
    std::string data = fsplusplus::FindStringWithReturn(STR(getenv("HOME")) + "/.scrift_aliases",
        name + "='");
    
    
    if(data == "null") {
        std::ofstream alias;
        
        alias.open((STR(getenv("HOME")) + "/.scrift_aliases").c_str(), std::ios_base::app); // append instead of overwrite
    
        alias << name + "='" + replacement + "'\n";
    
        alias.close();
    
        return;
    }
    
    std::ifstream readfile(STR(getenv("HOME")) + "/.scrift_aliases");
    
    std::string line, _repl_data;

    /* Read file line-by-line with alias replacement */ 
    if(readfile.is_open()) {
        while (std::getline(readfile, line)) {
            if(line == data) {
                line = name + "='" + replacement + "'";
            }
            
            _repl_data.append(line + "\n");
        }
    }
    
    readfile.close();
    
    std::remove((STR(getenv("HOME")) + "/.scrift_aliases").c_str());
    
    fsplusplus::CreateFile(STR(getenv("HOME")) + "/.scrift_aliases", _repl_data);
    
}


void
FAlias::Init() {
    if(fsplusplus::IsExistFile(STR(getenv("HOME")) + "/.scrift_aliases") == false) {
        fsplusplus::CreateFile(STR(getenv("HOME")) + "/.scrift_aliases", "hello='echo Hello, Scrift!'\n");
    }
}
