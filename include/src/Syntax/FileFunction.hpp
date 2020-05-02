#ifndef FILE_FUNCTION_HPP
#define FILE_FUNCTION_HPP

#include "GetNameFunction.hpp"


namespace FileFunction {
// CD Function
class FCDFunction : public FGetUsername {
public:

    FCDFunction();
    destructor FCDFunction();
    virtual func CDFunctionInit(fstr);
    virtual boolean FileExists(const fstr &);
};

// MKDir Function
class FMKDirFunction : public FCDFunction {
public:
    FMKDirFunction();
    destructor FMKDirFunction();
    virtual func MKDirFunctionInit(fstr);
};


// Create File Function
class FCreateFileFunction : public FMKDirFunction {
public:
    FCreateFileFunction();
    destructor FCreateFileFunction();
    virtual func CreateASCIIFileFunction();
    virtual func CreateFeLogFileFunction();
    virtual func CreateFileFunctionInit(fstr);
};

// ReadFile Function
class FReadFileFunction : public FCreateFileFunction {
public:
    FReadFileFunction();
    destructor FReadFileFunction();
    virtual func ReadFileInit();
    boolean ReadFileExists();
    // virtual func CreateFeLog....
    virtual func ReadASCIIFunction();
    virtual func ReadFeLogFunction();
    virtual func ReadFileFunction(fstr);
};

// List Function
class FLSFunction : public FCDFunction {
public:
    FLSFunction();
    destructor FLSFunction();
    func InitLSFunction();
    virtual boolean DirectoryExists();
    virtual func LSFunction();
};

class FRemoveFileFunction : public FCDFunction {
public:
    virtual func DeleteFile(std::string);
    // DeleteMultipleFiles coming soon.
};


typest {
public:
    boolean FileExist(const fstr);
    static func AppendLine(fstr);
    static func DeleteLine(fstr);
} faddtextfunction;


// Home Directory Function
typest {
public:
    virtual func GetHome();
} fhomefunction;
};


#endif // FILE_FUNCTION_HPP