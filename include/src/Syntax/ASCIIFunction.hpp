/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef ASCII_FUNCTION_HPP
#define ASCII_FUNCTION_HPP
#include "Colors.hpp"
#include "../synflang.hpp"
#include "../main.h"
#include "FileFunction.hpp"
#include "Log.hpp"
#include <pwd.h>

using namespace FileFunction;

typedef struct {
public:
    FeLog *logfunc = new FeLog();
    FCommand *fegeyacommand = new FCommand();
    FCreateFileFunction *createfilefunc = new FCreateFileFunction();
    FReadFileFunction *readfilefunc = new FReadFileFunction();
    inline boolean InitFile()
    {
        struct stat buffer;
        std::string path;
        uid_t uid = geteuid();
        struct passwd *password = getpwuid(uid);
        path.append("/home/");
        path.append(password->pw_name);
        path.append("/");
        path.append(".scrift_ascii");   
        return (stat (path.c_str(), &buffer) == 0); 
    }

    virtual void GenerateString() 
    {
        if(InitFile() == true)
        {
            YELLOW_COLOR
            logfunc->WriteLog("ASCIIFile is exists! Nice - ");
            BLACK_COLOR // reset
        }
        else {
            createfilefunc->CreateASCIIFileFunction();
        }
    }  

    virtual void FReadFile() 
    {
        readfilefunc->ReadASCIIFunction();
    }
    virtual void Allofthem() 
    {
        GenerateString();
        FReadFile();
        //delete createfilefunc, readfilefunc;
    }

} asciifunction;








#endif // ASCII_FUNCTION_HPP