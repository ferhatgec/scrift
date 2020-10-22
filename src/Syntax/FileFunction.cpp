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
#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>
#include <vector>
#include <memory>

#include <src/Syntax/CommandFunc.h>
#include <src/Scrift.hpp>
#include <src/Syntax/RunFunction.hpp>
#include <src/Syntax/GetNameFunction.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Syntax/MkdirFunction.hpp>
#include <src/Syntax/Log.hpp>
#include <src/Syntax/Settings.hpp>
#include <src/Syntax/ASCIIFunction.hpp>

// Library
#include <Colorized.hpp>
#include <FileSystemPlusPlus.h>
#include <StringTools.h>

using namespace FileFunction;

/*
	Classes
*/
std::unique_ptr<FRunFunction> filerunfunction(new FRunFunction);
std::unique_ptr<FeLog> filelog(new FeLog);
std::unique_ptr<FSettings> settings(new FSettings);
std::unique_ptr<FCommand> command(new FCommand);
std::unique_ptr<FMain> fmain(new FMain);
std::unique_ptr<FCDFunction> fcdfunction(new FCDFunction);

/*
	Structures.
*/
std::unique_ptr<FASCIIFunction> ascii(new FASCIIFunction);

struct stat filestat;
struct dirent *entryname;

fchar* file_name;
fchar* file_directory;
std::string path_directory;
std::string file_directory_string;

FCDFunction::FCDFunction() {}


bool
FCDFunction::FileExists(const std::string &Filename) {
    return access(Filename.c_str(), 0) == 0;
}

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
FCDFunction::CDFunctionInit(std::string name) {
    if(name != "") {
        if(fmain->_home != true) {
	    	if(strstr(name.c_str(), "#")) {
	    		name = stringtools::EraseAllSubString(name, "#");
	    		std::string new_name(getenv(name.c_str()));
	    		if(new_name.rfind("/") == 0) {
	    			if(FileExists(new_name) == true) {
            		    std::strcpy(command->_file_path_cd_function, new_name.c_str());
	    		    	chdir(new_name.c_str());
			    		fmain->SetTitle();
            		} else {
            		    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "scrift : ");
			    		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), new_name.c_str());
			    		colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), " : This directory is not exist!\n");
            		    
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
            		} else {
            		    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "scrift : ");
			    		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), new_name.c_str());
			    		colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), " : This directory is not exist!\n");
            		    
						return;
            		}
            	}
	   	 	} else {
	    		if(name.rfind("/") == 0) {
	    			if(FileExists(name) == true) {
	    		    	std::strcpy(command->_file_path_cd_function, name.c_str());
	    		    	chdir(name.c_str());
            		} else {
            		    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "scrift : ");
			    		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), name.c_str());
				    	colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), " : This directory is not exist!\n");
            		}
            		
					return;
	    		} else {
					std::string path;
	    			/*if(command->_file_path_cd_function == "/") {
					path.append(command->_file_path_cd_function);
					path.append(name);
					} else {*/
            		path.append(command->_file_path_cd_function);
            		path.append("/");
            		path.append(name);
            		//}
            		if(FileExists(path) == true) {
            	    	chdir(name.c_str());
		    			//char *path(&fsplusplus::GetCurrentWorkingDir()[0]);
                    	std::strcpy(command->_file_path_cd_function, &fsplusplus::GetCurrentWorkingDir()[0]);
		    			fmain->SetTitle();
					} else {
            	    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "scrift : ");
				    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), name.c_str());
		    			colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), " : This directory is not exist!\n");
            	    
						return;
            		}
            	}
            }
        }
    }

    return;
}

// FMKDIRFUNCTION
FMKDirFunction::FMKDirFunction() {}


FMKDirFunction::~FMKDirFunction() {}


