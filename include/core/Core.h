#ifndef CORE_H
#define CORE_H
#include "../main.h"
#include "../Lang/Language.hpp"
#include "../Lang/Reader.hpp"
#include "../File/Directory.h"
#include "../File/File.h"
#include "../File/Path.h"
#include "../File/Sync.h"
#include "../Syntax/CommandFunc.h"
namespace FCore {
void FCoreFile();
void Core();
void FCore_init();
class FReadCore {
public:
    FReadCore();
    ~FReadCore();
    virtual void Construct();
    virtual void IP();
    virtual void RunGCC();
    virtual void RunGPP();
protected:
    char* _ip_;
    char* _shell_;
    char* _core_init;
    char* _run_;
};

class FLanguageCore {
public:
    FLanguageCore();
    ~FLanguageCore();
    virtual void RunCFile();
    virtual void RunCPPFile();
    virtual void Init_Core();
    virtual void GetVersionGCC();
    virtual void GetVersionScrift();
protected:
    char* _lang_;
    char* _version_;
};

class FMainCore {
public:
    FMainCore();
    ~FMainCore();
    virtual void Main();
    int Size();
    float SizeF();
    struct size_main;
protected:
    char* _size_;
    char* _init;
    FReadCore *_read ;
};

class FDirectoryCore {
public:
    FDirectoryCore();
    ~FDirectoryCore();
    virtual void DirectorySync();
    virtual void PathChar();
    virtual int Return();
protected:
    char* _path;
};

class FSyncCore {
public:
    FSyncCore();
    ~FSyncCore();
    virtual int ReturnSync();
    virtual uint64_t _ReturnUnsignedSync();
protected:
    FSync *_sync;
    char* _sync_file;
};
};
#endif // CORE_H