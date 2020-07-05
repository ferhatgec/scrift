/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

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
#include <Syntax/Colors.hpp>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>
#include <Syntax/Log.hpp>
#include <Syntax/Colors.hpp>
#include <Syntax/Settings.hpp>
#include <vector>
#include <Syntax/ASCIIFunction.hpp>

// Library
#include "../../Library/Colorized.hpp"

using namespace FileFunction;
FSettings *settings = new FSettings();
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
FCDFunction::FCDFunction() {

}


bool
FCDFunction::FileExists(const std::string &Filename) {
    return access(Filename.c_str(), 0 ) == 0;
}


bool
faddtextfunction::FileExist(const std::string filename) {
    fcdfunction->FileExists(filename);
}

std::string pathnamef;
void
FCDFunction::CDFunctionInit(std::string name) {
    command = new FCommand();
    fmain = new FMain();

    // or std::getline
    if(name != "") {
        if(fmain->_home != true) {
	    if(name.rfind("#") == 0) {
	    	name = settings->EraseAllSubString(name, "#");
	    	std::string new_name(getenv(name.c_str()));
	    	if(new_name.rfind("/") == 0) {
	    		if(FileExists(new_name) == true) {
            		    std::strcpy(command->_file_path_cd_function, new_name.c_str());
	    		    chdir(new_name.c_str());
            		} else {
            		    printerror->PrintError("This directory is not exist!");
            		    slashn
            		    return;
            		}
           	} else {
	    		std::string path;
            		path.append(command->_file_path_cd_function);
            		path.append("/");
            		path.append(new_name);
            		if(FileExists(path) == true) {
            		    std::strcat(command->_file_path_cd_function, "/");
            		    std::strcat(command->_file_path_cd_function, new_name.c_str());
            		    chdir(new_name.c_str());
            		    pathnamef = new_name;
            		} else {
            		    printerror->PrintError("This directory is not exist!");
            		    slashn
            		    return;
            		}
            	}
	    } else {
	    	if(name.rfind("/") == 0) {
	    		if(FileExists(name) == true) {
	    		    std::strcpy(command->_file_path_cd_function, name.c_str());
	    		    chdir(name.c_str());
            		} else {
            		    printerror->PrintError("This directory is not exist!");
            		    slashn
            		}
            		return;
	    	} else {
		std::string path;
	    	if(command->_file_path_cd_function == "/") {
			path.append(command->_file_path_cd_function);
			path.append(name);				    		
		} else {
            		path.append(command->_file_path_cd_function);
            		path.append("/");
            		path.append(name);
            	}
            	if(FileExists(path) == true) {
            	    std::string path;
	    	    if(command->_file_path_cd_function == "/") {
		    } else {
            		std::strcat(command->_file_path_cd_function, "/");
                    }
                    std::strcat(command->_file_path_cd_function, name.c_str());
            	    chdir(name.c_str());
            	    pathnamef = name;
            	}  else {
            	    printerror->PrintError("This directory is not exist!");
            	    slashn
            	    return;
            	}
            	}
            }
        }
    }
    return;
}

// FMKDIRFUNCTION
FMKDirFunction::FMKDirFunction() {
    input_char = new fchar;
}


FMKDirFunction::~FMKDirFunction() {
    delete input_char;
}


void
FMKDirFunction::MKDirFunctionInit(std::string name) {
    // I will use std::getline.
    path_directory.append(command->_file_path_cd_function); // default getenv("HOME")
    path_directory.append("/"); // ex: /home/username -> getenv("HOME") -> /home/username'/'
    path_directory.append(name); // maybe directory is exist or directory is not exist.
    if(mkdir(path_directory.c_str(), 0777) == -1 ) {// 0777 is user permission number.
        printerror->PrintError("Directory is exist or you're not root");
        slashn
    } else {
            BOLD_GREEN_COLOR
            printlnf("Success");
            BLACK_COLOR
            slashn
    }
    return;
}

// FCREATEFILEFUNCTION
FCreateFileFunction::FCreateFileFunction() {
    file_name = new fchar;
    file_directory = new fchar;
}

void
FCreateFileFunction::CreateScriftFile(std::string pathname) {
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append(slash);
    path.append(pathname);
    path.append(scrift);
    std::ofstream file(path, std::ios::app);
    file << "printlnf(\"This Scrift file created by Scrift, Hahaha!\");\n";
    BOLD_GREEN_COLOR
    printlnf("File created successfuly\n");
    BLACK_COLOR
    file.close();
}

