/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include "Sync.h"
#include "main.h"
#include "File.h"

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
    file_sync_t *__file__sync;
    def_username_ =  __file__sync->default_username;
    _def_dir_size = __file__sync->default_file_sync_size_path;
    _def_dir = __file__sync->default_file_sync_path;
}


FSync::~FSync()
{
    delete[] def_username_;
    delete[] _def_dir;
}

void
FSync::DirSync(char *default_dir, char *parent_dir)
{
    parent_dir = getenv("USER");
    default_dir = "/home/", parent_dir;
    
}


void 
FSync::GetUsername(char *uname)
{
   
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
