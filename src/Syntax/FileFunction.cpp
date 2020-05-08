/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include "Syntax/ASCIIFunction.hpp"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <Syntax/CommandFunc.h>
#include <Scrift.hpp>
#include <Syntax/RunFunction.hpp>
#include <Syntax/GetNameFunction.hpp>
#include <Syntax/FileFunction.hpp>
#include <Syntax/PrintErrorFunction.hpp>
#include <Syntax/MkdirFunction.hpp>
#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>
#include <Syntax/Log.hpp>
#include <Syntax/Colors.hpp>
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

struct stat filestat;
struct dirent *entryname;
fchar *string;
FRunFunction *filerunfunction = new FRunFunction();
asciifunction *ascii = new asciifunction;
FeLog *filelog = new FeLog();
// FCDFUNCTION
FCDFunction::FCDFunction()
{
    
}



FCDFunction::~FCDFunction()
{
    delete fmain, printerror, command, ascii, filelog;
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

std::string pathnamef;
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
                chdir(name.c_str());
                pathnamef = name;
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

func 
FCreateFileFunction::CreateScriftFile(std::string pathname)
{
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append(slash);
    path.append(pathname);
    path.append(scrift); 
    std::ofstream file(path, std::ios::app);
    file << "printlnf  This Scrift file created by Scrift, Hahaha!\n";
    file << "string  test\n";
    file << "strprintlnf";
    printlnf("File created successfuly\n");
    file.close();
}

void
FCreateFileFunction::CreateFileFunctionInit(fstr name)
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

boolean 
FCreateFileFunction::IsExistFile()
{
    uid_t fuid = geteuid();
    struct passwd *password = getpwuid(fuid);
    filelog->WriteLog("Appended passwd structure - ");
    std::string path;
    path.append("/home/");
    path.append(password->pw_name);
    path.append("/");
    path.append(".scrift_settings");
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}



func 
FCreateFileFunction::CreateSettingsFileFunction()
{
    if(IsExistFile() != true) {
    FeLog *logsystem = new FeLog();
    logsystem->WriteLog("Calling getuid from CreateSettingsFileFunction - ");
    uid_t fuid = geteuid();
    logsystem->WriteLog("Calling getpwuid from CreateSettingsFileFunction - "); 
    struct passwd *password = getpwuid(fuid);   
    logsystem->WriteLog("Creating pathfile from CreateSettingsFileFunction - ");
    std::string pathfile;   
    logsystem->WriteLog("Appending password->pw_name in pathfile - ");
    pathfile.append("/home/");
    pathfile.append(password->pw_name);
    logsystem->WriteLog("Appending slash in pathfile - ");
    pathfile.append("/");
    logsystem->WriteLog("Appending ScriftSettings file in pathfile - ");
    pathfile.append(".scrift_settings");
    logsystem->WriteLog("Creating ofstream from CreateSettingsFileFunction - ");
    std::ofstream file(pathfile, std::ios::app);
    file << "Test";
    //file <<  Settings variables begin.
    // Settings variables end.
    logsystem->WriteLog("Calling file<dot>close from CreateSettingsFileFunction - ");
    file.close();
    } else {
        filelog->WriteLog("Settings file is exists! Nice. - ");
    }
}

func 
FClearFileFunction::ClearSettingsFunction()
{
    if(IsExistFile() == true)
    {
        filelog->WriteLog("Clearing Settings File - ");
        uid_t fuid = getuid(); 
        struct passwd *password = getpwuid(fuid);
        std::string path;
        path.append("/home/");
        path.append(password->pw_name);
        path.append("/");
        path.append(".scrift_settings");
        std::ofstream file(path); // App = Append
        file << " ";
        filelog->WriteLog("Cleared.. - ");
    } 
    else {
        CreateSettingsFileFunction();
    }
}


void
FCreateFileFunction::CreateASCIIFileFunction()
{
    if(ascii->InitFile() != true) {
    file_directory_string.append(command->_file_path_cd_function);
    file_directory_string.append(slash);
    file_directory_string.append(".scrift_ascii");
    command->chartostring(file_directory_string, file_directory);
    std::ofstream file(file_directory_string, std::ios::app);
    file << "  _____           _  __ _  \n";
    file << " / ____|         (_)/ _| | \n";
    file << "| (___   ___ _ __ _| |_| |_ \n";
    file << " \\___ \\ / __| '__| |  _| __|\n";
    file << " ____) | (__| |  | | | | |_ \n";
    file << "|_____/ \\___|_|  |_|_|  \\__|\n";
    file.close();
    }
    else {
        printlnf("Good luck!\n");
    } 
}



func 
FCreateFileFunction::CreateFeLogFileFunction()
{

}

func 
FReadFileFunction::ReadHistoryFileFunction()
{
    std::string line;
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    path.append(slash);
    path.append(".scrift_history");
    std::ifstream readfile(path);
    if(readfile.is_open()) 
    {
        while(std::getline(readfile, line))
        {
            printlnf(line.c_str());
            slashn
        }
        readfile.close();
    } 
    else {
        filelog->AllofThem();
    }
}



void
faddtextfunction::DeleteLine(std::string filename)
{
    std::string file_string_path;
    file_string_path.append("nano ");
    file_string_path.append(command->_file_path_cd_function);
    file_string_path.append("/");
    file_string_path.append(filename);
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

func
FReadFileFunction::ReadFeLogFunction() 
{
    std::string line;
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    path.append(slash);
    path.append(".scrift_log");
    std::ifstream readfile(path);
    if(readfile.is_open()) 
    {
        while(std::getline(readfile, line))
        {
            printlnf(line.c_str());
            slashn
        }
        readfile.close();
    } 
    else {
        filelog->AllofThem();
    }
}

void 
FReadFileFunction::ReadFileFunction(fstr filename)
{
    std::string line;
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(filename);
    //path.append(txt);
    std::ifstream readfile(path);
    if(readfile.is_open())
    {
        while (std::getline(readfile, line))
        {
            printlnf(line.c_str());
            slashn
        }
        
        readfile.close();
    } else {
        printerror->PrintError("Unable to open file\n");
    } 
}

func 
FReadFileFunction::ReadSettingsFunction()
{
    std::string line;
    std::string fpath;
    uid_t fuid = geteuid();
    struct passwd *pass = getpwuid(fuid);
    fpath.append("/home/");
    fpath.append(pass->pw_name); // Your username 
    fpath.append("/"); // slash
    fpath.append(".scrift_settings");
    std::ifstream readfile(fpath);
    if(readfile.is_open()) {
    while (std::getline(readfile, line))
    {
        printlnf(line.c_str());
        slashn
    }
    }
}


void 
FReadFileFunction::ReadASCIIFunction()
{
    std::string line;
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(".scrift_ascii");
    //path.append(txt);
    std::ifstream readfile(path);
    if(readfile.is_open())
    {
        while (std::getline(readfile, line))
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
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    std::strcpy(command->_file_path_cd_function, path.c_str());
}


std::string 
fhomefunction::CurrentDirectory(void)
{
  char buff[FILENAME_MAX];
  getcwd( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
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


func
FRemoveFileFunction::DeleteFile(std::string file)
{
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(file);
    const integer filedeletestage = std::remove(path.c_str());
    if(filedeletestage == 0) {
        printlnf("Succesfully deleted\n");
    } 
    else {
        printlnf("Error: bla bla\n");
    }
}
