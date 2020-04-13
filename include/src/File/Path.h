/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */



#ifndef PATH_H
#define PATH_H
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include "../synflang.hpp"
typedef std::vector<std::string> vec;

class FPath {
public:
    FPath();
    ~FPath();
    virtual void FPathDir(const fchar *);
    virtual void FSetPath(std::string&, vec&);
    void read_dir(const std::string&, vec&);
private:
    fchar *_path;
};

#endif //PATH_H