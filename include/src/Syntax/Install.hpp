/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef INSTALL_HPP
#define INSTALL_HPP

#include <iostream>
#include <cstring>

class FInstall {
public:
	void InstallFetcheya(int); /* int : Uninstall */
	void InstallFlaScript(int);
	void InstallCopyboard(int);
	void InstallFegeyaList(int); /* Lsf */
	void InstallFreeBrain(int);
	void InstallBrainfuckPlusPlus(int); /* Brainfuck Implementation */


	void InstallFunction(std::string, int); /* Arg, Type */
	void UnInstallFunction(std::string, int); /* Arg, Type */
	void FegeyaPackageInstaller(std::string); /* Arg */
};

#endif // LINKER_HPP
