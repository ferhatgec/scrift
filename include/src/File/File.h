/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "../Syntax/Syntax.h"
#include "../main.h"
#include "Path.h"
#include <fstream>
#include "Sync.h"
#include <cstring>
#include <string.h>

struct FileSync {
public:
    char *file_sync_path;
    char *default_file_sync_path = "/home/"; // For Linux and extFS
    char *default_username;
    char *default_child_file_sync_path = getenv("USER");
    char *default_lang = "en";
    char *_cpu_name;
    int64_t *ram_size_;
    uint64_t file_sync_size_path; 
    uint64_t default_file_sync_size_path = 16;

/*protected:
    size_t *size_file_sync_path_; not now!*/
};



class FFile  {
public:
    FFile();
    ~FFile(); 
    void FileSync(char *path, uint64_t _size);
    void FFileRead(char *path, char *name);
    void FFileWrite(char *path, char *name);
    void Sync(char *default_path, uint64_t default_size, char *default_username_)
    {
        default_path = "/home/";
        default_path = strcat (default_path, default_username_); // Linux or extFS
        default_size = 16; //byte -> size_t
       
    }

private:
    char *_path;
    uint64_t _size;
};
















#endif  // FILE_H
