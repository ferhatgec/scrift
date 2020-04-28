
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "../../include/src/Syntax/CommandFunc.h"
#include "../../include/src/main.h"
#include "../../include/src/Syntax/GetNameFunction.hpp"
#include "../../include/src/Syntax/FileFunction.hpp"
#include "../../include/src/Syntax/PrintErrorFunction.hpp"
#include "../../include/src/Syntax/MkdirFunction.hpp"
#include <iostream>
#include <unistd.h>

FCommand *command = new FCommand();
FMain *fmain = new FMain();
fprinterror *printerror = new fprinterror;
std::string str;
fchar *file_path = new fchar;
fchar* input_char;
std::string path_directory;

fchar* file_name;
fchar* file_directory;
std::string file_directory_string;

FCDFunction::FCDFunction()
{
    
}



FCDFunction::~FCDFunction()
{
    delete fmain, printerror, command, str;
}


boolean
FCDFunction::FileExists(const std::string &Filename)
{
    return access(Filename.c_str(), 0 ) == 0;
}

void
FCDFunction::CDFunctionInit(std::string name)
{
    command = new FCommand();
    fmain = new FMain();
    // or std::getline
    if(name != "") 
    {
        if(fmain->_home != true) 
        {
            std::string path;
            path.append(command->_file_path_cd_function);
            path.append("/");
            path.append(name);
            if(FileExists(path) == true) {
                std::strcat(command->_file_path_cd_function, "/");
                std::strcat(command->_file_path_cd_function, name.c_str()); 
            } else {
                printerror->PrintError("This directory is not exist!");
                slashn
                return;
            }
        }
    } 
    return;         
}



FMKDirFunction::FMKDirFunction()
{
    input_char = new fchar;
}


FMKDirFunction::~FMKDirFunction()
{
    delete input_char;
}


void
FMKDirFunction::MKDirFunctionInit(std::string name)
{
    // I will use std::getline.
    path_directory.append(command->_file_path_cd_function); // default getenv("HOME")
    path_directory.append("/"); // ex: /home/username -> getenv("HOME") -> /home/username'/'
    path_directory.append(name); // maybe directory is exist or directory is not exist.
    if(mkdir(path_directory.c_str(), 0777) == -1 ) {// 0777 is user permission number.
        printerror->PrintError("Directory is exist or you're not root");
        slashn
    } else {
            printlnf("Success");
            slashn
    }
    return;
}
FCreateFileFunction::FCreateFileFunction() 
{
    file_name = new fchar;
    file_directory = new fchar;
}

FCreateFileFunction::~FCreateFileFunction()
{
     delete file_path, file_name, file_directory_string, file_directory;
}

void
FCreateFileFunction::CreateFileFunctionInit(std::string name)
{
    file_directory_string.append(command->_file_path_cd_function);
    file_directory_string.append(slash);
    file_directory_string.append(name.c_str());
    file_directory_string.append(txt); 
    command->chartostring(file_directory_string, file_directory);
    std::ofstream file(file_directory_string, std::ios::app);
    file << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n Eleifend mi in nulla posuere sollicitudin aliquam.";
    slashn
    file.close();
}