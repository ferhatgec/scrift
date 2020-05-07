/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef DEVELOPER_MODE_HPP
#define DEVELOPER_MODE_HPP

#pragma once
#include "Log.hpp"
#include "../Scrift.hpp"
#include "GetNameFunction.hpp"
#include "CommandFunc.h"
#include "ASCIIFunction.hpp"
#include "KernelName.hpp"
#include "Test.hpp"
#include "MkdirFunction.hpp"
#include "Linker.hpp"
#include "HelpFunction.hpp"

class FDeveloperMode {
    FGetUsername *username = new FGetUsername();
    asciifunction *asciisystem = new asciifunction;
    fprinterror *errorsystem = new fprinterror;
    FRunFunction *runsystem = new FRunFunction();
    FileFunction::FCDFunction *cdsystem = new FileFunction::FCDFunction();
    FileFunction::FCreateFileFunction *createfilesystem = new FileFunction::FCreateFileFunction();
    FeLog *logsystem = new FeLog();
    boolean developermode;
    public:
    virtual boolean GetUsername();
    virtual boolean ASCIIFunc();
    virtual boolean ErrorSystem();
    virtual boolean RunSystem();
    virtual boolean CDFunction();
    virtual boolean CreateFileFunc();
    virtual boolean LogSystem();
    virtual boolean GetDeveloperMode();
    virtual boolean AllOfThem(boolean);
    protected:
        virtual boolean SetDeveloperMode(boolean devmode)
        {
            developermode = devmode;
            logsystem->WriteLog("Developer Mode equal is devmode - ");
            username->GetUsername();
            logsystem->WriteLog("GetUsername is called - ");
            logsystem->WriteLog("Going to GetUsername - ");
            GetUsername();
        }
};

boolean
FDeveloperMode::GetUsername()
{
    // Default: 
    logsystem->WriteLog("Default Scrift Shell Running - ");
    logsystem->WriteLog("Waiting... - ");
    ASCIIFunc();
    logsystem->WriteLog("Going to ASCIIFunction - ");
}

boolean
FDeveloperMode::ASCIIFunc()
{
    logsystem->WriteLog("Calling InitFile from ASCIIFunction - ");
    asciisystem->InitFile();
    logsystem->WriteLog("Going to ErrorSystem - ");
}

boolean
FDeveloperMode::ErrorSystem()
{
    errorsystem->PrintBugError("DeveloperMode PrintBugError - ");
    errorsystem->PrintError("Developer Mode PrintError - ");
    errorsystem->PrintCriticalError("DeveloperMode PrintCriticalError - ");
    logsystem->WriteLog("Calling CDFunction from ErrorSystem - ");
    CDFunction();
    logsystem->WriteLog("Going to CDFunction - ");
}

boolean 
FDeveloperMode::RunSystem()
{

}

boolean
FDeveloperMode::CDFunction()
{
    logsystem->WriteLog("Searching scrift_log - ");
    cdsystem->FileExists(".scrift_log\n");
    logsystem->WriteLog("Exists! - ");
    logsystem->WriteLog("Calling CDFunctionInit from CDFunction - ");
    cdsystem->CDFunctionInit(".scrift_dev");
    logsystem->WriteLog("Going to CDFunctionInit - ");

    logsystem->WriteLog("Calling CreateFileFunc from CDFunction - ");
    CreateFileFunc();
    logsystem->WriteLog("Going to CreateFileFunc - ");
}

boolean
FDeveloperMode::CreateFileFunc()
{

}

boolean
FDeveloperMode::LogSystem()
{

}

boolean
FDeveloperMode::GetDeveloperMode()
{

}


boolean
FDeveloperMode::AllOfThem(boolean virtualdev)
{
    SetDeveloperMode(virtualdev);
    GetUsername();
    ASCIIFunc();
    ErrorSystem();
    RunSystem();
    CDFunction();
    CreateFileFunc();
    LogSystem();
    GetDeveloperMode();
}












#endif // DEVELOPER_MODE_HPP