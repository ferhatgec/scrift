/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef SYNC_H
#define SYNC_H
#include <sstream>
#include <cpuid.h>
#include "main.h"
#include "File.h"
#include <fstream>
#include <math.h>
//char *username; 


class FSync {
public:
    FSync();
    ~FSync();
    virtual void DirSync(char *default_dir, char *parent_dir);
    virtual void GetUsername(char *uname);
private: 
    char *_def_dir;
    uint64_t _def_dir_size;
    char *def_username_;
};

#endif //SYNC_H
