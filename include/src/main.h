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

class FMain {
public:
    FMain();
    ~FMain();
    virtual void Shell();
   // virtual void Log();
    boolean    _home;
    std::string header_string;
    std::string str;
    std::string _h_str;
    std::string strfor_h_str;
};





#endif // MAIN_H
