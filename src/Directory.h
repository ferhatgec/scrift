#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "main.h"
#include "File.h"
#include "Sync.h"
#include "Syntax.h"
#include "Path.h"

file_sync_t *___file_;
FSync *__sync__file = new FSync();

class FDirectory {
public:
    FDirectory();
    ~FDirectory();
    void SetDir(char *_dir, char *_child_dir) 
    {
        __sync__file->DirSync(_dir, _child_dir);
    }

protected: 
    char *_default_dir = ___file_->default_file_sync_path;
    bool listed_ = true;
};











#endif // DIRECTORY_H 

