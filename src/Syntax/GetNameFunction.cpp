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

FStructure::~FStructure() {
    delete terminal;
}

void
FGetUsername::InitUsername() {
    //#ifdef __linux__ 
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
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

std::string customize = fsettings->InputCustomize();
void
FStructure::Terminal() {
    fchar* _username = new fchar;
    BOLD_BLUE_COLOR
    InitUsername();
    BOLD_CYAN_COLOR
    printlnf("@");
    BOLD_MAGENTA_COLOR
    InitHostname();
    BOLD_CYAN_COLOR
    printlnf(":~");
    BOLD_YELLOW_COLOR
    printlnf(terminal->_file_path_cd_function);
    printlnf(" ");
    BOLD_RED_COLOR
    std::cout << customize;
    printlnf(" ");
    BLACK_COLOR
    delete _username;
}
