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

typedef struct CursorPos {
    int x = 0;
} cursorp;

cursorp cursorpos;

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

std::string fx;

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

void moveCursor(std::ostream& os, int col, int row) {
  os << "\033[" << col << ";" << row << "H";
}


void InputFunction() {
	std::string sign;
        struct termios t;
        int c;
        tcgetattr(0,&t);
        t.c_lflag&=~ECHO+~ICANON;
        tcsetattr(0,TCSANOW,&t);
        fflush(stdout);
        c=getchar();
        t.c_lflag|=ICANON+ECHO;
        tcsetattr(0,TCSANOW,&t);
        main_function->_h_str.push_back(c);
        if(main_function->_h_str == keywords.Help) {
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_YELLOW_COLOR << "help" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		slashn 
        		helpstr->help();
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal();
        	return; 
        } else if(main_function->_h_str == keywords.Lsd) {
                std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_RED_COLOR << "d" << WBOLD_YELLOW_COLOR << "ls" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		main_->list_direc(true);
        	}
        	history->WriteHistory(main_function->_h_str);
         	main_function->_h_str.erase();
        	terminalstr->Terminal();       	
        	return;
        } else if(main_function->_h_str == keywords.Create) {
        	std::cout<<"\b";
        	std::cout<<"\b";
                std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_BLUE_COLOR << "create" << WBLACK_COLOR;
       	std::cout << WBOLD_CYAN_COLOR << " scrift_project";
        	BOLD_MAGENTA_COLOR
        	std::getline(std::cin, main_function->_h_str);
        	BLACK_COLOR
        	filefunction->CreateScriftFile(main_function->_h_str);
        	history->WriteHistory(main_function->_h_str); 
        	main_function->_h_str.erase();
        	terminalstr->Terminal();  
        	return;
        } else if(main_function->_h_str.rfind(keywords.DeleteText, 0) == 0) {
       	 logsystem->WriteLog("Launching deletetext function.. - ");
       	 std::cout<<"\b";
        	 std::cout<<"\b";
        	 std::cout<<"\b";
        	 std::cout<<"\b";
        	 std::cout<<"\b";
                 std::cout<<"\b";
        	 std::cout<<"\b";
        	 std::cout<<"\b";
        	 std::cout<<"\b";
        	 std::cout << WBOLD_RED_COLOR << "delete" << WBOLD_YELLOW_COLOR << "text ";
        	 BOLD_BLUE_COLOR
        	 std::getline(std::cin, main_function->_h_str);
       	 fileaddtextfunction->DeleteLine(main_function->_h_str);
       	 history->WriteHistory(main_function->_h_str);
       	 main_function->_h_str.erase();
        	 terminalstr->Terminal();   
       	 return;
    	} else if(main_function->_h_str == keywords.Lsf) {
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_BLUE_COLOR << "f" << WBOLD_YELLOW_COLOR << "ls" << WBLACK_COLOR;
        	if(getchar() == '\n') {	
        		main_->list_file(true);
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
    	} else if(main_function->_h_str == keywords.GitLink) {
      		std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_YELLOW_COLOR << "gitlink" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		slashn
        		helpstr->GitLink();
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
        } else if(main_function->_h_str.rfind(keywords.CreateText, 0) == 0) {
        	logsystem->WriteLog("Launching ctxt function..\n");
      		std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_MAGENTA_COLOR << "ctxt " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::getline(std::cin, main_function->_h_str);
        	BLACK_COLOR
        	filefunction->CreateFileFunctionInit(main_function->_h_str);
        	history->WriteHistory(main_function->_h_str);
          	main_function->_h_str.erase();
        	terminalstr->Terminal();      	
        	return;
        } else if(main_function->_h_str == keywords.Pause) {
                logsystem->WriteLog("Launching pause function.. - ");
              	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_MAGENTA_COLOR << "pause" << WBLACK_COLOR; 
        	if(getchar() == '\n') {                	          
        		BOLD_BLUE_COLOR
        		printlnf("Enter the continue...");
        		BLACK_COLOR
        		returni: if(std::cin.get() == '\n') {
                		BOLD_GREEN_COLOR
                		printlnf("Access - \n");
                		BLACK_COLOR
            	} else {
                	goto returni;
        	}
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
    } else if(main_function->_h_str == keywords.KName) {
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_YELLOW_COLOR << "kname" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		printlnf(main_->FName().c_str());
    			slashn
    		}
    		history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal(); 
    		return;
        } else if(main_function->_h_str == keywords.Contr) {
                std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_YELLOW_COLOR << "contr" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		slashn
        		contributors_lists->AllOfThem();
        		slashn
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
        } else if(main_function->_h_str == keywords.LsObject) {
                std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";    
        	std::cout << WBOLD_MAGENTA_COLOR << "obj" << WBOLD_YELLOW_COLOR << "ls" << WBLACK_COLOR;
        	if(getchar() == '\n') {   	
    			listdirectoryfunction->ListObjectFunction();
    		}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal();     		
    		return;
    	} else if(main_function->_h_str.find(keywords.SetName, 0) == 0) {
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_BLUE_COLOR << " setname " << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		std::cin >> main_function->_h_str;
        		SetNameString = scriftlang->EraseAllSubString(main_function->_h_str, keywords.SetName + keywords.Whitespace);
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	return;
        } else if(main_function->_h_str.find(keywords.SetTo, 0) == 0) {
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_CYAN_COLOR << "setto " << WBLACK_COLOR;
        	std::cin >> main_function->_h_str;
    		SetNameToString = scriftlang->EraseAllSubString(main_function->_h_str, keywords.SetTo + keywords.Whitespace);
    		setenv(SetNameString.c_str(), SetNameToString.c_str(), true);
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
        	return;
    	} else if(main_function->_h_str == keywords.Now) {
    	        std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_YELLOW_COLOR << "now" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		WHITE_COLOR
    			printlnf(currentDateTime().c_str());
    			slashn
    			BLACK_COLOR
    		}
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal(); 
        	return;
    	} else if(main_function->_h_str.find(keywords.Printlnf, 0) == 0){
        	logsystem->WriteLog("Launching printlnf function.. - ");
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_BLUE_COLOR << " printlnf " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::getline(std::cin, main_function->_h_str);
        	WHITE_COLOR
        	main_->echo_printlnf(main_function->_h_str);
        	slashn
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
       } else if(main_function->_h_str == keywords.ClearLog) {
            	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
		std::cout << WBOLD_GREEN_COLOR << "clear_log";
		if(getchar() == '\n') {
       		logsystem->WriteLog("Launching ClearLog function.. - ");
       		logsystem->ClearLog();
       		printlnf("Done.\n");
       	}
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
        	return;
        } else if(main_function->_h_str.find(keywords.MKDir, 0) == 0) {
        	logsystem->WriteLog("Launching mkdir function.. - ");
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_GREEN_COLOR << "mkdir " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
        	BLACK_COLOR
        	mkdirfunction->MKDirFunctionInit(scriftlang->EraseAllSubString(main_function->_h_str, keywords.MKDir + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	return;
   	}  else if(main_function->_h_str.rfind(keywords.RandomizeString, 0) == 0) {
        	logsystem->WriteLog("Launching rstr function.. - ");
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_GREEN_COLOR << "rstr " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
        	BOLD_BLUE_COLOR
        	main_->_generated_hash_string(atoi(main_function->_h_str.c_str()));
        	BLACK_COLOR
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	return;
       } else if(main_function->_h_str.find(keywords.RemoveFile, 0) == 0) {
   	      logsystem->WriteLog("Launching rmvfile function.. -");
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_RED_COLOR << "rmv" << WBOLD_MAGENTA_COLOR << "file " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
        	BLACK_COLOR
        	removefile->DeleteFile(scriftlang->EraseAllSubString(main_function->_h_str, keywords.RemoveFile + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
          	main_function->_h_str.erase();
        	return;      	
        }  else if(main_function->_h_str == keywords.Scr) {
        	logsystem->WriteLog("Erasing _h_str function.. - ");
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_GREEN_COLOR << "scr " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::getline(std::cin, main_function->_h_str);
        	BLACK_COLOR
        	runfunction->RunFunction(main_function->_h_str);
       	main_function->_h_str.erase();
        	history->WriteHistory(main_function->_h_str);
       	terminalstr->Terminal(); 
       	return;
       } else if(main_function->_h_str == keywords.FeLog) {
          std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_YELLOW_COLOR << "felog" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		slashn
       		logsystem->WriteLog("Launching felog function.. - ");
        		readfilefunction->ReadFeLogFunction();
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;  
       }  else if(main_function->_h_str.rfind(keywords.Find, 0) == 0) {
          	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
   		FFindFileFunction *find = new FFindFileFunction();
        	std::cout << WBOLD_BLUE_COLOR << "ffind " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
   		find->FindFile(scriftlang->EraseAllSubString(main_function->_h_str, keywords.Find + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
   		main_function->_h_str.erase();
   		return;
       } else if(main_function->_h_str.find(keywords.AddText, 0) == 0) {
        	logsystem->WriteLog("Launching addtext function.. - ");
          	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
          	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_GREEN_COLOR << " addtext " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
  		WHITE_COLOR
        	fileaddtextfunction->AppendLine(scriftlang->EraseAllSubString(main_function->_h_str, keywords.AddText + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
          	main_function->_h_str.erase();
          	BLACK_COLOR
          	terminalstr->Terminal(); 
   				return;
       }  else if(main_function->_h_str.find(keywords.RunDotSlash, 0) == 0) {
          	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_MAGENTA_COLOR << " .." << WBOLD_BLUE_COLOR << "/" << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
      		std::string pathrun = "./";
      		pathrun.append(scriftlang->EraseAllSubString(main_function->_h_str, keywords.RunDotSlash));
      		system(pathrun.c_str());
        	history->WriteHistory(main_function->_h_str);
      		main_function->_h_str.erase();
      		BLACK_COLOR
          	return;
      } else if(main_function->_h_str == keywords.IP) {
          logsystem->WriteLog("Launching ip function.. - ");
          std::cout<<"\b";
		std::cout << WBOLD_YELLOW_COLOR << "ip" << WBLACK_COLOR;
		if(getchar() == '\n') {
			slashn
       		main_->getIPAddress();
        		history->WriteHistory(main_function->_h_str);
       	}
        	history->WriteHistory(main_function->_h_str);
       	main_function->_h_str.erase();
       	terminalstr->Terminal(); 
       	return;
      } else if(main_function->_h_str == keywords.History) {                                       
        logsystem->WriteLog("Calling ReadHistoryFileFunction - ");
         	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
          	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_YELLOW_COLOR << "history" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		readfilefunction->ReadHistoryFileFunction();
        	}
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal(); 	
    		return;
    } else if (main_function->_h_str == keywords.Clear_History) {
         logsystem->WriteLog("Calling ClearHistory - ");
                std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
          	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_RED_COLOR << "rmvhistory" << WBLACK_COLOR; 
         	history->ClearHistory();
        	history->WriteHistory(main_function->_h_str);
   	 	main_function->_h_str.erase();
         	BLACK_COLOR
         	terminalstr->Terminal(); 
   	 	return;
    } else if(main_function->_h_str == keywords.Back) {
          	logsystem->WriteLog("Launching back function.. - ");
      	  	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_MAGENTA_COLOR << "back" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		std::string path_string(main_->_file_path_cd_function);
        		std::size_t test = path_string.find_last_of("/\\");
        		std::string test_string = path_string.substr(0, test);
        		int convertdata = static_cast<int>(test);
        		std::strcpy(main_->_file_path_cd_function, test_string.c_str());
        		chdir(test_string.c_str());
        		logsystem->WriteLog(main_->_file_path_cd_function);
        	}
        	history->WriteHistory(main_function->_h_str);
       	main_function->_h_str.erase();
       	terminalstr->Terminal(); 
       	return;
     } else if(main_function->_h_str == keywords.Ls) {
          logsystem->WriteLog("Launching ls function.. - ");
          std::cout<<"\b";
          std::cout << WBOLD_YELLOW_COLOR << "ls" << WBLACK_COLOR; 
     	  if(getchar() == '\n') {
      	  	listdirectoryfunction->LSFunction();
      	  }
          history->WriteHistory(main_function->_h_str);
      	  main_function->_h_str.erase();
      	  terminalstr->Terminal();
      	  return;
     } else if(main_function->_h_str.find(keywords.Fr) == 0 || main_function->_h_str.find(keywords.Cd) == 0) {
          logsystem->WriteLog("Launching cd function.. -");
      	  std::cout<<"\b";
      	  std::cout << WBOLD_GREEN_COLOR << "fr " << WBLACK_COLOR;
      	  BOLD_CYAN_COLOR
      	  std::getline(std::cin, main_function->_h_str);
          cdfunction->CDFunctionInit(scriftlang->EraseAllSubString(main_function->_h_str, keywords.Fr + keywords.Whitespace));
          history->WriteHistory(main_function->_h_str);
     	  main_function->_h_str.erase();
     	  terminalstr->Terminal();
      	  return;
     } else if(main_function->_h_str == keywords.Clear_Settings) {
          logsystem->WriteLog("Calling DeleteSettingsFunction .. -  ");
     	  std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
          std::cout<<"\b";
	  std::cout << WBOLD_RED_COLOR << "clear" << WBOLD_YELLOW_COLOR << "settings" << WBLACK_COLOR;
	  if(getchar() == '\n') {
          	clearfile->ClearSettingsFunction();
          }
          history->WriteHistory(main_function->_h_str);
          main_function->_h_str.erase();
          terminalstr->Terminal();
      	  return;
    } else if (main_function->_h_str == keywords.Home) {
        	logsystem->WriteLog("Launching home function.. - ");
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_MAGENTA_COLOR << "home" << WBLACK_COLOR;
        	if(getchar() == '\n') {
       		homefunction->GetHome();
       		slashn
       	}
        	history->WriteHistory(main_function->_h_str);
       	main_function->_h_str.erase();
       	terminalstr->Terminal();
       	return;
     } else if(main_function->_h_str == keywords.Close)  {                                      
        	logsystem->WriteLog("Exit signal.. - ");
          std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_MAGENTA_COLOR << "cls" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		slashn
        		history->WriteHistory(main_function->_h_str);
        		main_function->_h_str.erase();
          		exit(EXIT_SUCCESS);
          	}
          	return;
     } else if(main_function->_h_str.find("fscrift", 0) == 0) {
          	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";    
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout << WBOLD_GREEN_COLOR << "fscrift " << WBLACK_COLOR;
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
        	scriftlang->ReadFunc(scriftlang->EraseAllSubString(main_function->_h_str, keywords.Scrift + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
         	main_function->_h_str.erase();
       	return;
     } else if(main_function->_h_str == keywords.Settings) {
     		logsystem->WriteLog("Calling ReadSettingsFunction.. - ");
    		std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";    
        	std::cout<<"\b";
        	std::cout<<"\b";
        	std::cout<<"\b";    
        	std::cout<<"\b";	
        	std::cout << WBOLD_YELLOW_COLOR << "settings" << WBLACK_COLOR;
        	if(getchar() == '\n') {
        		readfilefunction->ReadSettingsFunction();
        		slashn
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal();
        	return;
    } else if(main_function->_h_str == keywords.Clear) { 
         	logsystem->WriteLog("Launching clear function.. - ");                                    
      		std::cout<<"\b";
      		std::cout<<"\b";
      		std::cout<<"\b";
      		std::cout<<"\b";
      		std::cout << WBOLD_YELLOW_COLOR << "clear" << WBLACK_COLOR;
      		if(getchar() == '\n') {
      	  		printlnf("\033c");
      	  	}
        	history->WriteHistory(main_function->_h_str);
         	main_function->_h_str.erase();
         	terminalstr->Terminal();
       		return;
     } else if(main_function->_h_str == keywords.Version)  {          
                std::cout<<"\b";
      		std::cout<<"\b";
      		std::cout<<"\b";
      		std::cout<<"\b";  
      		std::cout<<"\b";
      		std::cout<<"\b";  
      		std::cout << WBOLD_YELLOW_COLOR << "version" << WBLACK_COLOR;
      		if(getchar() == '\n') {
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
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal();
       	return;
     } else {
     		sign.push_back(c);
     		if(c == ARROW_UP) {
     			
     		} else if(c == ARROW_DOWN) {
     			
     		} if(c == ARROW_RIGHT) { 
     			std::cout << "\033[1C";
     			cursorpos.x += 1;
     		} else if(c == ARROW_LEFT) {
     			if(cursorpos.x >= 2) {
		        	std::cout << "\033[1D";
		        	cursorpos.x -= 1;	
		        } else {
		        	return;
		        }
		} else if(c == BACKSPACE) {
			if(cursorpos.x >= 1)
			{
				cursorpos.x -= 1;
				if(cursorpos.x + 2 == main_function->_h_str.length()) {
					main_function->_h_str.erase(main_function->_h_str.begin() + cursorpos.x);
     					std::cout << '\b' << " " << '\b';
				} 
				else if(cursorpos.x > 2) {
     					main_function->_h_str.erase(main_function->_h_str.begin() + cursorpos.x - 1);
     					std::cout << '\b' << " " << '\b';
     				} 
			}
     		} else if(c == 91) {
     		
		} else if(c == '\n') {
			cursorpos.x = 0;
			printlnf(main_function->_h_str.c_str());
        		main_function->_h_str.erase();
        		terminalstr->Terminal(); 
        		return;
        	}
		else {
			//std::cout << "CURSORPOS" << cursorpos.x;
			//std::cout << cursorpos.x;
        		std::cout << sign;
        		cursorpos.x += 1;
        		return;
        	}
        	//std::cout << cursorpos.x;
        	sign.erase();
        }
}

func
FMain::Shell()
{	
    readfilefunction->ReadFeLogFunctionWithoutPrint();
    char output;
    WHITE_COLOR
    InputFunction();
    //std::getline(std::cin, _h_str); // ws -> whitespace
    BLACK_COLOR
    int t = 0;
    if (_h_str != "") { //NULL
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
    std::locale::global(std::locale("")); 
    logsystem->AllofThem();
    asciifunction *ascii = new asciifunction;
    ascii->Allofthem();
    BOLD_MAGENTA_COLOR
    printlnf("Welcome ");
    BOLD_CYAN_COLOR
    printlnf(getenv("USER"));
    BOLD_BLUE_COLOR
    std::cout << " " << emojiplusplus::EmojiString(runsyntax->FWelcomeEmoji()) << "\n";
    BLACK_COLOR
    history->AllofThem();
    filefunction->CreateSettingsFileFunction(); // Directory is "/home/<username>/<dot>scrift_settings"
    logsystem->WriteLog("Launching hello function.. - ");
    helpstr->hello();
    logsystem->WriteLog("Launched.. - ");
    terminalstr->Terminal(); 
    while(argc = 2) {
        logsystem->WriteLog("Launching ScriftShell function.. Good luck bro! - ");
        main_function->Shell();
        logsystem->WriteLog("Launched.. - ");
    }
    return F_OK;
}
