/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SCRIFT_HPP
#define SCRIFT_HPP

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include "synflang.hpp"
#include "Syntax/CommandFunc.h"

#define slashn printlnf("\n");

#define typest typedef struct
#define func void
#define fstr std::string
#define destructor ~

#define printhyphen printlnf("-");
#define hyphen "-"

#define SCRIFT_VERSION "0.1.7"
#define SCRIFT_STATUS "beta-3"


// Input Definitions
#define ARROW_UP    65
#define ARROW_LEFT  68
#define ARROW_RIGHT  67
#define ARROW_DOWN  66
#define BACKSPACE 127

class FMain {
public:
    FMain();
    ~FMain();
    /* Dynamic titles. */
    void SetTitle();
    
    /* Shell */
    void Shell();
    
    /* Input, directory variables. */
    std::string header_string;
    std::string str;
    std::string _h_str;
    std::string strfor_h_str;
    bool _home;
};

#endif // SCRIFT_HPP
