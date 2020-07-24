/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <sstream>
#include <ctype.h>
#include <fstream>
#include <memory>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
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
#include <locale.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdbool.h>

// Source
#include "../include/src/Syntax/CommandFunc.h"
#include "../include/src/Scrift.hpp"
#include "../include/src/Keywords/ScriftKeywords.hpp"
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
#include "../include/src/Syntax/Settings.hpp"
#include "../include/src/Syntax/Language.hpp"
#include "../include/src/Syntax/History.hpp"
#include "../include/src/Syntax/Template.hpp"
#include "../include/Library/Keywords.hpp"

// Libraries
#include "../Library/InputPlusPlus.h"
#include "../Library/EmojiPlusPlus.h"
#include "../Library/Colorized.hpp"
#include "../Library/EasyMorse.hpp"

// Variables
using namespace FileFunction;

const std::string compilation_date = __DATE__;
const std::string compilation_time = __TIME__;

// Definitions
#define ESC 033 

// For Environment
static std::string SetNameToString;
static std::string SetNameString;

FContributors *contributors_lists = new FContributors();
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
FeLog *logsystem = new FeLog();
FRemoveFileFunction *removefile = new FRemoveFileFunction();
FClearFileFunction *clearfile = new FClearFileFunction();
FSettings *runsyntax = new FSettings();
FLanguage *scriftlang = new FLanguage();
FHistory *history = new FHistory();
ScriftKeywords keywords;
FTemplate temp;

typedef struct CursorPos {
    int x = 0;
} cursorp;

cursorp cursorpos;

FMain::FMain() { }


FMain::~FMain() {
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
    removefile,
    contributors_lists,
    clearfile,
    runsyntax,
    scriftlang,
    history;
}


void RemovePrintedChar(int value) {
	int rvalue = 0;
	do {
		std::cout << "\b";
		rvalue++;
	}
	while(rvalue != value);	
	return;
}

int factorial(int n);
int space = 0;
std::string ftime(compilation_time); // Convert
int input_value = 0;
    // Get Between String    
void GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, std::string &rStr) {  
    int start = oStr.find(sStr1);   
    if (start >= 0) {       
      std::string tstr = oStr.substr(start + sStr1.length());        
      int stop = tstr.find(sStr2);      
      if (stop >1)          
        rStr = oStr.substr(start + sStr1.length(), stop);
      else
        rStr ="error";  
    }
    else
       rStr = "error"; 
}  

std::string VersionGenerator() {
	return "scriftv" + scriftlang->EraseAllSubString(ftime, ":");
}

void Space(int space, std::string sign, bool theme) {
	if(theme == true) {
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), sign.c_str());
	} else {
		if(space == 1 || space % 1) {
			colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), sign.c_str());
		} else if(space % 2 || space == 2) {
			colorized::PrintWith(colorized::Colorize(BOLD, MAGENTA).c_str(), sign.c_str());
		} else if(space % 3 || space == 3) {
			colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), sign.c_str());
		} else if(space % 4 || space == 4) {
			colorized::PrintWith(colorized::Colorize(BOLD, YELLOW).c_str(), sign.c_str());
		} else if(space % 5) {
			colorized::PrintWith(colorized::Colorize(BOLD, GREEN).c_str(), sign.c_str());
		} else if(space % 6 || space == 6) {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), sign.c_str());
		} else if(space % 7 || space == 7) {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), sign.c_str());
		} else if(space % 7 || space == 7) {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), sign.c_str());
		} else if(space == 0) {
			std::cout << WBOLD_CYAN_COLOR << sign << WBLACK_COLOR;
		}
	}
}

