/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <string>

#include <src/Syntax/Branch.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Syntax/Settings.hpp>

#include <ExecutePlusPlus.hpp>
#include <StringTools.h>

std::string
FBranch::GetGitBranch() {
    std::string branch;

    ExecutePlusPlus exec;

    if(!access(".git", R_OK)) { // && std::filesystem::exists(".git")) {
        branch = exec.ExecWithOutput(R"(git branch | grep "^\*" | sed 's/^..//')");
    } else if (!access(".hg", R_OK)) {
        /* It's too slow! */
        branch = exec.ExecWithOutput("hg branch");
    }

    if (stringtools::Find(branch, "fatal") || branch.length() == 0) {
        return "";
    } else {
        FSettings set;

        branch.pop_back();

        if (set.GitBranch())
            return "⎇  " + branch;
    }

    return "";
}
