/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#ifndef MAIN_H
#define MAIN_H

#include "Syntax.h"
#include "Path.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


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

class FMain : public FSyntax {
public:
    FMain();
    ~FMain();
    void echo_str(char *str_echo)
    {
        printf(str_echo);
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
    void _term_(char *file_str)
    {
        file_str = "$|";
        printf(file_str);
    }
    void readfunc(char *_cin,  char *argv[])
    {   
        // ls func begin
        if(_cin != "ls")
        {
           //I will be adding  
        }
    
        // ls func end
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