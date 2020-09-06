/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include <src/Syntax/Install.hpp>
#include <src/Scrift.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>
#include <StringTools.h>

/*
	TODO: Loading bar?
*/

void
FInstall::InstallFetcheya() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/fetcheya") == false) {
		#ifdef __FreeBSD__
			std::cout << "Use this command as super user.\n";
		#else		
			std::cout << "Fetcheya is not installed.\nDo you want to install Fetcheya from source? (y/n) : ";	
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				std::string output = exec.ExecWithOutput("git");
				if(strstr(output.c_str(), "usage: git [--version] [--help]")) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/fetcheya.git");
					output = exec.ExecWithOutput("g++ --h");
					if(strstr(output.c_str(), "Usage: g++ [options] file.")) {
						output = exec.ExecWithOutput("gcc --h");
						if(strstr(output.c_str(), "Usage: gcc [options] file.")) {
							std::string path(getenv("HOME"));
							path.append("/fetcheya");
							std::cout << "Directory changed. : " << getenv("HOME") << "/fetcheya\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");
							
							if(fsplusplus::IsExistFile("/bin/fetcheya") == true) {
								std::cout << "Installed!\n";
							}
						} else
							std::cout << "GCC not found. Aborted.\n";
					} else
						std::cout << "G++ not found. Aborted.\n";						
				}
			} else
				std::cout << "Aborted.\n";	
		#endif
	} else {
		std::cout << "Fetcheya is already installed\nWould you like to run it? (y/n) : "; 
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("fetcheya");
		else
			std::cout << "Aborted.\n";
	}
}

/*
	Simple git-based package installer for Fegeya Community's applications. (Build & Install)
*/
void
FInstall::FegeyaPackageInstaller(std::string arg) {
	/* --i fetcheya */
	if(strstr(arg.c_str(), "--i")) {
		std::cout << "Checking..\n";
		arg = stringtools::EraseAllSubString(arg, "fpi --i ");
		if(strstr(arg.c_str(), "fetcheya")) {
			InstallFetcheya();
		}
	}
}
