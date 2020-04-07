/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include "Syntax.h"
#include "Path.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "Sync.h"
#include <iomanip>

#define TR_ 1
#define FL_ 0

typedef struct {
public:
 char *err_str = "ERROR - string is not declared";
 char *err_syn = "ERROR - syntax is undefined";
 char *err_ls  = "There is no such directory";
 char *_help_str_ = "help arguments: "
    "echo <arg>"
    "<intnumber> plus <intnumber>"
    "./<file>"
    "exit"
    "cd <folder>";
 char *_func_err_ = "Function calling error";
}help_str;


//FSync *fsync__ = new FSync();

class FMain  {
public:
    FMain();
    ~FMain();
    void echo_str(char *str_echo)
    {
        printf(str_echo);
    }
    void get_username(char *_your_username)
    {
        _your_username = getenv("USER");
    }
    void list_dir(const char *path) 
    {
        struct dirent *entry; // #i.. <dirent.h>
        DIR *dir = opendir(path); // open path dir
   
        if (dir == NULL) 
        {
            return;
        }
        while ((entry = readdir(dir)) != NULL) 
        {
            std::cout << entry->d_name << "  ";
        }
        closedir(dir);
    }
    void plus_num(uint64_t first_num, uint64_t sec_num)
    {
        printf("First number: ");
        std::cin >> first_num;
        printf("Second number ");
        std::cin >> sec_num;
        uint64_t fs_num = sec_num + first_num;
        std::cout << fs_num << "\n";
    }
    void fetcheya(int ram_size, char *cpu_type)
    {
       // fsync__->CPU(cpu_type);
    }
    void error_undfnd(char *undefined_str)
    {
        undefined_str = "This is Undefined \n";
        printf(undefined_str);
    }
    void _term_(char *file_str)
    {
        file_str = "$|";
        printf(file_str);
    }
    void help()
    {
      //  std::cin >> _cin;
   
     printf(_help_str);
        
    }
    void hello()
    {
      //  *_h_str = *_hello_str; -> This code calling Segmentation Fault error. 
        printf(_hello_str);
    }
    void printerror(char *err_str, int8_t err_number)
    {
        printf(err_str, err_number);
    }

    void error_syntax(char *err_str, int8_t err_number)
    {   
      
        printerror(err_str, err_number);
    }
private:
    char *_help_str = "help arguments: "
    "echo <arg>"
    "<intnumber> plus <intnumber>"
    "./<file>"
    "exit"
    "cd <folder>";
    char *_hello_str = "Welcome ScriftLang Terminal\n"
    "ScriftLang licensed with GPLv3'\n"
    "Copyright (c) 2020 Ferhat Gecdogan\n";
};





#endif // MAIN_H