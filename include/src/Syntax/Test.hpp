/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef TEST_HPP
#define TEST_HPP

#include "Log.hpp"
#include "../Scrift.hpp"
#include "ASCIIFunction.hpp"
#include "FileFunction.hpp"
#include "MkdirFunction.hpp"
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
        logsystem->WriteLog("Bad Working LogSystem - ");
        // TODO: Add create <dot>scrift_log file
    else 
        logsystem->WriteLog("Good Working LogSystem - "); 
}

func 
FTest::MKDirSystem()
{
    if(!mkdirsystem)
        logsystem->WriteLog("Bad Working MKDir System - ");
    else 
        logsystem->WriteLog("Good Working MKDir System - ");
}

func
FTest::CDSystem()
{
    if(!cdsystem)
        logsystem->WriteLog("Bad Working CD System - ");
    else 
        logsystem->WriteLog("Good Working CD System - ");
}

#endif // TEST_HPP
