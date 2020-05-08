/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
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
    //virtual func CDFunctionBack();
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
    virtual boolean IsExistFile();
    //virtual func CreateHistoryFileFunction();
    virtual func CreateASCIIFileFunction();
    virtual func CreateFeLogFileFunction();
    virtual func CreateScriftFile(std::string);
    virtual func CreateFileFunctionInit(fstr);
    virtual func CreateSettingsFileFunction();
};

// ReadFile Function
class FReadFileFunction : public FCreateFileFunction {
public:
    FReadFileFunction();
    destructor FReadFileFunction();
    virtual func ReadFileInit();
    boolean ReadFileExists();
    // virtual func CreateFeLog..
    virtual func ReadHistoryFileFunction();
    virtual func ReadSettingsFunction();
    virtual func ReadASCIIFunction();
    virtual func ReadFeLogFunction();
    virtual func ReadFileFunction(fstr);
};

class FClearFileFunction : public FReadFileFunction {
public:
    virtual func ClearSettingsFunction(); 
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
    virtual std::string CurrentDirectory(void);
    virtual func GetHome();
} fhomefunction;
};


#endif // FILE_FUNCTION_HPP
