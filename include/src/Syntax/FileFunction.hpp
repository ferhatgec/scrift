#ifndef FILE_FUNCTION_HPP
#define FILE_FUNCTION_HPP

#include "GetNameFunction.hpp"


namespace FileFunction {
// CD Function
fclass FCDFunction : public FGetUsername {
public:
    FCDFunction();
    destructor FCDFunction();
    fvirt func CDFunctionInit(fstr);
    fvirt boolean FileExists(const fstr &);
};

// MKDir Function
fclass FMKDirFunction : public FCDFunction {
public:
    FMKDirFunction();
    destructor FMKDirFunction();
    fvirt func MKDirFunctionInit(fstr);
};


// Create File Function
fclass FCreateFileFunction : public FMKDirFunction {
public:
    FCreateFileFunction();
    destructor FCreateFileFunction();
    fvirt func CreateFileFunctionInit(fstr);
};

// ReadFile Function
fclass FReadFileFunction : public FCreateFileFunction {
public:
    FReadFileFunction();
    destructor FReadFileFunction();
    fvirt func ReadFileInit();
    boolean ReadFileExists();
    fvirt func ReadFileFunction(fstr);
};

// List Function
fclass FLSFunction : public FCDFunction {
public:
    FLSFunction();
    destructor FLSFunction();
    func InitLSFunction();
    fvirt boolean DirectoryExists();
    fvirt func LSFunction();
};

typedef struct {
public:
    boolean FileExist(const fstr);
    static func AppendLine(fstr);
    static func DeleteLine(fstr);
} faddtextfunction;


// Home Directory Function
typedef struct {
public:
    fvirt func GetHome();
} fhomefunction;
};


#endif // FILE_FUNCTION_HPP