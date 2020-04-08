/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include "../../include/src/File/Sync.h"
#include "../../include/src/File/File.h"

/*

typedef struct FileSync {
public:
    char *file_sync_path;
    char *default_file_sync_path = "/home/"; // For Linux and extFS
    char *default_username;
    uint64_t file_sync_size_path; 
    uint64_t default_file_sync_size_path = 16;

/*protected:
    size_t *size_file_sync_path_; not now!
}file_sync_t;*/



FSync::FSync()
{
 
}


FSync::~FSync()
{
}

void
FSync::DirSync(char *default_dir, char *parent_dir)
{
  //  parent_dir = getenv("USER");
    default_dir = "/home/", parent_dir;
    
}





/*
class FSync : public FFile {
public:
    FSync();
    ~FSync();
    virtual void DirSync(char *default_dir);
    virtual void GetUsername(char *def_username);
private:
    char *_def_dir;
    uint64_t *_def_dir_size;
};



*/
