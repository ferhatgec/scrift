/*# MIT License
# Forked from https://github.com/FerhatGec/fsplusplus
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

namespace fsplusplus {
	std::string GetCurrentWorkingDir(void) {
  		char buff[FILENAME_MAX];
  		GetCurrentDir( buff, FILENAME_MAX );
  		std::string current_working_dir(buff);
  		return current_working_dir;
	}

	void List() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("ERR: DIRECTORY NOT FOUND OR NULL\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
            	printf("%4s: %s\n", "[Dir]", entryname->d_name);
            	}
            } 
            else if(strstr(entryname->d_name, ".scr"))
            {
            	printf("%4s: %s\n", "[Scrift]", entryname->d_name);
            }     
	    else if(strstr(entryname->d_name, ".cpp")) 
	    {
            	printf("%4s: %s\n", "[C++]", entryname->d_name);
	    }  
	    else if(strstr(entryname->d_name, ".c"))
	    {
            	printf("%4s: %s\n", "[C]", entryname->d_name);		
	    }
	    else if(strstr(entryname->d_name, "CMakeLists.txt"))
	    {
            	printf("%4s: %s\n", "[CMake]", entryname->d_name);	
	    }
	    else if(strstr(entryname->d_name, ".sh"))
	    {
            	printf("%4s: %s\n", "[Bash]", entryname->d_name);	
	    }
 	    else if(strstr(entryname->d_name, ".py")) 
	    {
            	printf("%4s: %s\n", "[Python]", entryname->d_name);
	    }
	    else if(strstr(entryname->d_name, ".md")) 
	    {
            	printf("%4s: %s\n", "[Markdown]", entryname->d_name);
	    }	
            else {
               printf("%4s: %s\n", "[File]", entryname->d_name);
            }
    	}
   	 closedir(directory);
	}
	
	void ListFile() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("ERR: DIRECTORY NOT FOUND OR NULL\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          	// Null
            	}
            } 
            else if(strstr(entryname->d_name, ".scr"))
            {
            	printf("%4s: %s\n", "[Scrift]", entryname->d_name);
            }     
	    else if(strstr(entryname->d_name, ".cpp")) 
	    {
            	printf("%4s: %s\n", "[C++]", entryname->d_name);
	    }  
	    else if(strstr(entryname->d_name, ".c"))
	    {
            	printf("%4s: %s\n", "[C]", entryname->d_name);		
	    }
	    else if(strstr(entryname->d_name, "CMakeLists.txt"))
	    {
            	printf("%4s: %s\n", "[CMake]", entryname->d_name);	
	    }
	    else if(strstr(entryname->d_name, ".sh"))
	    {
            	printf("%4s: %s\n", "[Bash]", entryname->d_name);	
	    }
 	    else if(strstr(entryname->d_name, ".py")) 
	    {
            	printf("%4s: %s\n", "[Python]", entryname->d_name);
	    }
	    else if(strstr(entryname->d_name, ".md")) 
	    {
            	printf("%4s: %s\n", "[Markdown]", entryname->d_name);
	    }	
            else {
               printf("%4s: %s\n", "[File]", entryname->d_name);
            }
    	}
   	 closedir(directory);
	}
	
	void ListDirectory() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("ERR: DIRECTORY NOT FOUND OR NULL\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          		printf("%4s: %s\n", "[Dir]", entryname->d_name);
            	}
            } else {
               // Null
            }
    	   }
   	 closedir(directory);
	}
	
	void ListFileDefault() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("ERR: DIRECTORY NOT FOUND OR NULL\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          	// Null
            	}
            } else {
               printf("%4s %s\n", entryname->d_name);
            }
    	}
   	 closedir(directory);
	}
	
	void ListDirectoryDefault() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("ERR: DIRECTORY NOT FOUND OR NULL\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          		printf("%4s %s\n", entryname->d_name);
            	}
            } else {
               // Null
            }
    	   }
   	 closedir(directory);	
	}
	
	void ListPath(std::string path) {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(path.c_str());
    	    if(directory == NULL) {
        	printf("ERR: DIRECTORY NOT FOUND OR NULL\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
            	printf("%4s: %s\n", "[Dir]", entryname->d_name);
            	}
            } 
            else if(strstr(entryname->d_name, ".scr"))
            {
            	printf("%4s: %s\n", "[Scrift]", entryname->d_name);
            }     
	    else if(strstr(entryname->d_name, ".cpp")) 
	    {
            	printf("%4s: %s\n", "[C++]", entryname->d_name);
	    }  
	    else if(strstr(entryname->d_name, ".c"))
	    {
            	printf("%4s: %s\n", "[C]", entryname->d_name);		
	    }
	    else if(strstr(entryname->d_name, "CMakeLists.txt"))
	    {
            	printf("%4s: %s\n", "[CMake]", entryname->d_name);	
	    }
	    else if(strstr(entryname->d_name, ".sh"))
	    {
            	printf("%4s: %s\n", "[Bash]", entryname->d_name);	
	    }
 	    else if(strstr(entryname->d_name, ".py")) 
	    {
            	printf("%4s: %s\n", "[Python]", entryname->d_name);
	    }
	    else if(strstr(entryname->d_name, ".md")) 
	    {
            	printf("%4s: %s\n", "[Markdown]", entryname->d_name);
	    }	
            else {
               printf("%4s: %s\n", "[File]", entryname->d_name);
            }
    	}
   	 closedir(directory);				
	}

	std::string CDFunction(std::string path) {
		return GetCurrentWorkingDir() + path;
	}
	
	void ReadFile(std::string file) {
		std::string line;
    		std::ifstream readfile((GetCurrentWorkingDir() + "/" + file).c_str());
    		if(readfile.is_open())
    		{
        	while (std::getline(readfile, line))
        	{
			printf(line.c_str());
			printf("\n");
        	}
        	readfile.close();
    	} else {
        	printf("Unable to open file\n");
    	}
    	}
    	
    	void FindPath(std::string name) {
    	    DIR *directory;
    	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
            printf("ERR: DIRECTORY OR FILE NOT FOUND OR NULL\n");
            return;
    	    }
    	    while ((entryname = readdir(directory)))
    	    {
            stat(entryname->d_name, &filestat);
            if(entryname->d_type == DT_DIR) {
                if(strstr(entryname->d_name, ".")) {
                // Null
                } else if(strstr(entryname->d_name, "..")){
	        // Null
	        } else if(strstr(entryname->d_name, name.c_str())) {  
            	  printf("%4s %s\n", "[Dir]", entryname->d_name);
                }
            } 
            else if(strstr(entryname->d_name, name.c_str())){
                 printf("%4s %s\n", "[File]", entryname->d_name);
            }
            }
   	 closedir(directory);
    	}
    	
    	void ReadFilePath(std::string path) {
    		std::string line;
    		std::ifstream readfile(path.c_str());
    		if(readfile.is_open())
    		{
        	while (std::getline(readfile, line))
        	{
			printf(line.c_str());
			printf("\n");
        	}
        	readfile.close();
    	} else {
        	printf("Unable to open file\n");
    	}
	
	}
}

#endif // FILE_SYSTEM_PLUS_PLUS_H
