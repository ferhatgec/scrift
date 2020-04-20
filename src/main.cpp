/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#include <stdlib.h>
#include "../include/src/File/Path.h"
#include "../include/src/Syntax/Syntax.h"
#include <iostream>
#include "../include/src/main.h"
#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include "../include/src/File/File.h"
#include "../include/src/File/Sync.h"
#include <stdio.h>
#include "../include/src/Syntax/CommandFunc.h"
#include <locale.h>
#include "../include/src/synflang.hpp"
static  integer argc;
static fchar* argv[128];

static std::string _h_str;
static integer8 num_str_;
static fchar *_str_file_, *_ech_str;
static uinteger64 fn, sn;
static fchar *_file_def_path;
static  fchar *_username, *_os_kernel_,  *_run_file, *_run_file_;

#define OK 0
FMain::FMain()
{

}


FMain::~FMain()
{

}



void usage()
{
    printlnf("Usage-> ./scrift <arguments>\n"
       "<arguments> -> fprintln\n"
       "<arguments> -> var\n");
}


void Shell()
{

    FCommand *main_ = new FCommand();
    argc = atoi(_h_str.c_str()); // string  to int
    main_->hello(); // printing hello text
    while(argc >= 0) 
    {
    // calling FMain -> _term_(char)
    if(argc >= 0)
    {
    main_->_term_(_str_file_); 
    // input _h_str 
    std::cin >> _h_str;
    argc += 1;

    if(_h_str == "") // NULL 
    {
        main_->_term_(_str_file_);
        num_str_ += 1;
        main_->printerror("This is NULL", num_str_);
    }
    else if(_h_str == "help" || _h_str == "-h")
    {
       
        argc -= 1;
    printlnf("Scrift \n");
       // printlnf(help_str_->_help_str_); This code calling Segmentation Fault (core dumped) error!
    //char *scr_help_str = help_str_->_help_str_; This code calling same error.
    printlnf("help arguments: \n "
    "echo <arg> \n"
    "plus"
    "./<file> \n"
    "cls || brk \n"
    "cd <folder>\n \n "
    "randomize || rstr\n"
    "username\n"
    "ls\n"
    "fetcheya\n"
    "set_locale_system || slcl_sys\n"
    "ip || myip\n");
    
    }

    else if(_h_str == "plus") // argument
    {
        main_->plus_num(fn, sn); // FMain -> plus_num (int64_t first_n..
    } 
    else if(_h_str == "brk" || _h_str == "cls") // break or close 
    {
       return; 
    } 
    else if(_h_str == "username" || _h_str == "uname") // This code calling Segmentation fault
    {
        //main_->get_username(_username);
        main_->get_username(_username);
    } // This code calling Segmentation fault
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       main_->list_dir("/home/ferhatgec");  
       printlnf("\n");    
    }
    else if(_h_str == "randomizestr" || _h_str == "rstr")
    {
        integer x;
        main_->_generated_hash_string(x);
    }
    else if(_h_str == "fetcheya" || _h_str == "-f")
    {
        main_->_os_kernel_name(_os_kernel_);
    }
    else if(_h_str == "ctxt" || _h_str == "createtxt")
    {
       // main_->
    }
    else if(_h_str  == "setlocale_system" || _h_str == "slcl_sys")
    {
	    main_->_set_locale();
     
    }  

    else if(_h_str == "run" || _h_str == "#/")
    {
        //scanf("%s", _run_file_);
        #ifdef __linux__
      
        #elif _WIN32
        printlnf("Sorry, Fegeya Scrift not supporting Windows NT");
        #elif _WIN64
        printlnf("Sorry, Fegeya Scrift not supporting Windows NT");
        #else
       
        #endif
    }
    else if(_h_str == "ip" || _h_str == "myip")
    {
        main_->_your_ip();
    } 

}
}
}


int main(integer argc, fchar* argv[])
{
    if(argc < 2)
        usage();

  
    if (argc >= 2) {
     for(integer i = 0; i < argc; i++)
     {
        std::string param = argv[i];
        printlnf("This command is not for Fegeya Scrift \n -> ");
        std::cout << param << "\n";
     }
    }

    Shell();

}




