/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <pwd.h>
#include <ctime>

#include <src/Syntax/Tools.hpp>
#include <src/Syntax/Branch.hpp>
#include <src/Syntax/GetNameFunction.hpp>
#include <src/Syntax/Settings.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <StringTools.h>
#include <Colorized.hpp>

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


/*
	welcome_message yes: Shows Welcome message
		* Welcome to Fegeya Scrift Terminal
		* Fegeya Scrift licensed with MIT License
		* Copyright (c) 2020 Ferhat Gecdogan

	welcome_message no_thanks:
*/

int
FSettings::WelcomeMessage() {
	std::string line = fsplusplus::FindStringWithReturn(Path(), "welcome_message");
	if(strstr(line.c_str(), "no_thanks_all"))
		return 0;
 	else if(strstr(line.c_str(), "no_thanks"))
		return 2;
 	else
		return 1;

	return 1;
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
        scrift_setup yes
        scrift_setup no
*/
bool
FSettings::Setup() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "scrift_setup");
    if(strstr(line.c_str(), "yes"))
        return true;
    else
        return false;

    return true;
}

/*
        date_info yes
        date_info no
*/
bool
FSettings::Date() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "date_info");
    if(strstr(line.c_str(), "yes"))
        return true;
    else
        return false;

    return true;
}

/*
	<emoji> emoji: Shows emoji.
*/
std::string
FSettings::FWelcomeEmoji() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "welcome_emoji");
    return stringtools::EraseAllSubString(line, "welcome_emoji ");
}

/*
	<felog> value: Clears your Felog history if Felog line more than value.
*/
int
FSettings::FeLogCleaner() {
	std::string line = fsplusplus::FindStringWithReturn(Path(), "felog_cleaner");

   	if(atoi(stringtools::EraseAllSubString(line, "felog_cleaner ").c_str()) <= 5) {
		colorized::PrintWith(colorized::Colorize(BOLD, RED), "felog_cleaner : Give 5 or higher value.\n");
   		return 20;
   	} else 
		return atoi(stringtools::EraseAllSubString(line, "felog_cleaner ").c_str());

    return 100;
}

int
FSettings::random(int min_num, int max_num) {
    srand(time(nullptr));
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
    std::string line = fsplusplus::FindStringWithReturn(Path(), "ascii_art_color");
    if(strstr(line.c_str(), "no_thanks"))
		return -1;
    else if(strstr(line.c_str(), "random"))
		return color();
    else if(atoi(stringtools::EraseAllSubString(line, "ascii_art_color ").c_str()) <= 29) {
		colorized::PrintWith(colorized::Colorize(BOLD, RED), "ascii_art_color : Give 30 or higher value.\n");
		return 34;
    } else
		return atoi(stringtools::EraseAllSubString(line, "ascii_art_color ").c_str());
    
    return 34;
}

/*
	Background color.
*/
int
FSettings::BackgroundColor() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "bg_color");
    return atoi(stringtools::EraseAllSubString(line, "bg_color ").c_str());
}

/*
	Auto clear for terminal buffer.
*/
int
FSettings::Clear() {
	std::string line = fsplusplus::FindStringWithReturn(Path(), "auto_clear");
	line = stringtools::EraseAllSubString(line, "auto_clear ");

	if(strstr(line.c_str(), "no_thanks"))
		return 2147483647;
	else {
		int val = atoi(line.c_str());
		if(val >= 2)
			return val;
		else
			return 40;
	}

	return 40;
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
    else if(strstr(line.c_str(), "halloween"))
    	return "halloween";
    else
		return "default";

    return "default";
}

/*
	<username>@<hostname>:~<path> (input_customize)
*/
std::string
FSettings::InputCustomize() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "input_customize");
    line = stringtools::EraseAllSubString(line, "input_customize ");

    return stringtools::EraseAllSubString(line, "\n");
}

std::string 
FSettings::Sign(std::string _command) {
    std::string line = fsplusplus::FindStringWithReturn(Path(), _command);
    line = stringtools::EraseAllSubString(line, _command + " ");
    return stringtools::EraseAllSubString(line, "\n");
}

/*
	Customize your Scrift prompt.
*/
void
FSettings::Customize(bool incognito) {
	std::string check, color, _color;
	
	/* get [PROMPT] line */
	std::string line = fsplusplus::FindStringWithReturn(Path(), "[PROMPT]");
	
	/* erase [PROMPT] */
	line = stringtools::EraseAllSubString(line , "[PROMPT] ");
	
	FGetUsername get;
	
	do {
		/* get 'check' variable */
		stringtools::GetBtwString(line, "@", "@", check);
		
		/* get color */
		stringtools::GetBtwString(line, "@[", "]", color);
		
		/* convert to escape sequence */
		_color = "\033[" + color;

		/* check */
		if(check == "username")
			std::cout << _color << getpwuid(geteuid())->pw_name;
		else if(check == "hostname") {
			std::cout << _color;
			get.InitHostname();
		} else if(check == "sign_1") {
			std::cout << _color << Sign(check);
		} else if(check == "sign_2") {
			std::cout << _color << Sign(check);
		} else if(check == "directory") {
			std::cout << _color << fsplusplus::GetCurrentWorkingDir();
		} else if(check == "branch") {
			FBranch branch;
			std::cout << _color << branch.GetGitBranch();
		} else if(check == "clock") {
			FTools tl;
			std::cout << _color << " "; tl.Clock();
		} else if(check == "input_sign") {
			std::cout << _color << InputCustomize();
		} else if(check == "whitespace" || check == "whspace") {
			std::cout << " ";
		} else if(check == "newline") {
			std::cout << "\n";
		} else if(check == "incognito") {
			if(incognito)
				std::cout << "🕵️";
		} else if(strstr(check.c_str(), "sign")) 
			std::cout << _color << Sign(check);

		/* erase controlled definition */
		line = stringtools::EraseAllSubString(line, "@" + check + "@[" + color + "]");
	} while(check != "error" && color != "error");
}
