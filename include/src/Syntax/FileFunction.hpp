/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
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
    ~FCDFunction();
    bool FileExists(const std::string &);
    void CDFunctionInit(std::string);
};

// MKDir Function
class FMKDirFunction : public FCDFunction {
public:
    FMKDirFunction();
    ~FMKDirFunction();
    void MKDirFunctionInit(fstr);
};

// Create File Function
class FCreateFileFunction : public FMKDirFunction {
public:
    FCreateFileFunction();
    ~FCreateFileFunction();
    bool IsExistFile(std::string);
    void CreateASCIIFileFunction();
    void CreateScriftFile(std::string);
    void CreateFileFunctionInit(fstr);
    void CreateSettingsFileFunction();
};

// ReadFile Function
class FReadFileFunction : public FCreateFileFunction {
public:
    FReadFileFunction();
    ~FReadFileFunction();
    void ReadFeLogFunctionWithoutPrint();
    void ReadHistoryFileFunction();
    void ReadSettingsFunction();
    void ReadASCIIFunction();
    void ReadFeLogFunction();
    void ReadFileFunction(fstr);
};


// FindFile Function
class FFindFileFunction : public FReadFileFunction {
public:
	FFindFileFunction() { }
	~FFindFileFunction() { }
	void FindFile(std::string);
	std::string FindWithoutPrint(std::string);
};


class FClearFileFunction : public FReadFileFunction {
public:
    void ClearSettingsFunction(); 
    void ClearFeLogFunction();
};

// List Function
class FLSFunction : public FCDFunction {
public:
    FLSFunction();
    ~FLSFunction();
    bool ListArgumentObjectFunction(std::string);
    void ListObjectFunction();
    void LSFunction(std::string);
    std::string GetObjects();
};

class FRemoveFileFunction : public FCDFunction {
public:
    void DeleteFile(std::string);
    // DeleteMultipleFiles coming soon.
};


typest {
public:
    static void AppendLine(std::string);
    static void DeleteLine(std::string);
} faddtextfunction;


// Home Directory Function
typest {
public:
    std::string CurrentDirectory(void);
    void GetHome();
} fhomefunction;
};


#endif // FILE_FUNCTION_HPP
