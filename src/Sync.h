#ifndef SYNC_H
#define SYNC_H

#include "main.h"
#include "File.h"
#include <fstream>
//char *username; 


class FSync {
public:
    FSync();
    ~FSync();
    virtual void DirSync(char *default_dir);
    virtual void GetUsername(char *uname);
private:
    char *_def_dir;
    uint64_t _def_dir_size;
    char *def_username_;
};

#endif //SYNC_H