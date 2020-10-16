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
#include <src/Syntax/Install.hpp>
#include <src/Syntax/RunFunction.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>
#include <StringTools.h>

/* Definitions */
#define IS_EXIST(x) std::cout << x << " already installed\nWould you like to run it? (y/n) : ";
#define IS_NOT_EXIST(x) std::cout << x << " is not installed.\nDo you want to install " << x << " from source? (y/n) : ";

#define IS_NOT_SUPER_USER(x) std::cout << "Use '" << x << "' as super user.\n"
#define IS_NOT_FOUND(x) std::cout << x << " not found. Aborted.\n";

#define CANNOT_BE_REMOVED(x) std::cout << "Really? " << x << " is not installed. Cannot be removed.\n";
#define UNINSTALL(x) std::cout << "Do you want to uninstall " << x << "? (y/n) : ";

void HelpFunction();

/*
	TODO: Loading bar?
*/

/*
	Fetcheya : Colorized System info application.
*/

/*
	int
		uninstall = 0 : Install
		uninstall = 1 : Uninstall
*/
void
FInstall::Install(std::string name, std::string repository, std::string object, std::string folder, int uninstall) {
	ExecutePlusPlus exec;
	/* Check is exist? */
	if(fsplusplus::IsExistFile("/bin/" + object) == false) {
		if(uninstall == 1)
			CANNOT_BE_REMOVED(name)
		else {
			IS_NOT_EXIST(name)
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true || fsplusplus::IsExistFile("/usr/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone " + repository);
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/" + folder);
							std::cout << "Directory changed. : " << path << "\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";

							#ifdef __FreeBSD__
								if (getuid())
									IS_NOT_SUPER_USER(name)
								else
								 	exec.RunFunction("sh install.sh");
							#else
								exec.RunFunction("sudo sh install.sh");
							#endif

							if(fsplusplus::IsExistFile("/bin/" + object) == true)
								std::cout << "Installed!\n";
							else
								std::cout << "Could not install.\n";
						} else
							IS_NOT_FOUND("gcc")
					} else
						IS_NOT_FOUND("g++")
				} else
					IS_NOT_FOUND("git")
			} else
				std::cout << "Aborted.\n";
		}
	} else {
		if(uninstall == 1) {
			UNINSTALL(name)
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				exec.RunFunction("sudo rm -f /bin/" + object);
				if(fsplusplus::IsExistFile("/bin/" + object) == false)
					std::cout << "Removed!\n";
				else
					std::cout << "Could not remove.\n";
			} else
				std::cout << "Aborted.\n";
		} else {
			IS_EXIST(name)
			char input = getchar();
			if(input == 'y' || input == 'Y')
				exec.RunFunction(object);
			else
				std::cout << "Aborted.\n";
		}
	}
}

/*
	Simple git-based package installer for Fegeya Community's applications. (Build & Install)
*/
void
FInstall::FegeyaPackageInstaller(std::string arg) {
	/* --i fetcheya */
	if(strstr(arg.c_str(), "--i "))
		InstallFunction(arg, 1);
	else if(strstr(arg.c_str(), "--install "))
		InstallFunction(arg, 2);
	else if(strstr(arg.c_str(), "--uninstall "))
		UnInstallFunction(arg, 1);
 	else if(strstr(arg.c_str(), "--uni "))
		UnInstallFunction(arg, 2);
	else
		HelpFunction();
}

void HelpFunction() {
	std::cout << "Fegeya Package Installer (fpi)\n" << 
	"Usage: fpi [--i --install || --uni --uninstall] <app>\n<app> :\n" <<
	"* fetcheya\n" << "* flascript (fla)\n" << "* copyboard\n" <<
	"* lsf\n" << "* freebrain (freebr)\n" << "* brainfuckplusplus (bfc)\n" << 
	"* generafor\n";
}

