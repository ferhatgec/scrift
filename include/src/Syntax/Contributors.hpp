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

// Library
#include "../../../Library/Colorized.hpp"

class FContributors {
public:
    void ShellContributors();
    void FeedbackContributors();
    void TestingContributors();
    void DonateContributors();
    void Sponsors();
    void AllOfThem();
};

void
FContributors::ShellContributors() {
    BOLD_GREEN_COLOR
    printlnf("Scrift Contributors:\n");
    BLACK_COLOR
}

void
FContributors::FeedbackContributors() {
    BOLD_GREEN_COLOR
    printlnf("Feedback Contributors:\n");
    BLACK_COLOR
}

void
FContributors::TestingContributors() {
    BOLD_GREEN_COLOR
    printlnf("Testing Contributors:\n");
    BLACK_COLOR
}

void
FContributors::DonateContributors() {
    BOLD_GREEN_COLOR
    printlnf("Donate Contributors:\n");
    BLACK_COLOR
}

void
FContributors::Sponsors() {
    BOLD_GREEN_COLOR
    printlnf("Sponsors:");
    BLACK_COLOR
}

void
FContributors::AllOfThem() {
    ShellContributors();
    FeedbackContributors();
    TestingContributors();
    DonateContributors();
    Sponsors();
}

#endif // CONTRIBUTORS_HPP
