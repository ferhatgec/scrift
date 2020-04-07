/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#include "../../include/src/File/Directory.h"


FDirectory::FDirectory()
{
    FDirectory *f_dir_ = new FDirectory();
    f_dir_->SetDir(_default_dir, NULL);
}


 
FDirectory::~FDirectory()
{
    delete[] _default_dir;
    delete ___file_;
    delete __sync__file;
 //   delete[] _default_dir;
}



