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
#include <src/Fpi/Parser.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>
#include <StringTools.h>
#include <Colorized.hpp>

void FParser::ParseRepositoryFile(std::string arg) {
	const std::string old_path = fsplusplus::GetCurrentWorkingDir();
	
	std::string path(getenv("HOME"));
	path.append("/fpi_repository/repository/scrift/");
	
	chdir(path.c_str());
	
	arg.pop_back();
	
	if(fsplusplus::IsExistFile(arg + ".repo") == true) {
		path = path + arg + ".repo";
		
		app_name 	= fsplusplus::FindStringWithReturn(path, "NAME=");
		app_desc 	= fsplusplus::FindStringWithReturn(path, "DESC=");
		app_author 	= fsplusplus::FindStringWithReturn(path, "AUTHOR=");
		app_license = fsplusplus::FindStringWithReturn(path, "LICENSE=");
		app_exec 	= fsplusplus::FindStringWithReturn(path, "EXEC=");
		app_repo	= fsplusplus::FindStringWithReturn(path, "REPOSITORY=");
		app_folder	= fsplusplus::FindStringWithReturn(path, "REPOSITORY_FOLDER=");
		
		app_name 	= stringtools::EraseAllSubString(app_name, "NAME=");
		app_desc 	= stringtools::EraseAllSubString(app_desc, "DESC=");
		app_author 	= stringtools::EraseAllSubString(app_author, "AUTHOR=");
		app_license = stringtools::EraseAllSubString(app_license, "LICENSE=");
		app_exec 	= stringtools::EraseAllSubString(app_exec, "EXEC=");
		app_repo 	= stringtools::EraseAllSubString(app_repo, "REPOSITORY=");
		app_folder	= stringtools::EraseAllSubString(app_folder, "REPOSITORY_FOLDER=");
		
		app_name.pop_back();
		app_desc.pop_back();
		app_author.pop_back();
		app_license.pop_back();
		app_exec.pop_back();
		app_repo.pop_back();
		app_folder.pop_back();
	}	
}
