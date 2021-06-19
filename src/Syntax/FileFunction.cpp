/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */


#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include <unistd.h>
#include <cstdlib>

#include <src/Syntax/CommandFunc.hpp>
#include <src/Scrift.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Syntax/Log.hpp>
#include <src/Syntax/Settings.hpp>
#include <src/Syntax/ASCIIFunction.hpp>
#include <src/Syntax/Locale.hpp>

// Library
#include <Colorized.hpp>

using namespace FileFunction;

// Classes
std::unique_ptr<FeLog> filelog(new FeLog);
std::unique_ptr<FSettings> settings(new FSettings);
std::unique_ptr<FCommand> command(new FCommand);
std::unique_ptr<FMain> fmain(new FMain);

// Structures
std::unique_ptr<FASCIIFunction> ascii(new FASCIIFunction);

/*
	fr #env
	cd #env
	-------
	fr dir
	cd dir
	-------
	fr ../../
	cd ../../
	-------
	fr /usr/
	cd /usr/
*/
void
FCDFunction::CDFunctionInit(std::string name, slocale_t &locale) {
    if (!name.empty()) {
        if (!fmain->_home) {
            std::string temporary_name;

            if (name.front() == '#') {
                temporary_name = std::basic_string(getenv(name.erase(0, 1).c_str()));
            } else {
                temporary_name = name;
            }

            if (temporary_name.front() == '/') {
                if (std::filesystem::exists(temporary_name)) {
                    command->_file_path_cd_function = temporary_name;
                    fmain->SetTitle();
                } else {
                    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), "scrift : ");
                    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), temporary_name);
                    colorized::PrintWith(colorized::Colorize(BOLD, RED), locale.dir_not_exist);

                    return;
                }
            } else {
                if (std::filesystem::exists(command->_file_path_cd_function + "/" + temporary_name)) {
                    command->_file_path_cd_function.append("/" + temporary_name);
                } else {
                    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), "scrift : ");
                    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), temporary_name);
                    colorized::PrintWith(colorized::Colorize(BOLD, RED), locale.dir_not_exist);

                    return;
                }
            }

            chdir(command->_file_path_cd_function.c_str());
        }
    }
}

void
FMKDirFunction::MKDirFunctionInit(const std::string &name) {
    if (!std::filesystem::create_directory(command->_file_path_cd_function + "/" + name)) {
        std::cout << "Directory is exist or a permission issue.\n";
    }
}

void
FCreateFileFunction::CreateScriftFile(const std::string &name) {
    std::ofstream file((command->_file_path_cd_function + "/" + name + ".scr"), std::ios::app);

    file << "printlnf(\"This Scrift file created by Scrift.\");\n";

    file.close();
}

void
FCreateFileFunction::CreateFileFunctionInit(const std::string &name) {
    std::ofstream file((command->_file_path_cd_function + "/" + name + ".txt"), std::ios::app);

    file << "This file created in Scrift";

    file.close();
}

void
FCreateFileFunction::CreateSettingsFileFunction() {
    if (!std::filesystem::exists(std::basic_string(getenv("HOME")) + "/.scrift_settings")) {
        std::ofstream file((std::basic_string(getenv("HOME")) + "/.scrift_settings"), std::ios::app);

        file << "[CUSTOMIZE]\nfelog_cleaner 100\n";
        file << "welcome_emoji :thinking_face:\n";
        file << "bg_color 12\n";
        file << "ascii_art_color random\n";
        file << "scrift_theme default\n";
        file << "input_customize ▶ \n";
        file << "welcome_message yes\n";
        file << "local_git_branch yes\n";
        file << "scrift_setup yes\n";
        file << "auto_clear 40\n";
        file << "date_info yes\n";
        file << "sign_1 @\n";
        file << "sign_2 :~\n";
        file
                << "\n[PROMPT] @username@[1;34m] @sign_1@[1;36m] @hostname@[1;35m] @sign_2@[1;36m] @directory@[1;33m] @whitespace@[1;36m] @branch@[1;36m] @clock@[1;93m] @whspace@[1;36m] @input_sign@[1;31m]";

        file.close();
    }
}

