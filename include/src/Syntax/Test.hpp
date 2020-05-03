/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#pragma once
#ifndef TEST_HPP
#define TEST_HPP

#include "Log.hpp"
#include "../main.h"
#include "ASCIIFunction.hpp"
#include "FileFunction.hpp"
#include "MkdirFunction.hpp"
#include "PrintErrorFunction.hpp"
#include "RunFunction.hpp"

class FTest {
    FeLog *logsystem = new FeLog();
    FileFunction::FMKDirFunction *mkdirsystem = new FileFunction::FMKDirFunction();
    FileFunction::FCDFunction *cdsystem = new FileFunction::FCDFunction();
    public:
    func LogSystem();
    func MKDirSystem();
    func CDSystem();
};

func
FTest::LogSystem() 
{
    if(!logsystem) 
        logsystem->WriteLog("Bad Working LogSystem\n");
        // TODO: Add create <dot>scrift_log file
    else 
        logsystem->WriteLog("Good Working LogSystem\n"); 
}

func 
FTest::MKDirSystem()
{
    if(!mkdirsystem)
        logsystem->WriteLog("Bad Working MKDir System\n");
    else 
        logsystem->WriteLog("Good Working MKDir System\n");
}

func
FTest::CDSystem()
{
    if(!cdsystem)
        logsystem->WriteLog("Bad Working CD System\n");
    else 
        logsystem->WriteLog("Good Working CD System\n");
}

#endif // TEST_HPP