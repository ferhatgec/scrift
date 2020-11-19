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
#include <filesystem>

#include <src/Scrift.hpp>
#include <src/Syntax/RunFunction.hpp>

#include <src/Fpi/Core.hpp>
#include <src/Fpi/Parser.hpp>
#include <src/Fpi/Get.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>
#include <StringTools.h>
#include <Colorized.hpp>
#include <IntelligenTUI.hpp>

/* Definitions */
#define IS_EXIST(x) std::cout << x << " already installed\nWould you like to run it? (y/n) : ";
#define IS_NOT_EXIST(x) std::cout << x << " is not installed.\nDo you want to install " << x << " from source? (y/n) : ";

#define IS_NOT_SUPER_USER(x) std::cout << "Use '" << x << "' as super user.\n"
#define IS_NOT_FOUND(x) std::cout << x << " not found. Aborted.\n";

#define CANNOT_BE_REMOVED(x) std::cout << "Really? " << x << " is not installed. Cannot be removed.\n";
#define UNINSTALL(x) std::cout << "Do you want to uninstall " << x << "? (y/n) : ";

static std::string installed = "✅ ";
static std::string uninstalled = "❎ ";

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
					
					system((STR("git clone ") + repository + STR(" &>/dev/null")).c_str());
					
					IntelligenTUI::ProgressBar(std::clog, 20, "", "=");
					
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/" + folder);
							
							chdir(path.c_str());
							
							IntelligenTUI::ProgressBar(std::clog, 20, "", "=");
							
							#ifdef __FreeBSD__
								if (getuid())
									IS_NOT_SUPER_USER(name)
								else
								 	system("sh install.sh");
							#else
								system("sudo sh install.sh &>/dev/null");
							#endif

							if(fsplusplus::IsExistFile("/bin/" + object) == true)
								std::cout << "Installed!\n";
							else
								std::cout << "Could not install.\n";
						
							chdir(getenv("HOME"));
								
							std::cout << "Cleaning..\n";
							
							std::filesystem::remove_all(STR(getenv("HOME")) + "/" + folder);
						
							IntelligenTUI::ProgressBar(std::clog, 10, "", "=");
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
		UnInstallFunction(arg, 2);
 	else if(strstr(arg.c_str(), "--uni "))
		UnInstallFunction(arg, 1);
	else if(strstr(arg.c_str(), "--info "))
		InfoFunction(arg);
	else if(strstr(arg.c_str(), "--update"))
		UpdatePackageList();
	else
		HelpFunction();
}

void Check_Installed(std::string name, std::string data, std::string object) {
	if(fsplusplus::IsExistFile("/bin/" + object) == true) {
		std::cout << installed << WBOLD_GREEN_COLOR << name + " ";
		
		RESETW printfc({160, 255, 8}, "(" + data + ")\n");
	} else {
		std::cout << uninstalled << WBOLD_GREEN_COLOR << name + " ";
		
		RESETW printfc({245, 178, 7}, "(" + data + ")\n");
	}
}


void HelpFunction() {
	RESETW printfc({8, 199, 107}, "Fegeya Package Installer ");
	
	RESETW printfc({245, 178, 7}, "(fpi)\n");
	 
	RESETW printfc({6, 140, 75}, "Usage: fpi [--i --install || --uni --uninstall | --info | --update] app\n");
}

void
FInstall::InstallFunction(std::string arg, int type) {
	FParser parser;
	
	std::cout << "Checking..\n";
	
	if(fsplusplus::IsExistFile(STR(getenv("HOME")) + "/fpi_repository/repository/") != true) {
		FGet get;
		
		get.FetchRepositoryData(STR(DEFAULT_FPI_REPOSITORY));
	}
		
	
	if(type == 1) /* fpi --i */
		arg = stringtools::EraseAllSubString(arg, "fpi --i ");
	else if(type == 2) /* fpi --install */
		arg = stringtools::EraseAllSubString(arg, "fpi --install ");
	else
		HelpFunction();

	parser.ParseRepositoryFile(arg);
	
	Install(parser.app_name, parser.app_repo, parser.app_exec, parser.app_folder, 0); 
}


void
FInstall::UnInstallFunction(std::string arg, int type) {
	FParser parser;
	
	std::cout << "Checking..\n";
	
	if(fsplusplus::IsExistFile(STR(getenv("HOME")) + "/fpi_repository/repository/") != true) {
		FGet get;
		
		get.FetchRepositoryData(STR(DEFAULT_FPI_REPOSITORY));
	}
	
	if(type == 1) /* fpi --uni */
		arg = stringtools::EraseAllSubString(arg, "fpi --uni ");
	else if(type == 2) /* fpi --uninstall */
		arg = stringtools::EraseAllSubString(arg, "fpi --uninstall ");
	else
		HelpFunction();

	parser.ParseRepositoryFile(arg);
	
	Install(parser.app_name, parser.app_repo, parser.app_exec, parser.app_folder, 1); 
}

void 
FInstall::InfoFunction(std::string arg) {
	FParser parser;
	
	if(fsplusplus::IsExistFile(STR(getenv("HOME")) + "/fpi_repository/repository/") != true) {
		FGet get;
		
		get.FetchRepositoryData(STR(DEFAULT_FPI_REPOSITORY));
	}
	
	arg = stringtools::EraseAllSubString(arg, "fpi --info ");
	
	parser.ParseRepositoryFile(arg);
	
	Info(parser);
}

void
FInstall::Info(FParser &package) {
	/* Name of package */
	std::cout << "App: " << package.app_name + "\n";
	
	/* Description of package */
	std::cout << "Desc: " << package.app_desc + "\n";
	
	/* Author of package */
	std::cout << "Author: " << package.app_author + "\n"; 

	/* License of package */
	std::cout << "License: " << package.app_license + "\n";
	
	/* Executable file of package */
	std::cout << "File: " << package.app_exec + "\n";
	
	/* Repository of package */
	std::cout << "Repository: " << package.app_repo + "\n";
}

void
FInstall::UpdatePackageList() {
	FGet get;
	
	if(fsplusplus::IsExistFile(STR(getenv("HOME")) + "/fpi_repository/repository/") != true) {
		std::cout << "Fetching from DEFAULT_FPI_REPOSITORY...";
			
		get.FetchRepositoryData(STR(DEFAULT_FPI_REPOSITORY));
	} else {
		std::cout << "Is this ok? (y/N) : ";
		char ok = getchar();
	
		if(ok == 'y' || ok == 'Y') {
			std::filesystem::remove_all(STR(getenv("HOME")) + "/fpi_repository/");
			
			get.FetchRepositoryData(STR(DEFAULT_FPI_REPOSITORY));
		} else std::cout << "Aborted.\n";
	}
}

void
FInstall::Check(std::string arg) {
	FRunFunction run;
	if(arg.length() > 1) {
		arg.pop_back();
		if(arg == "fetcheya" || arg == "flascript" || arg == "copyboard" ||
			arg == "lsf" || arg == "freebrain" || arg == "brainfuckplusplus" || 
			arg == "generafor" || arg == "desktof" || arg == "translatfe" || 
			arg == "colocat" || arg == "pls" || arg == "fisk") {
				if(fsplusplus::IsExistFile("/bin/" + arg) == true)
					run.RunFunction(arg);
				else {
					arg = "fpi --i " + arg;
					InstallFunction(arg, 1);
				}
		} else run.RunFunction(arg);
	} else run.RunFunction(arg);
}
