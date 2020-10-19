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

void
FTemplate::LangTemplate() {
	std::string name, lang;
	colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), "File name: ");
	
	BOLD_CYAN_COLOR
	std::getline(std::cin, name);
	colorized::PrintWith(colorized::Colorize(BOLD, CYAN).c_str(), 
		"Template (e.g. c, cpp, go, flascript, freebrain, rust, bash, d, python): ");
		
	BOLD_BLUE_COLOR
	std::getline(std::cin, lang);
	BLACK_COLOR
	
	if(lang == "cpp")
		fsplusplus::CreateFile(name, CPlusPlusTemplate());
	else if(lang == "c")
		fsplusplus::CreateFile(name, CTemplate());
	else if(lang == "go")
		fsplusplus::CreateFile(name, GoTemplate());
	else if(lang == "flascript")
		fsplusplus::CreateFile(name, FlaScriptTemplate());
	else if(lang == "python")
		fsplusplus::CreateFile(name, PythonTemplate());
	else if(lang == "haskell")
		fsplusplus::CreateFile(name, HaskellTemplate());
	else if(lang == "dart")
		fsplusplus::CreateFile(name, DartTemplate());
	else if(lang == "lua")
		fsplusplus::CreateFile(name, LuaTemplate());
	else if(lang == "rust")
		fsplusplus::CreateFile(name, RustTemplate());
	else if(lang == "ruby")
		fsplusplus::CreateFile(name, RubyTemplate());
	else if(lang =="bash")
		fsplusplus::CreateFile(name, BashTemplate());
	else if(lang == "csharp")
		fsplusplus::CreateFile(name, CSharpTemplate());
	else if(lang == "freebrain")
		fsplusplus::CreateFile(name, FreeBrainTemplate());
	else if(lang == "brainfuck")
		fsplusplus::CreateFile(name, BrainfuckTemplate());
	else if(lang == "d")
		fsplusplus::CreateFile(name, DLangTemplate());
	else if(lang == "odin")
		fsplusplus::CreateFile(name, OdinTemplate());
	else if(lang == "fish")
		fsplusplus::CreateFile(name, FishTemplate());
	else if(lang == "wren")
		fsplusplus::CreateFile(name, WrenTemplate());
	else if(lang == "holyc")
		fsplusplus::CreateFile(name, HolyCTemplate());
	else if(lang == "elixir")
		fsplusplus::CreateFile(name, ElixirTemplate());
	else
		fsplusplus::CreateFile(name, "Sorry, this is not available for Scrift, Try again later... Or create pull request for Template.cpp and Template.hpp\n\nhttps://github.com/ferhatgec/scrift");
}

