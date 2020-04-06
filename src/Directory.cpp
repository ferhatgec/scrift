#include "Directory.h"


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
    delete[] _default_dir;
}



