/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include "../synflang.hpp"
class FFile  {
public:
    FFile();
    ~FFile(); 

private:
    fchar *_path;
    uinteger64 _size;
};
















#endif  // FILE_H
