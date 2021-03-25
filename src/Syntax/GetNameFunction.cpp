/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <pwd.h>
#include <src/Syntax/Settings.hpp>
#include <src/Syntax/CommandFunc.hpp>
#include <src/Syntax/GetNameFunction.hpp>
#include <src/Syntax/Tools.hpp>

// Library

FTools tools;
FCommand *terminal = new FCommand();
FSettings *fsettings = new FSettings();
FStructure::FStructure() = default;
FGetUsername usr;
uid_t uid = geteuid();
struct passwd *password = getpwuid(uid);

FStructure::~FStructure() {
    delete terminal;
}

void
FGetUsername::InitUsername() {
    if(password)
        printlnf(password->pw_name);
}


void
FGetUsername::InitHostname() {
    fchar hostname_buffer[256];
    gethostname(hostname_buffer, sizeof(hostname_buffer));
    printlnf("%s", hostname_buffer);
}

std::string uname(password->pw_name);

void
FStructure::Terminal(bool incognito) {
    fsettings->Customize(incognito);
}