void
FMKDirFunction::MKDirFunctionInit(std::string name) {
    // I will use std::getline.
    path_directory.append(command->_file_path_cd_function); // default getenv("HOME")
    path_directory.append("/"); // ex: /home/username -> getenv("HOME") -> /home/username'/'
    path_directory.append(name); // maybe directory is exist or directory is not exist.
    if(mkdir(path_directory.c_str(), 0777) == -1 ) {// 0777 is user permission number.
        std::cout << "Directory is exist or you're not root\n";
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
FCreateFileFunction::FCreateFileFunction() { }

void
FCreateFileFunction::CreateScriftFile(std::string pathname) {
    std::string path;
    
	path.append(command->_file_path_cd_function);
    path.append(slash);
    path.append(pathname);
    path.append(scrift);
    std::ofstream file(path, std::ios::app);
    file << "printlnf(\"This Scrift file created by Scrift.\");\n";
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
    std::string path;
    path.append(getenv("HOME"));
    path.append("/");
    path.append(file);
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}



void
FCreateFileFunction::CreateSettingsFileFunction() {
    if(IsExistFile(".scrift_settings") != true) {
    	std::string pathfile;
    	pathfile.append(getenv("HOME"));
    	pathfile.append("/");
    	pathfile.append(".scrift_settings");
    	std::ofstream file(pathfile, std::ios::app);
    	file << "[CUSTOMIZE]\nfelog_cleaner 100\n";
    	file << "welcome_emoji :thinking_face:\n";
    	file << "bg_color 12\n";
    	file << "ascii_art_color random\n";
    	file << "scrift_theme default\n";
    	file << "input_customize ▶\n";
		file << "welcome_message yes\n";
		file << "local_git_branch yes\n";
        file << "scrift_setup yes\n";
		file << "auto_clear 40\n";
		file << "date_info yes\n";
		file << "sign_1 @\n";
		file << "sign_2 :~\n";
		file << "\n[PROMPT] @username@[1;34m] @sign_1@[1;36m] @hostname@[1;35m] @sign_2@[1;36m] @directory@[1;33m] @whitespace@[1;36m] @branch@[1;36m] @clock@[1;93m] @whspace@[1;36m] @input_sign@[1;31m]";
    	file.close();
    }
}

void
FClearFileFunction::ClearSettingsFunction() {
    if(IsExistFile(".scrift_settings") == true) {
        filelog->WriteLog("Clearing Settings File - ");
        std::string path;
        path.append(getenv("HOME"));
        path.append("/");
        path.append(".scrift_settings");
        std::ofstream file(path); // App = Append
        file << "[CUSTOMIZE]\nfelog_cleaner 100\n";
    	file << "welcome_emoji :thinking_face:\n";
    	file << "bg_color 12\n";
    	file << "ascii_art_color random\n";
    	file << "scrift_theme default\n";
    	file << "input_customize ▶\n";
		file << "welcome_message yes\n";
		file << "local_git_branch yes\n";
        file << "scrift_setup yes\n";
		file << "auto_clear 40\n";
		file << "date_info yes\n";
		file << "sign_1 @\n";
		file << "sign_2 :~\n";
		file << "\n[PROMPT] @username@[1;34m] @sign_1@[1;36m] @hostname@[1;35m] @sign_2@[1;36m] @directory@[1;33m] @whitespace@[1;36m] @branch@[1;36m] @clock@[1;93m] @whspace@[1;36m] @input_sign@[1;31m]";
		file.close();
    } else
        CreateSettingsFileFunction();
}


void
FCreateFileFunction::CreateASCIIFileFunction() {
    if(ascii->InitFile() != true) {
		std::string path;
    	path.append(getenv("HOME"));
    	path.append(slash);
    	path.append(".scrift_ascii");
    	//command->chartostring(file_directory_string, file_directory);
    	std::ofstream file(path, std::ios::app);
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
    int line_number = 0;
    std::string line;
    std::string path;
    path.append(getenv("HOME"));
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
    } else
        filelog->AllofThem();
}

std::string
FFindFileFunction::FindWithoutPrint(std::string name) {
    DIR *directory;
    directory = opendir(command->_file_path_cd_function);
    if(directory == NULL)
        std::cout << "Error: Directory not found.\n";
    
    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {} 
			else if(strstr(entryname->d_name, "..")){} 
			else if(strstr(entryname->d_name, name.c_str()))
	    		return entryname->d_name;
        } else if(strstr(entryname->d_name, name.c_str())) {}
    }

    closedir(directory);
    
	return "null";
}


