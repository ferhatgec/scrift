/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <ctype.h>
#include <fstream>
#include <memory>
#include <stdlib.h>
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
#include "../Library/EmojiPlusPlus.h"
#include "../include/src/Keywords/ScriftKeywords.hpp"
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
#include "../include/Library/Keywords.hpp"
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdbool.h>
// Variables

using namespace FileFunction;
using namespace FLinker;

const std::string compilation_date = __DATE__;
const std::string compilation_time = __TIME__;

// For Environment
static std::string SetNameToString;
static std::string SetNameString;

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
ScriftKeywords keywords;
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



std::string ftime(compilation_time); // Convert

std::string 
VersionGenerator() {
	return "scriftv" + scriftlang->EraseAllSubString(ftime, ":");
}

std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}



func
FMain::Shell()
{
    //std::cout << emojiplusplus::EmojiString("What's up? :atm: :atm:"); For testing
    char output;
    terminalstr->Terminal(); 
    WHITE_COLOR
    std::getline(std::cin, _h_str); // ws -> whitespace
    BLACK_COLOR
    int t = 0;
    if (_h_str != "") { //NULL
    // HELP FUNCTION
    
    // Help
    if(_h_str == keywords.Help || _h_str == keywords.Help_Short || _h_str == keywords.Help_Big || _h_str == keywords.Help_Biggest || _h_str == keywords.Help_Short_Biggest)
    {             	
        logsystem->WriteLog("Launching help function.. - ");
        helpstr->help();
        logsystem->WriteLog("Launched.. - ");
    }
    
    // Setname Function
    else if(_h_str.find(keywords.SetName + keywords.Whitespace, 0) == 0) 
    {
    	SetNameString = scriftlang->EraseAllSubString(_h_str, keywords.SetName + keywords.Whitespace );
    }
    
    // Setname To Function
    else if(_h_str.find(keywords.SetTo + keywords.Whitespace, 0) == 0) 
    {
    	SetNameToString = scriftlang->EraseAllSubString(_h_str, keywords.SetTo + keywords.Whitespace);
    	setenv(SetNameString.c_str(), SetNameToString.c_str(), true);
    }

    else if(_h_str.find(keywords.Printlnf + keywords.Whitespace + keywords.ArrowSign, 0) == 0)
    {
    	printlnf(getenv(scriftlang->EraseAllSubString(_h_str, keywords.Printlnf + keywords.Whitespace + keywords.ArrowSign).c_str()));
    	slashn
    }
    
    // GitHub link
    else if(_h_str == keywords.GitLink || _h_str == keywords.GitLink_Big)
    {
        helpstr->GitLink();
    }


    // Edifor Scrift-Based Text Editor
    else if(_h_str.rfind(keywords.Edifor, 0) == 0)
    {
    	logsystem->WriteLog("Deleting _h_str - ");
    	strfor_h_str = _h_str.erase(0, 7);
    	logsystem->WriteLog("RunFunction is running Fegeya Edifor - ");
 	runfunction->RunFunction("edifor " + strfor_h_str);
 	logsystem->WriteLog("Successfully! - ");
    }

    // Contributors
    else if(_h_str == keywords.Cont || _h_str == keywords.Contr || _h_str == keywords.Contributors || _h_str == keywords.Contributors_Big || _h_str == keywords.Cont_Big)
    {
        contributors_lists->AllOfThem();
    }

    // Show FeLog file.
    else if(_h_str == keywords.FeLog || _h_str == keywords.Show_Log || _h_str == keywords.FeLog_Big || _h_str == keywords.FeLog_F_Big || _h_str == keywords.FeLog_Biggest || _h_str == keywords.Show_Log_Big)
    {
        logsystem->WriteLog("Launching felog function.. - ");
        readfilefunction->ReadFeLogFunction();
        logsystem->WriteLog("Launched.. - ");
    }


    // Clear FeLog file.
    else if(_h_str == keywords.ClearLog || _h_str == keywords.FeLogClear || _h_str == keywords.Clear_Log_Big || _h_str == keywords.Clear_Log_Biggest || _h_str == keywords.FeLogClearBig || _h_str == keywords.FeLogClearBiggest)
    {
        logsystem->WriteLog("Launching ClearLog function.. - ");
        printlnf("Clearing... - ");
        logsystem->ClearLog();
        logsystem->WriteLog("Launched.. - ");
        printlnf("Done.\n");
    }

    // Developer Mode but this is not ended.
    else if(_h_str.rfind(keywords.GetDev, 0) == 0)
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
    else if(_h_str.rfind(keywords.AddText, 0) == 0) {
        logsystem->WriteLog("Launching addtext function.. - ");
        strfor_h_str = _h_str.erase(0, 8);
        logsystem->WriteLog("Erasing _h_str string.. -");
        fileaddtextfunction->AppendLine(strfor_h_str);
        logsystem->WriteLog("Launched\n");
    }


    // Castle Game
    else if(_h_str == keywords.Castle || _h_str == keywords.FCastle) {
          logsystem->WriteLog("Launching castle - ");
          runfunction->RunFunction("castle");
          logsystem->WriteLog("Launched - ");
    }

    else if(_h_str.rfind(keywords.RemoveFile, 0) == 0) {
        logsystem->WriteLog("Launching rmvfile function.. -");
        strfor_h_str = _h_str.erase(0, 8);
        logsystem->WriteLog("Erasing _h_str string. -");
        removefile->DeleteFile(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }


    // DELETE TEXT FUNCTION
    else if(_h_str.rfind(keywords.DeleteText, 0) == 0) {
        logsystem->WriteLog("Launching deletetext function.. - ");
        strfor_h_str = _h_str.erase(0,11);
        logsystem->WriteLog("Erasing _h_str string.. -");
        fileaddtextfunction->DeleteLine(strfor_h_str);
        logsystem->WriteLog("Launched.. -");
    }



    // CREATE FOLDER FUNCTION
    else if(_h_str.rfind(keywords.MKDir, 0) == 0) {
        logsystem->WriteLog("Launching mkdir function.. - ");
        strfor_h_str = _h_str.erase(0, 6);
        logsystem->WriteLog("Erasing _h_str string.. -");
        mkdirfunction->MKDirFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }



    // READ TEXT FUNCTION
    else if (_h_str.find(keywords.ReadText, 0) == 0) {
        logsystem->WriteLog("Launching readtext function.. - ");
        strfor_h_str = _h_str.erase(0,9);
        logsystem->WriteLog("Erasing _h_str string.. - ");
        readfilefunction->ReadFileFunction(strfor_h_str);
        logsystem->WriteLog("Launched.. -");
    }

    // Run ./
    else if(_h_str.rfind(keywords.RunDotSlash, 0) == 0 || _h_str.rfind(keywords.RunST, 0) == 0)
    {
      std::string pathrun = "./";
      logsystem->WriteLog("Deleting _h_str - ");
      strfor_h_str = _h_str.erase(0, 2);
      pathrun.append(strfor_h_str);
      system(pathrun.c_str());
    }

    // CD FUNCTION
    else if(_h_str.rfind(keywords.Fr, 0) == 0 || _h_str.rfind(keywords.Cd, 0) == 0)
    {
        logsystem->WriteLog("Launching cd function.. -");
        strfor_h_str = _h_str.erase(0,3);
        logsystem->WriteLog("Erasing _h_str string.. -");
        cdfunction->CDFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }

    // Back Function
    else if(_h_str == keywords.Back)
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
    else if (_h_str == keywords.Home || _h_str == keywords.Default || _h_str == keywords.Home_Big || _h_str == keywords.Home_Biggest || _h_str == keywords.Default_Big || _h_str == keywords.Default_Biggest)
    {
        logsystem->WriteLog("Launching home function.. - ");
        homefunction->GetHome();
        logsystem->WriteLog("Launched.. - ");
    }

    // Scrift Scripting Language Calls
    else if(_h_str.rfind(keywords.Scrift, 0) == 0)
    {
        logsystem->WriteLog("Deleting _h_str - ");
        strfor_h_str = _h_str.erase(0, 7);
        scriftlang->ReadFunc(strfor_h_str);
    }

    else if(_h_str.rfind(keywords.CreateScriftProject, 0) == 0)
    {
        logsystem->WriteLog("Deleting _h_str - ");
        strfor_h_str = _h_str.erase(0, 22);
        logsystem->WriteLog("Launching CreateScriftFile - ");
        filefunction->CreateScriftFile(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }
    else if(_h_str == keywords.TestSettings || _h_str == keywords.ScrLang)
    {
        logsystem->WriteLog("Calling ReadSettings... - ");
        runsyntax->ReadFile();
        logsystem->WriteLog("Launched... - ");
    }

    // List Objects Function
    else if(_h_str == keywords.LsObject) {
    	listdirectoryfunction->ListObjectFunction();
    }


    // List Directory Function
    else if(_h_str == keywords.Lsd || _h_str == keywords.Lsdir || _h_str == keywords.ls_d || _h_str == keywords.Lsd_Biggest || _h_str == keywords.Lsdir_Biggest || _h_str == keywords.Lsdir_Big)
    {
        main_->list_direc(true);
        logsystem->WriteLog("Launched.. - ");
    }

    // Settings 
    else if(_h_str == keywords.ShowSettings || _h_str == keywords.Settings)
    {
        logsystem->WriteLog("Calling ReadSettingsFunction.. - ");
        readfilefunction->ReadSettingsFunction();
        slashn
    }

    // Clear Settings
    else if(_h_str == keywords.Clear_Settings ||
    _h_str == keywords.DeleteSettings)
    {
        logsystem->WriteLog("Calling DeleteSettingsFunction .. -  ");
        clearfile->ClearSettingsFunction();
        logsystem->WriteLog("Cleared Settings - ");
    }

    // LIST FUNCTION
    else if(_h_str == keywords.Ls || _h_str == keywords.Dir ||_h_str == keywords.Ls_Biggest || _h_str == keywords.Dir_Biggest || _h_str == keywords.Ls_Big || _h_str == keywords.Dir_Big) // list directory
    {
       listdirectoryfunction->LSFunction();
       logsystem->WriteLog("Launched.. - ");
    }


    // LIST FILE FUNCTION
    else if(_h_str == keywords.Lsf || _h_str == keywords.Lsfile || _h_str == keywords.Ls_f || _h_str == keywords.Lsf_Biggest || _h_str == keywords.Lsfile_Biggest || _h_str == keywords.Ls_File)
    {
        main_->list_file(true);
        logsystem->WriteLog("Launched.. - ");
    }



    // CREATE TEXT FUNCTION
    else if(_h_str.rfind(keywords.CreateText, 0) == 0){
        logsystem->WriteLog("Launching ctxt function..\n");
        strfor_h_str = _h_str.erase(0,5);
        logsystem->WriteLog("Erasing _h_str function..\n");
        filefunction->CreateFileFunctionInit(strfor_h_str);
        logsystem->WriteLog("Launched.. -");
    }



    // PRINT FUNCTION
    else if(_h_str.rfind(keywords.Printlnf, 0) == 0){
        logsystem->WriteLog("Launching printlnf function.. - ");
        strfor_h_str = _h_str.erase(0, 9);
        logsystem->WriteLog("Erasing _h_str function.. - ");
        main_->echo_printlnf(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }



    // CLEAR FUNCTION
    else if(_h_str == keywords.Clear || _h_str == keywords.Clear___) {                                     
        logsystem->WriteLog("Launching clear function.. - ");
        printf("\033c");
        logsystem->WriteLog("Launched.. - ");
    }



    // CLOSE FUNCTION
    else if(_h_str == keywords.Break || _h_str == keywords.Close)  {                                      
        logsystem->WriteLog("Exit signal.. - ");
        logsystem->WriteLog("Launched.. - ");
        exit(EXIT_SUCCESS);
    }



    // USERNAME FUNCTION
    else if(_h_str == keywords.Username || _h_str == keywords.UName) {                                                   
        logsystem->WriteLog("Launching username function.. - ");
        BOLD_BLUE_COLOR
        userhostname->InitUsername();
        BLACK_COLOR
        logsystem->WriteLog("Launched.. - ");
        slashn
    }

    // READ HISTORY
    else if(_h_str == keywords.History || _h_str == keywords.FHist) {                                       
        logsystem->WriteLog("Calling ReadHistoryFileFunction - ");
        readfilefunction->ReadHistoryFileFunction();
        logsystem->WriteLog("Called - ");
    }


    // CLEAR HISTORY
    else if (_h_str == keywords.Clear_History || _h_str == keywords.History_Cleaner) {
         logsystem->WriteLog("Calling ClearHistory - ");
         history->ClearHistory();
         logsystem->WriteLog("Called - ");
    }


    // RUN FUNCTION
    else if(_h_str.rfind(keywords.Scr, 0) == 0)
    {
        logsystem->WriteLog("Erasing _h_str function.. - ");
        strfor_h_str = _h_str.erase(0,4);
        logsystem->WriteLog("Launching _h_str function.. - ");
        runfunction->RunFunction(strfor_h_str);
        logsystem->WriteLog("Launched.. - ");
    }



    // RANDOMIZE STRING FUNCTION
    else if(_h_str.rfind(keywords.RandomizeString, 0) == 0) {
        logsystem->WriteLog("Launching rstr function.. - ");
        strfor_h_str = _h_str.erase(0, 5);
        logsystem->WriteLog("Erasing _h_str function.. - ");
        int atest = atoi(strfor_h_str.c_str());
        logsystem->WriteLog("Append integer.. - ");
        main_->_generated_hash_string(atest);
        logsystem->WriteLog("Launched.. - ");
    }



    // PAUSE FUNCTION
    else if(_h_str == keywords.Pause) {                   	          
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

    // Date Now Function
    else if(_h_str == keywords.Now || _h_str == keywords.DateNow) 
    {
    	WHITE_COLOR
    	printlnf(currentDateTime().c_str());
    	slashn
    	BLACK_COLOR
    }

    // PRINT VERSION
    else if(_h_str == keywords.Version || _h_str == keywords._V)
    {                              
    	BOLD_MAGENTA_COLOR
    	printlnf("Fegeya Scrift Version: ");
    	BOLD_GREEN_COLOR
    	printlnf(SCRIFT_VERSION);
    	BOLD_YELLOW_COLOR
    	printhyphen // printlnf("-");
    	BOLD_CYAN_COLOR
    	printlnf(SCRIFT_STATUS);
    	BOLD_BLUE_COLOR
    	printhyphen // printlnf("-");
    	BOLD_MAGENTA_COLOR
    	printlnf(VersionGenerator().c_str());
    	slashn
    	BOLD_RED_COLOR
    	printlnf("Copyright (c) 2020 ");
    	BOLD_BLUE_COLOR
    	printlnf("Ferhat Gecdogan \n");
    	BOLD_YELLOW_COLOR
    	printlnf("All Rights Reserved. \n");
    	BOLD_CYAN_COLOR
	printlnf("Distributed under the terms of the MIT License.");
	BLACK_COLOR
    	slashn
    }

    // SYSTEM INFO FUNCTION
    else if(_h_str == keywords.Fetcheya || _h_str == keywords._f){
        logsystem->WriteLog("Launching fetcheya function.. - ");
	runfunction->RunFunction("fetcheya");
        logsystem->WriteLog("Erasing RAMInfo function.. - ");
    }
    // LOCALE FUNCTION
    else if(_h_str  == keywords.SetLocaleSystem){
        logsystem->WriteLog("Launching setlocale_system function.. - ");
        main_->_set_locale();
        logsystem->WriteLog("Launched.. - ");
    }



    // IP FUNCTION
    else if(_h_str == keywords.IP || _h_str == keywords.MyIP){
        logsystem->WriteLog("Launching ip function.. - ");
        main_->getIPAddress();
        logsystem->WriteLog("Launched.. - ");
    }

    else if (_h_str.rfind(keywords.Scrp, 0) == 0)
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
}


integer main(integer argc)
{
    logsystem->AllofThem();
    asciifunction *ascii = new asciifunction;
    ascii->Allofthem();
    BOLD_MAGENTA_COLOR
    printlnf("Welcome ");
    BOLD_CYAN_COLOR
    printlnf(getenv("USER"));
    BOLD_BLUE_COLOR
    printlnf(" ^-^\n");
    BLACK_COLOR
    history->AllofThem();
    filefunction->CreateSettingsFileFunction(); // Directory is "/home/<username>/<dot>scrift_settings"
    logsystem->WriteLog("Launching hello function.. - ");
    helpstr->hello();
    logsystem->WriteLog("Launched.. - ");
    while(argc = 2) {
        logsystem->WriteLog("Launching ScriftShell function.. Good luck bro! - ");
        main_function->Shell();
        logsystem->WriteLog("Launched.. - ");
    }
    return F_OK;
}
