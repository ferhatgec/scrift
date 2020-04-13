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

#define TR_ 1
#define FL_ 0
#define _BUILD_CODE_ ""
#define _LINE_SPACE_ "\n"
#define _SPACE_ " "
#define _SCRIFT_ "Scrift" + _SCRIFT_VERS_
#define _SCRIFT_VERS_ " "

typedef struct {
public:
 fchar* err_str = "ERROR - string is not declared";
 fchar* err_syn = "ERROR - syntax is undefined";
 fchar* err_ls  = "There is no such directory";
 fchar* _help_str_ = "help arguments: "
    "echo <arg>"
    "<intnumber> plus <intnumber>"
    "./<file>"
    "exit"
    "cd <folder>";
 fchar* _func_err_ = "Function calling error";
}help_str;


//FSync *fsync__ = new FSync();

class FMain  {
public:
    FMain();
    ~FMain();
};





#endif // MAIN_H
