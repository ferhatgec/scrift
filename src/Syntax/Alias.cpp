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
        (stringtools::getFirstCommand(inputted_command) + "='"));

    data = stringtools::GetBetweenString(data, stringtools::getFirstCommand(inputted_command)    + "='", "'");

    if(data.find("#<<")) {
        stringtools::replaceAll(data, "#<<",
            inputted_command.erase(0, stringtools::getFirstCommand(inputted_command).length() + 1));
    }

    return data;
}
void
FAlias::Init() {
    if(fsplusplus::IsExistFile(STR(getenv("HOME")) + "/.scrift_aliases") == false) {
        fsplusplus::CreateFile(STR(getenv("HOME")) + "/.scrift_aliases", "hello='echo Hello, Scrift!'");
    }
}