void
FCreateFileFunction::CreateFileFunctionInit(fstr name) {
    file_directory_string.append(command->_file_path_cd_function);
    file_directory_string.append(slash);
    file_directory_string.append(name.c_str());
    file_directory_string.append(txt);
    command->chartostring(file_directory_string, file_directory);
    std::ofstream file(file_directory_string, std::ios::app);
    file << "This file created in Scrift";
    BOLD_GREEN_COLOR
    printlnf("File created successfuly\n");
    BLACK_COLOR
    file.close();
}

bool
FCreateFileFunction::IsExistFile(std::string file) {
    uid_t fuid = geteuid();
    struct passwd *password = getpwuid(fuid);
    std::string path;
    path.append("/home/");
    path.append(password->pw_name);
    path.append("/");
    path.append(file);
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}



void
FCreateFileFunction::CreateSettingsFileFunction() {
    if(IsExistFile(".scrift_settings") != true) {
    FeLog *logsystem = new FeLog();
    uid_t fuid = geteuid();
    struct passwd *password = getpwuid(fuid);
    std::string pathfile;
    pathfile.append("/home/");
    pathfile.append(password->pw_name);
    pathfile.append("/");
    pathfile.append(".scrift_settings");
    std::ofstream file(pathfile, std::ios::app);
    file << "felog_cleaner 100\n";
    file << "welcome_emoji :thinking_face:\n";
    file << "bg_color 12\n";
    file << "ascii_art_color 34\n";
    file << "scrift_theme default\n";
    file.close();
    } else {
    }
}

void
FClearFileFunction::ClearSettingsFunction() {
    if(IsExistFile(".scrift_settings") == true) {
        filelog->WriteLog("Clearing Settings File - ");
        uid_t fuid = getuid();
        struct passwd *password = getpwuid(fuid);
        std::string path;
        path.append("/home/");
        path.append(password->pw_name);
        path.append("/");
        path.append(".scrift_settings");
        std::ofstream file(path); // App = Append
        file << "felog_cleaner 100\n";
    	file << "welcome_emoji :thinking_face:\n";
    } else {
        CreateSettingsFileFunction();
    }
}


void
FCreateFileFunction::CreateASCIIFileFunction() {
    if(ascii->InitFile() != true) {
    file_directory_string.append(command->_file_path_cd_function);
    file_directory_string.append(slash);
    file_directory_string.append(".scrift_ascii");
    command->chartostring(file_directory_string, file_directory);
    std::ofstream file(file_directory_string, std::ios::app);
    file << " ███████╗ ██████╗██████╗ ██╗███████╗████████╗ 	\n";
    file << " ██╔════╝██╔════╝██╔══██╗██║██╔════╝╚══██╔══╝ 	\n";
    file << " ███████╗██║     ██████╔╝██║█████╗     ██║	\n";   
    file << " ╚════██║██║     ██╔══██╗██║██╔══╝     ██║	\n";   
    file << " ███████║╚██████╗██║  ██║██║██║        ██║	\n";   
    file << " ╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝╚═╝        ╚═╝	\n";   
    file.close();
    }
    else {
        printlnf("Good luck!\n");
    }
}

void
FReadFileFunction::ReadHistoryFileFunction() {
    int line_number = 0;	
    std::string line;
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    path.append(slash);
    path.append(".scrift_history");
    std::ifstream readfile(path);
    if(readfile.is_open()) {
        while(std::getline(readfile, line)) {
            line_number++;
            std::cout << line_number << " : ";
            printlnf(line.c_str());
            slashn
        }
        readfile.close();
    }
    else {
        filelog->AllofThem();
    }
}

std::string 
FFindFileFunction::FindWithoutPrint(std::string name) {
    DIR *directory;
    directory = opendir((getenv("HOME"), "/", command->_file_path_cd_function));
    if(directory == NULL) {
        printerror->PrintError("ERR: DIRECTORY OR FILE NOT FOUND OR NULL\n");
    }
    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {
            // Null
            } else if(strstr(entryname->d_name, "..")){
	    // Null
	    } else if(strstr(entryname->d_name, name.c_str())) { 
	    	//std::string clone_entry(entryname->d_name); 
            	return entryname->d_name;
            }
        } 
        else if(strstr(entryname->d_name, name.c_str())){
            // Null
        }
        BLACK_COLOR // Reset
    }
    closedir(directory);
}


void
FFindFileFunction::FindFile(std::string name) {
    DIR *directory;
    directory = opendir((getenv("HOME"), "/", command->_file_path_cd_function));
    if(directory == NULL) {
        printerror->PrintError("ERR: DIRECTORY OR FILE NOT FOUND OR NULL\n");
        return;
    }
    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {
            // Null
            } else if(strstr(entryname->d_name, "..")){
	    // Null
	    } else if(strstr(entryname->d_name, name.c_str())) {  
            	printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
            }
        } 
        else if(strstr(entryname->d_name, name.c_str())){
            BOLD_YELLOW_COLOR
            printlnf("%4s: %s\n", "[File]", entryname->d_name);
        }
        BLACK_COLOR // Reset
    }
    closedir(directory);
}

