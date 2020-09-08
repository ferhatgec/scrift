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
FInstall::InstallFetcheya(int uninstall) {
	ExecutePlusPlus exec;
	/* Check is exist? */
	if(fsplusplus::IsExistFile("/bin/fetcheya") == false) {
		if(uninstall == 1) {
			CANNOT_BE_REMOVED("Fetcheya")
		} else {
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

							#ifdef __FreeBSD__
								 if (getuid())
									IS_NOT_SUPER_USER("Fetcheya")
								 else
								 	exec.RunFunction("sh install.sh");
							#else
								exec.RunFunction("sudo sh install.sh");
							#endif

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
		}
	} else {
		if(uninstall == 1) {
			UNINSTALL("Fetcheya")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				exec.RunFunction("sudo rm -f /bin/fetcheya");
				if(fsplusplus::IsExistFile("/bin/fetcheya") == false)
					std::cout << "Removed!\n";
				else
					std::cout << "Could not remove.\n";
			} else
				std::cout << "Aborted.\n";
		} else {
			IS_EXIST("Fetcheya")
			char input = getchar();
			if(input == 'y' || input == 'Y')
				exec.RunFunction("fetcheya");
			else
				std::cout << "Aborted.\n";
		}
	}
}

void
FInstall::InstallFlaScript(int uninstall) {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/fla") == false) {
		if(uninstall == 1) {
			CANNOT_BE_REMOVED("FlaScript (fla)")
		} else {
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
							#ifdef __FreeBSD__
								 if (getuid())
									IS_NOT_SUPER_USER("FlaScript (fla)")
								 else
								 	exec.RunFunction("sh install.sh");
							#else
								exec.RunFunction("sudo sh install.sh"); /* Run Shell script */
							#endif
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
		}
	} else {
		if(uninstall == 1) {
			UNINSTALL("FlaScript (fla)")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				exec.RunFunction("sudo rm -f /bin/fla");
				if(fsplusplus::IsExistFile("/bin/fla") == false)
					std::cout << "Removed!\n";
				else
					std::cout << "Could not remove.\n";
			} else
				std::cout << "Aborted.\n";
		} else {
			IS_EXIST("FlaScript (fla)")
			char input = getchar();
			if(input == 'y' || input == 'Y')
				exec.RunFunction("fla");
			else
				std::cout << "Aborted.\n";
		}
	}
}

void
FInstall::InstallCopyboard(int uninstall) {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/copyboard") == false) {
		if(uninstall == 1) {
			CANNOT_BE_REMOVED("Copyboard")
		} else {
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
							#ifdef __FreeBSD__
								 if (getuid())
									IS_NOT_SUPER_USER("Copyboard")
								 else
								 	exec.RunFunction("sh install.sh");
							#else
								exec.RunFunction("sudo sh install.sh");
							#endif

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
		}
	} else {
		if(uninstall == 1) {
			UNINSTALL("Copyboard")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				exec.RunFunction("sudo rm -f /bin/copyboard");
				if(fsplusplus::IsExistFile("/bin/copyboard") == false)
					std::cout << "Removed!\n";
				else
					std::cout << "Could not remove.\n";
			} else
				std::cout << "Aborted.\n";
		} else {
			IS_EXIST("Copyboard")
			char input = getchar();
			if(input == 'y' || input == 'Y')
				exec.RunFunction("copyboard");
			else
				std::cout << "Aborted.\n";
		}
	}
}

void
FInstall::InstallFegeyaList(int uninstall) {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/lsf") == false) {
		if(uninstall == 1) {
			CANNOT_BE_REMOVED("Fegeya List (lsf)")
		} else {
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
							#ifdef __FreeBSD__
								 if (getuid())
									IS_NOT_SUPER_USER("Fegeya List (lsf)")
								 else
								 	exec.RunFunction("sh install.sh");
							#else
								exec.RunFunction("sudo sh install.sh");
							#endif

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
		}
	} else {
		IS_EXIST("Fegeya List (lsf)")
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("lsf");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallFreeBrain(int uninstall) {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/freebr") == false) {
		if(uninstall == 1) {
			CANNOT_BE_REMOVED("FreeBrain (freebr)")
		} else {
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
							#ifdef __FreeBSD__
								 if (getuid())
									IS_NOT_SUPER_USER("FreeBrain (freebr)")
								 else
								 	exec.RunFunction("sh install.sh");
							#else
								exec.RunFunction("sudo sh install.sh");
							#endif

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
		}
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
FInstall::InstallBrainfuckPlusPlus(int uninstall) {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/bfc") == false) {
		if(uninstall == 1) {
			CANNOT_BE_REMOVED("BrainfuckPlusPlus (bfc)")
		} else {
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
							#ifdef __FreeBSD__
								 if (getuid())
									IS_NOT_SUPER_USER("BrainfuckPlusPlus (bfc)")
								 else
									exec.RunFunction("sh install.sh");
							#else
								exec.RunFunction("sudo sh install.sh");
							#endif
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
		}
	}  else {
		if(uninstall == 1) {
			UNINSTALL("BrainfuckPlusPlus (bfc)")
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				exec.RunFunction("sudo rm -f /bin/bfc");
				if(fsplusplus::IsExistFile("/bin/bfc") == false)
					std::cout << "Removed!\n";
				else
					std::cout << "Could not remove.\n";
			} else
				std::cout << "Aborted.\n";
		} else {
			IS_EXIST("BrainfuckPlusPlus (bfc)")
			char input = getchar();
			if(input == 'y' || input == 'Y')
				exec.RunFunction("bfc");
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
	std::cout << "Fegeya Package Installer (fpi)\nUsage: fpi [--i --install || --uni --uninstall] <app>\n<app> :\n* fetcheya\n* flascript (fla)\n* copyboard\n*" <<
		" lsf\n* freebrain (freebr)\n* brainfuckplusplus (bfc)\n";
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

	if(strstr(arg.c_str(), "fetcheya")) InstallFetcheya(0);
	else if(strstr(arg.c_str(), "flascript")) InstallFlaScript(0);
	else if(strstr(arg.c_str(), "copyboard")) InstallCopyboard(0);
	else if(strstr(arg.c_str(), "lsf")) InstallFegeyaList(0);
	else if(strstr(arg.c_str(), "freebrain")) InstallFreeBrain(0);
	else if(strstr(arg.c_str(), "brainfuckplusplus")) InstallBrainfuckPlusPlus(0);
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

	if(strstr(arg.c_str(), "fetcheya")) InstallFetcheya(1);
	else if(strstr(arg.c_str(), "flascript")) InstallFlaScript(1);
	else if(strstr(arg.c_str(), "copyboard")) InstallCopyboard(1);
	else if(strstr(arg.c_str(), "lsf")) InstallFegeyaList(1);
	else if(strstr(arg.c_str(), "freebrain")) InstallFreeBrain(1);
	else if(strstr(arg.c_str(), "brainfuckplusplus")) InstallBrainfuckPlusPlus(1);
	else
		std::cout << "No match for this argument : " << arg + "\n";
}
