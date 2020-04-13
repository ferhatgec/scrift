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
#include "../main.h"
#include "File.h"
#include <fstream>
#include <math.h>
//char *username; 


class FSync {
public:
    FSync();
    ~FSync();
    virtual void DirSync(fchar *, fchar *);
    fchar *_def_dir;
    uinteger64 _def_dir_size;
    fchar *def_username_;
};

#endif //SYNC_H
