/*# MIT License
# 
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef FILE_SYSTEM_PLUS_PLUS_H
#define FILE_SYSTEM_PLUS_PLUS_H

#include <cstring>
#include <iostream>
#include <pwd.h>
#include <dirent.h>
#include <fstream>
#include <sys/stat.h>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#define FS_PLUS_PLUS_VERSION "0.2-beta-1"

namespace fsplusplus {
    static std::string EraseAllSubString(std::string & mainString, const std::string & erase) {
        size_t pos = std::string::npos;
   	    
        while((pos = mainString.find(erase)) != std::string::npos) mainString.erase(pos, erase.length());
   		
        return mainString;
    }

	// Get Between String    
	static void GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, std::string &rStr) {  
        int start = oStr.find(sStr1);   
        
        if(start >= 0) {       
      		std::string tstr = oStr.substr(start + sStr1.length());        
      		int stop = tstr.find(sStr2);      
      		
            if (stop >1) rStr = oStr.substr(start + sStr1.length(), stop);
      		else rStr ="error";  
        } else
       		rStr = "error"; 
	}
	
	static std::string GetCurrentWorkingDir(void) {
  		char buff[FILENAME_MAX];
  		
        GetCurrentDir( buff, FILENAME_MAX );
  		std::string current_working_dir(buff);

  		return current_working_dir;
	}

	static bool IsExistFile(std::string path) {
        struct stat buffer;
    	return (stat(path.c_str(), &buffer) == 0);
	}


	static void List() {
	    DIR *directory;
	    
        struct dirent *entryname;
	    struct stat filestat;
        directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
        
        if(directory == NULL) {
        	std::cout << "Error: Directory not found.\n";
        	return;
        }
        
        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")){} 
                else
            	    std::cout << "[Dir]: " << entryname->d_name << "\n";
            } 
            else if(strstr(entryname->d_name, "Elitefile")) std::cout << "[Elitebuild]: " << entryname->d_name << "\n";
            else if(strstr(entryname->d_name, ".scrift_log")) std::cout << "[FeLog*]: " << entryname->d_name << "\n";
	    	else if(strstr(entryname->d_name, ".scrift_ascii")) std::cout << "[Ascii Art]: " << entryname->d_name << "\n";
            else if(strstr(entryname->d_name, ".scrift_settings")) std::cout << "[Settings*]: " << entryname->d_name << "\n";
	    	else if(strstr(entryname->d_name, ".scrift_history")) std::cout << "[History*]: " << entryname->d_name << "\n";
	    	else if(strstr(entryname->d_name, ".scr")) std::cout << "[Scrift]: " << entryname->d_name << "\n";
            else if(strstr(entryname->d_name, ".cpp") || 
                strstr(entryname->d_name, ".hpp") || 
                strstr(entryname->d_name, ".cxx") || 
                strstr(entryname->d_name, ".hxx") || 
                strstr(entryname->d_name, ".cc")  || 
                strstr(entryname->d_name, ".hh")) std::cout << "[C++]: " << entryname->d_name << "\n";
	        else if(strstr(entryname->d_name, ".c") || 
                strstr(entryname->d_name, ".h")) std::cout << "[C]: " << entryname->d_name << "\n";
	    	else if(strstr(entryname->d_name, "CMakeLists.txt")) std::cout << "[CMake]: " << entryname->d_name << "\n";
	    	else if(strstr(entryname->d_name, ".sh")) std::cout << "[Shell]: " << entryname->d_name << "\n";
	    	else if(strstr(entryname->d_name, ".py")) std::cout << "[Python]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".fls") || 
                strstr(entryname->d_name, ".flsh")) std::cout << "[FlaScript]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".md")) std::cout << "[Markdown]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".frbr")) std::cout << "[FreeBrain]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".png")) std::cout << "[Png]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".jpg") || 
                strstr(entryname->d_name, ".jpeg")) std::cout << "[Jpg]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".gif")) std::cout << "[Gif]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".html") || 
                strstr(entryname->d_name, ".htm")) std::cout << "[Html]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".rs") || 
                strstr(entryname->d_name, ".rslib")) std::cout << "[Rust]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".lua")) std::cout << "[Lua]: " << entryname->d_name << "\n";
		    else if(strstr(entryname->d_name, ".inclink")) std::cout << "[includeLink]: " << entryname->d_name << "\n";
		    else std::cout << "[File]: " << entryname->d_name << "\n";
        }
   	 
        closedir(directory);
	}
	
	static void ListFile() {
	    DIR *directory;
	    
        struct dirent *entryname;
	    struct stat filestat;
        directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
        
        if(directory == NULL) {
        	std::cout << "Error: Directory not found.\n";
        	return;
        }
        
        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type != DT_DIR) {
                if(strstr(entryname->d_name, "Elitefile")) std::cout << "[Elitebuild]: " << entryname->d_name << "\n"; 
                else if(strstr(entryname->d_name, ".scrift_log")) { std::cout << "[FeLog*]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".scrift_ascii")) { std::cout << "[Ascii Art]: " << entryname->d_name << "\n"; }
                else if(strstr(entryname->d_name, ".scrift_settings")) { std::cout << "[Settings*]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".scrift_history")) { std::cout << "[History*]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".scr")) { std::cout << "[Scrift]: " << entryname->d_name << "\n"; }
                else if(strstr(entryname->d_name, ".cpp") || 
                    strstr(entryname->d_name, ".hpp") || 
                    strstr(entryname->d_name, ".cxx") || 
                    strstr(entryname->d_name, ".hxx") || 
                    strstr(entryname->d_name, ".cc")  || 
                    strstr(entryname->d_name, ".hh")) { std::cout << "[C++]: " << entryname->d_name << "\n"; }
	            else if(strstr(entryname->d_name, ".c") || 
                    strstr(entryname->d_name, ".h")) {std::cout << "[C]: " << entryname->d_name << "\n"; }
    	    	else if(strstr(entryname->d_name, "CMakeLists.txt")) { std::cout << "[CMake]: " << entryname->d_name << "\n"; }
	        	else if(strstr(entryname->d_name, ".sh")) { std::cout << "[Shell]: " << entryname->d_name << "\n"; }
	        	else if(strstr(entryname->d_name, ".py")) { std::cout << "[Python]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".fls") || 
                    strstr(entryname->d_name, ".flsh")) { std::cout << "[FlaScript]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".md")) { std::cout << "[Markdown]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".frbr")) { std::cout << "[FreeBrain]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".png")) { std::cout << "[Png]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".jpg") || 
                    strstr(entryname->d_name, ".jpeg")) { std::cout << "[Jpg]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".gif")) { std::cout << "[Gif]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".html") || 
                    strstr(entryname->d_name, ".htm")) { std::cout << "[Html]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".rs") || 
                    strstr(entryname->d_name, ".rslib")) { std::cout << "[Rust]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".lua")) { std::cout << "[Lua]: " << entryname->d_name << "\n"; }
	    	    else if(strstr(entryname->d_name, ".inclink")) { std::cout << "[includeLink]: " << entryname->d_name << "\n"; }
	    	    else std::cout << "[File]: " << entryname->d_name << "\n";
            }
        }
   	 
        closedir(directory);
	}
	
	static void ListDirectory() {
	    DIR *directory;

	    struct dirent *entryname;
	    struct stat filestat;
        
        directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
        if(directory == NULL) {
        	std::cout << "Error: Directory not found.\n";
        	return;
        }

        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {} 
                else 
                    std::cout << "[Dir]: " << entryname->d_name << "\n";
            } 
        }
   	 
        closedir(directory);
	}
	
	static void ListFileDefault() {
	    DIR *directory;
    
	    struct dirent *entryname;
	    struct stat filestat;

    	    directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());

        if(directory == NULL) {
        	std::cout << "Error: Directory not found.\n";
        	return;
        }

        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type != DT_DIR) std::cout << entryname->d_name << "\n";
    	}
   	 
        closedir(directory);
	}
	
	static void ListDirectoryDefault() {
	    DIR *directory;
	    
        struct dirent *entryname;
	    struct stat filestat;

        directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());

        if(directory == NULL) {
        	std::cout << "Error: Directory not found.\n";
        	return;
        }
        
        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {}
	    	    else 
          		    std::cout << entryname->d_name << "\n";
            }        
        }
        
        closedir(directory);	
    }
		
    static void ListPath(std::string dir) {
	    DIR *directory;

	    struct dirent *entryname;
	    struct stat filestat;
        
        directory = opendir((fsplusplus::GetCurrentWorkingDir() +  "/" + dir).c_str());
        if(directory == NULL) {
        	std::cout << "Error: Directory not found.\n";
        	return;
        }

        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {} 
                else 
                    std::cout << "[Dir]: " << entryname->d_name << "\n";
            } 
        }
   	 
        closedir(directory);
	}

	static std::string ListPathWithReturn(std::string path) {
	    DIR *directory;
	    std::string add;
	 
        struct dirent *entryname;
	    struct stat filestat;

        directory = opendir(path.c_str());

        if(directory == NULL) return "null"; 

        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        
        	if(entryname->d_type == DT_DIR) {
            	if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {} 
                else   
          		    add.append(entryname->d_name);
            } else
               	add.append(entryname->d_name);
        }
   	 	
        closedir(directory);
		
        return add;	
	}

	static std::string ListDirectoryWithReturn(std::string path) {
	    DIR *directory;
	    std::string add;
	    
        struct dirent *entryname;
	    struct stat filestat;

        directory = opendir(path.c_str());

        if(directory == NULL) return "null";

        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type == DT_DIR) {
            	if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {} 
                else
          		    add.append(entryname->d_name);
            }
        }
        
   	    closedir(directory);
	    
        
        return add;
	}
	
	static std::string ListFileWithReturn(std::string path) {
	    DIR *directory;
	    std::string add;
	    
        struct dirent *entryname;
	    struct stat filestat;
        
        directory = opendir(path.c_str());

        if(directory == NULL) return "null";
    
        while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	
            if(entryname->d_type != DT_DIR) add.append(entryname->d_name);
        }
   	  
        closedir(directory);

        return add;
	}

	static std::string CDFunction(std::string path) {
		return fsplusplus::GetCurrentWorkingDir() + path;
	}
	
	static void ReadFile(std::string file) {
        std::string line;
        std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());
    		
        if(readfile.is_open()) {
        	while (std::getline(readfile, line)) std::cout << line << "\n";
    	} else 
            std::cout << "Unable to open file\n";
    }
    	
    static std::string ReadFileWithReturn(std::string file) {
		std::string line, data;
        std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());
    	
    	if(readfile.is_open()) {
        	while (std::getline(readfile, line)) data.append(line + "\n");
        } else 
        		std::cout << "Unable to open file\n";
            
        return data;
    }
    	
    static std::string FindStringWithReturn(std::string file, std::string str) {
		std::string line;
    	std::ifstream readfile(file.c_str());
    	
    	if(readfile.is_open()) {
        	while (std::getline(readfile, line))
        		if(strstr(line.c_str(), str.c_str())) return line + "\n";
    	}
		
    	return "null";
	}
    	
    static void FindPath(std::string name) {
        DIR *directory;
        struct dirent *entryname;
	    struct stat filestat;

        directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());

        if(directory == NULL) {
            std::cout << "Error: Directory not found.\n";
            return;
        }

        while ((entryname = readdir(directory))) {
            stat(entryname->d_name, &filestat);

            if(entryname->d_type == DT_DIR) {
                if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {} 
                else if(strstr(entryname->d_name, name.c_str())) std::cout << "[Dir]:" << entryname->d_name << "\n";
            } else if(strstr(entryname->d_name, name.c_str())) std::cout << "[File]:" << entryname->d_name << "\n";            
    	}
        
        closedir(directory);
    }

    static void ReadFilePath(std::string path) {
        std::string line;
    	std::ifstream readfile(path.c_str());
    	
       	if(readfile.is_open()) {
        	while (std::getline(readfile, line)) std::cout << line + "\n";
        	
    	} else
        	std::cout << "Unable to open file\n";
	}
	
	static void ReadCPU() {
        std::string line;
		
        #ifdef __FreeBSD__
			std::ifstream readfile("/var/run/dmesg.boot");
		#else     		
			std::ifstream readfile("/proc/cpuinfo");
		#endif    		

		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
			    #ifdef __FreeBSD__
			        if(line.find("CPU: ") == 0) {
				        line = EraseAllSubString(line, "CPU: ");

				        std::cout << line + "\n";
				        return;
        		    }
			    #else        		
			        if(line.find("model name	: ") == 0) {
				        line = fsplusplus::EraseAllSubString(line, "model name	: ");
				        
                        std::cout << line + "\n";
				        return;
        		    }
			    #endif
        	}
    	} else
        	std::cout << "Unable to open file\n";
	}
	
	static void ReadOSName(std::string path) {
        #ifdef __FreeBSD__
		    std::cout << "FreeBSD\n";
		#else
    		std::string line;
    		std::ifstream readfile(path.c_str());
    		
            if(readfile.is_open()) {
            	while (std::getline(readfile, line)) {
            		if(line.find("PRETTY_NAME=\"") == 0) {
        				fsplusplus::GetBtwString(line, "\"", "\"", line); 
				        
                        std::cout << line + "\n";
        		    }
        	    } 
    		} else
        		std::cout << "Unable to open file\n";
		#endif
	}
	
	static void CreateFile(std::string name, std::string input) {
        std::string path;
        path.append(fsplusplus::GetCurrentWorkingDir());
        path.append("/");
        path.append(name);
    
        std::ofstream file(path, std::ios::app);
        file << input;
        
        file.close();
	}
	
	static void CreateFileWithoutAppend(std::string name) {
		std::string path;
    	path.append(fsplusplus::GetCurrentWorkingDir());
        path.append("/");
        path.append(name);
    	
        std::ofstream file(path);
        
        file.close();
	}
}

#endif // FILE_SYSTEM_PLUS_PLUS_H
