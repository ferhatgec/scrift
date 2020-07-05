/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef CONTRIBUTORS_HPP
#define CONTRIBUTORS_HPP
#include "Log.hpp"
#include "../Scrift.hpp"
#include "Colors.hpp"

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
FContributors::ShellContributors() {
    BOLD_GREEN_COLOR
    printlnf("Scrift Contributors:\n");
    BOLD_RED_COLOR
    printlnf("I don't know but If you're supported Scrift with Shell codes, please add your name.\n");
    BLACK_COLOR
}

func
FContributors::FeedbackContributors() {
    BOLD_GREEN_COLOR
    printlnf("Feedback Contributors:\n");
    BOLD_RED_COLOR
    printlnf("I don't know but If you're supported Scrift with Feedback, please add your name.\n");
    BLACK_COLOR
}

func
FContributors::TestingContributors() {
    BOLD_GREEN_COLOR
    printlnf("Testing Contributors:\n");
    BOLD_RED_COLOR
    printlnf("I don't know but If you're supported Scrift with Testing, please add your name.\n");
    BLACK_COLOR
}

func
FContributors::DonateContributors() {
    BOLD_GREEN_COLOR
    printlnf("Donate Contributors:\n");
    BOLD_RED_COLOR
    printlnf("I don't know but If you're supported Scrift with Donate, please add your name.\n");
    BLACK_COLOR
}

func
FContributors::Sponsors() {
    BOLD_GREEN_COLOR
    printlnf("Sponsors:\n");
    BOLD_RED_COLOR
    printlnf("I don't know but If you're supported Scrift with Sponsors, please add your name.\n");
    BLACK_COLOR
}

func
FContributors::AllOfThem() {
    ShellContributors();
    FeedbackContributors();
    TestingContributors();
    DonateContributors();
    Sponsors();
}

#endif // CONTRIBUTORS_HPP