void PrintVersion() {
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

int sqrti(int x) {
    union { float f; int x; } v; 

    // convert to float
    v.f = (float)x;
    v.x  -= 1 << 23; // subtract 2^m 
    v.x >>= 1;       // divide by 2
    v.x  += 1 << 29; // add ((b + 1) / 2) * 2^m
    return (int)v.f;
}

int factorial(int n) {
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

std::string IntToString(int a) {
    	std::ostringstream temp;
    	temp << a;
    	return temp.str();
}

std::string currentDateTime() {
    // return "2020-01-01-12:34:67:00"; For Test.
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

std::string AsciiGenFreeBrain(int len) {
	std::string rtr = "~";
	for(int i = 0; i != len; i++) {
		rtr.append("+");
	}
	return rtr;
}

void textbackground(int color) {
	printf ("%c[%dm", ESC, 40+color);
}

std::string GetUptime() {
	#ifdef __FreeBSD__
	return "null";
	#else 
	double uptime, uptimeMinutes, uptimeHour, uptimeDay;
	int initialUptime, uptimeMinutesWhole, uptimeHourWhole, uptimeDayWhole;
	std::string uptimeString;
	std::stringstream uptimeStream;
	struct sysinfo info;
	sysinfo(&info);
	uptime = info.uptime;
	if(uptime/60 >= 60) {
		uptimeHour = (uptime/60)/60;
		uptimeHourWhole = uptimeHour;
		uptimeMinutes = uptimeHour - uptimeHourWhole;
		uptimeMinutesWhole = uptimeMinutes * 60;
		if(uptimeHour >= 24) {
			uptimeDay = uptimeHour/24;
			uptimeDayWhole = uptimeDay;
			uptimeHour = uptimeDay - uptimeDayWhole;
			uptimeHour = uptimeHour * 24;
			uptimeHourWhole = uptimeHour;
			uptimeStream << uptimeDayWhole << "d " << uptimeHourWhole << "h " << uptimeMinutesWhole << "m";
		} else {
			uptimeStream << WBOLD_LIGHT_CYAN_COLOR << uptimeHourWhole << WBOLD_CYAN_COLOR << "h " << WBOLD_LIGHT_MAGENTA_COLOR << uptimeMinutesWhole << WBOLD_MAGENTA_COLOR << "m" << WBLACK_COLOR;
		}
	} else {
		uptimeMinutes = uptime/60;
		uptimeMinutesWhole = uptimeMinutes;
		uptimeStream << uptimeMinutesWhole << "m";
	}
	uptimeString = uptimeStream.str();
	return uptimeString;
	#endif
}


void InputFunction() {
	textbackground(runsyntax->BackgroundColor());
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
        cursorpos.x = main_function->_h_str.length();
        if(c == BACKSPACE) {
		if(cursorpos.x >= 1) {
			cursorpos.x -= 1;
			// Under the Construction
     			main_function->_h_str.erase(main_function->_h_str.end() - 1);
     			std::cout << '\b' << " " << '\b';
		} else {
		}
		return;
     	} else {
        	main_function->_h_str.push_back(c);
        }
        if(main_function->_h_str == keywords.Help) {
		RemovePrintedChar(keywords.Help.length() - 1);
		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "help" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "help");
       	} else {
        		std::cout << WBOLD_YELLOW_COLOR << "help" << WBLACK_COLOR;
       	}
        	if(getchar() == '\n') {
        		slashn 
        		helpstr->help();
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal();
        	return; 
        } else if(main_function->_h_str == keywords.Lsd) {
        	std::string input;
                RemovePrintedChar(keywords.Lsd.length() - 1);
                if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_RED_COLOR << "d" << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "dls ");
       	} else {
        		std::cout << WBOLD_RED_COLOR << "d" << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
       	}
        	BOLD_CYAN_COLOR
          	std::getline(std::cin, input);
          	BLACK_COLOR
         	if(input == "") {
          		main_->list_direc(true, ".");
          	} else {
          		main_->list_direc(true, input);
          	}  
        	history->WriteHistory(main_function->_h_str);
         	main_function->_h_str.erase();
        	terminalstr->Terminal();       	
        	return;
        } else if(main_function->_h_str == keywords.Create) {
        	RemovePrintedChar(keywords.Create.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "create" << WBLACK_COLOR;
       		std::cout << WBOLD_CYAN_COLOR << " scrift_project";
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "create scrift_project");
       	} else {
        		std::cout << WBOLD_BLUE_COLOR << "create" << WBLACK_COLOR;
       		std::cout << WBOLD_CYAN_COLOR << " scrift_project";	
        	}
        	BOLD_MAGENTA_COLOR
        	std::getline(std::cin, main_function->_h_str);
        	BLACK_COLOR
        	filefunction->CreateScriftFile(main_function->_h_str);
        	history->WriteHistory(main_function->_h_str); 
        	main_function->_h_str.erase();
        	terminalstr->Terminal();  
        	return;
        } else if(main_function->_h_str == keywords.LanguageTemplate) {
        	RemovePrintedChar(keywords.LanguageTemplate.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "template");
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "template");
       	} else {
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "template");	
        	}
        	if(getchar() == '\n') {
        		temp.LangTemplate();
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal();
        	return;
        } else if(main_function->_h_str.rfind(keywords.DeleteText, 0) == 0) {
       	 logsystem->WriteLog("Launching deletetext function.. - ");
       	 RemovePrintedChar(keywords.DeleteText.length() - 1);
       	 if(runsyntax->Theme() == "default")  {
        		 std::cout << WBOLD_RED_COLOR << "delete" << WBOLD_YELLOW_COLOR << "text ";
       	 } else if(runsyntax->Theme() == "classic") {
       		 colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "deletetext ");
       	 } else {
        		 std::cout << WBOLD_RED_COLOR << "delete" << WBOLD_YELLOW_COLOR << "text ";	
        	 }
        	 BOLD_BLUE_COLOR
        	 std::getline(std::cin, main_function->_h_str);
       	 fileaddtextfunction->DeleteLine(main_function->_h_str);
       	 history->WriteHistory(main_function->_h_str);
       	 main_function->_h_str.erase();
        	 terminalstr->Terminal();   
       	 return;
    	} else if(main_function->_h_str == keywords.Random) {
    		RemovePrintedChar(keywords.Random.length() - 1);
    		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "random " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "random ");
       	} else {
        		std::cout << WBOLD_BLUE_COLOR << "random " << WBLACK_COLOR;
        	}
    		int number;
    		BOLD_CYAN_COLOR
    		std::cin >> number;
    		if(number == 0) {
    			return;
    		}
    		number = rand()%(number+1);
    		BOLD_YELLOW_COLOR
    		std::cout << number;
    		BLACK_COLOR
    		number = 0;
    		main_function->_h_str.erase();
    		return;
    	} else if(main_function->_h_str == keywords.Uninstall) {
    		RemovePrintedChar(keywords.Uninstall.length() - 1);
    		if(runsyntax->Theme() == "default")  {
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "uninstall");
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "uninstall");
       	} else {
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "uninstall");
        	}
        	if(getchar() == '\n') {
        		std::string option;
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "Remove with tools? (Fetcheya, Edifor etc.) : ");
        		BOLD_CYAN_COLOR
        		std::cin >> option;
        		BLACK_COLOR
        		if(option == "y" || option == "Y") {
        			system("sudo rm -f /bin/fetcheya");
  				colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "Fetcheya has been removed.\n");
        			system("sudo rm -f /bin/edifor");
        			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN).c_str(), "Edifor has been removed\n");
        			system("sudo rm -f /bin/castle");
        			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "Castle has been removed\n");
        			system("sudo rm -f /bin/fdate");
        			system("sudo rm -f /bin/tictactoe");
        			system("sudo rm -f /bin/pong");
        			system("sudo rm -f /bin/scrift");
        			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "Note: Select a shell and restart, because Scrift has been deleted\n");
        			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN).c_str(), "Goodbye!\n");
        		} else if(option == "n" || option == "N") {
        			system("sudo rm -f /bin/scrift");
        			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "Note: Select a shell and restart, because Scrift has been deleted\n");
        			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN).c_str(), "Goodbye!\n");
        		} else {
        			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "\nAborted.\n");
        		}
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal();
        	return;
    	} else if(main_function->_h_str == keywords.Lsf) {
    		std::string input;
        	RemovePrintedChar(keywords.Lsf.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "f" << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "fls ");
       	} else {
        		std::cout << WBOLD_BLUE_COLOR << "f" << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
        	}
        	BOLD_CYAN_COLOR
          	std::getline(std::cin, input);
          	BLACK_COLOR
         	if(input == "") {
          		main_->list_file(true, ".");
          	} else {
			main_->list_file(true, input);
          	}  
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
    	} else if(main_function->_h_str == keywords.Factorial) {
    		std::string input;
        	RemovePrintedChar(keywords.Factorial.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "fact");
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "fact");
       	} else {
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "fact");
        	}
        	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), " ");
          	std::cin >> input;
          	if(atoi(input.c_str()) < 0) {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "n must be > or = to 0");          	
          	} else {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), std::to_string(factorial(atoi(input.c_str()))).c_str());
        	}
                BLACK_COLOR 	
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	return;
    	} else if(main_function->_h_str == keywords.Uptime) {
    		RemovePrintedChar(keywords.Uptime.length() - 1);
    		if(runsyntax->Theme() == "default") {
    			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "uptime");
		} else if(runsyntax->Theme() == "classic") {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "uptime");
		} else {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "uptime");
		}
		if(getchar() == '\n') {
			colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), (GetUptime() + "\n").c_str());
		} 
		
		history->WriteHistory(main_function->_h_str);
		main_function->_h_str.erase();
		terminalstr->Terminal();
		return;
    	} else if(main_function->_h_str == keywords.GitLink) {
      		RemovePrintedChar(keywords.GitLink.length() - 1);
      		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "f" << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "fls ");
       	} else {
        		std::cout << WBOLD_BLUE_COLOR << "f" << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
        	}
        	if(getchar() == '\n') {
        		helpstr->GitLink();
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
        } else if(main_function->_h_str.rfind(keywords.CreateText, 0) == 0) {
        	logsystem->WriteLog("Launching ctxt function..\n");
      		RemovePrintedChar(keywords.CreateText.length() - 1);
      		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "ctxt " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "ctxt ");
       	} else {
        		std::cout << WBOLD_MAGENTA_COLOR << "ctxt " << WBLACK_COLOR;
        	}
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
              	RemovePrintedChar(keywords.Pause.length() - 1);
              	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "ctxt " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "ctxt ");
       	} else {
        		std::cout << WBOLD_MAGENTA_COLOR << "ctxt " << WBLACK_COLOR;
        	}
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
        	RemovePrintedChar(keywords.KName.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "kname" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "kname");
       	} else {
        		std::cout << WBOLD_YELLOW_COLOR << "kname" << WBLACK_COLOR;
        	}
        	if(getchar() == '\n') {
        		printlnf(main_->FName().c_str());
    			slashn
    		}
    		history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal(); 
    		return;
        } else if(main_function->_h_str == keywords.Contr) {
                RemovePrintedChar(keywords.Contr.length() - 1);
                if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "contr" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "contr");
       	} else {
        		std::cout << WBOLD_YELLOW_COLOR << "contr" << WBLACK_COLOR;
        	}
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
                RemovePrintedChar(keywords.LsObject.length() - 1); 
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "obj" << WBOLD_YELLOW_COLOR << "ls" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "objls");
       	} else {
        		std::cout << WBOLD_MAGENTA_COLOR << "obj" << WBOLD_YELLOW_COLOR << "ls" << WBLACK_COLOR;
        	}
        	if(getchar() == '\n') {   	
    			listdirectoryfunction->ListObjectFunction();
    		}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal();     		
    		return;
    	} else if(main_function->_h_str.find(keywords.SetName, 0) == 0) {
        	RemovePrintedChar(keywords.SetName.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "setname " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "setname ");
       	} else {
			std::cout << WBOLD_BLUE_COLOR << "setname " << WBLACK_COLOR;
        	}
		BOLD_LIGHT_CYAN_COLOR
        	std::getline(std::cin, main_function->_h_str);
		BLACK_COLOR        	
		SetNameString = scriftlang->EraseAllSubString(main_function->_h_str, keywords.SetName + keywords.Whitespace);
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;
        } else if(main_function->_h_str.find(keywords.SetTo, 0) == 0) {
        	RemovePrintedChar(keywords.SetTo.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_CYAN_COLOR << "setto " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "setto ");
       	} else {
			std::cout << WBOLD_CYAN_COLOR << "setto " << WBLACK_COLOR;
        	}      	
		BOLD_LIGHT_BLUE_COLOR
        	std::getline(std::cin, main_function->_h_str);
		BLACK_COLOR    		
		SetNameToString = scriftlang->EraseAllSubString(main_function->_h_str, keywords.SetTo + keywords.Whitespace);
    		setenv(SetNameString.c_str(), SetNameToString.c_str(), true);
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal(); 
        	return;
    	} else if(main_function->_h_str == keywords.Now) {
    	        RemovePrintedChar(keywords.Now.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "now" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "now");
       	} else {
			std::cout << WBOLD_YELLOW_COLOR << "now" << WBLACK_COLOR;
        	}
        	if(getchar() == '\n') {
        		WHITE_COLOR
    			printlnf(currentDateTime().c_str());
    			slashn
    			BLACK_COLOR
    		}
        	history->WriteHistory(keywords.Now);
    		main_function->_h_str.erase();
    		terminalstr->Terminal(); 
        	return;
    	} else if(main_function->_h_str == keywords.Printlnf || main_function->_h_str == keywords.Echo){
        	logsystem->WriteLog("Launching printlnf function.. - ");
        	RemovePrintedChar(main_function->_h_str.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "printlnf " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "printlnf ");
       	} else {
			std::cout << WBOLD_BLUE_COLOR << "printlnf " << WBLACK_COLOR;
        	}
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
            	RemovePrintedChar(keywords.ClearLog.length() - 1);
            	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_GREEN_COLOR << "clear_log";
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "clear_log");
       	} else {
			std::cout << WBOLD_GREEN_COLOR << "clear_log";
        	}
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
        	RemovePrintedChar(keywords.MKDir.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_GREEN_COLOR << "mkdir " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "mkdir ");
       	} else {
			std::cout << WBOLD_GREEN_COLOR << "mkdir " << WBLACK_COLOR;
        	}
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
        	BLACK_COLOR
        	mkdirfunction->MKDirFunctionInit(scriftlang->EraseAllSubString(main_function->_h_str, keywords.MKDir + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	return;
   	} else if(main_function->_h_str == keywords.SquareofNumber) {
   		RemovePrintedChar(keywords.SquareofNumber.length() - 1);
   		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "square " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "square ");
       	} else {
			std::cout << WBOLD_BLUE_COLOR << "square " << WBLACK_COLOR;
        	}
   		BOLD_CYAN_COLOR
  		main_function->_h_str.erase();
   		std::cin >> main_function->_h_str;
   		std::cout << atoi(main_function->_h_str.c_str()) * atoi(main_function->_h_str.c_str());
   		history->WriteHistory(keywords.SquareofNumber + " "  + main_function->_h_str);
   		main_function->_h_str.erase();
   		return;
   	} else if(main_function->_h_str == keywords.SquareRootofNumber) {
   		RemovePrintedChar(keywords.SquareRootofNumber.length() - 1);
   		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "sqrt " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "sqrt ");
       	} else {
			std::cout << WBOLD_BLUE_COLOR << "sqrt " << WBLACK_COLOR;
        	}
   		BOLD_CYAN_COLOR
   		main_function->_h_str.erase();
   		std::cin >> main_function->_h_str;
   		(atoi(main_function->_h_str.c_str()) <= - 1) ? std::cout << "Hmm" : std::cout << sqrti(atoi(main_function->_h_str.c_str()));
   		history->WriteHistory(keywords.SquareRootofNumber + " " + IntToString(atoi(main_function->_h_str.c_str())));
   		main_function->_h_str.erase();
   		return;
   	} else if(main_function->_h_str.rfind(keywords.RandomizeString, 0) == 0) {
        	logsystem->WriteLog("Launching rstr function.. - ");
        	RemovePrintedChar(keywords.RandomizeString.length() - 1);
		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_GREEN_COLOR << "rstr " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "rstr ");
       	} else {
			std::cout << WBOLD_GREEN_COLOR << "rstr " << WBLACK_COLOR;
        	}
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
                RemovePrintedChar(keywords.RemoveFile.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_RED_COLOR << "rmv" << WBOLD_MAGENTA_COLOR << "file " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "rmvfile ");
       	} else {
			std::cout << WBOLD_RED_COLOR << "rmv" << WBOLD_MAGENTA_COLOR << "file " << WBLACK_COLOR;
        	}        	
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
        	BLACK_COLOR
        	removefile->DeleteFile(scriftlang->EraseAllSubString(main_function->_h_str, keywords.RemoveFile + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
          	main_function->_h_str.erase();
        	return;      	
        }  else if(main_function->_h_str == keywords.Scr) {
        	logsystem->WriteLog("Erasing _h_str function.. - ");
        	RemovePrintedChar(keywords.Scr.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_GREEN_COLOR << "scr " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "scr ");
       	} else {
			std::cout << WBOLD_GREEN_COLOR << "scr " << WBLACK_COLOR;
        	}        	
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
        	RemovePrintedChar(keywords.FeLog.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << " felog" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), " felog");
       	} else {
			std::cout << WBOLD_YELLOW_COLOR << " felog" << WBLACK_COLOR;
        	}        	
        	if(getchar() == '\n') {
        		slashn
       		logsystem->WriteLog("Launching felog function.. - ");
        		readfilefunction->ReadFeLogFunction();
        	}
        	history->WriteHistory(main_function->_h_str);
        	main_function->_h_str.erase();
        	terminalstr->Terminal(); 
        	return;  
       } else if(main_function->_h_str.rfind(keywords.Find, 0) == 0) {
          	RemovePrintedChar(keywords.Find.length() - 1);
   		FFindFileFunction *find = new FFindFileFunction();
   		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "ffind " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "ffind ");
       	} else {
			std::cout << WBOLD_BLUE_COLOR << "ffind " << WBLACK_COLOR;
        	}
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
   		find->FindFile(scriftlang->EraseAllSubString(main_function->_h_str, keywords.Find + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
   		main_function->_h_str.erase();
   		return;
       } else if(main_function->_h_str.find(keywords.AddText, 0) == 0) {
        	logsystem->WriteLog("Launching addtext function.. - ");
          	RemovePrintedChar(keywords.AddText.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_GREEN_COLOR << " addtext " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), " addtext ");
       	} else {
       		std::cout << WBOLD_GREEN_COLOR << " addtext " << WBLACK_COLOR;
        	}
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
  		WHITE_COLOR
        	fileaddtextfunction->AppendLine(scriftlang->EraseAllSubString(main_function->_h_str, keywords.AddText + keywords.Whitespace));
        	history->WriteHistory(main_function->_h_str);
          	main_function->_h_str.erase();
          	BLACK_COLOR
          	terminalstr->Terminal(); 
   				return;
       } else if(main_function->_h_str.find(keywords.Emoji) == 0) {
       	RemovePrintedChar(keywords.Emoji.length() - 1);
       	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_BLUE_COLOR << "emoji " << WBLACK_COLOR; 
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "emoji ");
       	} else {
       		std::cout << WBOLD_BLUE_COLOR << "emoji " << WBLACK_COLOR; 
        	}       	
       	BOLD_CYAN_COLOR
       	std::getline(std::cin, main_function->_h_str);
     		std::cout << emojiplusplus::EmojiString(main_function->_h_str) << "\n";
     		history->WriteHistory(main_function->_h_str);
       	main_function->_h_str.erase();
       	terminalstr->Terminal();
       	return;
       } else if(main_function->_h_str.find(keywords.RunDotSlash, 0) == 0) {
          	RemovePrintedChar(keywords.RunDotSlash.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "." << WBOLD_BLUE_COLOR << "/" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "./");
       	} else {
       		std::cout << WBOLD_MAGENTA_COLOR << "." << WBOLD_BLUE_COLOR << "/" << WBLACK_COLOR;
        	}
        	BOLD_LIGHT_MAGENTA_COLOR
        	std::getline(std::cin, main_function->_h_str);
        	BLACK_COLOR
        	if(main_function->_h_str.length() == 0) {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : ./ : Is a directory.\n"); 
		} else if(strstr(main_function->_h_str.c_str(), ".scr")) { 
			scriftlang->ReadFunc(main_function->_h_str);
		} else  {
			runfunction->RunFunction("./" + main_function->_h_str);
		}
        	
        	history->WriteHistory(main_function->_h_str);
      		main_function->_h_str.erase();
      		terminalstr->Terminal();
          	return;
      } else if(main_function->_h_str == keywords.IP) {
          	logsystem->WriteLog("Launching ip function.. - ");
          	RemovePrintedChar(keywords.IP.length() - 1);
          	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "ip" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "ip");
       	} else {
       		std::cout << WBOLD_YELLOW_COLOR << "ip" << WBLACK_COLOR;
       	}
       	
		if(getchar() == '\n') {
       		main_->getIPAddress();
        		history->WriteHistory(main_function->_h_str);
       	}
       	main_function->_h_str.erase();
       	terminalstr->Terminal(); 
       	return;
      } else if(main_function->_h_str == keywords.Clear_History) {
      		RemovePrintedChar(keywords.Clear_History.length() - 1);
      		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_RED_COLOR << "rmv" << WBOLD_MAGENTA_COLOR << "history" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "rmvhistory");
       	} else {
       		std::cout << WBOLD_RED_COLOR << "rmv" << WBOLD_MAGENTA_COLOR << "history" << WBLACK_COLOR;
       	}
      		if(getchar() == '\n') {
      			history->ClearHistory();
      		}
      		history->WriteHistory(main_function->_h_str);
      		main_function->_h_str.erase();
      		terminalstr->Terminal();
      		return;
      } else if(main_function->_h_str == keywords.History) {                                       
        	logsystem->WriteLog("Calling ReadHistoryFileFunction - ");
         	RemovePrintedChar(keywords.History.length() - 1);
         	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "history" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "history");
       	} else {
       		std::cout << WBOLD_YELLOW_COLOR << "history" << WBLACK_COLOR;
       	}
        	if(getchar() == '\n') {
        		readfilefunction->ReadHistoryFileFunction();
        	}
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal(); 	
    		return;
    } else if(main_function->_h_str == keywords.Back) {
          	logsystem->WriteLog("Launching back function.. - ");
      	  	RemovePrintedChar(keywords.Back.length() - 1);
      	  	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "back" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "back");
       	} else {
        		std::cout << WBOLD_MAGENTA_COLOR << "back" << WBLACK_COLOR;
       	}
        	if(getchar() == '\n') {
        		std::string path_string(main_->_file_path_cd_function);
        		std::size_t test = path_string.find_last_of("/\\");
        		std::string test_string = path_string.substr(0, test);
        		int convertdata = static_cast<int>(test);
        		if(test_string == "") {
        			test_string.append("/");
        		}
        		std::strcpy(main_->_file_path_cd_function, test_string.c_str());
        		chdir(test_string.c_str());
        		logsystem->WriteLog(main_->_file_path_cd_function);
        	}
        	history->WriteHistory(main_function->_h_str);
       	main_function->_h_str.erase();
       	terminalstr->Terminal(); 
       	return;
     } else if(main_function->_h_str == keywords.Ls) {
          	std::string input;
          	logsystem->WriteLog("Launching ls function.. - ");
          	RemovePrintedChar(keywords.Ls.length() - 1);
                if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "ls ");
       	} else {
        		std::cout << WBOLD_YELLOW_COLOR << "ls " << WBLACK_COLOR;
       	}
          	BOLD_BLUE_COLOR
          	std::getline(std::cin, input);
          	BLACK_COLOR
          	if(input == "") {
          		listdirectoryfunction->LSFunction(".");
          	} else {
          		listdirectoryfunction->LSFunction(input);
          	}  	
          	history->WriteHistory(main_function->_h_str);
      	  	main_function->_h_str.erase();
      	  	terminalstr->Terminal();
      	  	return;
     } else if(main_function->_h_str.find(keywords.Fr) == 0 || main_function->_h_str.find(keywords.Cd) == 0) {
          	logsystem->WriteLog("Launching cd function.. -");
      	  	RemovePrintedChar(keywords.Fr.length() - 1);
      	  	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_GREEN_COLOR << "fr " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "fr ");
       	} else {
        		std::cout << WBOLD_GREEN_COLOR << "fr " << WBLACK_COLOR;
       	}
      	  	BOLD_CYAN_COLOR
      	  	std::getline(std::cin, main_function->_h_str);
          	cdfunction->CDFunctionInit(scriftlang->EraseAllSubString(main_function->_h_str, keywords.Fr + keywords.Whitespace));
          	history->WriteHistory(main_function->_h_str);
     	  	main_function->_h_str.erase();
     	  	terminalstr->Terminal();
      	  	return;
     } else if(main_function->_h_str == keywords.Clear_Settings) {
          	logsystem->WriteLog("Calling DeleteSettingsFunction .. -  ");
     	  	RemovePrintedChar(keywords.Clear_Settings.length() - 1);
     	  	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_RED_COLOR << "rmv" << WBOLD_YELLOW_COLOR << "settings" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "rmvsettings");
       	} else {
	  		std::cout << WBOLD_RED_COLOR << "rmv" << WBOLD_YELLOW_COLOR << "settings" << WBLACK_COLOR;
       	}
	  	if(getchar() == '\n') {
          		clearfile->ClearSettingsFunction();
          	}
          	history->WriteHistory(main_function->_h_str);
          	main_function->_h_str.erase();
          	terminalstr->Terminal();
      	  	return;
    } else if (main_function->_h_str == keywords.Home) {
        	logsystem->WriteLog("Launching home function.. - ");
        	RemovePrintedChar(keywords.Home.length() - 1);
        	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "home" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "home");
       	} else {
       		std::cout << WBOLD_MAGENTA_COLOR << "home" << WBLACK_COLOR;
       	}
        	if(getchar() == '\n') {
       		homefunction->GetHome();
       		slashn
       	}
        	history->WriteHistory(main_function->_h_str);
       	main_function->_h_str.erase();
       	terminalstr->Terminal();
       	return;
     } else if(main_function->_h_str == keywords.Close || main_function->_h_str == keywords.Exit)  {                                      
        	logsystem->WriteLog("Exit signal.. - ");
          	RemovePrintedChar(main_function->_h_str.length() - 1);
          	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "cls" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "cls");
       	} else {
	  		std::cout << WBOLD_MAGENTA_COLOR << "cls" << WBLACK_COLOR;
       	}
        	if(getchar() == '\n') {
        		history->WriteHistory(main_function->_h_str);
        		history->WriteAllHistory();
        		main_function->_h_str.erase();
          		exit(EXIT_SUCCESS);
          	}
          	return;
     } else if(main_function->_h_str.find(keywords.Scrift) == 0) {
          	RemovePrintedChar(keywords.Scrift.length() - 1);
          	if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_GREEN_COLOR << "fscrift " << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "fscrift ");
       	} else {
	  		std::cout << WBOLD_GREEN_COLOR << "fscrift " << WBLACK_COLOR;
       	}
        	BOLD_CYAN_COLOR
        	std::cin >> main_function->_h_str;
        	scriftlang->ReadFunc(main_function->_h_str + ".scr");
        	history->WriteHistory(main_function->_h_str);
         	main_function->_h_str.erase();
       	return;
     } else if(main_function->_h_str == keywords.Settings) {
     		logsystem->WriteLog("Calling ReadSettingsFunction.. - ");
    		RemovePrintedChar(keywords.Settings.length() - 1);	
    		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "settings" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "settings");
       	} else {
	  		std::cout << WBOLD_YELLOW_COLOR << "settings" << WBLACK_COLOR;
       	}
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
      		RemovePrintedChar(keywords.Clear.length() - 1);
      		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "clear" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "clear");
       	} else {
	  		std::cout << WBOLD_YELLOW_COLOR << "clear" << WBLACK_COLOR;
       	}
      		if(getchar() == '\n') {
      	  		printlnf("\033c");
      	  	}
        	history->WriteHistory(main_function->_h_str);
         	main_function->_h_str.erase();
         	terminalstr->Terminal();
       	return;
     } else if(main_function->_h_str == keywords.MyASCIIArt) {
     		RemovePrintedChar(keywords.MyASCIIArt.length() - 1);
     		if(runsyntax->Theme() == "default") {
     			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "asciiart");
     		} else if(runsyntax->Theme() == "classic") {
     			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "asciiart");
     		} else {
     			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "asciiart");
     		}
     		if(getchar() == '\n') {
     			readfilefunction->ReadASCIIFunction();
     		}
     		main_function->_h_str.erase();
     		terminalstr->Terminal();
     		return;
     } else if(main_function->_h_str == keywords.Username) {
		RemovePrintedChar(keywords.Username.length() - 1);
		if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_MAGENTA_COLOR << "username" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "username");
       	} else {
	  		std::cout << WBOLD_MAGENTA_COLOR << "username" << WBLACK_COLOR;
       	}
		if(getchar() == '\n') {
			BOLD_CYAN_COLOR
			userhostname->InitUsername();
			BLACK_COLOR
			slashn
		}
		history->WriteHistory(main_function->_h_str);	
		main_function->_h_str.erase();
		terminalstr->Terminal();
		return;
     } else if(main_function->_h_str == keywords.Version)  {          
                RemovePrintedChar(keywords.Version.length() - 1);  
                if(runsyntax->Theme() == "default")  {
        		std::cout << WBOLD_YELLOW_COLOR << "version" << WBLACK_COLOR;
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "version");
       	} else {
	  		std::cout << WBOLD_YELLOW_COLOR << "version" << WBLACK_COLOR;
       	}
      		if(getchar() == '\n') {
    			PrintVersion();
    		}
        	history->WriteHistory(main_function->_h_str);
    		main_function->_h_str.erase();
    		terminalstr->Terminal();
       	return;
     } else if(main_function->_h_str == keywords.Morse) {
     		RemovePrintedChar(keywords.Morse.length() - 1);
     		if(runsyntax->Theme() == "default") {
     			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "morse ");
     		} else if(runsyntax->Theme() == "classic") {
     			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "morse ");
		} else {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "morse ");
		}
		if(getchar() == '\n') {
			EasyMorse::MainMorse();
		}
		history->WriteHistory(main_function->_h_str);
		main_function->_h_str.erase();
		terminalstr->Terminal();
		return;
     } else if(main_function->_h_str == keywords.Welcome) {
     		RemovePrintedChar(keywords.Welcome.length() - 1);
     		if(runsyntax->Theme() == "default")  {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "welcome");
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "welcome");
       	} else {
	  		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "welcome");
       	}
      		if(getchar() == '\n') {
      	  		 helpstr->hello();
      	  	}
        	history->WriteHistory(main_function->_h_str);
         	main_function->_h_str.erase();
         	terminalstr->Terminal();
       	return;
     } else if(main_function->_h_str == keywords.FreeBrainGen) {
     		RemovePrintedChar(keywords.FreeBrainGen.length() - 1);
     		if(runsyntax->Theme() == "default")  {
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "genfrbr ");
       	} else if(runsyntax->Theme() == "classic") {
       		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), "genfrbr ");
       	} else {
	  		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "genfrbr ");
       	}
       	BOLD_LIGHT_MAGENTA_COLOR
       	std::getline(std::cin, main_function->_h_str);
       	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), (AsciiGenFreeBrain(atoi(scriftlang->EraseAllSubString(main_function->_h_str, " ").c_str())) + "\n").c_str());
       	history->WriteHistory(keywords.FreeBrainGen + " " + main_function->_h_str);
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
		} else if(c == 32) {
			printlnf(" ");
			space++;
		} else if(c == '\n') {
			space = 0;
			input_value++;
			cursorpos.x = 0;
			slashn
			if(main_function->_h_str == "\n") {} else {
				std::string copy(main_function->_h_str);
        			runfunction->RunFunction(copy);
        		}
        		main_function->_h_str.erase();
        		terminalstr->Terminal(); 
        		return;
        	} else {
			//std::cout << "CURSORPOS" << cursorpos.x;
			//std::cout << cursorpos.x;
			if(runsyntax->Theme() == "default")  {
				Space(space, sign, false);
       		} else if(runsyntax->Theme() == "classic") {
       			Space(space, sign, true);
       		} else {
	  			Space(space, sign, false);
       		}
        		cursorpos.x += 1;
        		return;
        	}
        	//std::cout << cursorpos.x;
        	sign.erase();
        }
}

