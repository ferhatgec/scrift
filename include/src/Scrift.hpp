/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
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

#define SCRIFT_VERSION "0.1.4"

#define ARROW_UP    72

#define ARROW_LEFT  75

#define ARROW_RIGHT  77

#define ARROW_DOWN  80


class FMain {
public:
    FMain();
    destructor FMain();
    virtual func Shell();
    boolean    _home;
    fstr header_string;
    fstr str;
    fstr _h_str;
    fstr strfor_h_str;
};

#endif // SCRIFT_HPP
