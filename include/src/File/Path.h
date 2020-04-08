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
typedef std::vector<std::string> vec;

class FPath {
public:
    FPath();
    ~FPath();
    virtual void FPathDir(const char *_dir);
    virtual void FSetPath(std::string& dirname, vec& vdir);
    void read_dir(const std::string& dirname, vec& v_dir)
    {
        DIR* directory = opendir(dirname.c_str());
        struct dirent *dp;
        while((dp = readdir(directory)) != NULL)
        {
            v_dir.push_back(dp->d_name);
        } 
        closedir(directory);
    }
private:
    char *_path;
};

#endif //PATH_H