func
FMain::Shell() {	
    readfilefunction->ReadFeLogFunctionWithoutPrint();
    char output;
    WHITE_COLOR
    InputFunction();
    //std::getline(std::cin, _h_str); // ws -> whitespace
    BLACK_COLOR
    int t = 0;
    if (_h_str != "") { //NULL
    } else {
        return;
    }
}

integer main(integer argc, char** argv) {
    setlocale(LC_ALL, "");
    if(currentDateTime().substr(4, 6) == "-01-01") {
    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "Happy new year!");
    	std::cout << " " << emojiplusplus::EmojiString(":balloon:") << " - ";
    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "Scrift\n");
    }
    if(argc > 1) {
		for(int i = 1; i < argc; i++) {
			std::string arg(argv[i]);

			if(arg.substr(0, 2) == "--") {
				if(arg == "--build") {
					main_function->_h_str.erase();
        				std::cin >> main_function->_h_str;
        				scriftlang->ReadFunc(main_function->_h_str);
				} else if(arg == "--b") {
					main_function->_h_str.erase();
        				std::cin >> main_function->_h_str;
        				scriftlang->ReadFunc(main_function->_h_str);
				} else if(arg == "--help") {
					BOLD_RED_COLOR
					helpstr->help();
					BLACK_COLOR
					exit(EXIT_SUCCESS);
				} else if(arg == "--h") {
					BOLD_RED_COLOR
					helpstr->help();
					BLACK_COLOR
					exit(EXIT_SUCCESS);
				} else if(arg == "--version") {
					PrintVersion();
					exit(EXIT_SUCCESS);
				} else if(arg == "--v") {
					PrintVersion();
					exit(EXIT_SUCCESS);			
				}
			} 
		}
    } else {
    	filefunction->CreateSettingsFileFunction(); // Directory is "/home/<username>/<dot>scrift_settings"
    	logsystem->AllofThem();
    	asciifunction *ascii = new asciifunction;
    	ascii->Allofthem();
    	uid_t fuid = geteuid();
    	struct passwd *pass = getpwuid(fuid);
    	BOLD_MAGENTA_COLOR
    	printlnf("Welcome ");
    	BOLD_CYAN_COLOR
    	printlnf(pass->pw_name);
    	BOLD_BLUE_COLOR
    	std::cout << " " << emojiplusplus::EmojiString(runsyntax->FWelcomeEmoji()) << "\n";
    	BLACK_COLOR
    	history->AllofThem();
    	logsystem->WriteLog("Launching hello function.. - ");
    	helpstr->hello();
    	terminalstr->Terminal(); 
    	while(argc = 2) {
    	    std::cout << "\e]2; " << "Scrift: " << pass->pw_name << "@" << main_->_file_path_cd_function << "\a";
    	    main_function->Shell();
    	}
    	history->WriteAllHistory();
    }
    return F_OK;
}
