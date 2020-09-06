/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <sys/stat.h>
#include <ctime>
#include <cstdio>
#include <pwd.h>

#include <src/Syntax/Log.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Scrift.hpp>
#include <src/Syntax/CommandFunc.h>
// #include <Syntax/PrintErrorFunction.hpp>

std::ofstream file;
FCommand *commandlog = new FCommand();
std::string filepath_with_path;
FeLog::FeLog(){}

FeLog::~FeLog(){  }

func
FeLog::ClearLog() {
    std::string path;
    path.append(getenv("HOME"));
    path.append(slash);
    path.append(".scrift_log");
    file.open(path); // append
    file << "FeLog Cleared.. \n";
    file << TimeFunction() << "\n";
    file.close();
}


const std::string
FeLog::TimeFunction() {
    time_t nowtime = time(0);
    struct tm tstruct;
    char    buff[80];
    tstruct = *localtime(&nowtime);
    std::strftime(buff, sizeof(buff), "%Y-%M-%d.%X", &tstruct);
    return buff;
}


func
FeLog::WriteLog(fstr filepathw) {
    std::string filepath_with_path;
    filepath_with_path.append(getenv("HOME"));
    filepath_with_path.append(slash);
    filepath_with_path.append(".scrift_log");
    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);
    if(file.fail()) {
        printlnf("ERROR\n");
    }

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << filepathw << " ";
    file << TimeFunction() << std::endl;

   // printlnf("Done\n");
}




func
FeLog::CreateFile() {   
    std::string path;
    path.append(getenv("HOME"));
    path.append(slash);
    path.append(".scrift_log");

    file.open(path, std::ios::app);
    file << "FeLog Started. ";
    file << TimeFunction() << "\n";
    file.close();
}   

func 
FeLog::InitFile() {}

boolean
FeLog::IsExist() {
    struct stat buffer;
    return (stat(filepath_with_path.c_str(), &buffer) == 0);
}


func 
FeLog::AllofThem() {
    if(IsExist() != true) {
    CreateFile();
    }
    else {
        printlnf("FeLog file is exists\n");
        WriteLog("FeLog file is exists! - ");
    }
}
