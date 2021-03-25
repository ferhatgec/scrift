/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef CONTRIBUTORS_HPP
#define CONTRIBUTORS_HPP

#include "../Scrift.hpp"

#include "Log.hpp"

// Library
#include <Colorized.hpp>

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
    std::cout << "Scrift Contributors:\n";
    BLACK_COLOR
}

void
FContributors::FeedbackContributors() {
    BOLD_GREEN_COLOR
    std::cout << "Feedback Contributors:\n";
    BLACK_COLOR
}

void
FContributors::TestingContributors() {
    BOLD_GREEN_COLOR
    std::cout << "Testing Contributors:\n";
    BLACK_COLOR
}

void
FContributors::DonateContributors() {
    BOLD_GREEN_COLOR
    std::cout << "Donate Contributors:\n";
    BLACK_COLOR
}

void
FContributors::Sponsors() {
    BOLD_GREEN_COLOR
    std::cout << "Sponsors:";
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