/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#ifndef MAIN_H
#define MAIN_H

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


#define ARROW_UP    0x48

#define ARROW_LEFT  0x4B

#define ARROW_RIGHT 0x4D

#define ARROW_DOWN  0x50

#define ARROW_NONE  0x00

#define ESC_KEY     0x1B


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





#endif // MAIN_H