void
FClearFileFunction::ClearSettingsFunction() {
    if (std::filesystem::exists(std::basic_string(getenv("HOME")) + "/.scrift_settings")) {
        std::ofstream file((std::basic_string(getenv("HOME")) + "/.scrift_settings"));

        // TODO: Clear
        file << "[CUSTOMIZE]\nfelog_cleaner 100\n";
        file << "welcome_emoji :thinking_face:\n";
        file << "bg_color 12\n";
        file << "ascii_art_color random\n";
        file << "scrift_theme default\n";
        file << "input_customize ▶ \n";
        file << "welcome_message yes\n";
        file << "local_git_branch yes\n";
        file << "scrift_setup yes\n";
        file << "auto_clear 40\n";
        file << "date_info yes\n";
        file << "sign_1 @\n";
        file << "sign_2 :~\n";
        file
                << "\n[PROMPT] @username@[1;34m] @sign_1@[1;36m] @hostname@[1;35m] @sign_2@[1;36m] @directory@[1;33m] @whitespace@[1;36m] @branch@[1;36m] @clock@[1;93m] @whspace@[1;36m] @input_sign@[1;31m]";

        file.close();
    } else {
        CreateSettingsFileFunction();
    }
}


void
FCreateFileFunction::CreateASCIIFileFunction() {
    if (!ascii->InitFile()) {
        std::string path;
        path.append(getenv("HOME"));
        path.append("/.scrift_ascii");

        std::ofstream file((std::basic_string(getenv("HOME")) + "/.scrift_ascii"), std::ios::app);

        file << " ███████╗ ██████╗██████╗ ██╗███████╗████████╗ 	\n";
        file << " ██╔════╝██╔════╝██╔══██╗██║██╔════╝╚══██╔══╝ 	\n";
        file << " ███████╗██║     ██████╔╝██║█████╗     ██║	\n";
        file << " ╚════██║██║     ██╔══██╗██║██╔══╝     ██║	\n";
        file << " ███████║╚██████╗██║  ██║██║██║        ██║	\n";
        file << " ╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝╚═╝        ╚═╝	\n";

        file.close();
    }
}

void
FReadFileFunction::ReadHistoryFileFunction() {
    unsigned line_number = 0;

    std::ifstream readfile((std::basic_string(getenv("HOME")) + "/.scrift_history"));

    if (readfile.is_open()) {
        for (std::string line; std::getline(readfile, line); line_number++) {
            std::cout << line_number << " : " << line << '\n';
        }

        readfile.close();
    } else {
        filelog->AllofThem();
    }
}

std::string
FFindFileFunction::FindWithoutPrint(const std::string &name) {
    for (auto &p: std::filesystem::directory_iterator(command->_file_path_cd_function)) {
        if (p.path().string().find(name)) {
            return p.path().string();
        }
    }

    return "null";
}


void
FFindFileFunction::FindFile(const std::string &name) {
    FLSFunction find;

    for (auto &p: std::filesystem::directory_iterator(command->_file_path_cd_function)) {
        if (p.path().string().find(name)) {
            if (p.is_directory()) {
                std::cout << WBOLD_LIGHT_RED_COLOR << "[Direc]:     " << WBLWHITE << p.path().filename().string()
                          << '\n';
            } else {
                std::string filename = p.path().filename().string();
                std::string extension = p.path().extension().string();

                find.ParseListing(filename, extension);
            }
        }

    }

    BLACK_COLOR
}

void
faddtextfunction::AppendLine(const std::string &filepathw) {
    std::string line;

    std::cout << "Text : ";

    std::getline(std::cin, line);

    std::ofstream file((command->_file_path_cd_function + "/" + filepathw + ".txt"), std::ios::out | std::ios::app);

    if (file.fail()) {
        std::cout << "Failed.\n";
        return;
    }

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << line << std::endl;
}

