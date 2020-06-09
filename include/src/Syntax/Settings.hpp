/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "FileFunction.hpp"
#include "Log.hpp"
#include "../Scrift.hpp"
#include <pwd.h>
#include "../synflang.hpp"

class FSettings {
public:
    FeLog *logsystem = new FeLog();
    FileFunction::FCreateFileFunction *createfile = new FileFunction::FCreateFileFunction();
    FileFunction::FReadFileFunction *readfile = new FileFunction::FReadFileFunction();	
    fchar* fname;
    integer linenumber;
    std::string WelcomeEmoji = ":thinking_face:";
    std::string EraseAllSubString(std::string & mainString, const std::string & erase)
    {
    size_t pos = std::string::npos;
    while((pos = mainString.find(erase)) != std::string::npos)
    {
        mainString.erase(pos, erase.length());
    }
    return mainString;
    }
    std::string fsettings_username; 
    virtual func ReadFile()
    {
    std::string line;
    std::string ftest;
    uid_t fuid = geteuid();
    struct passwd *password = getpwuid(fuid);
    std::string fpath;
    fpath.append("/home/");
    fpath.append(password->pw_name);
    fpath.append("/");
    fpath.append(".scrift_settings");
    std::ifstream readfile(fpath);
    if(readfile.is_open()) {
    while (std::getline(readfile, line))
    {
        if(line.rfind("felog_cleaner", 0) == 0)
        {
        	std::string fsettings = EraseAllSubString(line, "felog_cleaner ");
        	linenumber = atoi(fsettings.c_str());
        } else {
        	createfile->CreateSettingsFileFunction();
        	return;
        }
        
        if(line.rfind("welcome_emoji", 0) == 0) {
        	WelcomeEmoji = EraseAllSubString(line, "welcome_emoji ");
        } else {
        	createfile->CreateSettingsFileFunction();
        	return;
        }
    }
    }
}
};

#endif // RUN_FUNCTION_HPP_
