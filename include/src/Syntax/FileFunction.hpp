#ifndef FILE_FUNCTION_HPP
#define FILE_FUNCTION_HPP

#include "GetNameFunction.hpp"

class FCDFunction : public FGetUsername {
public:
    FCDFunction();
    ~FCDFunction();
    virtual void CDFunctionInit(std::string);
    virtual boolean FileExists(const std::string &);
};


class FMKDirFunction : public FCDFunction {
public:
    FMKDirFunction();
    ~FMKDirFunction();
    virtual void MKDirFunctionInit(std::string);
};

class FCreateFileFunction : public FMKDirFunction {
public:
    FCreateFileFunction();
    ~FCreateFileFunction();
    virtual void CreateFileFunctionInit(std::string);
};

class FReadFileFunction : public FCreateFileFunction {
public:
    FReadFileFunction();
    ~FReadFileFunction();
    virtual void ReadFileInit();
    boolean ReadFileExists();
    virtual void ReadFileFunction(std::string);
};


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
    virtual void GetHome();
} fhomefunction;




#endif // FILE_FUNCTION_HPP