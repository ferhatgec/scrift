#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "../main.h"
#include "../File/File.h"
#include "../File/Sync.h"
#include "../Syntax/Syntax.h"
#include "../File/Path.h"



class FDirectory {
public:
    FDirectory();
    ~FDirectory();
    FSync *__sync__file = new FSync();
    file_sync_t *___file_;
    void SetDir(char *_dir, char *_child_dir) 
    {
        __sync__file->DirSync(_dir, _child_dir);
    }

protected:
    char *_default_dir = ___file_->default_file_sync_path;
    bool listed_ = true;
};











#endif // DIRECTORY_H 

