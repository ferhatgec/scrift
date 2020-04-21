/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <memory>
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

// Variables 
static integer argc;
static fchar* argv[128];
integer x;
static std::string _h_str;
static integer8 num_str_;
static fchar *_str_file_, *_ech_str;
static uinteger64 fn, sn;
static fchar *_file_def_path;
static  fchar *_username, *_os_kernel_,  *_run_file, *_run_file_;
FCommand *main_ = new FCommand();


#define OK 0
FMain::FMain()
{

}


FMain::~FMain()
{
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
  
    argc = atoi(_h_str.c_str()); // string  to int
    main_->hello(); // printing hello text
    while(argc >= 0) 
    {
    // calling FMain -> _term_(char)
    if(argc >= 0)
    {
    main_->_term_(_str_file_);  
    std::cin >> _h_str;
    argc += 1;
    if(_h_str == "help" || _h_str == "-h")
    {
       // argc -= 1;
        printlnf("Scrift \n"
        "help arguments: \n "
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

    else if(_h_str == "plus") {main_->plus_num(fn, sn);} 
    else if(_h_str == "brk" || _h_str == "cls")  {return;} 
    else if(_h_str == "username" || _h_str == "uname") {main_->get_username(_username); printf("\n");} 
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       main_->list_dir(); 
       slashn    
    }
    else if(_h_str == "randomizestr" || _h_str == "rstr"){main_->_generated_hash_string(x);}
    else if(_h_str == "fetcheya" || _h_str == "-f"){main_->_os_kernel_name(_os_kernel_);}
    else if(_h_str == "ctxt" || _h_str == "createtxt"){/* main_->*/}
    else if(_h_str  == "setlocale_system" || _h_str == "slcl_sys"){main_->_set_locale();}  
    
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
    else if(_h_str == "ip" || _h_str == "myip"){main_->_your_ip();} 
}
}
}



int main(integer argc, fchar* argv[])
{
    std::shared_ptr<FMain> fmain = std::make_shared<FMain>(); 
    if(argc < 2)
        fmain->usage();
    

    fmain->Shell();
    
}




