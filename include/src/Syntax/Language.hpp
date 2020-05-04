/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP
#include "Colors.hpp"
#include "Log.hpp"
#include "Settings.hpp"
#include "../main.h"
#include "CommandFunc.h"
#include <pwd.h>

class FLanguage {
public:
    // Keywords
    fchar* sprintlnf = "printlnf";
    fchar* string = "string";
    virtual func ReadFunc(std::string filename)
    {
    std::string line;
    FCommand *command = new FCommand();
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(filename);
    path.append(scrift);
    std::ifstream readfile(path);
    if(readfile.is_open()) {
    while (std::getline(readfile, line))
    {
        if(line.find(sprintlnf, 0) == 0)
            std::cout << line.erase(0, 10) << "\n";
    }
    }

}

};

#endif // LANGUAGE_HPP