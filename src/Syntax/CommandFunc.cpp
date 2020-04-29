/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>

#include <Syntax/GetNameFunction.hpp>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <main.h>
#include <Syntax/CommandFunc.h>
#include <pwd.h>
#include <string.h>
#include <synflang.hpp>
#include <experimental/filesystem>
namespace filesys = std::experimental::filesystem;

static const char *_uname;

FCommand::FCommand()
{
    

}

FCommand::~FCommand()
{
    delete[] _home_dir, _file_path_cd_function, _uname;   
}



void 
FCommand::remove_character(char * _str, char ptr)
{
    if(_str == NULL)
        return;

    char * _pstr = _str;
    while(*_str)
    {
        if(*_str != ptr)
            *_pstr++ = *_str;
    _str++;
    }
    *_pstr = '\0';    
}

void
FCommand::echo_printlnf(std::string name)
{ 
    if(name != "")
    {
    printlnf(name.c_str());
    slashn
    } else  {
        printerror("ERR: CHAR IS NULL", 13, "ERR:CHISNULL");
        return;
    }
}

void
FCommand::_set_locale()
{
        printlnf("Set up -> Your system language");// setlocale(LC_CTYPE, NULL);
        setlocale(LC_CTYPE, NULL); // FOR UNIX AND FUSION
        printlnf(" \n"); 
}

void 
FCommand::clear_shell()
{
   std::cout << "\033[2J\033[1;1H"; 
}

void
FCommand::list_direc(boolean _home)
{
        integer files = 0;
        struct stat filestat;
        struct dirent *entry;
        DIR *dir;

        if(_home != false) {dir = opendir((getenv("HOME"), "/", _file_path_cd_function)); /*For Linux and *nix*/
        } else if(_home == false || _home == NULL)
        {
            dir = opendir(getenv("HOME"));
        }
        
        if (dir == NULL) 
        {
            printerror("ERR:DIRECTORY NOT FOUND", 12, "ERR:DIRNFND");
            return;
        }
        while ((entry = readdir(dir))) 
        {
            files++;
            char * _str = entry->d_name;
            remove_character(_str, '.');
            remove_character(_str, '..');
            stat(entry->d_name,&filestat);
            if(entry->d_type == DT_DIR) {
                BOLD_RED_COLOR
                printf("%4s: %s\n","Dir",entry->d_name); 
            }
            BLACK_COLOR
        }
        closedir(dir);
}

void 
FCommand::list_file(boolean _home)
{
        integer files = 0;
        struct stat filestat;
        struct dirent *entry;
        DIR *dir;

        if(_home != false) {dir = opendir((getenv("HOME"), "/", _file_path_cd_function)); /*For Linux and *nix*/
        } else if(_home == false || _home == NULL)
        {
            dir = opendir(getenv("HOME"));
        }
        
        if (dir == NULL) 
        {
            printerror("ERR:DIRECTORY NOT FOUND", 12, "ERR:DIRNFND");
            return;
        }
        while ((entry = readdir(dir))) 
        {
            files++;
            char * _str = entry->d_name;
            remove_character(_str, '.');
            remove_character(_str, '..');
            //printf("%d", entry->d_type, "\n");
            //printf("%d");
          //  printf("\033[0;34m");
            stat(entry->d_name,&filestat);
            if(entry->d_type == DT_DIR) {
            } else{
                BOLD_YELLOW_COLOR
                printf("%4s: %s\n"," File",entry->d_name);
            } 
            BLACK_COLOR
        }
        closedir(dir);
}


std::string 
FCommand::chartostring(std::string const & s, fchar *a)
{
    return s + a;
}

void 
FCommand::_run_all_func(std::string name)
{
    std::string _dir;
    _dir.append("/usr/bin/");
    _dir.append(name);
    system(_dir.c_str());
}

void
FCommand::plus_num(uinteger64 first_num, uinteger64 sec_num)
{
        printlnf("First number: ");
        std::cin >> first_num;
        printlnf("Second number ");
        std::cin >> sec_num;
        uinteger64 fs_num = sec_num + first_num;
        std::cout << fs_num << "\n";
}


void
FCommand::_generated_hash_string(integer size)
{
    slashn
    std::string str;
    for (integer i = 0; i < size; i++)
    {
        auto d = rand() % 26 + 'a';
        str.push_back(d);
    }
    for (integer i = 0; i < size; i++)
    {
        std::cout << str[i];
    }
    slashn
}

void
FCommand::_your_ip()
{
    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4
            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            fchar addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            printlnf("%s IP Address %s\n", ifa->ifa_name, addressBuffer); 
        } else if (ifa->ifa_addr->sa_family == AF_INET6) { // check it is IP6
            // is a valid IP6 Address
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            fchar addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            printlnf("%s IP Address %s\n", ifa->ifa_name, addressBuffer); 
        } 
 }
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
    return;
} 


void
FCommand::printerror(fchar *err_str, integer8 err_number, fchar * _error_code)
{
        printlnf(err_str, err_number);
}

void
FCommand::_n_supported_()
{
    printerror("Your os not supported!", 10, "1_n_support \n");
}
