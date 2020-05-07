/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "FileFunction.hpp"
#include "Log.hpp"
#include "../Scrift.hpp"
#include <pwd.h>


class FRunFunctionSyntax {
    FeLog *logsystem = new FeLog();
    FileFunction::FCreateFileFunction *createfile = new FileFunction::FCreateFileFunction();
    FileFunction::FReadFileFunction *readfile = new FileFunction::FReadFileFunction();
public:
    fchar* fprinttext = "printtext";
    fchar* fname;
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
        if(line.find(fprinttext, 0) == 0)
        std::cout << line.erase(0, 10) << "\n";
    }
    }
}
};

#endif // RUN_FUNCTION_HPP_