/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <src/Syntax/Branch.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <ExecutePlusPlus.hpp>
#include <FileSystemPlusPlus.h>

std::string
FBranch::GetGitBranch() {
	std::string branch(fsplusplus::ListDirectoryWithReturn(".git"));
	if(branch != "null") {
		ExecutePlusPlus exec;
		branch = exec.ExecWithOutput("git branch | grep \"^\*\" | sed 's/^..//'");
		if(strstr(branch.c_str(), "fatal")) {
			return "";
		} else {
			return "[" + branch + "] ";
		}
	}
	return "";
}
