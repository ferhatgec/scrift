
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <Syntax/CommandFunc.h>
#include <main.h>
#include <Syntax/RunFunction.hpp>
#include <Syntax/GetNameFunction.hpp>
#include <Syntax/FileFunction.hpp>
#include <Syntax/PrintErrorFunction.hpp>
#include <Syntax/MkdirFunction.hpp>
#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>

using namespace FileFunction;

FCommand *command = new FCommand();
FMain *fmain = new FMain();
fprinterror *printerror = new fprinterror;
std::string str;
fchar *file_path = new fchar;
fchar* input_char;
std::string path_directory;
FCDFunction *fcdfunction = new FCDFunction;
fchar* file_name;
fchar* file_directory;
std::string file_directory_string;
std::string homedirectory;
struct stat filestat;
struct dirent *entryname;
fchar *string;
FRunFunction *filerunfunction = new FRunFunction();

// FCDFUNCTION
FCDFunction::FCDFunction()
{
    
}



FCDFunction::~FCDFunction()
{
    delete fmain, printerror, command, str, homedirectory;
}


boolean
FCDFunction::FileExists(const std::string &Filename)
{
    return access(Filename.c_str(), 0 ) == 0;
}


boolean
faddtextfunction::FileExist(const std::string filename)
{
    fcdfunction->FileExists(filename);
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


// FMKDIRFUNCTION
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

// FCREATEFILEFUNCTION
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
    file << "This file created in Scrift";
    printlnf("File created successfuly\n");
    file.close();
}

void
faddtextfunction::DeleteLine(std::string filename)
{
    std::string file_string_path;
    file_string_path.append("nano ");
    file_string_path.append(command->_file_path_cd_function);
    file_string_path.append("/");
    file_string_path.append(filename);
    file_string_path.append(txt);
    filerunfunction->RunFunction(file_string_path); // I will write Scrift based text editor and run in Scrift.
}

void
faddtextfunction::AppendLine(std::string filepathw)
{
    std::string line;
    std::string filepath_with_path;
    filepath_with_path.append(command->_file_path_cd_function);
    filepath_with_path.append("/");
    filepath_with_path.append(filepathw);
    filepath_with_path.append(txt);

    printlnf("Text : ");
    std::getline(std::cin, line);
    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);
    if(file.fail()) {
        printerror->PrintError("FAIL");
    }

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << line << std::endl;
    printlnf("Done\n");
}



// READFILEFUNCTION
FReadFileFunction::FReadFileFunction()
{

}

FReadFileFunction::~FReadFileFunction() 
{
  
}

void
FReadFileFunction::ReadFileInit()
{

}


boolean
FReadFileFunction::ReadFileExists()
{
    
}

void 
FReadFileFunction::ReadFileFunction(std::string filename)
{
    std::string line;
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(filename);
    path.append(txt);
    std::ifstream readfile (path);
    if (readfile.is_open()) {
        while (getline(readfile, line))
        {
            printlnf(line.c_str());
            slashn
        }
        readfile.close();
    } else {
        printerror->PrintError("Unable to open file\n");
    }
}

// FHOMEFUNCTION
void
fhomefunction::GetHome() 
{
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    homedirectory.append("/home/");
    homedirectory.append(password->pw_name);
    std::strcpy(command->_file_path_cd_function, homedirectory.c_str());
}

// FILELSFUNCTION
FLSFunction::FLSFunction()
{
    string = new fchar;
}

FLSFunction::~FLSFunction()
{
}

void
FLSFunction::InitLSFunction()
{

}

boolean
FLSFunction::DirectoryExists()
{

}


void
FLSFunction::LSFunction()
{

    DIR *directory;
    directory = opendir((getenv("HOME"), "/", command->_file_path_cd_function));
    if(directory == NULL) {
        printerror->PrintError("ERR: DIRECTORY NOT FOUND OR NULL");
        return;
    }
    while ((entryname = readdir(directory))) 
    {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
        } else {
            BOLD_YELLOW_COLOR
            printlnf("%4s: %s\n", "[File]", entryname->d_name);
        }
        BLACK_COLOR // Reset
    }
    closedir(directory);
}
