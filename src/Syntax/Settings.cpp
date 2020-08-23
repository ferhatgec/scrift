/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <pwd.h>
#include <ctime>
#include <memory>

#include <src/Syntax/Settings.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Syntax/Log.hpp>
#include <src/synflang.hpp>
#include <src/Scrift.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <StringTools.h>
#include <Colorized.hpp>
#include <StringTools.h>

std::unique_ptr<FileFunction::FCreateFileFunction> createfile(new FileFunction::FCreateFileFunction);
std::unique_ptr<FileFunction::FReadFileFunction> readfile(new FileFunction::FReadFileFunction);	


/* 
	.scrift_settings 
*/
std::string 
FSettings::Path() {
    std::string Path;
    Path.append(getenv("HOME"));
    Path.append("/");
    return Path.append(".scrift_settings");
}

std::string GPath() {
	FSettings pth;
	return pth.Path();
}

std::ifstream freadfile(GPath());


/*	
	welcome_message yes: Shows Welcome message
		* Welcome to Fegeya Scrift Terminal 
		* Fegeya Scrift licensed with MIT License 
		* Copyright (c) 2020 Ferhat Gecdogan
 
	welcome_message no_thanks: 
*/

bool 
FSettings::WelcomeMessage() {
	std::string line = fsplusplus::FindStringWithReturn(Path(), "welcome_message");
	if(strstr(line.c_str(), "no_thanks"))
		return false;
 	else
		return true;

	return true;
}

/*
	local_git_branch yes
		... [develop]
	
	local_git_branch no_thanks
		...
*/

bool
FSettings::GitBranch() {
	std::string line = fsplusplus::FindStringWithReturn(Path(), "local_git_branch");
	if(strstr(line.c_str(), "no_thanks"))
		return false;
	else
		return true;

	return true;
}

/*
	<emoji> emoji: Shows emoji.
*/
std::string 
FSettings::FWelcomeEmoji() {
    std::string line;
    std::string ftest;
    if(freadfile.is_open()) {
    	while(std::getline(freadfile, line)) {
    		if(line.rfind("welcome_emoji", 0) == 0)
    			return stringtools::EraseAllSubString(line, "welcome_emoji ");
    		else
    			createfile->CreateSettingsFileFunction(); 
    	}
    }
    return ":thinking_face:";
}

/*
	<felog> value: Clears your Felog history if Felog line more than value.
*/
int 
FSettings::FeLogCleaner() {
   std::string line;
   std::string ftest;
    if(freadfile.is_open()) {
    	while(std::getline(freadfile, line)) {
    		if(line.rfind("felog_cleaner", 0) == 0) {
    			if(atoi(stringtools::EraseAllSubString(line, "felog_cleaner ").c_str()) <= 5) {
    				BOLD_RED_COLOR
    				printlnf("Please give 5 or higher value for felog_cleaner.\n");
    				BLACK_COLOR
    				return 20;
    			} else {
    				return atoi(stringtools::EraseAllSubString(line, "felog_cleaner ").c_str());
    			}
    		} else {
    			createfile->CreateSettingsFileFunction();
    		} 
    	}
    }
    return 100;
}

int 
FSettings::random(int min_num, int max_num) {
    srand(time(0));
    return rand() % (max_num - min_num + 1 ) + min_num;
}
    
int 
FSettings::color() {
    int x = random(0, 2);
    if(x == 1)
    	return random(30, 37);
    else if(x == 2)
    	return random(90, 97);
    else if(x == 0)
    	return random(30, 37); 
 	
    return random(90, 97);
}

/*
	<asciiart> no_thanks: Not shows ASCIIArt.
	<asciiart> random: Shows ASCIIArt with random color.
	<asciiart> <value>: Shows ASCIIArt with <value>.
*/
int 
FSettings::ASCIIColor() {
    std::string line;
    if(freadfile.is_open()) {
    	while(std::getline(freadfile, line)) {
    		if(line.rfind("ascii_art_color", 0) == 0) {
    			if(stringtools::EraseAllSubString(line, "ascii_art_color ") == "no_thanks") {
				return -1;
			} else if(stringtools::EraseAllSubString(line, "ascii_art_color ") != "random" && 
			atoi(stringtools::EraseAllSubString(line, "ascii_art_color ").c_str()) <= 29) {
    				BOLD_RED_COLOR
    				printlnf("Give 30 or higher value for ascii_art_color.\n");
    				BLACK_COLOR
    				return 34;
    			} else if(stringtools::EraseAllSubString(line, "ascii_art_color ") == "random") {
    				return color();
    			} else {
    				return atoi(stringtools::EraseAllSubString(line, "ascii_art_color ").c_str());
    			}
    		} else {
    			createfile->CreateSettingsFileFunction();
    		} 
    	}
    }
    return 34;
}
    
int 
FSettings::BackgroundColor() {
    std::string line;
    if(freadfile.is_open()) {
    	while(std::getline(freadfile, line)) {
    		if(line.rfind("bg_color") == 0)
    			return atoi(stringtools::EraseAllSubString(line, "bg_color ").c_str());
    		else
    			createfile->CreateSettingsFileFunction(); 
    	}
    }
    return 12;
}

/*
	default: input color is a lot of colors!
	classic: input color is light white.
*/
std::string 
FSettings::Theme() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "scrift_theme");
    if(strstr(line.c_str(), "default"))
	return "default";
    else if(strstr(line.c_str(), "classic"))
	return "classic";
    else
	return "default";

    return "default";
}

/*
	<username>@<hostname>:~<path> (input_customize) 
*/
std::string 
FSettings::InputCustomize() {
    std::string line;
    if(freadfile.is_open()) {
    	while(std::getline(freadfile, line)) {
    		if(line.find("input_customize") == 0)
    			return stringtools::EraseAllSubString(line, "input_customize ");
    	}
    }
    return "▶";
}
