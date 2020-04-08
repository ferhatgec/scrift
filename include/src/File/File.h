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

class FFile  {
public:
    FFile();
    ~FFile(); 

private:
    char *_path;
    uint64_t _size;
};
















#endif  // FILE_H
