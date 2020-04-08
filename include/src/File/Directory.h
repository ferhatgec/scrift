/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


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
    void SetDir(char *_dir, char *_child_dir) {}

protected:
    bool listed_ = true;
};











#endif // DIRECTORY_H 