void
FClearFileFunction::ClearFeLogFunction() {
    std::ofstream file(std::basic_string(getenv("HOME")) + "/.scrift_log");

    file << "FeLog Cleared.. \n";

    file.close();
}

void
FReadFileFunction::ReadFeLogFunction() {
    unsigned a = 0;

    std::ifstream readfile((std::basic_string(getenv("HOME")) + "/.scrift_log"));

    if (readfile.is_open()) {
        for (std::string line; std::getline(readfile, line); a++) {
            std::cout << line << '\n';
        }

        std::cout << a << "\n";

        if (a >= settings->FeLogCleaner()) {
            FClearFileFunction clearlog;
            clearlog.ClearFeLogFunction();
        } else
            std::cout << "Cool\n";

        readfile.close();
    } else
        filelog->AllofThem();
}

std::string FReadFileFunction::ReadFile(const std::string &filename) {
    std::ifstream file(filename);
    std::string file_data;

    if (!file.is_open()) {
        std::cout << "Unable to open file : " << filename << '\n';

        return "";
    }

    for (std::string data; std::getline(file, data);) {
        file_data.append(data + "\n");
    }

    return file_data;
}

void
FReadFileFunction::ReadFileFunction(std::string filename) {
    if (filename.front() != '/') {
        ReadFile(command->_file_path_cd_function + "/" + filename);
    } else {
        ReadFile(filename);
    }
}

void
FReadFileFunction::ReadSettingsFunction() {
    colorized::PrintWhReset(colorized::Colorize(BOLD, BLUE),
                            ReadFile(std::basic_string(getenv("HOME")) + "/.scrift_settings"));
}

void
FReadFileFunction::ReadASCIIFunction() {
    colorized::PrintWith(colorized::Colorize(BOLD, settings->ASCIIColor()),
                         ReadFile(std::basic_string(getenv("HOME")) + "/.scrift_ascii"));
}

void
FReadFileFunction::ReadAliasFunction() {
    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_GREEN),
                            ReadFile(std::basic_string(getenv("HOME")) + "/.scrift_aliases"));
}


void
fhomefunction::GetHome() {
    command->_file_path_cd_function = getenv("HOME");

    chdir(getenv("HOME"));
}


std::string
fhomefunction::CurrentDirectory() {
    return std::filesystem::current_path().string();
}

void
FLSFunction::GetObjects() {
    for (auto &p: std::filesystem::directory_iterator("/bin/")) {
        if (p.is_directory()) {
            std::cout << WBOLD_LIGHT_RED_COLOR << "[Dir]: " << p.path().string() << '\n';
        } else {
            std::cout << WBOLD_LIGHT_YELLOW_COLOR << "[Object]: " << p.path().string() << '\n';
        }
    }
}

void
FLSFunction::ListObjectFunction() {
    GetObjects();
}

bool
FLSFunction::ListArgumentObjectFunction(const std::string &argument) {
    for (auto &p: std::filesystem::directory_iterator("/bin/")) {
        if (p.is_directory()) {
            if (p.path().string() == argument) {
                return true;
            }
        }
    }

    return false;
}

void
FLSFunction::LSFunction(std::string arg) {
    std::string list_path;

    if (arg.front() == '#') {
        arg.erase(0, 1);
        list_path = std::basic_string(getenv(arg.c_str()));
    } else {
        list_path = arg;
    }

    for (auto &p: std::filesystem::directory_iterator(list_path)) {
        if (p.is_directory()) {
            std::cout << WBOLD_BLUE_COLOR << "[Direc]:     " << WBLWHITE << p.path().filename().string() << '\n';
        } else {
            ParseListing(p.path().filename().string(), p.path().extension().string());
        }
    }

    BLACK_COLOR // Reset
}

