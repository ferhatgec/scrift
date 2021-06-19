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
        void MKDirFunctionInit(const std::string &);
    };

    class FCreateFileFunction : public FMKDirFunction {
    public:
        void CreateASCIIFileFunction();

        void CreateScriftFile(const std::string &);

        void CreateFileFunctionInit(const std::string &);

        void CreateSettingsFileFunction();
    };

    class FReadFileFunction : public FCreateFileFunction {
    public:
        std::string ReadFile(const std::string &filename);

        void ReadHistoryFileFunction();

        void ReadSettingsFunction();

        void ReadASCIIFunction();

        void ReadFeLogFunction();

        void ReadAliasFunction();

        void ReadFileFunction(std::string);
    };


    class FFindFileFunction : public FReadFileFunction {
    public:
        void FindFile(const std::string &);

        std::string FindWithoutPrint(const std::string &name);
    };


    class FClearFileFunction : public FReadFileFunction {
    public:
        void ClearSettingsFunction();

        void ClearFeLogFunction();
    };

    class FLSFunction : public FCDFunction {
    public:
        bool ListArgumentObjectFunction(const std::string &);

        void ListObjectFunction();

        void LSFunction(std::string);

        void ParseListing(const std::string &filename, const std::string &extension);

        std::string GetFileExtension(const std::string &file);

        void GetObjects();
    };

    class FRemoveFileFunction : public FCDFunction {
    public:
        void DeleteFile(const std::string &file);
    };


    typedef struct {
    public:
        static void AppendLine(const std::string &);
    } faddtextfunction;

    typedef struct {
    public:
        std::string CurrentDirectory();

        void GetHome();
    } fhomefunction;
}

#endif // FILE_FUNCTION_HPP
