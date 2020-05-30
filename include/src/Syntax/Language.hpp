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
#include "../Scrift.hpp"
#include "CommandFunc.h"
#include <pwd.h>
#include <vector>
#include "../synflang.hpp"
#include "FileFunction.hpp"

class FLanguage {
public:
    // Keywords
    std::string name;

    // Test
    fchar* red = "(red)";

    std::string EraseAllSubString(std::string & mainString, const std::string & erase)
    {
    size_t pos = std::string::npos;
    while((pos = mainString.find(erase)) != std::string::npos)
    {
        mainString.erase(pos, erase.length());
    }
    return mainString;
    }

    virtual func ReadFunc(std::string filename)
    {
    FileFunction::FCDFunction *cdfunc = new FileFunction::FCDFunction();
    FRunFunction *run = new FRunFunction();
    std::string line;
    float floatvar;
    FCommand *command = new FCommand();
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(filename);
    path.append(scrift);
    std::ifstream readfile(path);
    fchar* printstr;
    std::string sfname;
    std::string inputcommand;
    integer finteger = 0;
    fchar* sprintlnf = "printlnf(";
    integer f;
    if(readfile.is_open()) {

    while (std::getline(readfile, line))
    {
        if(line.find("slashn", 0) == 0) {
            slashn
        }

        if(line.find("integer", 0) == 0) {
            finteger = std::atoi(line.erase(0, 8).c_str());
        }
        if(line.find("#*", 0) == 0) {
            if(line.find("*#", 0) == 0) {
                printlnf("Found..\n");
            }
        }

        if(line.rfind("# ", 0) == 0)
        {
           line.erase(line.begin(), line.end());
           std::cout << line;
        }
        if(line.rfind("input", 0) == 0) {
            std::cin >> inputcommand;
        }



        if(line.find("wsinput", 0) == 0)
        {
            std::getline(std::cin, inputcommand);
        }

        if(line == "inputpr") {
            printlnf(inputcommand.c_str());
        }

        if(line.find("fplus(", 0) == 0)
        {
            std::string test = EraseAllSubString(line, "fplus(");
            test = EraseAllSubString(test, ");");
            f = std::atoi(test.c_str());
        }

        if(line.find("splus(", 0) == 0)
        {
            std::string test = EraseAllSubString(line, "splus(");
            test = EraseAllSubString(test, ");");
            f = f + std::atoi(test.c_str());
        }

        if(line == "plpr")
        {
            std::cout << f;
        }

        if(line == "return")
        {
            return;
        }

        if(line.find("function()",0) == 0) {
            std::string voidf = EraseAllSubString(line, "function()");
        }

        if(line.find("{", 0) == 0  && line.find("}", 4) == 0) {
            std::string voids = EraseAllSubString(voids, "{");
            voids = EraseAllSubString(voids, "}");
            line = voids;
        }

        if(line.find("string", 0) == 0) {
            name = line.erase(0, 7);
        }
	
	if(line.find("(green)printlnf", 0) == 0)
	{
           std::string test = EraseAllSubString(line, "(green)printlnf(\"");
           std::cout << WBOLD_GREEN_COLOR << EraseAllSubString(test, "\");") << WBLACK_COLOR;
	}
	
	
	if(line.find("(red)printlnf", 0) == 0)
	{
           std::string test = EraseAllSubString(line, "(red)printlnf(\"");
           std::cout << WBOLD_RED_COLOR << EraseAllSubString(test, "\");") << WBLACK_COLOR;
	}
		
        if(line.find("printlnf", 0) == 0)
        {
           std::string test = EraseAllSubString(line, "printlnf(\"");
           std::cout << EraseAllSubString(test, "\");");
        }
							
        if (line == "floatpr")
        {
            std::cout << floatvar;
        }

        if (line.rfind("intpr", 0) == 0)
        {
            std::cout << finteger;
        }

        if (line.find("sysjam", 0) == 0)
        {
          std::string jamfile = EraseAllSubString(line, "sysjam(\"");
          jamfile = EraseAllSubString(jamfile, "\");");
          run->RunJamFunction(jamfile);
          std::cout << "RunFunction calling" + jamfile;
          slashn
        }

        if (line.find("system", 0) == 0)
        {
            std::string test = EraseAllSubString(line, "system(\"");
            test = EraseAllSubString(test, "\");");
            if(test.rfind("fr", 0) == 0)
            {
            	test = EraseAllSubString(line, "fr ");
            	std::string path = "cd ";
            	path.append(test);
            	system(path.c_str());
            }
            run->RunFunction(test);
            std::cout << "RunFunction calling " + test;
            slashn
        }
        if(line.rfind("strpr", 0) == 0)
            std::cout << name << "\n";
        }
    }

}

};

#endif // LANGUAGE_HPP
