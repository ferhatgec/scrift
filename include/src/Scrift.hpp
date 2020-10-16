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

#define SCRIFT_VERSION "0.1.8"
#define SCRIFT_STATUS "beta-2"


// Input Definitions
#define ARROW_UP    65
#define ARROW_LEFT  68
#define ARROW_RIGHT  67
#define ARROW_DOWN  66
#define BACKSPACE 127

inline std::string STR(const char* _ch) {
	return (std::string)_ch;
}


class FMain {
public:
    FMain();
    ~FMain();
    /* Dynamic titles. */
    void SetTitle();
    
    /* Shell */
    void Shell();
    
    std::string Time();

    /* Input, directory variables. */
    std::string header_string;
    std::string str;
    std::string _h_str;
    std::string strfor_h_str;
    bool _home;
};

#endif // SCRIFT_HPP
