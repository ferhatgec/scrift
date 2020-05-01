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
#include "../include/src/Syntax/Linker.hpp"
#include "../include/src/synflang.hpp"
#include "../include/src/Syntax/Log.hpp"
#include "../include/src/Syntax/FileFunction.hpp"
#include "../include/src/Syntax/KernelName.hpp"
#include "../include/src/Syntax/HelpFunction.hpp"
#include "../include/src/Syntax/GetNameFunction.hpp"
#include "../include/src/Syntax/RunFunction.hpp"
#include "../include/src/Syntax/ASCIIFunction.hpp"
// Variables 

using namespace FileFunction;
using namespace FLinker;

FMain *main_function = new FMain();
FCommand *main_ = new FCommand();
fhelp *helpstr = new fhelp;
FStructure *terminalstr = new FStructure();
fkernel *kernel = new fkernel;
FCDFunction *cdfunction = new FCDFunction();
FMKDirFunction *mkdirfunction = new FMKDirFunction();
FCreateFileFunction *filefunction = new FCreateFileFunction();
FGetUsername *userhostname = new FGetUsername(); 
fhomefunction *homefunction = new fhomefunction;
FLSFunction *listdirectoryfunction = new FLSFunction();
FRunFunction *runfunction = new FRunFunction();
FReadFileFunction *readfilefunction = new FReadFileFunction();
faddtextfunction *fileaddtextfunction = new faddtextfunction;
FLinkerAndSign *linkersign = new FLinkerAndSign();
FeLog *logsystem = new FeLog();

FMain::FMain()
{
    
}


FMain::~FMain()
{
    delete terminalstr,  helpstr, kernel, _h_str, main_, mkdirfunction, filefunction, userhostname, main_function,
    homefunction, listdirectoryfunction, runfunction, readfilefunction, fileaddtextfunction,
    linkersign;
}   


func
FMain::Shell()
{
    terminalstr->Terminal(); 
    std::getline(std::cin, _h_str); // ws -> whitespace
    
    if (_h_str != "") { //NULL
    // HELP FUNCTION
    if(_h_str == "help" || _h_str == "-h")
    {
        helpstr->help();
    }
    if(_h_str.find("&&", 0) == 0)
    {
        printlnf("Found!\n");
    }
    if(_h_str == "edifor" || _h_str == "scrifteditor")
    {
     
    }
    // ADD TEXT FUNCTION
    else if(_h_str.rfind("addtext", 0) == 0) {
        strfor_h_str = _h_str.erase(0, 8);
        fileaddtextfunction->AppendLine(strfor_h_str);
    }
    // NANO ADD TEXT FUNCTION
    else if(_h_str.rfind("nanoaddtext", 0) == 0) {
        strfor_h_str = _h_str.erase(0, 12);
        fileaddtextfunction->DeleteLine(strfor_h_str);
    }
    // DELETE TEXT FUNCTION
    else if(_h_str.rfind("deletetext", 0) == 0) {
        strfor_h_str = _h_str.erase(0,11);
        fileaddtextfunction->DeleteLine(strfor_h_str);
    }
    // CREATE FOLDER FUNCTION
    else if(_h_str.rfind("mkdir", 0) == 0) {
        strfor_h_str = _h_str.erase(0, 6);
        mkdirfunction->MKDirFunctionInit(strfor_h_str);
    }
    // READ TEXT FUNCTION
    else if (_h_str.find("readtext", 0) == 0) {
        strfor_h_str = _h_str.erase(0,9);
        readfilefunction->ReadFileFunction(strfor_h_str);
    }
    // CD FUNCTION
    else if(_h_str.rfind("cd", 0) == 0) {
        strfor_h_str = _h_str.erase(0,3);
        cdfunction->CDFunctionInit(strfor_h_str);
    }
    // HOME FUNCTION
    else if (_h_str == "home" || _h_str == "default") {homefunction->GetHome();}
    // LIST DIRECTORY FUNCTION
    else if(_h_str == "lsd" || _h_str == "lsdir")
    {
        main_->list_direc(true);
        slashn
    }
    // LIST FUNCTION
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       listdirectoryfunction->LSFunction();
       slashn   
    }
    // LIST FILE FUNCTION
    else if(_h_str == "lsf" || _h_str == "lsfile")
    {   
        main_->list_file(true);
        slashn
    }
    // CREATE TEXT FUNCTION
    else if(_h_str.rfind("ctxt", 0) == 0){
        strfor_h_str = _h_str.erase(0,5);
        filefunction->CreateFileFunctionInit(strfor_h_str);
    }
    // PRINT FUNCTION
    else if(_h_str.rfind("printlnf") == 0){
        strfor_h_str = _h_str.erase(0, 9);
        main_->echo_printlnf(strfor_h_str); 
    }
    // CLEAR FUNCTION
    else if(_h_str == "clear" || _h_str == "clear!!!") {main_->clear_shell();}

    // CLOSE FUNCTION
    else if(_h_str == "brk" || _h_str == "cls")  {exit(EXIT_SUCCESS);} 
    // USERNAME FUNCTION
    else if(_h_str == "username" || _h_str == "uname") {userhostname->InitUsername();} 
    // RUN FUNCTION
    else if(_h_str.rfind("scr", 0) == 0)
    {
        strfor_h_str = _h_str.erase(0,4);
        runfunction->RunFunction(strfor_h_str);
    }
    // RANDOMIZE STRING FUNCTION
    else if(_h_str.rfind("rstr", 0) == 0) {
        strfor_h_str = _h_str.erase(0, 5);
        int atest = atoi(strfor_h_str.c_str());
        main_->_generated_hash_string(atest); 
    }
    // PAUSE FUNCTION
    else if(_h_str == "pause" || _h_str == "stop") {
        printlnf("Enter the continue...");
        returni: if(std::cin.get() == '\n') {
                printlnf("Access\n");
            } else {
                goto returni;
        }
    }
    // SYSTEM INFO FUNCTION
    else if(_h_str == "fetcheya" || _h_str == "-f"){
        kernel->KernelName();
        kernel->CPUInfo();
        kernel->RAMInfo();
    }
    // LOCALE FUNCTION
    else if(_h_str  == "setlocale_system" || _h_str == "slcl_sys"){main_->_set_locale();}  
    // IP FUNCTION
    else if(_h_str == "ip" || _h_str == "myip"){main_->_your_ip();} 
    else { 
        printlnf("This command is not found!");
        slashn 
    }
    }
    
}



integer main(integer argc, fchar* argv[])
{
    asciifunction *ascii = new asciifunction;
    ascii->Allofthem();
    helpstr->hello();
    while(argc = 2) {    
        main_function->Shell();
    }
    
    return 0;
}