void
faddtextfunction::DeleteLine(std::string filename) {
    std::string file_string_path;
    file_string_path.append("edifor ");
    file_string_path.append(command->_file_path_cd_function);
    file_string_path.append("/");
    file_string_path.append(filename);
    filerunfunction->RunFunction(file_string_path); // I will write Scrift based text editor and run in Scrift.
}

void
faddtextfunction::AppendLine(std::string filepathw) {
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
FReadFileFunction::FReadFileFunction() {

}

FReadFileFunction::~FReadFileFunction() {

}

void
FClearFileFunction::ClearFeLogFunction() {
    std::ofstream file;
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    path.append(slash);
    path.append(".scrift_log");
    file.open(path); // append
    file << "FeLog Cleared.. \n";
    file.close();
}

void 
FReadFileFunction::ReadFeLogFunctionWithoutPrint() {
	int a = 0;
	std::string line;
	std::ifstream readfile(settings->Path());
	if(readfile.is_open()) {
		while(std::getline(readfile, line)) {
			a++;
		}
		if(a >= settings->FeLogCleaner()) {
			FClearFileFunction clearlog;
			clearlog.ClearFeLogFunction();
		} 
		readfile.close();
	} else { 
		filelog->AllofThem();
	}
}

void
FReadFileFunction::ReadFeLogFunction() {
    int a = 0;
    std::string line;
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    path.append(slash);
    path.append(".scrift_log");
    std::ifstream readfile(path);
    if(readfile.is_open()) {
        while(std::getline(readfile, line)) {
            printlnf(line.c_str());
            a++;
            slashn
        }
        std::cout << a << "\n";
        if(a >= settings->FeLogCleaner()) {
            FClearFileFunction *clearlog = new FClearFileFunction();
            clearlog->ClearFeLogFunction();
        } else {
            printlnf("Cool");
            slashn
        }
        readfile.close();
    } else {
        filelog->AllofThem();
    }
}

void
FReadFileFunction::ReadFileFunction(fstr filename) {
    std::string line;
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(filename);
    //path.append(txt);
    std::ifstream readfile(path);
    if(readfile.is_open()) {
        while (std::getline(readfile, line)) {
            printlnf(line.c_str());
            slashn
        }

        readfile.close();
    } else {
        printerror->PrintError("Unable to open file\n");
    }
}

void
FReadFileFunction::ReadSettingsFunction() {
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
    while (std::getline(readfile, line)) {
        BOLD_BLUE_COLOR
        printlnf(line.c_str());
        BLACK_COLOR
        slashn
    }
    }
}

void
FReadFileFunction::ReadASCIIFunction() {
    std::string line;
    std::string path;
    uid_t fuid = geteuid();
    struct passwd *pass = getpwuid(fuid);
    path.append("/home/");
    path.append(pass->pw_name); // Your username
    path.append("/");
    path.append(".scrift_ascii");
    //path.append(txt);
    std::ifstream readfile(path);
    if(readfile.is_open()) {
        while (std::getline(readfile, line)) {
            colorized::PrintWith(colorized::Colorize(BOLD, settings->ASCIIColor()).c_str(), line.c_str());
            slashn
        }
        readfile.close();
    } else {
        printerror->PrintError("Unable to open file\n");
    }
}
// FHOMEFUNCTION
void
fhomefunction::GetHome() {
    std::string path;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);
    path.append("/home/");
    path.append(password->pw_name);
    std::strcpy(command->_file_path_cd_function, path.c_str());
}