void
FInstall::InstallFunction(std::string arg, int type) {
	std::cout << "Checking..\n";
	if(type == 1) /* fpi --i */
		arg = stringtools::EraseAllSubString(arg, "fpi --i ");
	else if(type == 2) /* fpi --install */
		arg = stringtools::EraseAllSubString(arg, "fpi --install ");
	else
		HelpFunction();

	if(strstr(arg.c_str(), "fetcheya")) 
		Install(STR("Fegeya Fetcheya"), STR("https://github.com/ferhatgec/fetcheya.git"), STR("fetcheya"), STR("fetcheya"), 0);
	else if(strstr(arg.c_str(), "flascript")) 
		Install(STR("Fegeya FlaScript (fla)"), STR("https://github.com/ferhatgec/flascript.git"), STR("fla"), 
			STR("flascript"), 0);
	else if(strstr(arg.c_str(), "copyboard")) 
		Install(STR("Fegeya Copyboard"), STR("https://github.com/ferhatgec/copyboard.git"), STR("copyboard"), 
			STR("copyboard"), 0);
	else if(strstr(arg.c_str(), "lsf")) 
		Install(STR("Fegeya List"), STR("https://github.com/ferhatgec/lsf.git"), STR("lsf"), STR("lsf"), 0);
	else if(strstr(arg.c_str(), "freebrain")) 
		Install(STR("Fegeya FreeBrain"), STR("https://github.com/ferhatgec/freebrain.git"), STR("fetcheya"), 
			STR("freebr"), 0);
	else if(strstr(arg.c_str(), "brainfuckplusplus")) 
		Install(STR("Fegeya Brainfuck++"), STR("https://github.com/ferhatgec/brainfuckplusplus.git"), STR("brainfuckplusplus"), 
			STR("bfc"), 0);
	else if(strstr(arg.c_str(), "generafor"))
		Install(STR("Fegeya Generafor"), STR("https://github.com/ferhatgec/generafor.git"), STR("generafor"), 
			STR("generafor"), 0);
	else
		std::cout << "No match for this argument : " << arg + "\n";
}

void
FInstall::UnInstallFunction(std::string arg, int type) {
	std::cout << "Checking..\n";
	if(type == 1) /* fpi --uni */
		arg = stringtools::EraseAllSubString(arg, "fpi --uni ");
	else if(type == 2) /* fpi --uninstall */
		arg = stringtools::EraseAllSubString(arg, "fpi --uninstall ");
	else
		HelpFunction();

	if(strstr(arg.c_str(), "fetcheya")) 
		Install(STR("Fegeya Fetcheya"), STR("https://github.com/ferhatgec/fetcheya.git"), STR("fetcheya"), STR("fetcheya"), 1);
	else if(strstr(arg.c_str(), "flascript")) 
		Install(STR("Fegeya FlaScript (fla)"), STR("https://github.com/ferhatgec/flascript.git"), STR("fla"), 
			STR("flascript"), 1);
	else if(strstr(arg.c_str(), "copyboard")) 
		Install(STR("Fegeya Copyboard"), STR("https://github.com/ferhatgec/copyboard.git"), STR("copyboard"), 
			STR("copyboard"), 1);
	else if(strstr(arg.c_str(), "lsf")) 
		Install(STR("Fegeya List"), STR("https://github.com/ferhatgec/lsf.git"), STR("lsf"), STR("lsf"), 1);
	else if(strstr(arg.c_str(), "freebrain")) 
		Install(STR("Fegeya FreeBrain"), STR("https://github.com/ferhatgec/freebrain.git"), STR("fetcheya"), 
			STR("freebr"), 1);
	else if(strstr(arg.c_str(), "brainfuckplusplus")) 
		Install(STR("Fegeya Brainfuck++"), STR("https://github.com/ferhatgec/brainfuckplusplus.git"), STR("brainfuckplusplus"), 
			STR("bfc"), 1);
	else if(strstr(arg.c_str(), "generafor"))
		Install(STR("Fegeya Generafor"), STR("https://github.com/ferhatgec/generafor.git"), STR("generafor"), 
			STR("generafor"), 1);
	else
		std::cout << "No match for this argument : " << arg + "\n";
}

void
FInstall::Check(std::string arg) {
	FRunFunction run;
	if(arg.length() > 1) {
		arg.pop_back();
		if(arg == "fetcheya" || arg == "flascript" || arg == "copyboard" ||
			arg == "lsf" || arg == "freebrain" || arg == "brainfuckplusplus") {
				if(fsplusplus::IsExistFile("/bin/" + arg) == true)
					run.RunFunction(arg);
				else {
					arg = "fpi --i " + arg;
					InstallFunction(arg, 1);
				}
		} else run.RunFunction(arg);
	} else run.RunFunction(arg);
}
