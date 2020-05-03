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
    printlnf("I don't know but If you're supported Scrift with Shell codes, please add your name.\n");
}

func 
FContributors::FeedbackContributors()
{
    printlnf("I don't know but If you're supported Scrift with Feedback, please add your name.\n");
}

func 
FContributors::TestingContributors()
{
    printlnf("I don't know but If you're supported Scrift with Testing, please add your name.\n");
}

func 
FContributors::DonateContributors()
{
    printlnf("I don't know but If you're supported Scrift with Donate, please add your name.\n");
}

func
FContributors::Sponsors()
{
    printlnf("I don't know but If you're supported Scrift with Sponsors, please add your name.\n");
}

func 
FContributors::AllOfThem()
{

    ShellContributors();
    FeedbackContributors();
    TestingContributors();
    DonateContributors();
    Sponsors();
}

#endif // CONTRIBUTORS_HPP