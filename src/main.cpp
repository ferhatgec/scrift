/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */



#include "Path.h"
#include "Syntax.h"
#include <iostream>
#include "main.h"
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

FMain::FMain()
{
    _help_str = _hello_str;
}


FMain::~FMain()
{
    delete[] _help_str;
}


int main(int argc, char *argv[], std::string _h_str, help_str* help_str_, int8_t num_str_, char *_str_file_, char *_ech_str,
uint64_t first_num, uint64_t sec_num)
{
    argc = atoi(_h_str.c_str());
    FMain *_main = new FMain();
    _main->hello();
    while(argc >= 0)
    {
    FMain *_str_file = new FMain();
    _str_file->_term_(_str_file_);
    if(argc >= 0)
    {
 std::cin >> _h_str;
    argc += 1;
    
    if(_h_str == "")
    {
        num_str_ += 1;
        FMain *_err = new FMain();
        _err->printerror("This is NULL", num_str_);
    }
    if(_h_str == "help" || _h_str == "-h")
    {
        argc -= 1;
    printf("Scrift \n");
       // printf(help_str_->_help_str_); This code calling Segmentation Fault (core dumped) error!
    //char *scr_help_str = help_str_->_help_str_; This code calling same error.
    printf("help arguments: \n "
    "echo <arg> \n"
    "plus"
    "./<file> \n"
    "close || break \n"
    "cd <folder>\n \n ");
    
    } 
    if(_h_str == "plus")
    {
        FMain *plus = new FMain();
        plus->plus_num(first_num, sec_num);
    }
    if(_h_str == "break" || _h_str == "close")
    {
       return 0;
    }


    }
   
    
    }
}





