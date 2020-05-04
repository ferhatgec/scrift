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
        logsystem->WriteLog("Launching help function..\n");
        helpstr->help();
        logsystem->WriteLog("Launched..\n");
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
        logsystem->WriteLog("Launching felog function..\n");
        readfilefunction->ReadFeLogFunction();
        logsystem->WriteLog("Launched..\n");
    }
    else if(_h_str == "clear_log" || _h_str == "felog --clear")
    {
        logsystem->WriteLog("Launching ClearLog function..\n");
        printlnf("Clearing...\n");
        logsystem->ClearLog();
        logsystem->WriteLog("Launched..\n");
        printlnf("Done.\n");
    }
    else if(_h_str.rfind("getdev", 0) == 0)
    {
        logsystem->WriteLog("Launching getdev function..\n");
        strfor_h_str = _h_str.erase(0, 7);
        if(strfor_h_str == "true" || strfor_h_str == "-t")  {
            developermode->AllOfThem(true);
            logsystem->WriteLog("Launched with true boolean\n");
        }
        else {
            developermode->AllOfThem(false);
            logsystem->WriteLog("Launched with false boolean\n");
        }
    }
    // ADD TEXT FUNCTION
    else if(_h_str.rfind("addtext", 0) == 0) {
        logsystem->WriteLog("Launching addtext function..\n");
        strfor_h_str = _h_str.erase(0, 8);
        logsystem->WriteLog("Erasing _h_str string..\n");
        fileaddtextfunction->AppendLine(strfor_h_str);
        logsystem->WriteLog("Launched\n");
    }
    // NANO ADD TEXT FUNCTION
    else if(_h_str.rfind("nanoaddtext", 0) == 0) {
        logsystem->WriteLog("Launching nanoaddtext function..\n");
        strfor_h_str = _h_str.erase(0, 12);
        logsystem->WriteLog("Erasing _h_str string..\n");
        fileaddtextfunction->DeleteLine(strfor_h_str);
        logsystem->WriteLog("Launched\n");
    }
    else if(_h_str.rfind("rmvfile", 0) == 0) {
        logsystem->WriteLog("Launching rmvfile function..\n");
        strfor_h_str = _h_str.erase(0, 8);
        logsystem->WriteLog("Erasing _h_str string.\n");
        removefile->DeleteFile(strfor_h_str);
        logsystem->WriteLog("Launched..\n");
    }
    // DELETE TEXT FUNCTION
    else if(_h_str.rfind("deletetext", 0) == 0) {
        logsystem->WriteLog("Launching deletetext function..\n");
        strfor_h_str = _h_str.erase(0,11);
        logsystem->WriteLog("Erasing _h_str string..\n");
        fileaddtextfunction->DeleteLine(strfor_h_str);
        logsystem->WriteLog("Launched..\n");
    }
    // CREATE FOLDER FUNCTION
    else if(_h_str.rfind("mkdir", 0) == 0) {
        logsystem->WriteLog("Launching mkdir function..\n");
        strfor_h_str = _h_str.erase(0, 6);
        logsystem->WriteLog("Erasing _h_str string..\n");
        mkdirfunction->MKDirFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched..\n"); 
    }
    // READ TEXT FUNCTION
    else if (_h_str.find("readtext", 0) == 0) {
        logsystem->WriteLog("Launching readtext function..\n");
        strfor_h_str = _h_str.erase(0,9);
        logsystem->WriteLog("Erasing _h_str string..\n");
        readfilefunction->ReadFileFunction(strfor_h_str);
        logsystem->WriteLog("Launched..\n");  
    }
    // CD FUNCTION
    else if(_h_str.rfind("cd", 0) == 0) {
        logsystem->WriteLog("Launching cd function..\n");
        strfor_h_str = _h_str.erase(0,3);
        logsystem->WriteLog("Erasing _h_str string..\n");
        cdfunction->CDFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched..\n");
    }
    // HOME FUNCTION
    else if (_h_str == "home" || _h_str == "default") {
        logsystem->WriteLog("Launching home function..\n");
        homefunction->GetHome();
        logsystem->WriteLog("Launched..\n");
    }
    // LIST DIRECTORY FUNCTION
    else if(_h_str == "lsd" || _h_str == "lsdir")
    {

        main_->list_direc(true);
        logsystem->WriteLog("Launched..\n"); 
        slashn
    }
    // LIST FUNCTION
    else if(_h_str == "ls" || _h_str == "dir") // list directory
    {
       listdirectoryfunction->LSFunction();
       logsystem->WriteLog("Launched..\n");
       slashn   
    }
    // LIST FILE FUNCTION
    else if(_h_str == "lsf" || _h_str == "lsfile")
    {   
        main_->list_file(true);
        logsystem->WriteLog("Launched..\n"); 
        slashn
    }
    // CREATE TEXT FUNCTION
    else if(_h_str.rfind("ctxt", 0) == 0){
        logsystem->WriteLog("Launching ctxt function..\n");
        strfor_h_str = _h_str.erase(0,5);
        logsystem->WriteLog("Erasing _h_str function..\n");
        filefunction->CreateFileFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched..\n"); 
    }
    // PRINT FUNCTION
    else if(_h_str.rfind("printlnf") == 0){
        logsystem->WriteLog("Launching printlnf function..\n");
        strfor_h_str = _h_str.erase(0, 9);
        logsystem->WriteLog("Erasing _h_str function..\n");
        main_->echo_printlnf(strfor_h_str); 
        logsystem->WriteLog("Launched..\n"); 
    }
    // CLEAR FUNCTION
    else if(_h_str == "clear" || _h_str == "clear!!!") {
        logsystem->WriteLog("Launching clear function..\n");
        main_->clear_shell();
        logsystem->WriteLog("Launched..\n"); 
    }

    // CLOSE FUNCTION
    else if(_h_str == "brk" || _h_str == "cls")  {
        logsystem->WriteLog("Exit signal..\n");
        logsystem->WriteLog("Launched..\n"); 
        exit(EXIT_SUCCESS);
    } 
    // USERNAME FUNCTION
    else if(_h_str == "username" || _h_str == "uname") {
        logsystem->WriteLog("Launching username function..\n");
        userhostname->InitUsername();
        logsystem->WriteLog("Launched..\n");
        slashn
    } 
    // RUN FUNCTION
    else if(_h_str.rfind("scr", 0) == 0)
    {
        logsystem->WriteLog("Erasing _h_str function..\n");
        strfor_h_str = _h_str.erase(0,4);
        logsystem->WriteLog("Launching _h_str function..\n");
        runfunction->RunFunction(strfor_h_str);
        logsystem->WriteLog("Launched..\n");
    }
    // RANDOMIZE STRING FUNCTION
    else if(_h_str.rfind("rstr", 0) == 0) {
        logsystem->WriteLog("Launching rstr function..\n");
        strfor_h_str = _h_str.erase(0, 5);
        logsystem->WriteLog("Erasing _h_str function..\n");
        int atest = atoi(strfor_h_str.c_str());
        logsystem->WriteLog("Append integer..\n");
        main_->_generated_hash_string(atest);
        logsystem->WriteLog("Launched..\n"); 
    }
    // PAUSE FUNCTION
    else if(_h_str == "pause" || _h_str == "stop") {
        logsystem->WriteLog("Launching pause function..\n");
        printlnf("Enter the continue...");
        logsystem->WriteLog("Printing Enter the continue..\n");
        returni: if(std::cin.get() == '\n') {
                logsystem->WriteLog("Input..\n");
                printlnf("Access\n");
                logsystem->WriteLog("Accessing returni function..\n");
            } else {
                goto returni;
        }
        logsystem->WriteLog("Launched..\n");
    }
    // SYSTEM INFO FUNCTION
    else if(_h_str == "fetcheya" || _h_str == "-f"){
        logsystem->WriteLog("Launching fetcheya function..\n");
        kernel->KernelName();
        logsystem->WriteLog("Running KernelName function..\n");
        kernel->CPUInfo();
        logsystem->WriteLog("Running CPUInfo function..\n");
        kernel->RAMInfo();
        logsystem->WriteLog("Erasing RAMInfo function..\n");
    }
    // LOCALE FUNCTION
    else if(_h_str  == "setlocale_system" || _h_str == "slcl_sys"){
        logsystem->WriteLog("Launching setlocale_system function..\n");
        main_->_set_locale();
        logsystem->WriteLog("Launched..\n");
    }  
    // IP FUNCTION
    else if(_h_str == "ip" || _h_str == "myip"){
        logsystem->WriteLog("Launching ip function..\n");
        main_->_your_ip();
        logsystem->WriteLog("Launched..\n");
    } 
    else { 
        RED_COLOR
        logsystem->WriteLog("Launching printlnf(This Command is not found)  function..\n");
        printlnf("This command is not found!");
        logsystem->WriteLog("Launched..\n");
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

    logsystem->WriteLog("Launching hello function..\n");
    helpstr->hello();
    logsystem->WriteLog("Launched..\n");

    while(argc = 2) {  
        logsystem->WriteLog("Launching ScriftShell function.. Good luck bro!\n");  
        main_function->Shell();
        logsystem->WriteLog("Launched..\n");
    }
    
    return 0;
}




