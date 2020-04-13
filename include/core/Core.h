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
    fchar* _ip_;
    fchar* _shell_;
    fchar* _core_init;
    fchar* _run_;
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
    fchar* _lang_;
    fchar* _version_;
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
    fchar* _size_;
    fchar* _init;
    FReadCore *_read ;
};

class FDirectoryCore {
public:
    FDirectoryCore();
    ~FDirectoryCore();
    virtual void DirectorySync();
    virtual void PathChar();
    virtual integer Return();
protected:
    fchar* _path;
};

class FSyncCore {
public:
    FSyncCore();
    ~FSyncCore();
    virtual integer ReturnSync();
    virtual uinteger64 _ReturnUnsignedSync();
protected:
    FSync *_sync;
    fchar* _sync_file;
};
};
#endif // CORE_H