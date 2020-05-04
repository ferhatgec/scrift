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
#include "../include/src/Syntax/PrintErrorFunction.hpp"
#include "../include/src/Syntax/KernelName.hpp"
#include "../include/src/Syntax/HelpFunction.hpp"
#include "../include/src/Syntax/GetNameFunction.hpp"
#include "../include/src/Syntax/RunFunction.hpp"
#include "../include/src/Syntax/Test.hpp"
#include "../include/src/Syntax/ASCIIFunction.hpp"
#include "../include/src/Syntax/DeveloperMode.hpp"
#include "../include/src/Syntax/Contributors.hpp"
#include "../include/src/Syntax/Colors.hpp"
// Variables 

using namespace FileFunction;
using namespace FLinker;
FContributors *contributors_lists = new FContributors();
FDeveloperMode *developermode = new FDeveloperMode();
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
FRemoveFileFunction *removefile = new FRemoveFileFunction();
FMain::FMain()
{
    
}


FMain::~FMain()
{
    delete terminalstr,  helpstr, kernel, _h_str, main_, mkdirfunction, filefunction, userhostname, main_function,
    homefunction, listdirectoryfunction, runfunction, readfilefunction, fileaddtextfunction,
    linkersign, removefile, developermode, contributors_lists;
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
        logsystem->WriteLog("Launching help function.. - ");
        helpstr->help();
        logsystem->WriteLog("Launched.. - ");
    }
    else if(_h_str == "gitlink" || _h_str == "scrift_link" || _h_str == "fusionlink")
    {
        helpstr->GitLink();
    }
    else if(_h_str == "cont" || _h_str == "contr" || _h_str == "contributors")
    {
        contributors_lists->AllOfThem();
    }
    else if(_h_str.find("&&", 0) == 0)
    {
        printlnf("Found!\n");
    }
    else if(_h_str == "felog" || _h_str == "show_log")
    {
        logsystem->WriteLog("Launching felog function.. - ");
        readfilefunction->ReadFeLogFunction();
        logsystem->WriteLog("Launched.. - ");
    }
    else if(_h_str == "clear_log" || _h_str == "felog --clear")
    {
        logsystem->WriteLog("Launching ClearLog function.. - ");
        printlnf("Clearing... - ");
        logsystem->ClearLog();
        logsystem->WriteLog("Launched.. - ");
        printlnf("Done.\n");
    }
    else if(_h_str.rfind("getdev", 0) == 0)
    {
        logsystem->WriteLog("Launching getdev function.. - ");
        strfor_h_str = _h_str.erase(0, 7);
        if(strfor_h_str == "true" || strfor_h_str == "-t")  {
            developermode->AllOfThem(true);
            logsystem->WriteLog("Launched with true boolean - ");
        }
        else {
            developermode->AllOfThem(false);
            logsystem->WriteLog("Launched with false boolean - ");
        }
    }
    // ADD TEXT FUNCTION
    else if(_h_str.rfind("addtext", 0) == 0) {
        logsystem->WriteLog("Launching addtext function.. - ");
        strfor_h_str = _h_str.erase(0, 8);
        logsystem->WriteLog("Erasing _h_str string.. -");
        fileaddtextfunction->AppendLine(strfor_h_str);
        logsystem->WriteLog("Launched\n");
    }
    // NANO ADD TEXT FUNCTION
    else if(_h_str.rfind("nanoaddtext", 0) == 0) {
        logsystem->WriteLog("Launching nanoaddtext function.. - ");
        strfor_h_str = _h_str.erase(0, 12);
        logsystem->WriteLog("Erasing _h_str string.. - ");
        fileaddtextfunction->DeleteLine(strfor_h_str);
        logsystem->WriteLog("Launched\n");
    }
    else if(_h_str.rfind("rmvfile", 0) == 0) {
        logsystem->WriteLog("Launching rmvfile function.. -");
        strfor_h_str = _h_str.erase(0, 8);
        logsystem->WriteLog("Erasing _h_str string. -");
        removefile->DeleteFile(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }
    // DELETE TEXT FUNCTION
    else if(_h_str.rfind("deletetext", 0) == 0) {
        logsystem->WriteLog("Launching deletetext function.. - ");
        strfor_h_str = _h_str.erase(0,11);
        logsystem->WriteLog("Erasing _h_str string.. -");
        fileaddtextfunction->DeleteLine(strfor_h_str);
        logsystem->WriteLog("Launched.. -");
    }
    // CREATE FOLDER FUNCTION
    else if(_h_str.rfind("mkdir", 0) == 0) {
        logsystem->WriteLog("Launching mkdir function.. - ");
        strfor_h_str = _h_str.erase(0, 6);
        logsystem->WriteLog("Erasing _h_str string.. -");
        mkdirfunction->MKDirFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched.. - "); 
    }
    // READ TEXT FUNCTION
    else if (_h_str.find("readtext", 0) == 0) {
        logsystem->WriteLog("Launching readtext function.. - ");
        strfor_h_str = _h_str.erase(0,9);
        logsystem->WriteLog("Erasing _h_str string.. - ");
        readfilefunction->ReadFileFunction(strfor_h_str);
        logsystem->WriteLog("Launched.. -");  
    }
    // CD FUNCTION
    else if(_h_str.rfind("cd", 0) == 0) {
        logsystem->WriteLog("Launching cd function.. -");
        strfor_h_str = _h_str.erase(0,3);
        logsystem->WriteLog("Erasing _h_str string.. -");
        cdfunction->CDFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }
    // HOME FUNCTION
    else if (_h_str == "home" || _h_str == "default") {
        logsystem->WriteLog("Launching home function.. - ");
        homefunction->GetHome();
        logsystem->WriteLog("Launched.. - ");
    }
    // LIST DIRECTORY FUNCTION
    else if(_h_str == "lsd" || _h_str == "lsdir")
    {

        main_->list_direc(true);
        logsystem->WriteLog("Launched.. - "); 
        slashn
    }
    // LIST FUNCTION
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       listdirectoryfunction->LSFunction();
       logsystem->WriteLog("Launched.. - ");
       slashn   
    }
    // LIST FILE FUNCTION
    else if(_h_str == "lsf" || _h_str == "lsfile")
    {   
        main_->list_file(true);
        logsystem->WriteLog("Launched.. - "); 
        slashn
    }
    // CREATE TEXT FUNCTION
    else if(_h_str.rfind("ctxt", 0) == 0){
        logsystem->WriteLog("Launching ctxt function..\n");
        strfor_h_str = _h_str.erase(0,5);
        logsystem->WriteLog("Erasing _h_str function..\n");
        filefunction->CreateFileFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched.. -"); 
    }
    // PRINT FUNCTION
    else if(_h_str.rfind("printlnf") == 0){
        logsystem->WriteLog("Launching printlnf function.. - ");
        strfor_h_str = _h_str.erase(0, 9);
        logsystem->WriteLog("Erasing _h_str function.. - ");
        main_->echo_printlnf(strfor_h_str); 
        logsystem->WriteLog("Launched.. - "); 
    }
    // CLEAR FUNCTION
    else if(_h_str == "clear" || _h_str == "clear!!!") {
        logsystem->WriteLog("Launching clear function.. - ");
        main_->clear_shell();
        logsystem->WriteLog("Launched.. - "); 
    }

    // CLOSE FUNCTION
    else if(_h_str == "brk" || _h_str == "cls")  {
        logsystem->WriteLog("Exit signal.. - ");
        logsystem->WriteLog("Launched.. - "); 
        exit(EXIT_SUCCESS);
    } 
    // USERNAME FUNCTION
    else if(_h_str == "username" || _h_str == "uname") {
        logsystem->WriteLog("Launching username function.. - ");
        userhostname->InitUsername();
        logsystem->WriteLog("Launched.. - ");
        slashn
    } 
    // RUN FUNCTION
    else if(_h_str.rfind("scr", 0) == 0)
    {
        logsystem->WriteLog("Erasing _h_str function.. - ");
        strfor_h_str = _h_str.erase(0,4);
        logsystem->WriteLog("Launching _h_str function.. - ");
        runfunction->RunFunction(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }
    // RANDOMIZE STRING FUNCTION
    else if(_h_str.rfind("rstr", 0) == 0) {
        logsystem->WriteLog("Launching rstr function.. - ");
        strfor_h_str = _h_str.erase(0, 5);
        logsystem->WriteLog("Erasing _h_str function.. - ");
        int atest = atoi(strfor_h_str.c_str());
        logsystem->WriteLog("Append integer.. - ");
        main_->_generated_hash_string(atest);
        logsystem->WriteLog("Launched.. - "); 
    }
    // PAUSE FUNCTION
    else if(_h_str == "pause" || _h_str == "stop") {
        logsystem->WriteLog("Launching pause function.. - ");
        printlnf("Enter the continue...");
        logsystem->WriteLog("Printing Enter the continue.. - ");
        returni: if(std::cin.get() == '\n') {
                logsystem->WriteLog("Input.. - ");
                printlnf("Access - ");
                logsystem->WriteLog("Accessing returni function.. - ");
            } else {
                goto returni;
        }
        logsystem->WriteLog("Launched.. - ");
    }
    // SYSTEM INFO FUNCTION
    else if(_h_str == "fetcheya" || _h_str == "-f"){
        logsystem->WriteLog("Launching fetcheya function.. - ");
        kernel->KernelName();
        logsystem->WriteLog("Running KernelName function.. - ");
        kernel->CPUInfo();
        logsystem->WriteLog("Running CPUInfo function.. - ");
        kernel->RAMInfo();
        logsystem->WriteLog("Erasing RAMInfo function.. - ");
    }
    // LOCALE FUNCTION
    else if(_h_str  == "setlocale_system" || _h_str == "slcl_sys"){
        logsystem->WriteLog("Launching setlocale_system function.. - ");
        main_->_set_locale();
        logsystem->WriteLog("Launched.. - ");
    }  
    // IP FUNCTION
    else if(_h_str == "ip" || _h_str == "myip"){
        logsystem->WriteLog("Launching ip function.. - ");
        main_->_your_ip();
        logsystem->WriteLog("Launched.. - ");
    } 
    else { 
        RED_COLOR
        logsystem->WriteLog("Launching printlnf(This Command is not found)  function.. - ");
        printlnf("This command is not found!");
        logsystem->WriteLog("Launched.. - ");
        BLACK_COLOR
        slashn 
    }
    }
    
}


integer main(integer argc)
{
    logsystem->AllofThem();
    asciifunction *ascii = new asciifunction;
    ascii->Allofthem();

    logsystem->WriteLog("Launching hello function.. - ");
    helpstr->hello();
    logsystem->WriteLog("Launched.. - ");

    while(argc = 2) {  
        logsystem->WriteLog("Launching ScriftShell function.. Good luck bro! - ");  
        main_function->Shell();
        logsystem->WriteLog("Launched.. - ");
    }
    
    return 0;
}




