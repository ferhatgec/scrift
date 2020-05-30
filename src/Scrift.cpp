/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <ctype.h>
#include <fstream>
#include <memory>
#include <stdlib.h>
#include <iostream>
#include "../include/src/Scrift.hpp"
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
#include "../include/src/Syntax/Settings.hpp"
#include "../include/src/Syntax/Language.hpp"
#include "../include/src/Syntax/History.hpp"
#include "../include/src/Syntax/Configuration.hpp"
#include "../include/src/Library/Keywords.hpp"
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/ioctl.h> // For FIONREAD
#include <termios.h>
#include <stdbool.h>
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
FClearFileFunction *clearfile = new FClearFileFunction();
FSettings *runsyntax = new FSettings();
FLanguage *scriftlang = new FLanguage();
FHistory *history = new FHistory();
FConfiguration *conf = new FConfiguration();

integer limit;

FMain::FMain()
{

}


FMain::~FMain()
{
    delete terminalstr,
    helpstr,
    kernel,
    main_,
    mkdirfunction,
    filefunction, 
    userhostname,
    main_function,
    homefunction,
    listdirectoryfunction,
    runfunction,
    readfilefunction,
    fileaddtextfunction,
    linkersign,
    removefile,
    developermode,
    contributors_lists,
    clearfile,
    runsyntax,
    scriftlang,
    history,
    conf;
}

