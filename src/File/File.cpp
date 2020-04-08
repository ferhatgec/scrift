/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include "../../include/src/File/File.h"


FFile::FFile()
{
  
   // FFile *file = new FFile();
   // file->Sync(_path, _size);
    
}

FFile::~FFile()
{
    delete[] _path;
}

void
FFile::FileSync(char *path, uint64_t _size)
{
 
}



void
FFile::FFileRead(char *path, char* name)
{

}

void
FFile::FFileWrite(char *path, char *name)
{



}





