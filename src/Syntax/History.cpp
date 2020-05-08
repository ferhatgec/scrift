/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include <Syntax/History.hpp>
#include <Syntax/Log.hpp> // Get Log Header
#include <Syntax/FileFunction.hpp> // For  create file and folder 
#include <Scrift.hpp>
#include <Syntax/CommandFunc.h>
#include <sys/stat.h>
#include <ctime>
#include <cstdio>
#include <pwd.h>
// #include <Syntax/PrintErrorFunction.hpp>

FeLog *loghistory = new FeLog();
std::ofstream historyfile;
std::string filepath_history;

FHistory::FHistory()
{

}

FHistory::~FHistory()
{
    delete loghistory, historyfile, filepath_history;
}

func
FHistory::ClearHistory()
{
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    path.append(slash);
    path.append(".scrift_history");
    historyfile.open(path); // append
    historyfile << "clear_history \n";
    historyfile.close();
}


const std::string
FHistory::TimeFunction()
{
    time_t nowtime = time(0);
    struct tm tstruct;
    char    buff[80];
    tstruct = *localtime(&nowtime);
    std::strftime(buff, sizeof(buff), "%Y-%M-%d.%X", &tstruct);
    return buff;
}


func
FHistory::WriteHistory(fstr filepathw)
{
    std::string filepath_with_path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    filepath_with_path.append("/home/");
    filepath_with_path.append(password->pw_name);
    filepath_with_path.append(slash);
    filepath_with_path.append(".scrift_history");
    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);
    if(file.fail()) {
        printlnf("ERROR\n");
    }

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << filepathw << "\n";

   // printlnf("Done\n");
}




func
FHistory::CreateFile()
{   
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    path.append(slash);
    path.append(".scrift_history");

    historyfile.open(path, std::ios::app);
    historyfile << " ";
    historyfile << TimeFunction() << "\n";
    historyfile.close();
}   

func 
FHistory::InitFile() 
{

}

boolean
FHistory::IsExist()
{
    struct stat buffer;
    return (stat(filepath_history.c_str(), &buffer) == 0);
}


func 
FHistory::AllofThem()
{
    if(IsExist() != true) {
    CreateFile();
    }
    else {
        printlnf("FHistory file is exists\n");
        loghistory->WriteLog("FHistory file is exists! - ");
    }
}
