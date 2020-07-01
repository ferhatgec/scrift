/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>
#include <Syntax/Template.hpp>
#include <Scrift.hpp>

// Libraries
#include "../../Library/FileSystemPlusPlus.h"
#include "../../Library/Colorized.hpp"

void
FTemplate::LangTemplate() {
	std::string name, lang;
	colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), "File name:");
	std:getline(std::cin, name);
	colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), "Template (e.g. c, cpp, go, flascript, python):");
	std::getline(std::cin, lang);
	if(lang == "cpp") {
		fsplusplus::CreateFile(name, CPlusPlusTemplate());
	} else if(lang == "c") {
		fsplusplus::CreateFile(name, CTemplate());
	} else if(lang == "go") {
		fsplusplus::CreateFile(name, GoTemplate());
	} else if(lang == "flascript") {
		fsplusplus::CreateFile(name, FlaScriptTemplate());
	} else if(lang == "python") {
		fsplusplus::CreateFile(name, PythonTemplate());
	} else if(lang == "haskell") {
		fsplusplus::CreateFile(name, HaskellTemplate());
	} else {
		fsplusplus::CreateFile(name, "Sorry, this is not available for Scrift, Try again later... Or create pull request for Template.cpp and Template.hpp\n\nhttps://github.com/FerhatGec/scrift-lang");
	}
}

