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
	void Install(std::string name, std::string repository, std::string object, std::string folder, int type); /* int : Uninstall */

	void InstallFunction(std::string, int); /* Arg, Type */
	void UnInstallFunction(std::string, int); /* Arg, Type */
	void FegeyaPackageInstaller(std::string); /* Arg */
	
	void Check(std::string);
};

#endif // LINKER_HPP
