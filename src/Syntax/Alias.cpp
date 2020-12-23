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
        inputted_command + "='");

    data = stringtools::GetBetweenString(data, inputted_command + "='", "'");

    return data;
}
void
FAlias::Init() {
    if(fsplusplus::IsExistFile(STR(getenv("HOME")) + "/.scrift_aliases") == false) {
        fsplusplus::CreateFile(STR(getenv("HOME")) + "/.scrift_aliases", "hello='echo Hello, Scrift!'");
    }
}
