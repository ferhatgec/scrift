
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "../../include/src/Syntax/CommandFunc.h"
#include "../../include/src/main.h"
#include "../../include/src/Syntax/GetNameFunction.hpp"
#include "../../include/src/Syntax/CDFunction.hpp"
#include "../../include/src/Syntax/PrintErrorFunction.hpp"
#include "../../include/src/Syntax/MkdirFunction.hpp"
#include <iostream>
#include <unistd.h>
FCommand *command = new FCommand();
FMain *fmain = new FMain();
fprinterror *printerror = new fprinterror;
std::string str;
struct stat sb;
fchar *file_path = new fchar;


FCDFunction::FCDFunction()
{
    
}



FCDFunction::~FCDFunction()
{
    delete fmain, printerror, command, str;
}


bool FileExists(const std::string &Filename)
{
    return access(Filename.c_str(), 0 ) == 0;
}

void
FCDFunction::CDFunctionInit()
{
    command = new FCommand();
    fmain = new FMain();
    std::cin >> str;
    // or std::getline
    if(str != "") 
    {
        if(fmain->_home != true) 
        {
            std::string path;
            path.append(command->_file_path_cd_function);
            path.append("/");
            path.append(str);
            if(FileExists(path) == true) {
                std::strcat(command->_file_path_cd_function, "/");
                std::strcat(command->_file_path_cd_function, str.c_str()); 
            }
            slashn
        }
    } 
    else 
    {
        printerror->PrintError("This directory is null");
        slashn 
    }  
    return;         
}
