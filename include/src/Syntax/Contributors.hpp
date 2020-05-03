/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef CONTRIBUTORS_HPP
#define CONTRIBUTORS_HPP
#include "Log.hpp"
#include "../main.h"
FeLog *log = new FeLog();
class FContributors {
public:
    virtual func ShellContributors();
    virtual func FeedbackContributors();
    virtual func TestingContributors();
    virtual func DonateContributors();
    virtual func Sponsors();
    virtual func AllOfThem();
};

func
FContributors::ShellContributors()
{
    log->WriteLog("Printing..\n");
    printlnf("I don't know but If you're supported Scrift with Shell codes, please add your name.\n");
    log->WriteLog("Launched..\n");
}

func 
FContributors::FeedbackContributors()
{
    log->WriteLog("Printing..\n");
    printlnf("I don't know but If you're supported Scrift with Feedback, please add your name.\n");
    log->WriteLog("Launched..\n");
}

func 
FContributors::TestingContributors()
{
    log->WriteLog("Printing..\n");
    printlnf("I don't know but If you're supported Scrift with Testing, please add your name.\n");
    log->WriteLog("Launched..\n");
}

func 
FContributors::DonateContributors()
{
    log->WriteLog("Printing..\n");
    printlnf("I don't know but If you're supported Scrift with Donate, please add your name.\n");
    log->WriteLog("Launched..\n");
}

func
FContributors::Sponsors()
{
    log->WriteLog("Printing..\n");
    printlnf("I don't know but If you're supported Scrift with Sponsors, please add your name.\n");
    log->WriteLog("Launched..\n");
}

func 
FContributors::AllOfThem()
{
    log->WriteLog("Printing..\n");
    ShellContributors();
    FeedbackContributors();
    TestingContributors();
    DonateContributors();
    Sponsors();
    log->WriteLog("Launched..\n");
}

#endif // CONTRIBUTORS_HPP