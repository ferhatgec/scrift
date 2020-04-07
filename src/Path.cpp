/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#include "../include/src/Path.h"
#include <algorithm>
#include <iterator>

// typedef std::vector<std::string> str_vector;




FPath::FPath()
{
    _path = "";
}

FPath::~FPath()
{
    delete[] _path;
}


void
FPath::FPathDir(const char *_dir)
{
    _dir = _path; 
}

void
FPath::FSetPath(std::string& dirname, vec& vdir)
{
    dirname = _path;
    FPath *file_path = new FPath();
    file_path->read_dir(dirname, vdir);
}


/*

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
*/


