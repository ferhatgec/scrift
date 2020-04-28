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
#include "../include/src/Syntax/FileFunction.hpp"
#include "../include/src/Syntax/KernelName.hpp"
#include "../include/src/Syntax/HelpFunction.hpp"
#include "../include/src/Syntax/GetNameFunction.hpp"

// Variables 
FMain *main_function = new FMain();

static integer argc;
static fchar* argv[128];
integer x;
static integer8 num_str_;
static fchar *_ech_str;
static uinteger64 fn, sn;
static fchar *_file_def_path;
static  fchar *_username, *_os_kernel_,  *_run_file, *_run_file_;
FCommand *main_ = new FCommand();
fhelp *helpstr = new fhelp;
std::string _h_str;
FStructure *terminalstr = new FStructure();
fkernel *kernel = new fkernel;
FCDFunction *cdfunction = new FCDFunction();
FMKDirFunction *mkdirfunction = new FMKDirFunction();
FCreateFileFunction *filefunction = new FCreateFileFunction();
FGetUsername *userhostname = new FGetUsername(); 

// TEST VARIABLES 
fchar* testcharacter = new fchar;
integer test;
bool tesssst;
FMain::FMain()
{

}


FMain::~FMain()
{
    delete terminalstr,  helpstr, kernel,  _username, _os_kernel_, _run_file, _run_file_, _file_def_path,
    _ech_str, _h_str, argv, main_, mkdirfunction, filefunction, userhostname, main_function;
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
    terminalstr->Terminal(); 
    std::getline(std::cin, _h_str); // ws -> whitespace
    if (_h_str != "") { //NULL
    if(_h_str == "help" || _h_str == "-h")
    {
        argc = 1;
        helpstr->help();
        argc = 0;
        test = 1;
    }
    else if(_h_str.rfind("mkdir", 0) == 0) {
        argc = 1;
        strfor_h_str = _h_str.erase(0, 6);
        mkdirfunction->MKDirFunctionInit(strfor_h_str);
        argc = 0;
        test = 1;
    }
    else if(_h_str == "clear" || _h_str == "clear!!!") {argc = 1; main_->clear_shell(); argc = 0;
    test = 1;}
    else if (_h_str == "home" || _h_str == "default") {argc = 1;  argc = 0; 
    test = 1;}
    else if(_h_str.rfind("printlnf") == 0){
        strfor_h_str = _h_str.erase(0, 9);
        main_->echo_printlnf(strfor_h_str); 

    }
    else if(_h_str.rfind("cd", 0) == 0) {
        strfor_h_str = _h_str.erase(0,3);
        argc = 1; cdfunction->CDFunctionInit(strfor_h_str); argc = 0;  test = 1;
        
    }
    else if(_h_str == "brk" || _h_str == "cls")  {exit(EXIT_SUCCESS);} 
    else if(_h_str == "username" || _h_str == "uname") {argc = 1;  userhostname->InitUsername(); argc = 0;  test = 1;} 
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       argc = 1;
       fchar *_char_cin;
       main_->list_dir(true, true, true); 
       slashn
       argc = 0; 
       test = 1;   
    }
    else if(_h_str == "lsf" || _h_str == "lsfile")
    {   
        argc = 1;
        main_->list_file(true);
        slashn
        argc = 0;
        test = 1;
    }
    else if(_h_str.rfind("scr", 0) == 0)
    {
        strfor_h_str = _h_str.erase(0,4);
        argc = 1;
        main_->_run_all_func(strfor_h_str);
        argc = 0;
    }
    else if(_h_str == "lsd" || _h_str == "lsdir")
    {
        argc = 1;
        main_->list_direc(true);
        slashn
        argc = 0;  test = 1;
    }
    else if(_h_str.rfind("rstr", 0) == 0) {
        strfor_h_str = _h_str.erase(0, 5);
        int atest = atoi(strfor_h_str.c_str());
        main_->_generated_hash_string(atest); 
    }
    else if(_h_str == "fetcheya" || _h_str == "-f"){argc = 1; kernel->KernelName(); argc = 0;  test = 1; }
    else if(_h_str.rfind("ctxt", 0) == 0){
        strfor_h_str = _h_str.erase(0,5);
        filefunction->CreateFileFunctionInit(strfor_h_str);
    }
    else if(_h_str  == "setlocale_system" || _h_str == "slcl_sys"){argc = 1; main_->_set_locale(); argc = 0;  test = 1;}  
    else if(_h_str == "ip" || _h_str == "myip"){argc = 1; main_->_your_ip(); argc = 0;
     test = 1;} 
    else {
        printlnf("This command is not found!");
        slashn 
    }
    }
}



integer main(integer argc, fchar* argv[])
{
    helpstr->hello();
    while(argc = 2) {    
        main_function->Shell();
    }
    return 0;
}




