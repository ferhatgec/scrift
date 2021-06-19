/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <sys/stat.h>

#include <src/Scrift.hpp>
#include <src/Syntax/History.hpp>
#include <src/Syntax/Log.hpp>
#include <src/Syntax/FileFunction.hpp>

/* TODO:
   * Clear.
*/
FeLog *loghistory = new FeLog();
std::ofstream historyfile;
std::string filepath_history;

FHistory::FHistory() = default;

void
FHistory::ClearHistory() {
    std::string path;
    path.append(getenv("HOME"));

    path.append("/.scrift_history");
    historyfile.open(path); // append
    historyfile << "rmvhistory\n";
    historyfile.close();
}


void
FHistory::WriteInHistory(const std::string &element) {
    std::string filepath_with_path;
    filepath_with_path.append(getenv("HOME"));

    filepath_with_path.append("/.scrift_history");

    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);

    if (file.fail())
        std::cout << "[history]: error\n";


    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << element;

    file.close();
}

void
FHistory::CreateFile() {
    std::string path;
    path.append(getenv("HOME"));

    path.append("/.scrift_history");
    historyfile.open(path, std::ios::app);
    historyfile.close();
}

bool
FHistory::IsExist() {
    struct stat buffer{};
    return (stat(filepath_history.c_str(), &buffer) == 0);
}


void
FHistory::AllofThem() {
    if (!IsExist())
        CreateFile();
    else {
        printlnf("FHistory file is exists\n");
        loghistory->WriteLog("FHistory file is exists! - ");
    }
}


FHistory::~FHistory() = default;

