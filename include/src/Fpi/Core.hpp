/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <cstring>

class FInstall {
public:
	void Install(std::string name, std::string repository, std::string object, std::string folder, int type); /* int : Uninstall */

	void InstallFunction(std::string, int); /* Arg, Type */
	void UnInstallFunction(std::string, int); /* Arg, Type */
	void FegeyaPackageInstaller(std::string); /* Arg */
	void InfoFunction(std::string arg);
	
	void Check(std::string arg);
	void Info(std::string app, std::string desc, std::string author);
};

#endif // CORE_HPP
