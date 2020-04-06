#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "Syntax.h"
#include "main.h"
#include "Path.h"
#include <fstream>
#include "Sync.h"
#include <cstring>
#include <string.h>
typedef struct FileSync {
public:
    char *file_sync_path;
    char *default_file_sync_path = "/home/"; // For Linux and extFS
    char *default_username;
    uint64_t file_sync_size_path; 
    uint64_t default_file_sync_size_path = 16;

/*protected:
    size_t *size_file_sync_path_; not now!*/
}file_sync_t;



class FFile  {
public:
    FFile();
    ~FFile(); 
    file_sync_t *file;
    void FileSync(char *path, uint64_t _size);
    void FFileRead(char *path, char *name);
    void FFileWrite(char *path, char *name);
    void Sync(char *default_path, uint64_t default_size, char *default_username_)
    {
        default_username_ = file->default_username; 
        default_path = "/home/";
        default_path = strcat (default_path, default_username_); // Linux or extFS
        default_size = 16; //byte -> size_t
       
    }

private:
    char *_path;
    uint64_t _size;
};
















#endif  // FILE_H