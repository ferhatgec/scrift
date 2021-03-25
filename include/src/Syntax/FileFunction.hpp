/* MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef FILE_FUNCTION_HPP
#define FILE_FUNCTION_HPP

#include <src/Syntax/Locale.hpp>
#include <src/Syntax/GetNameFunction.hpp>

namespace FileFunction {
    class FCDFunction : public FGetUsername {
    public:
    	void CDFunctionInit(std::string name, slocale_t &locale);
    };

    class FMKDirFunction : public FCDFunction {
    public:
        FMKDirFunction();
        ~FMKDirFunction();
    
        void MKDirFunctionInit(std::string);
    };

    class FCreateFileFunction : public FMKDirFunction {
    public:
        FCreateFileFunction();
        ~FCreateFileFunction();
    
    	/* TODO: Will be removed */ 
        bool IsExistFile(std::string);
    
        void CreateASCIIFileFunction();
        void CreateScriftFile(std::string);
        void CreateFileFunctionInit(std::string);
        void CreateSettingsFileFunction();
    };

    class FReadFileFunction : public FCreateFileFunction {
    public:
        FReadFileFunction();
        ~FReadFileFunction();
     
     	/* TODO: Remove DRY codes */
        void ReadFeLogFunctionWithoutPrint();
        void ReadHistoryFileFunction();
        void ReadSettingsFunction();
        void ReadASCIIFunction();
        void ReadFeLogFunction();
        void ReadAliasFunction();
        
        void ReadFileFunction(std::string);
    };


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

    class FLSFunction : public FCDFunction {
    public:
        FLSFunction();
        ~FLSFunction();
    
        bool ListArgumentObjectFunction(std::string);
        void ListObjectFunction();
        void LSFunction(std::string);
        void ParseListing(std::string file);
        std::string GetFileExtension(const std::string& file);
        
        std::string GetObjects();
    };

    class FRemoveFileFunction : public FCDFunction {
    public:
        void DeleteFile(std::string);
    };


    typedef struct {
    public:
        static void AppendLine(std::string);
        static void DeleteLine(std::string);
    } faddtextfunction;

    typedef struct {
    public:
        std::string CurrentDirectory(void);
        void GetHome();
    } fhomefunction;
};

#endif // FILE_FUNCTION_HPP
