#ifndef FILE_FUNCTION_HPP
#define FILE_FUNCTION_HPP

#include "GetNameFunction.hpp"

class FCDFunction : public FGetUsername {
public:
    FCDFunction();
    ~FCDFunction();
    virtual void CDFunctionInit();
    virtual boolean FileExists(const std::string &);
};


class FMKDirFunction : public FCDFunction {
public:
    FMKDirFunction();
    ~FMKDirFunction();
    virtual void MKDirFunctionInit();
};

class FCreateFileFunction : public FMKDirFunction {
public:
    FCreateFileFunction();
    ~FCreateFileFunction();
    virtual void CreateFileFunctionInit();
};

#endif // FILE_FUNCTION_HPP