/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

#include <src/Scrift.hpp>
#include <src/Syntax/RunFunction.hpp>

#include <src/Fpi/Get.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>
#include <StringTools.h>
#include <Colorized.hpp>

void FGet::FetchRepositoryData(std::string repository) {
	std::string path(getenv("HOME"));
	path.append("/");
	
	chdir(path.c_str());
	
	if (mkdir("fpi_repository", 0777) != -1) { 
		chdir("fpi_repository");
		
		/* home/scrift_repository/repository/scrift/app.repo */
		ExecutePlusPlus exec;
		exec.RunFunction(STR("git clone ") + repository);	
	
		chdir("repository/scrift");
	}
}
