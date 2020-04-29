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

typedef struct {
public:
    virtual void GetHome();
} fhomefunction;


#endif // FILE_FUNCTION_HPP