func
FMain::Shell()
{
    char output;
    terminalstr->Terminal(); 
    WHITE_COLOR
    std::getline(std::cin, _h_str); // ws -> whitespace
    BLACK_COLOR
    int t = 0;
    if (_h_str != "") { //NULL
    // HELP FUNCTION
    
    // Help
    if(_h_str == "help" || _h_str == "-h" || _h_str == "Help" || _h_str == "HELP" || _h_str == "-H")
    {             	
        logsystem->WriteLog("Launching help function.. - ");
        helpstr->help();
        logsystem->WriteLog("Launched.. - ");
    }
    
    
    // GitHub link
    else if(_h_str == "gitlink" || _h_str == "scrift_link" || _h_str == "fusionlink" || _h_str == "GitLink" || _h_str == "Fusion")
    {
        helpstr->GitLink();
    }


    // Edifor Scrift-Based Text Editor
    else if(_h_str.rfind("edifor", 0) == 0)
    {
    	logsystem->WriteLog("Deleting _h_str - ");
    	strfor_h_str = _h_str.erase(0, 7);
    	logsystem->WriteLog("RunFunction is running Fegeya Edifor - ");
 	runfunction->RunFunction("edifor " + strfor_h_str);
 	logsystem->WriteLog("Successfully! - ");
    }

    // Contributors
    else if(_h_str == "cont" || _h_str == "contr" || _h_str == "contributors" || _h_str == "Contributors" || _h_str == "Cont")
    {
        contributors_lists->AllOfThem();
    }

    // Show FeLog file.
    else if(_h_str == "felog" || _h_str == "show_log" || _h_str == "FeLog" || _h_str == "Felog" || _h_str == "FELOG" || _h_str == "Show_Log" ||
    _h_str == "SHOW_LOG")
    {
        logsystem->WriteLog("Launching felog function.. - ");
        readfilefunction->ReadFeLogFunction();
        logsystem->WriteLog("Launched.. - ");
    }


    // Clear FeLog file.
    else if(_h_str == "clear_log" || _h_str == "felog --clear" || _h_str == "Clear_Log" || _h_str == "CLEAR_LOG" || _h_str == "FeLog --Clear" || _h_str == "FELOG --CLEAR")
    {
        logsystem->WriteLog("Launching ClearLog function.. - ");
        printlnf("Clearing... - ");
        logsystem->ClearLog();
        logsystem->WriteLog("Launched.. - ");
        printlnf("Done.\n");
    }

    // Developer Mode but this is not ended.
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


    // FOR DEVELOPERS
    else if(_h_str == "goscrift" || _h_str == "devs")
    {
        std::strcat(main_->_file_path_cd_function, "/Desktop/scrift-lang");
    }
    // ONLY DEVELOPERS

    // Castle Game
    else if(_h_str == "castle" || _h_str == "fcastle") {
          logsystem->WriteLog("Launching castle - ");
          runfunction->RunFunction("castle");
          logsystem->WriteLog("Launched - ");
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

    // Run ./
    else if(_h_str.rfind("./", 0) == 0 || _h_str.rfind("st", 0) == 0)
    {
      std::string pathrun = "./";
      logsystem->WriteLog("Deleting _h_str - ");
      strfor_h_str = _h_str.erase(0, 2);
      pathrun.append(strfor_h_str);
      system(pathrun.c_str());
    }

    // CD FUNCTION
    else if(_h_str.rfind("fr", 0) == 0 || _h_str.rfind("cd", 0) == 0)
    {
        logsystem->WriteLog("Launching cd function.. -");
        strfor_h_str = _h_str.erase(0,3);
        logsystem->WriteLog("Erasing _h_str string.. -");
        cdfunction->CDFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }

    // Back Function
    else if(_h_str == "back" || _h_str == "cddot")
    {
        logsystem->WriteLog("path string = filepathcdfunc - ");
        std::string path_string(main_->_file_path_cd_function);
        logsystem->WriteLog("finding last folder.... - ");
        std::size_t test = path_string.find_last_of("/\\");
        std::string test_string = path_string.substr(0, test);
        int convertdata = static_cast<int>(test);
        std::strcpy(main_->_file_path_cd_function, test_string.c_str());
        chdir(test_string.c_str());
        logsystem->WriteLog(main_->_file_path_cd_function);
    }



    // HOME FUNCTION
    else if (_h_str == "home" || _h_str == "default" || _h_str == "Home" || _h_str == "HOME" || _h_str == "Default" || _h_str == "DEFAULT")
    {
        logsystem->WriteLog("Launching home function.. - ");
        homefunction->GetHome();
        logsystem->WriteLog("Launched.. - ");
    }

    // Scrift Scripting Language Calls
    else if(_h_str.rfind("scrift", 0) == 0)
    {
        logsystem->WriteLog("Deleting _h_str - ");
        strfor_h_str = _h_str.erase(0, 7);
        scriftlang->ReadFunc(strfor_h_str);
    }

    else if(_h_str.rfind("create_scrift_project", 0) == 0)
    {
        logsystem->WriteLog("Deleting _h_str - ");
        strfor_h_str = _h_str.erase(0, 22);
        logsystem->WriteLog("Launching CreateScriftFile - ");
        filefunction->CreateScriftFile(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }
    else if(_h_str == "testsettings" || _h_str == "scrlang")
    {
        logsystem->WriteLog("Calling ReadSettings... - ");
        runsyntax->ReadFile();
        logsystem->WriteLog("Launched... - ");
    }

    // LIST DIRECTORY FUNCTION
    else if(_h_str == "lsd" || _h_str == "lsdir" || _h_str == "ls -d" || _h_str == "LSD" || _h_str == "LSDIR" || _h_str == "Ls Dir")
    {
        main_->list_direc(true);
        logsystem->WriteLog("Launched.. - ");
    }

    // Settings 
    else if(_h_str == "show_settings" || _h_str == "settings")
    {
        logsystem->WriteLog("Calling ReadSettingsFunction.. - ");
        readfilefunction->ReadSettingsFunction();
        slashn
    }

    // Clear Settings
    else if(_h_str == "clear_settings" ||
    _h_str == "deletesettings")
    {
        logsystem->WriteLog("Calling DeleteSettingsFunction .. -  ");
        clearfile->ClearSettingsFunction();
        logsystem->WriteLog("Cleared Settings - ");
    }

    // LIST FUNCTION
    else if(_h_str == "ls" || _h_str == "dir" ||_h_str == "LS" || _h_str == "DIR" || _h_str == "Ls" || _h_str == "Dir") // list directory
    {
       listdirectoryfunction->LSFunction();
       logsystem->WriteLog("Launched.. - ");
    }


    // LIST FILE FUNCTION
    else if(_h_str == "lsf" || _h_str == "lsfile" || _h_str == "ls -f" || _h_str == "LSF" || _h_str == "LSFILE" || _h_str == "Ls File")
    {
        main_->list_file(true);
        logsystem->WriteLog("Launched.. - ");
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
        printf("\033c");
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
        BOLD_BLUE_COLOR
        userhostname->InitUsername();
        BLACK_COLOR
        logsystem->WriteLog("Launched.. - ");
        slashn
    }

    // READ HISTORY
    else if(_h_str == "history" || _h_str == "fhist") {                                       
        logsystem->WriteLog("Calling ReadHistoryFileFunction - ");
        readfilefunction->ReadHistoryFileFunction();
        logsystem->WriteLog("Called - ");
    }


    // CLEAR HISTORY
    else if (_h_str == "clear_history" || _h_str == "history_cleaner") {
         logsystem->WriteLog("Calling ClearHistory - ");
         history->ClearHistory();
         logsystem->WriteLog("Called - ");
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
    else if(_h_str == "pause") {                   	          
        logsystem->WriteLog("Launching pause function.. - ");
        BOLD_BLUE_COLOR
        printlnf("Enter the continue...");
        BLACK_COLOR
        logsystem->WriteLog("Printing Enter the continue.. - ");
        returni: if(std::cin.get() == '\n') {
                logsystem->WriteLog("Input.. - ");
                BOLD_GREEN_COLOR
                printlnf("Access - \n");
                BLACK_COLOR
                logsystem->WriteLog("Accessing returni function.. - ");
            } else {
                goto returni;
        }
        logsystem->WriteLog("Launched.. - ");
    }

    // PRINT VERSION
    else if(_h_str == "--version" || _h_str == "-v")
    {                              
    	BOLD_MAGENTA_COLOR
    	printlnf("Fegeya Scrift Version: ");
    	BOLD_GREEN_COLOR
    	printlnf(SCRIFT_VERSION);
    	BOLD_YELLOW_COLOR
    	printlnf(hyphen);
    	BOLD_CYAN_COLOR
    	printlnf(SCRIFT_STATUS);
    	slashn
    	BOLD_RED_COLOR
    	printlnf("Copyright (c) 2020 ");
    	BOLD_BLUE_COLOR
    	printlnf("Ferhat Gecdogan \n");
    	BOLD_YELLOW_COLOR
    	printlnf("All Rights Reserved. \n");
    	BOLD_CYAN_COLOR
	printlnf("Distributed under the terms of the GPLv3 License.");
	BLACK_COLOR
    	slashn
    }

    // SYSTEM INFO FUNCTION
    else if(_h_str == "fetcheya" || _h_str == "-f"){
        logsystem->WriteLog("Launching fetcheya function.. - ");
	runfunction->RunFunction("fetcheya");
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
        main_->getIPAddress();
        logsystem->WriteLog("Launched.. - ");
    }

    else if (_h_str.rfind("scrp", 0) == 0)
    {
        logsystem->WriteLog("Launching Scrift Run in Path function.. - ");
        logsystem->WriteLog("Erasing _h_str.. - ");
        strfor_h_str = _h_str.erase(0, 5);
        runfunction->RunGMakeFunction(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }

    else {
        runfunction->RunFunction(_h_str);
        slashn
    }
    history->WriteHistory(_h_str);
    } else {
    	if(limit >= 50)
    	{
    			BOLD_RED_COLOR
    			printlnf("Please don't spamming :)\n");
    			BLACK_COLOR
    			limit = 0;
    	}
    	limit++;
        return;
    }

    //history->WriteHistory(_h_str); -> gets error

}


integer main(integer argc)
{
    logsystem->AllofThem();
    asciifunction *ascii = new asciifunction;
    ascii->Allofthem();
    BOLD_MAGENTA_COLOR
    printlnf("Welcome ");
    printlnf(getenv("USER"));
    printlnf(" ^-^\n");
    BLACK_COLOR
    history->AllofThem();
    filefunction->CreateSettingsFileFunction(); // Directory is "/home/<username>/<dot>scrift_settings"
    // TODO: Add Initialize Settings File Function.
    // TODO: Support Read Text.
    logsystem->WriteLog("Launching hello function.. - ");
    helpstr->hello();
    logsystem->WriteLog("Launched.. - ");
    while(argc = 2) {
        logsystem->WriteLog("Launching ScriftShell function.. Good luck bro! - ");
        main_function->Shell();
        logsystem->WriteLog("Launched.. - ");
       // history->WriteHistory(main_function->_h_str);
    }
    return F_OK;
}
