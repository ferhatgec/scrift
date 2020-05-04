/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef SETTINGS_HPP
#define SETTIGNS_HPP

#include "FileFunction.hpp"
#include "Log.hpp"
#include "../main.h"

class FRunFunction {
    fchar* printtext;
    FeLog *logsystem = new FeLog();
    FileFunction::FCreateFileFunction *createfile = new FileFunction::FCreateFileFunction();
    FileFunction::FReadFileFunction *readfile = new FileFunction::FReadFileFunction();
public:
    virtual func CreateSettingsFile();
    virtual func KeyWords();
    virtual func ReadFile();
private:
    virtual boolean SetPermission();
};

func 
FRunFunction::CreateSettingsFile()
{
    logsystem->WriteLog("Creating Settings File \n");
}

func 
FRunFunction::KeyWords()
{
    printtext = "printtext";
    
}

#endif // RUN_FUNCTION_HPP_