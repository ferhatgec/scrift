/* MIT License
#
# Copyright (c) 2020-2022 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <src/Scrift.hpp>
#include <src/Syntax/Settings.hpp>
#include <src/Syntax/GetNameFunction.hpp>
#include <unistd.h>

void
FGetUsername::InitUsername() {
// #if defined(_WIN32) || defined(_WIN64)
    // std::cout << std::getenv("USERNAME");
// #else
    std::cout << std::getenv("USER");
// #endif
}

void
FGetUsername::InitHostname() {
// #if defined(_WIN32) || defined(_WIN64)
    // std::cout << std::getenv("COMPUTERNAME");
// #else
    FCHAR hostname[LIMIT];
    gethostname(hostname, LIMIT);
    std::cout << hostname;
// #endif
}

void
FStructure::Terminal(bool incognito) {
    this->customize.Customize(incognito);
}
