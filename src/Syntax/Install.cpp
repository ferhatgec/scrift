/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>

#include <src/Syntax/Install.hpp>
#include <src/Scrift.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>

void
FInstall::InstallFetcheya() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/fetcheya") == false) {
		if (getuid()) { /* Check superuser privileges */
			std::cout << "Use this command as super user.\n";		
		} else {
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
								chdir(path.c_str());
								exec.RunFunction("sh install.sh");
							} else
								std::cout << "GCC not found. Aborted.\n";
						} else
							std::cout << "G++ not found. Aborted.\n";						
					}
				} else
					std::cout << "Aborted.\n";		
				}
			} else
				exec.RunFunction("fetcheya");
}