std::string
fhomefunction::CurrentDirectory(void) {
  char buff[FILENAME_MAX];
  getcwd( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}
// FILELSFUNCTION
FLSFunction::FLSFunction() {
    string = new fchar;
}

FLSFunction::~FLSFunction() { }

void
FLSFunction::InitLSFunction() { }

boolean
FLSFunction::DirectoryExists() { }


std::string
FLSFunction::GetObjects() {
    DIR *directory;
    directory = opendir("/bin/");
    while((entryname = readdir(directory))) {
    	stat(entryname->d_name, &filestat);
    	if(entryname->d_type == DT_DIR) {
    		BOLD_RED_COLOR
    		if(strstr(entryname->d_name, ".")) {
    		
    		} else if(strstr(entryname->d_name, "..")) {
    		
    		} else {
   			printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
		}
	} else {
		BOLD_YELLOW_COLOR
		printlnf("%4s: %s\n", "[Object]", entryname->d_name);
	}
	return entryname->d_name;
    	BLACK_COLOR
    }
    closedir(directory);
}

void 
FLSFunction::ListObjectFunction() {
    DIR *directory;
    directory = opendir("/bin/");
    while((entryname = readdir(directory))) {
    	stat(entryname->d_name, &filestat);
    	if(entryname->d_type == DT_DIR) {
    		BOLD_RED_COLOR
    		if(strstr(entryname->d_name, ".")) {
    		
    		} else if(strstr(entryname->d_name, "..")) {
    		
    		} else {
   			printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
		}
	} else {
		BOLD_YELLOW_COLOR
		printlnf("%4s: %s\n", "[Object]", entryname->d_name);
	}
    	BLACK_COLOR
    }
    closedir(directory);
}

bool
FLSFunction::ListArgumentObjectFunction(std::string argument) {
    DIR *directory;
    directory = opendir("/bin/");
    while((entryname = readdir(directory))) {
    	stat(entryname->d_name, &filestat);
    	if(entryname->d_type == DT_DIR) {
    		BOLD_RED_COLOR
    		if(strstr(entryname->d_name, ".")) {
    		
    		} else if(strstr(entryname->d_name, "..")) { } else if(strstr(entryname->d_name, argument.c_str())) {
   			return true;
		} else { }
	} else { }
    }
    closedir(directory);
}

void
FLSFunction::LSFunction(std::string arg) {
    DIR *directory;
    if(arg.rfind("#") == 0) {
    	arg = settings->EraseAllSubString(arg, "#");
    	std::string new_name(getenv(arg.c_str()));
    	directory = opendir((getenv("HOME"), "/", command->_file_path_cd_function, "/", new_name.c_str()));
    } else {
    	directory = opendir((getenv("HOME"), "/", command->_file_path_cd_function, "/", arg.c_str()));
    }
    if(directory == NULL) {
        printerror->PrintError("Directory not found.\n");
        return;
    }
    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {
            // Null
            } else if(strstr(entryname->d_name, "..")){
	    // Null
	    } else {  
            	printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
            }
        }  else if(strstr(entryname->d_name, "Elitefile")) {
            BOLD_BLUE_COLOR
            printlnf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
        } else if(strstr(entryname->d_name, ".scr")) {
            BOLD_GREEN_COLOR
            printlnf("%4s: %s\n", "[Scrift]", entryname->d_name);
        } else if(strstr(entryname->d_name, ".cpp") || strstr(entryname->d_name, ".hpp") || strstr(entryname->d_name, ".cxx") || strstr(entryname->d_name, ".hxx") || strstr(entryname->d_name, ".cc") || strstr(entryname->d_name, ".hh")) {
	    BOLD_CYAN_COLOR
            printlnf("%4s: %s\n", "[C++]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".c") || strstr(entryname->d_name, ".h")) {
	    BOLD_BLUE_COLOR
            printlnf("%4s: %s\n", "[C]", entryname->d_name);		
	} else if(strstr(entryname->d_name, "CMakeLists.txt")) {
	    BOLD_MAGENTA_COLOR
            printlnf("%4s: %s\n", "[CMake]", entryname->d_name);	
	} else if(strstr(entryname->d_name, ".sh")) {
	    BOLD_GREEN_COLOR
            printlnf("%4s: %s\n", "[Bash]", entryname->d_name);	
	
	} else if(strstr(entryname->d_name, ".py")) {
	    BOLD_BLUE_COLOR
            printlnf("%4s: %s\n", "[Python]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".fls") || strstr(entryname->d_name, ".flsh")) {
	    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    printlnf("%4s: %s\n", "[FlaScript]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".md")) {
	    BOLD_YELLOW_COLOR
            printlnf("%4s: %s\n", "[Markdown]", entryname->d_name);
	} else {
            BOLD_YELLOW_COLOR
            printlnf("%4s: %s\n", "[File]", entryname->d_name);
        }
        BLACK_COLOR // Reset
    }
    closedir(directory);
}


void
FRemoveFileFunction::DeleteFile(std::string file) {
    std::string path;
    path.append(command->_file_path_cd_function);
    path.append("/");
    path.append(file);
    const integer filedeletestage = std::remove(path.c_str());
    if(filedeletestage == 0) {
    	BOLD_GREEN_COLOR
        printlnf("Succesfully deleted\n");
        BLACK_COLOR
    } else {
        BOLD_RED_COLOR
        printlnf("Error: Unable to delete file.\n");
        BLACK_COLOR
    }
}


FCreateFileFunction::~FCreateFileFunction() {
     delete file_path, 
     file_name, 
     file_directory_string, 
     file_directory;
}

FCDFunction::~FCDFunction() {
    delete fmain, 
    printerror,
    command,
    ascii, 
    filelog, 
    settings;
}

