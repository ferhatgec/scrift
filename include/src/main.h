/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include "Syntax/Syntax.h"
#include "File/Path.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "File/Sync.h"
#include <iomanip>

#define TR_ 1
#define FL_ 0

typedef struct {
public:
 char *err_str = "ERROR - string is not declared";
 char *err_syn = "ERROR - syntax is undefined";
 char *err_ls  = "There is no such directory";
 char *_help_str_ = "help arguments: "
    "echo <arg>"
    "<intnumber> plus <intnumber>"
    "./<file>"
    "exit"
    "cd <folder>";
 char *_func_err_ = "Function calling error";
}help_str;


//FSync *fsync__ = new FSync();

class FMain  {
public:
    FMain();
    ~FMain();

};





#endif // MAIN_H