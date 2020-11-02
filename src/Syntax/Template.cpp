/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>

#include <src/Syntax/Template.hpp>
#include <src/Scrift.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <Colorized.hpp>
#include <StringTools.h>

void
FTemplate::LangTemplate(std::string name) {
    if(strstr(name.c_str(), ".cpp"))
		fsplusplus::CreateFile(name, CPlusPlusTemplate());
	else if(strstr(name.c_str(), ".cpp"))
		fsplusplus::CreateFile(name, CTemplate());
	else if(strstr(name.c_str(), ".go"))
		fsplusplus::CreateFile(name, GoTemplate());
	else if(strstr(name.c_str(), ".fls"))
		fsplusplus::CreateFile(name, FlaScriptTemplate());
	else if(strstr(name.c_str(), ".py"))
		fsplusplus::CreateFile(name, PythonTemplate());
	else if(strstr(name.c_str(), ".hs"))
		fsplusplus::CreateFile(name, HaskellTemplate());
	else if(strstr(name.c_str(), ".dart"))
		fsplusplus::CreateFile(name, DartTemplate());
	else if(strstr(name.c_str(), ".lua"))
		fsplusplus::CreateFile(name, LuaTemplate());
	else if(strstr(name.c_str(), ".rs"))
		fsplusplus::CreateFile(name, RustTemplate());
	else if(strstr(name.c_str(), ".rb"))
		fsplusplus::CreateFile(name, RubyTemplate());
	else if(strstr(name.c_str(), ".bash"))
		fsplusplus::CreateFile(name, BashTemplate());
	else if(strstr(name.c_str(), ".cs"))
		fsplusplus::CreateFile(name, CSharpTemplate());
	else if(strstr(name.c_str(), ".frbr"))
		fsplusplus::CreateFile(name, FreeBrainTemplate());
	else if(strstr(name.c_str(), ".bf"))
		fsplusplus::CreateFile(name, BrainfuckTemplate());
	else if(strstr(name.c_str(), ".d"))
		fsplusplus::CreateFile(name, DLangTemplate());
	else if(strstr(name.c_str(), ".odin"))
		fsplusplus::CreateFile(name, OdinTemplate());
	else if(strstr(name.c_str(), ".fish"))
		fsplusplus::CreateFile(name, FishTemplate());
	else if(strstr(name.c_str(), ".wren"))
		fsplusplus::CreateFile(name, WrenTemplate());
	else if(strstr(name.c_str(), ".hc"))
		fsplusplus::CreateFile(name, HolyCTemplate());
	else if(strstr(name.c_str(), ".ex"))
		fsplusplus::CreateFile(name, ElixirTemplate());
	else
		fsplusplus::CreateFile(name, "Sorry, this is not available for Scrift, Try again later... Or create pull request for Template.cpp and Template.hpp\n\nhttps://github.com/ferhatgec/scrift");
}

