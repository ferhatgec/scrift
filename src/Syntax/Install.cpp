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

/* Definitions */
#define IS_EXIST(x) std::cout << x << " already installed\nWould you like to run it? (y/n) : ";
#define IS_NOT_EXIST(x) std::cout << x << " is not installed.\nDo you want to install " << x << " from source? (y/n) : ";

#define IS_NOT_SUPER_USER(x) std::cout << "Use '" << x << "' as super user.\n"
#define IS_NOT_FOUND(x) std::cout << x << " not found. Aborted.\n";

void HelpFunction();

/*
	TODO: Loading bar?
*/

/*
	Fetcheya : Colorized System info application.
*/
void
FInstall::InstallFetcheya() {
	ExecutePlusPlus exec;
	/* Check is exist? */
	if(fsplusplus::IsExistFile("/bin/fetcheya") == false) {
		#ifdef __FreeBSD__
			IS_NOT_SUPER_USER("fetcheya")
		#else
			IS_NOT_EXIST("Fetcheya")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/fetcheya.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/fetcheya");
							std::cout << "Directory changed. : " << path << "\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");

							if(fsplusplus::IsExistFile("/bin/fetcheya") == true)
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
		#endif
	} else {
		IS_EXIST("Fetcheya")
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("fetcheya");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallFlaScript() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/fla") == false) {
		#ifdef __FreeBSD__
			IS_NOT_SUPER_USER("flascript")
		#else
			IS_NOT_EXIST("FlaScript (fla)")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/flascript.git"); /* Clone repo */
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/flascript");
							std::cout << "Directory changed. : " << path << "\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh"); /* Run Shell script */

							if(fsplusplus::IsExistFile("/bin/fla") == true)
								std::cout << "\nInstalled!\n";
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
		#endif
	} else {
		IS_NOT_EXIST("FlaScript (fla)")
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("fla");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallCopyboard() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/copyboard") == false) {
		#ifdef __FreeBSD__
			IS_NOT_SUPER_USER("copyboard")
		#else
			IS_NOT_EXIST("Copyboard")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/copyboard.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/copyboard");
							std::cout << "Directory changed. : " << path << "\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");

							if(fsplusplus::IsExistFile("/bin/copyboard") == true)
								std::cout << "\nInstalled!\n";
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
		#endif
	} else {
		IS_EXIST("Copyboard")
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("copyboard");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallFegeyaList() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/lsf") == false) {
		#ifdef __FreeBSD__
			IS_NOT_SUPER_USER("lsf")
		#else
			IS_NOT_EXIST("Fegeya List (lsf)")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/lsf.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/lsf");
							std::cout << "Directory changed. : " << path << "\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");

							if(fsplusplus::IsExistFile("/bin/lsf") == true)
								std::cout << "\nInstalled!\n";
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
		#endif
	} else {
		IS_NOT_EXIST("Fegeya List (lsf)")
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("lsf");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallFreeBrain() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/freebr") == false) {
		#ifdef __FreeBSD__
			IS_NOT_SUPER_USER("freebrain")
		#else
			IS_NOT_EXIST("FreeBrain (freebr)")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/freebrain.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/freebrain");
							std::cout << "Directory changed. : " << path << "\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");

							if(fsplusplus::IsExistFile("/bin/freebr") == true)
								std::cout << "\nInstalled!\n";
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
		#endif
	} else {
		IS_EXIST("FreeBrain (freebr)")
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("freebr");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallBrainfuckPlusPlus() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/bfc") == false) {
		#ifdef __FreeBSD__
			IS_NOT_SUPER_USER("brainfuckplusplus")
		#else
			IS_NOT_EXIST("BrainfuckPlusPlus (bfc)")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/brainfuckplusplus.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/brainfuckplusplus");
							std::cout << "Directory changed. : " << path << "\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";

							exec.RunFunction("sudo sh install.sh");
							if(fsplusplus::IsExistFile("/bin/bfc") == true)
								std::cout << "\nInstalled!\n";
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
		#endif
	} else {
		IS_EXIST("BrainfuckPlusPlus (bfc)")
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("bfc");
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
		if(strstr(arg.c_str(), "fetcheya")) InstallFetcheya();
		else if(strstr(arg.c_str(), "flascript")) InstallFlaScript();
		else if(strstr(arg.c_str(), "copyboard")) InstallCopyboard();
		else if(strstr(arg.c_str(), "lsf")) InstallFegeyaList();
		else if(strstr(arg.c_str(), "freebrain")) InstallFreeBrain();
		else if(strstr(arg.c_str(), "brainfuckplusplus")) InstallBrainfuckPlusPlus();
		else
			std::cout << "No match for this argument : " << arg + "\n";
	} else
		HelpFunction();
}

void HelpFunction() {
	std::cout << "Fegeya Package Installer (fpi)\nUsage: fpi [--i] <app>\n<app> :\n* fetcheya\n* flascript (fla)\n* copyboard\n*" <<
		" lsf\n* freebrain (freebr)\n* brainfuckplusplus (bfc)\n";
}
