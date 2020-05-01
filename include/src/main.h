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
#define fclass class
#define fvirt virtual 
#define func void 
#define fstr std::string
#define destructor ~

fclass FMain {
public:
    FMain();
    destructor FMain();
    fvirt func Shell();
    boolean    _home;
    fstr header_string;
    fstr str;
    fstr _h_str;
    fstr strfor_h_str;
};





#endif // MAIN_H
