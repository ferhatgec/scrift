/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <sys/utsname.h>
#include <cstdlib>
#include <cstdio>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <src/Scrift.hpp>
#include <src/synflang.hpp>
#include <src/Syntax/Settings.hpp>

// Libraries
#include <EmojiPlusPlus.h>
#include <Colorized.hpp>
#include <StringTools.h>

static FCommand *command;

FCommand::FCommand() = default;

FCommand::~FCommand() = default;

void 
FCommand::remove_character(char * _str, char ptr) {
    if(_str == nullptr)
        return;

    char * _pstr = _str;
    while(*_str) {
        if(*_str != ptr)
            *_pstr++ = *_str;

    	_str++;
    }
    *_pstr = '\0';    
}


std::string
FCommand::FName() {
	struct utsname buf{};

	if(!uname(&buf)) { //Get name and information about current kernel.
		WHITE_COLOR
		//printf("%s\n",buf.sysname);//Display the system name.
		return buf.sysname;
	} else {
		BOLD_RED_COLOR
		perror("uname");
		return "?";
	}
	BLACK_COLOR
}


void
FCommand::echo_printlnf(std::string name) { 
    if(name.empty()) {
        WHITE_COLOR
        if(name.rfind("#USER") == 0) {
            std::cout << getenv("USER") << "\n";
        } else if(name.rfind("#PATH") == 0) {
            std::cout << getenv("PWD")  << "\n";
        } else if(name[0] == '#') {
		    name = name.erase(0, 1);
        	const char* env = getenv(name.c_str());
		
            if(env != nullptr)
			    std::cout << env;
		    else {
			    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : This Environment not found. ");
			    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), "Use:\n");
			    colorized::PrintWith(colorized::Colorize(BOLD, BLUE), "setname ");
			    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN), name.c_str());
			    colorized::PrintWith(colorized::Colorize(BOLD, CYAN), "\nsetto ");
			    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW), "<variable>");
		    }
        } else
        	std::cout << emojiplusplus::EmojiString(name);
        
        BLACK_COLOR
    }
}


void
FCommand::list_direc(boolean _home, std::string arg) {
    integer files = 0;
    struct stat filestat{};
    struct dirent *entry;
    DIR *dir;
	
    if(_home && arg.rfind('#') == 0) {
		arg = stringtools::EraseAllSubString(arg, "#");
    	dir = opendir((command->_file_path_cd_function, "/", getenv(arg.c_str())));
	} else {
        if(_home)
            dir = opendir((_file_path_cd_function, arg.c_str())); /*For Linux and *nix*/
        else dir = opendir(getenv("HOME"));
    }
    
    if (dir == nullptr) {
        std::cout << WBLWHITE << "Directory not found.\n";
        return;
    }
    
    while ((entry = readdir(dir))) {
        files++;
        stat(entry->d_name,&filestat);
        if(entry->d_type == DT_DIR) {
        	if(strstr(entry->d_name, ".")) {} 
            else if(strstr(entry->d_name, "..")) {} 
            else {	
        		std::cout << WBLBLUE << "[Direc]:  " << WBLWHITE << entry->d_name << "\n";        
            }
        }
        
        BLACK_COLOR
    }
    
    closedir(dir);
}

void 
FCommand::list_file(boolean _home, std::string arg) {
    integer files = 0;
    struct stat filestat{};
    struct dirent *entry;
    DIR *dir;
	
    if(_home && arg.rfind('#') == 0) {
		arg = stringtools::EraseAllSubString(arg, "#");
    	std::string new_name(getenv(arg.c_str()));
    	dir = opendir((command->_file_path_cd_function, "/", new_name.c_str()));
	} else {
        if(_home)
            dir = opendir((_file_path_cd_function, arg.c_str())); /*For Linux and *nix*/
        else dir = opendir(getenv("HOME"));
    }
        
    if (dir == nullptr) {
        std::cout << WBLWHITE << "Directory not found.\n";
        return;
    }
    
    while ((entry = readdir(dir))) {
        files++;
        remove_character(entry->d_name, '.');
        remove_character(entry->d_name, '..');
        
        stat(entry->d_name,&filestat);
        if(entry->d_type == DT_DIR) {} 
        else {
            std::cout << WBYELLOW << "[File]:   " << WBWHITE << entry->d_name << "\n";
        } 
        
        BLACK_COLOR
    }
    
    closedir(dir);
}


void
FCommand::_generated_hash_string(integer size) {
    std::string str;
    for (integer i = 0; i < size; i++) {
        auto d = rand() % 40 + '0';
        str.push_back(d);
    }
    
    for (integer i = 0; i < size; i++) {
    	BOLD_CYAN_COLOR
        std::cout << str[i];
        BLACK_COLOR
    }
}

void
FCommand::getIPAddress() {
    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    sockaddr_in loopback{};

    if (sock == -1) 
        std::cerr << "Could not socket\n";

    std::memset(&loopback, 0, sizeof(loopback));
    loopback.sin_family = AF_INET;
    loopback.sin_addr.s_addr = INADDR_LOOPBACK;   // using loopback ip address
    loopback.sin_port = htons(9);                 // using debug port

    if (connect(sock, reinterpret_cast<sockaddr*>(&loopback), sizeof(loopback)) == -1) {
        close(sock);
        std::cerr << "Could not connect\n";
    }

    socklen_t addrlen = sizeof(loopback);
    
    if (getsockname(sock, reinterpret_cast<sockaddr*>(&loopback), &addrlen) == -1) {
        close(sock);
        std::cerr << "Could not getsockname\n";
    }

    close(sock);

    char buf[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET, &loopback.sin_addr, buf, INET_ADDRSTRLEN) == nullptr)
        std::cerr << "Could not inet_ntop\n";
    else {
        std::cout << WBOLD_GREEN_COLOR << "Local ip address: ";
        std::cout << WBOLD_YELLOW_COLOR << buf << "\n";
    }
}

