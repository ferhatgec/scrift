/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <sys/stat.h>
#include <ctime>

#include <src/Syntax/Log.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Scrift.hpp>

/* TODO:
   * Clear.
*/

std::ofstream file;
std::string filepath_with_path;

FeLog::FeLog() = default;

FeLog::~FeLog() = default;

void
FeLog::ClearLog() {
    std::string path;
    path.append(getenv("HOME"));
    path.append("/.scrift_log");
    file.open(path); // append
    file << "FeLog Cleared.. \n";
    file << TimeFunction() << "\n";
    file.close();
}


std::string
FeLog::TimeFunction() {
    time_t nowtime = time(nullptr);
    struct tm tstruct{};
    char buff[80];
    tstruct = *localtime(&nowtime);
    std::strftime(buff, sizeof(buff), "%Y-%M-%d.%X", &tstruct);
    return buff;
}


void FeLog::WriteLog(fstr filepathw) {
    std::string filepath_with_path;
    filepath_with_path.append(getenv("HOME"));
    filepath_with_path.append("/.scrift_log");
    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);
    if (file.fail())
        printlnf("ERROR\n");


    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << filepathw << " ";
    file << TimeFunction() << std::endl;

    // printlnf("Done\n");
}


void FeLog::CreateFile() {
    std::string path;
    path.append(getenv("HOME"));

    path.append("/.scrift_log");

    file.open(path, std::ios::app);
    file << "FeLog Started. ";
    file << TimeFunction() << "\n";
    file.close();
}

bool
FeLog::IsExist() {
    struct stat buffer{};
    return (stat(filepath_with_path.c_str(), &buffer) == 0);
}


void
FeLog::AllofThem() {
    if (!IsExist())
        CreateFile();
    else {
        printlnf("FeLog file is exists\n");
        WriteLog("FeLog file is exists! - ");
    }
}
