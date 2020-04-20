/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <unistd.h>
#include <limits.h>
#include "../../include/src/main.h"
#include "../../include/src/Syntax/CommandFunc.h"
#include "../../include/src/File/File.h"
#include "../../include/src/File/Directory.h"
#include <pwd.h>
#include "../../include/src/synflang.hpp"

FCommand::FCommand()
{


}

FCommand::~FCommand()
{


    
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
FCommand::echo_str(fchar *str_echo)
{
        std::cin >> str_echo;
        printlnf(str_echo);
}


void
FCommand::get_username(fchar *_your_username)
{
      #ifdef __linux__
       uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (pw)
    {
      printlnf(pw->pw_name);
      _your_username = pw->pw_name;
     }
     // printlnf("\n", _your_username, "\n");
      #else 
      printlnf("\nFegeya Fusion Username:", "user", "or ",  _n_supported_()); // ; deleted
      #endif
}
void
FCommand::_os_kernel_name(fchar *_your_os_kernel)
{
    #ifdef _WIN32
    _your_os_kernel = "Windows NT 32-bit\n";
    #elif _WIN64
    _your_os_kernel "Windows NT 64-bit \n";
    #elif __APPLE__ || __MACH__
    _your_os_kernel  = "Darwin \n";
    #elif __linux__
    _your_os_kernel = "Linux <3 \n";
    #elif __FreeBSD__
    _your_os_kernel = "BSD \n";
    #elif __unix || __unix__
    _your_os_kernel = "Unix \n";
    #else
    _your_os_kernel = "Fegeya Fusion or not supported operating system :) \n";
    #endif
    printlnf(_your_os_kernel);
}

void
FCommand::_set_locale()
{
        printlnf("Set up -> Your system language");// setlocale(LC_CTYPE, NULL);
        setlocale(LC_CTYPE, NULL); // FOR UNIX AND FUSION
        printlnf(" \n"); 
}

void
FCommand::list_dir(const fchar *path) 
{
        struct dirent *entry; // #i.. <dirent.h>
        DIR *dir = opendir(path); // open path dir
   
        if (dir == NULL) 
        {
            return;
        }
        while ((entry = readdir(dir)) != NULL) 
        {
            char * _str = entry->d_name;
            remove_character(_str, '.');
            remove_character(_str, '..');
            std::cout << _str << "  ";
            
        }
        closedir(dir);
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
FCommand::_generated_hash_string(int size)
{
    
    std::cout << "Enter size : ";
    std::cin >> size;
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
    printlnf("\n");
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
FCommand::error_undfnd(fchar *undefined_str)
{
        undefined_str = "This is Undefined \n";
        printlnf(undefined_str);
}
void
FCommand::_file_path(fchar *list_path_def_name)
{
         list_dir("/home/ferhatgec"); 
}

void
FCommand::get_hostname() // username@hostname$|
{
    fchar hostbuffer[256];  
    struct hostent *host_entry; 
    integer hostname; 
    hostname = gethostname(hostbuffer, sizeof(hostbuffer)); 
    printlnf("%s", hostbuffer); 
}


void
FCommand::_term_(fchar *file_str)
{
    fchar *_uname;
    get_username(_uname);
    file_str = " $# ";
    printlnf("@");
    get_hostname();
    printlnf(file_str);
}
void
FCommand::help()
{
      //  std::cin >> _cin;
   
     printlnf(_help_str);
        
}

void
FCommand::cd_func(fchar *new_path)
{
        
}

void
FCommand::hello()
{
      //  *_h_str = *_hello_str; -> This code calling Segmentation Fault error. 
        printlnf(_help_str);
}

void
FCommand::printerror(fchar *err_str, integer8 err_number)
{
        printlnf(err_str, err_number);
}

void
FCommand::_n_supported_()
{
    fchar *file = "Your os not supported!";
     fchar *_err_code = "1_n_support \n";
    printlnf(file, " ", _err_code);
}

void
FCommand::error_syntax(fchar *err_str, integer8 err_number)
{   
      
        printerror(err_str, err_number);
}