void
FFindFileFunction::FindFile(std::string name) {
    DIR *directory;
    directory = opendir(command->_file_path_cd_function);
    if(directory == NULL) {
        std::cout << "Error: Directory not found.\n";
        return;
    }
    
	while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {} 
			else if(strstr(entryname->d_name, "..")) {} 
			else if(strstr(entryname->d_name, name.c_str()))
            	printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
        } else if(strstr(entryname->d_name, "Elitefile")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
            	BOLD_BLUE_COLOR
            	printlnf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
	    	}
        } else if(strstr(entryname->d_name, ".scrift_log")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
	    		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printlnf("%4s: %s\n", "FeLog*", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".scrift_ascii")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printlnf("%4s: %s\n", "Ascii Art*", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".scrift_settings")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
            	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printlnf("%4s: %s\n", "Settings*", entryname->d_name);
	    	}
        } else if(strstr(entryname->d_name, ".scrift_history")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
            	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printlnf("%4s: %s\n", "History*", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".scr")) {
            if(strstr(entryname->d_name, name.c_str())) {
            	BOLD_GREEN_COLOR
            	printlnf("%4s: %s\n", "[Scrift]", entryname->d_name);
		    }
        } else if(strstr(entryname->d_name, ".cpp") || strstr(entryname->d_name, ".hpp") ||
				strstr(entryname->d_name, ".cxx") || strstr(entryname->d_name, ".hxx") || strstr(entryname->d_name, ".cc") || strstr(entryname->d_name, ".hh")) {
            if(strstr(entryname->d_name, name.c_str())) {
				BOLD_CYAN_COLOR
            	printlnf("%4s: %s\n", "[C++]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".c") || strstr(entryname->d_name, ".h")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
	    		BOLD_BLUE_COLOR
            	printlnf("%4s: %s\n", "[C]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, "CMakeLists.txt")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
	    		BOLD_MAGENTA_COLOR
            	printlnf("%4s: %s\n", "[CMake]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".sh")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
	    		BOLD_GREEN_COLOR
            	printlnf("%4s: %s\n", "[Bash]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".py")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
	    		BOLD_BLUE_COLOR
            	printlnf("%4s: %s\n", "[Python]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".fls") || strstr(entryname->d_name, ".flsh")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    		printlnf("%4s: %s\n", "[FlaScript]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".md")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				BOLD_YELLOW_COLOR
        		printlnf("%4s: %s\n", "[Markdown]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".frbr")) {
     	    if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "");
           		printlnf("%4s: %s\n", "[FreeBrain]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".png")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
  	    		printlnf("%4s: %s\n", "[Png]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".jpg") || strstr(entryname->d_name, ".jpeg")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
	    		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
	    		printlnf("%4s: %s\n", "[Jpg]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".gif")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
	    		printlnf("%4s: %s\n", "[Gif]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".html") || strstr(entryname->d_name, ".htm")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "");
            	printlnf("%4s: %s\n", "[Html]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".rs") || strstr(entryname->d_name, ".rslib")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, YELLOW).c_str(), "");
	    		printlnf("%4s: %s\n", "[Rust]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".lua")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLACK).c_str(), "");
	    		printlnf("%4s: %s\n", "[Lua]", entryname->d_name);
	    	}
		} else if(strstr(entryname->d_name, ".inclink")) {
	    	if(strstr(entryname->d_name, name.c_str())) {
				colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
				printlnf("%4s: %s\n", "[includeLink]", entryname->d_name);
		    }
		} else {
			if(strstr(entryname->d_name, name.c_str())) {
            	BOLD_YELLOW_COLOR
            	printlnf("%4s: %s\n", "[File]", entryname->d_name);
			}
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
    
	if(file.fail())
        std::cout << "Fail.";
    

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << line << std::endl;
    printlnf("Done.\n");
}



// READFILEFUNCTION
FReadFileFunction::FReadFileFunction() {}

FReadFileFunction::~FReadFileFunction() {}

void
FClearFileFunction::ClearFeLogFunction() {
    std::ofstream file;
    std::string path;
    path.append(getenv("HOME"));
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
		while(std::getline(readfile, line))	a++;
		
		if(a >= settings->FeLogCleaner()) {
			FClearFileFunction clearlog;
			clearlog.ClearFeLogFunction();
		}
		
		readfile.close();
	} else 
		filelog->AllofThem();
}

void
FReadFileFunction::ReadFeLogFunction() {
    int a = 0;
    std::string line;
    std::string path;
    path.append(getenv("HOME"));
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
        } else
            printlnf("Cool\n");
        
        readfile.close();
    } else
        filelog->AllofThem();
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
    } else
		std::cout << "Unable to open file\n";
}

void
FReadFileFunction::ReadSettingsFunction() {
    std::string line;
    std::string fpath;
    fpath.append(getenv("HOME"));
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
    path.append(getenv("HOME"));
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
    } else
        std::cout << "Unable to open file\n";
    
}
// FHOMEFUNCTION
void
fhomefunction::GetHome() {
    std::string path;
    path.append(getenv("HOME"));
    std::strcpy(command->_file_path_cd_function, path.c_str());
    chdir(getenv("HOME"));
}


std::string
fhomefunction::CurrentDirectory(void) {
	char buff[FILENAME_MAX];
  	getcwd( buff, FILENAME_MAX );
  	std::string current_working_dir(buff);
  
  	return current_working_dir;
}
// FILELSFUNCTION
FLSFunction::FLSFunction() { }

FLSFunction::~FLSFunction() { }

std::string
FLSFunction::GetObjects() {
    DIR *directory;
    directory = opendir("/bin/");
    while((entryname = readdir(directory))) {
    	stat(entryname->d_name, &filestat);
    	if(entryname->d_type == DT_DIR) {
    		BOLD_RED_COLOR
    		if(strstr(entryname->d_name, ".")) {} 
			else if(strstr(entryname->d_name, "..")) {} 
			else 
   				printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
		} else {
			BOLD_YELLOW_COLOR
			printlnf("%4s: %s\n", "[Object]", entryname->d_name);
		}
		
		BLACK_COLOR
		return entryname->d_name;
    }

    closedir(directory);
    
	return "null";
}

void
FLSFunction::ListObjectFunction() {
    DIR *directory;
    directory = opendir("/bin/");
    while((entryname = readdir(directory))) {
    	stat(entryname->d_name, &filestat);
    	if(entryname->d_type == DT_DIR) {
    		BOLD_RED_COLOR
    		if(strstr(entryname->d_name, ".")) {} 
			else if(strstr(entryname->d_name, "..")) {} 
			else 
   				printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
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
    		if(strstr(entryname->d_name, ".")) {} 
			else if(strstr(entryname->d_name, "..")) {} 
			else if(strstr(entryname->d_name, argument.c_str()))
   				return true;
			else {}
		}
    }
    
	closedir(directory);
    
	return false;
}

void
FLSFunction::LSFunction(std::string arg) {
    DIR *directory;
    if(arg.rfind("#") == 0) {
    	arg = stringtools::EraseAllSubString(arg, "#");
    	std::string new_name(getenv(arg.c_str()));
    	directory = opendir((command->_file_path_cd_function, "/", new_name.c_str()));
    } else
    	directory = opendir((command->_file_path_cd_function, "/", arg.c_str()));
    
    if(directory == NULL) {
        std::cout << "Directory not found.\n";
        return;
    }

    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {} 
			else if(strstr(entryname->d_name, "..")) {} 
			else
            	printlnf("%4s: %s\n", "[Dir]", entryname->d_name);
        } else if(strstr(entryname->d_name, "Elitefile")) {
            BOLD_BLUE_COLOR
            printlnf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
        } else if(strstr(entryname->d_name, ".scrift_log")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    	printlnf("%4s: %s\n", "FeLog*", entryname->d_name);
		} else if(strstr(entryname->d_name, ".scrift_ascii")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    	printlnf("%4s: %s\n", "Ascii Art*", entryname->d_name);
		} else if(strstr(entryname->d_name, ".scrift_settings")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    	printlnf("%4s: %s\n", "Settings*", entryname->d_name);
		} else if(strstr(entryname->d_name, ".scrift_history")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    	printlnf("%4s: %s\n", "History*", entryname->d_name);
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
		} else if(strstr(entryname->d_name, ".frbr")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "");
	    	printlnf("%4s: %s\n", "[FreeBrain]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".png")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
		    printlnf("%4s: %s\n", "[Png]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".jpg") || strstr(entryname->d_name, ".jpeg")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
	    	printlnf("%4s: %s\n", "[Jpg]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".gif")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
	    	printlnf("%4s: %s\n", "[Gif]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".html") || strstr(entryname->d_name, ".htm")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "");
	    	printlnf("%4s: %s\n", "[Html]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".rs") || strstr(entryname->d_name, ".rslib")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, YELLOW).c_str(), "");
	    	printlnf("%4s: %s\n", "[Rust]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".lua")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLACK).c_str(), "");
	    	printlnf("%4s: %s\n", "[Lua]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".inclink")) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    	printlnf("%4s: %s\n", "[includeLink]", entryname->d_name);
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


FCreateFileFunction::~FCreateFileFunction() {}

FCDFunction::~FCDFunction() {}
