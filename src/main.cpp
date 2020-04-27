/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include <fstream>
#include <memory>
#include <stdlib.h>
#include <iostream>
#include "../include/src/main.h"
#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <time.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include "../include/src/Syntax/CommandFunc.h"
#include <locale.h>
#include "../include/src/synflang.hpp"
#include "../include/src/Syntax/HelpFunction.hpp"

// Variables 
static integer argc;
static fchar* argv[128];
integer x;
static integer8 num_str_;
static fchar *_str_file_, *_ech_str;
static uinteger64 fn, sn;
static fchar *_file_def_path;
static  fchar *_username, *_os_kernel_,  *_run_file, *_run_file_;
FCommand *main_ = new FCommand();
fhelp *helpstr = new fhelp;
std::string _h_str;


#define OK 0
FMain::FMain()
{

}


FMain::~FMain()
{
    delete helpstr;
    delete[] _username, _os_kernel_, _run_file, _run_file_, _file_def_path,
    _ech_str, _str_file_, _h_str, argv; // Deleting chars
    delete main_;
}   



void
FMain::usage() 
{
    printlnf("Usage-> ./scrift <arguments>\n" 
       "<arguments> -> fprintln\n"
       "<arguments> -> var\n");
}


void
FMain::Shell()
{
    helpstr->hello();
    while(argc == 0)
    {
    argc = 0;
    main_->_term_(_str_file_); 
    std::cin >> _h_str;
    if(_h_str == "help" || _h_str == "-h")
    {
        argc = 1;
        helpstr->help();
        argc = 0;
    }
    else if(_h_str == "clear" || _h_str == "clear!!!") {argc = 1; main_->clear_shell(); argc = 0;}
    else if (_h_str == "home" || _h_str == "default") {argc = 1; main_->cd_func(getenv("HOME"), true); argc = 0; }
    else if(_h_str == "echo" || _h_str == "printlnf"){argc = 1; main_->echo_printlnf(); argc = 0;}
    else if(_h_str == "cd" || _h_str == "opendir") {argc = 1; main_->cd_func(main_->_file_path_cd_function, false); argc = 0;}
    else if(_h_str == "plus") {argc = 1; main_->plus_num(fn, sn); argc = 0;} 
    else if(_h_str == "brk" || _h_str == "cls")  {exit(EXIT_SUCCESS);} 
    else if(_h_str == "username" || _h_str == "uname") {argc = 1; main_->get_username(_username); printf("\n"); argc = 0;} 
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       argc = 1;
       fchar *_char_cin;
       main_->list_dir(true, true, true); 
       slashn
       argc = 0;    
    }
    else if(_h_str == "lsf" || _h_str == "lsfile")
    {   
        argc = 1;
        main_->list_file(true);
        slashn
        argc = 0;
    }
    else if(_h_str == "scr" || _h_str == "scriftrun")
    {
        argc = 1;
        main_->_run_all_func();
        argc = 0;
    }
    else if(_h_str == "lsd" || _h_str == "lsdir")
    {
        argc = 1;
        main_->list_direc(true);
        slashn
        argc = 0;
    }
    else if(_h_str == "randomizestr" || _h_str == "rstr"){argc = 1; main_->_generated_hash_string(x); argc = 0;}
    else if(_h_str == "fetcheya" || _h_str == "-f"){argc = 1; main_->_os_kernel_name(_os_kernel_); argc = 0;}
    else if(_h_str == "ctxt" || _h_str == "createtxt"){
        argc = 1;
        main_->create_file();
        argc = 0;
    }
    else if(_h_str  == "setlocale_system" || _h_str == "slcl_sys"){argc = 1; main_->_set_locale(); argc = 0;}  
    
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
    else if(_h_str == "ip" || _h_str == "myip"){argc = 1; main_->_your_ip(); argc = 0;} 
    }
}



integer main(integer argc, fchar* argv[])
{
    std::shared_ptr<FMain> fmain = std::make_shared<FMain>(); 
    if(argc < 2)
        fmain->usage();


    fmain->Shell();
    
}




