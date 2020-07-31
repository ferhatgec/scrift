/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <Syntax/CommandFunc.h>
#include <Syntax/GetNameFunction.hpp>
#include <pwd.h>
#include <Syntax/Settings.hpp>

// Library
#include "../../Library/Colorized.hpp"

FCommand *terminal = new FCommand();
FSettings *fsettings = new FSettings();
FStructure::FStructure() { }
FGetUsername usr;
uid_t uid = geteuid();
struct passwd *password = getpwuid(uid);

FStructure::~FStructure() {
    delete terminal;
}

void
FGetUsername::InitUsername() {
    //#ifdef __linux__ 
    if(password) {
        printlnf(password->pw_name);
    }
   //#else 
   // slashn 
   // printlnf("Fegeya Fusion Username: 'user'");
   // #endif
}

void
FGetUsername::GetUsername() {
    InitUsername();
}


void 
FGetUsername::InitHostname() {
    fchar hostname_buffer[256];
    gethostname(hostname_buffer, sizeof(hostname_buffer));
    printlnf("%s", hostname_buffer);
}
std::string uname(password->pw_name);
std::string customize = fsettings->InputCustomize();
void
FStructure::Terminal() {
    BOLD_BLUE_COLOR
    std::cout << uname;
    BOLD_CYAN_COLOR
    std::cout << "@";
    BOLD_MAGENTA_COLOR
    usr.InitHostname();
    BOLD_CYAN_COLOR
    std::cout << ":~";
    BOLD_YELLOW_COLOR
    std::cout << terminal->_file_path_cd_function << " ";
    BOLD_RED_COLOR
    // std::cout << "$# ";
    std::cout << customize << " ";
    BLACK_COLOR
}
