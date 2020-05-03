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
#include "../main.h"
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
            logsystem->WriteLog("Developer Mode equal is devmode\n");
            username->GetUsername();
            logsystem->WriteLog("GetUsername is called\n");
            logsystem->WriteLog("Going to GetUsername\n");
            GetUsername();
        }
};

boolean
FDeveloperMode::GetUsername()
{
    // Default: 
    logsystem->WriteLog("Default Scrift Shell Running\n");
    logsystem->WriteLog("Waiting...\n");
    ASCIIFunc();
    logsystem->WriteLog("Going to ASCIIFunction\n");
}

boolean
FDeveloperMode::ASCIIFunc()
{
    logsystem->WriteLog("Calling InitFile from ASCIIFunction\n");
    asciisystem->InitFile();
    logsystem->WriteLog("Going to ErrorSystem\n");
}

boolean
FDeveloperMode::ErrorSystem()
{
    errorsystem->PrintBugError("DeveloperMode PrintBugError\n");
    errorsystem->PrintError("Developer Mode PrintError\n");
    errorsystem->PrintCriticalError("DeveloperMode PrintCriticalError\n");
    logsystem->WriteLog("Calling CDFunction from ErrorSystem\n");
    CDFunction();
    logsystem->WriteLog("Going to CDFunction\n");
}

boolean 
FDeveloperMode::RunSystem()
{

}

boolean
FDeveloperMode::CDFunction()
{
    logsystem->WriteLog("Searching scrift_log\n");
    cdsystem->FileExists(".scrift_log\n");
    logsystem->WriteLog("Exists!\n");
    logsystem->WriteLog("Calling CDFunctionInit from CDFunction\n");
    cdsystem->CDFunctionInit(".scrift_dev");
    logsystem->WriteLog("Going to CDFunctionInit\n");

    logsystem->WriteLog("Calling CreateFileFunc from CDFunction\n");
    CreateFileFunc();
    logsystem->WriteLog("Going to CreateFileFunc\n");
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