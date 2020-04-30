#ifndef FILE_FUNCTION_HPP
#define FILE_FUNCTION_HPP

#include "GetNameFunction.hpp"


namespace FileFunction {
// CD Function
class FCDFunction : public FGetUsername {
public:
    FCDFunction();
    ~FCDFunction();
    virtual void CDFunctionInit(std::string);
    virtual boolean FileExists(const std::string &);
};

// MKDir Function
class FMKDirFunction : public FCDFunction {
public:
    FMKDirFunction();
    ~FMKDirFunction();
    virtual void MKDirFunctionInit(std::string);
};


// Create File Function
class FCreateFileFunction : public FMKDirFunction {
public:
    FCreateFileFunction();
    ~FCreateFileFunction();
    virtual void CreateFileFunctionInit(std::string);
};

// ReadFile Function
class FReadFileFunction : public FCreateFileFunction {
public:
    FReadFileFunction();
    ~FReadFileFunction();
    virtual void ReadFileInit();
    boolean ReadFileExists();
    virtual void ReadFileFunction(std::string);
};

// List Function
class FLSFunction : public FCDFunction {
public:
    FLSFunction();
    ~FLSFunction();
    void InitLSFunction();
    virtual boolean DirectoryExists();
    virtual void LSFunction();
};

typedef struct {
public:
    boolean FileExist(const std::string);
    static void AppendLine(std::string);
} faddtextfunction;


// Home Directory Function
typedef struct {
public:
    virtual void GetHome();
} fhomefunction;
};


#endif // FILE_FUNCTION_HPP