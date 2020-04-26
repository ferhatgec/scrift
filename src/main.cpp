/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include <fstream>
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
static integer8 num_str_;
static fchar *_str_file_, *_ech_str;
static uinteger64 fn, sn;
static fchar *_file_def_path;
static  fchar *_username, *_os_kernel_,  *_run_file, *_run_file_;
FCommand *main_ = new FCommand();
std::string _h_str;


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
        "help arguments: \n"
        "echo <arg> \n"
        "plus\n"
        "./<file> \n"
        "cls || brk \n"
        "cd <folder>\n"
        "randomize || rstr\n"
        "username\n"
        "ls\n"
        "fetcheya\n"
        "clear || clear!!!\n"
        "set_locale_system || slcl_sys\n"
        "ip || myip\n");
    
    }
    else if(_h_str == "run" || _h_str == "./" || _h_str == "bash" || _h_str == "sh")
    {
        main_->_run_bash_file();
    }
    else if(_h_str == "clear" || _h_str == "clear!!!") {main_->clear_shell();}
    else if (_h_str == "home" || _h_str == "default") {main_->cd_func(getenv("HOME"), true); }
    else if(_h_str == "echo" || _h_str == "printlnf"){main_->echo_printlnf();}
    else if(_h_str == "cd" || _h_str == "opendir") {main_->cd_func(main_->_file_path_cd_function, false);}
    else if(_h_str == "plus") {main_->plus_num(fn, sn);} 
    else if(_h_str == "brk" || _h_str == "cls")  {exit(EXIT_SUCCESS);} 
    else if(_h_str == "username" || _h_str == "uname") {main_->get_username(_username); printf("\n");} 
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       fchar *_char_cin;
       main_->list_dir(true, true, true); 
       slashn    
    }
    else if(_h_str == "lsf" || _h_str == "lsfile")
    {   
        main_->list_file(true);
        slashn
    }
    else if(_h_str == "apt" || _h_str == "advancedpackagetool")
    {
        main_->_run_apt();
        slashn
    }
    else if(_h_str == "drun" || _h_str == "scriftrun")
    {
        main_->_run_all_func();
    }
    else if(_h_str == "make" || _h_str == "Make")
    {
        main_->_run_gnu_make();
        slashn;
    }
    else if(_h_str == "lsd" || _h_str == "lsdir")
    {
        main_->list_direc(true);
        slashn
    }
    else if(_h_str == "randomizestr" || _h_str == "rstr"){main_->_generated_hash_string(x);}
    else if(_h_str == "fetcheya" || _h_str == "-f"){main_->_os_kernel_name(_os_kernel_);}
    else if(_h_str == "ctxt" || _h_str == "createtxt"){
        main_->create_file();
    }
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