// Under the FileFunction namespace
void
FLSFunction::ParseListing(const std::string &filename, const std::string &extension) {
    if (filename == "Elitefile") {
        std::cout << WBBLUE << "[Elitebuild]:" << WBWHITE << filename << '\n';
    } else if (filename == "CMakeLists.txt") {
        std::cout << WBBLUE << "[CMake]:     " << WBWHITE << filename << '\n';
    } else if (filename == ".scrift_log") {
        std::cout << WBLYELLOW << "FeLog*:      " << WBWHITE << filename << '\n';
    } else if (filename == ".scrift_ascii") {
        std::cout << WBLYELLOW << "Ascii Art*:  " << WBWHITE << filename << '\n';
    } else if (filename == ".scrift_settings") {
        std::cout << WBLYELLOW << "Settings*:   " << WBWHITE << filename << '\n';
    } else if (filename == ".scrift_history") {
        std::cout << WBLYELLOW << "History*:    " << WBWHITE << filename << '\n';
    } else if (extension == ".scr") {
        std::cout << WBGREEN << "[Scrift]:    " << WBWHITE << filename << '\n';
    } else if (extension == ".cpp" || extension == ".hpp" ||
               extension == ".cxx" || extension == ".hxx" ||
               extension == ".cc" || extension == ".hh") {
        std::cout << WBCYAN << "[C++]:       " << WBWHITE << filename << '\n';
    } else if (extension == ".c" || extension == ".h") {
        std::cout << WBBLUE << "[C]:         " << WBWHITE << filename << '\n';
    } else if (extension == ".sh" || extension == ".bash") {
        std::cout << WBGREEN << "[Bash]:      " << WBWHITE << filename << '\n';
    } else if (extension == ".py" || extension == ".pyc") {
        std::cout << WBBLUE << "[Python]:    " << WBWHITE << filename << '\n';
    } else if (extension == ".fls" || extension == ".flsh") {
        std::cout << WBLYELLOW << "[FlaScript]: " << WBWHITE << filename << '\n';
    } else if (extension == ".md") {
        std::cout << WBYELLOW << "[Markdown]:  " << WBWHITE << filename << '\n';
    } else if (extension == ".frbr") {
        std::cout << WBLMAGENTA << "[FreeBr]:    " << WBWHITE << filename << '\n';
    } else if (extension == ".png") {
        std::cout << WBLBLUE << "[Png]:       " << WBWHITE << filename << '\n';
    } else if (extension == ".jpg" || extension == ".jpeg") {
        std::cout << WBLBLUE << "[Jpg]:       " << WBWHITE << filename << '\n';
    } else if (extension == ".gif") {
        std::cout << WBBLUE << "[Gif]:       " << WBWHITE << filename << '\n';
    } else if (extension == ".htm" || extension == ".html") {
        std::cout << WBLRED << "[Html]:      " << WBWHITE << filename << '\n';
    } else if (extension == ".rs" || extension == ".rslib") {
        std::cout << WBYELLOW << "[Rust]:      " << WBWHITE << filename << '\n';
    } else if (extension == ".lua") {
        std::cout << WBLBLACK << "[Lua]:       " << WBWHITE << filename << '\n';
    } else if (extension == ".inclink") {
        std::cout << WBLYELLOW << "[incLink]:   " << WBWHITE << filename << '\n';
    } else {
        std::cout << WBYELLOW << "[File]:      " << WBWHITE << filename << '\n';
    }
}

std::string
FLSFunction::GetFileExtension(const std::string &file) {
    if (file.find_last_of('.') != std::string::npos) return file.substr(file.find_last_of('.') + 1);

    return "";
}


void
FRemoveFileFunction::DeleteFile(const std::string &file) {
    const int8_t delete_stage = std::remove((command->_file_path_cd_function + "/" + file).c_str());

    if (delete_stage != 0) {
        BOLD_RED_COLOR
        std::cout << "Error: Unable to delete file : " << file << '\n';
        BLACK_COLOR
    }
}