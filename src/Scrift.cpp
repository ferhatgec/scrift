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
#include <thread>

#ifndef __FreeBSD__
	#include <sys/sysinfo.h>
#endif

/* Source */
#include <src/Syntax/CommandFunc.h> /* For rstr, printlnf etc. */
#include <src/Scrift.hpp> /* Scrift main */
#include <src/Keywords/ScriftKeywords.hpp> /* Shell keywords */
#include <src/synflang.hpp> /* Some definitions */
#include <src/Syntax/Log.hpp> /* FeLog */
#include <src/Syntax/FileFunction.hpp> /* All file I/O functions, variables. */
#include <src/Syntax/KernelName.hpp> /* Get kernel name */
#include <src/Syntax/HelpFunction.hpp> /* HelpFunction(), Welcome() etc. */
#include <src/Syntax/GetNameFunction.hpp> /* Terminal */
#include <src/Syntax/RunFunction.hpp> /* Command execution */
#include <src/Syntax/Test.hpp> /* Test. */
#include <src/Syntax/ASCIIFunction.hpp> /* ASCII */
#include <src/Syntax/DeveloperMode.hpp> /* Under the construction */
#include <src/Syntax/Contributors.hpp> /* Contributors etc. */
#include <src/Syntax/Settings.hpp> /* Settings */
#include <src/Syntax/Language.hpp> /* Under the construction. Scripting language */
#include <src/Syntax/History.hpp> /* History */
#include <src/Syntax/Template.hpp> /* 'Hello world' example for a lot of languages */
#include <src/Syntax/Setup.hpp> /* Scrift Configuration & Setup */
#include <src/Syntax/Tools.hpp>

#include <Library/Keywords.hpp>

/* Fpi */
/* Simple build & install package installer for Fegeya Community's applications */
#include <src/Fpi/Core.hpp> 

/* Libraries */
#include <InputPlusPlus.h> /* For key-codes */
#include <EmojiPlusPlus.h> /* Emoji? */
#include <Colorized.hpp> /* Color library */
#include <EasyMorse.hpp> /* Morse-String to String-Morse converter library. */
#include <ExecutePlusPlus.hpp> /* Command execution library */
#include <FileSystemPlusPlus.h> /* File I/O library. */
#include <StringTools.h> /* Functions for STL String */

/* FileFunction namespace */
using namespace FileFunction;

/* Variables */
const std::string compilation_date = __DATE__;
const std::string compilation_time = __TIME__;

/* Definitions */
#define ESC 033

/* For Environment */
static std::string SetNameToString, SetNameString;

/* Classes */
std::unique_ptr<FMain> main_function(new FMain);
std::unique_ptr<FCommand> main_(new FCommand);
std::unique_ptr<FStructure> terminalstr(new FStructure);
std::unique_ptr<FCDFunction> cdfunction(new FCDFunction);
std::unique_ptr<FMKDirFunction> mkdirfunction(new FMKDirFunction);
std::unique_ptr<FCreateFileFunction> filefunction(new FCreateFileFunction);
std::unique_ptr<FLSFunction> listdirectoryfunction(new FLSFunction);
std::unique_ptr<FRunFunction> runfunction(new FRunFunction);
std::unique_ptr<FReadFileFunction> readfilefunction(new FReadFileFunction);
std::unique_ptr<FeLog> logsystem(new FeLog);
std::unique_ptr<FRemoveFileFunction> removefile(new FRemoveFileFunction);
std::unique_ptr<FSettings> runsyntax(new FSettings);
std::unique_ptr<FLanguage> scriftlang(new FLanguage);
std::unique_ptr<FHistory> history(new FHistory);
std::unique_ptr<FHelpFunction> helpstr(new FHelpFunction);
std::unique_ptr<FSetup> setup(new FSetup);
std::unique_ptr<FTools> date_tools(new FTools);

/* Structures */
std::unique_ptr<faddtextfunction> fileaddtextfunction(new faddtextfunction);
std::unique_ptr<fhomefunction> homefunction(new fhomefunction);

/* Keywords */
ScriftKeywords keywords;
FTemplate temp;

/*
	Get username.
*/

uid_t fuid = geteuid();
struct passwd *pass = getpwuid(fuid);

typedef struct CursorPos {
    int x = 0;
} cursorp;

cursorp cursorpos;

FMain::FMain() {}


FMain::~FMain() {}


void RemovePrintedChar(int value) {
	int rvalue = 0;
	do {
		std::cout << "\b";
		rvalue++;
	} while(rvalue != value);

	return;
}

int kbhit (void) {
    struct timeval tv;
    fd_set rdfs;
 
    tv.tv_sec = 0;
    tv.tv_usec = 0;
 
    FD_ZERO(&rdfs);
    FD_SET (STDIN_FILENO, &rdfs);
 
    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  
    return FD_ISSET(STDIN_FILENO, &rdfs);
}

int space = 0, input_value = 0, scrift_line = 0;

std::string ftime(compilation_time); // Convert

/* TODO: Remove this and replace with GetBetweenString of StringTools library. Get Between String */
void GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, std::string &rStr) {
    int start = oStr.find(sStr1);
    if (start >= 0) {
      std::string tstr = oStr.substr(start + sStr1.length());
      int stop = tstr.find(sStr2);
      if (stop >1)
        rStr = oStr.substr(start + sStr1.length(), stop);
      else
        rStr ="error";
    } else
       rStr = "error";
}

std::string VersionGenerator() { return "scriftv" + scriftlang->EraseAllSubString(ftime, ":"); }

/* For input colorizing */
void Space(int space, std::string sign, unsigned theme) {
	if(theme == 1) /* Classic (White & Black) theme */
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_WHITE).c_str(), sign.c_str());
	else if(theme == 2) { /* Halloween theme */
		RESETW
		if(space % 2) printfc({255, 154, 0}, sign);
		else if(space % 3) printfc({247, 95, 28}, sign);
		else printfc({0, 0, 0}, sign);
	} else /* Colorized theme */
		if(space == 1 || space % 1)
			colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), sign.c_str());
		else if(space % 2 || space == 2)
			colorized::PrintWith(colorized::Colorize(BOLD, MAGENTA).c_str(), sign.c_str());
		else if(space % 3 || space == 3)
			colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), sign.c_str());
		else if(space % 4 || space == 4)
			colorized::PrintWith(colorized::Colorize(BOLD, YELLOW).c_str(), sign.c_str());
		else if(space % 5)
			colorized::PrintWith(colorized::Colorize(BOLD, GREEN).c_str(), sign.c_str());
		else if(space % 6 || space == 6)
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), sign.c_str());
		else if(space % 7 || space == 7)
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), sign.c_str());
		else if(space % 7 || space == 7)
			colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), sign.c_str());
		else if(space == 0)
			std::cout << WBOLD_CYAN_COLOR << sign << WBLACK_COLOR;
}

void PrintVersion() {
	BOLD_MAGENTA_COLOR
    printlnf("Fegeya Scrift Version: ");
    	
    /* Version */
    BOLD_GREEN_COLOR
    printlnf(SCRIFT_VERSION);
    /* - */
    BOLD_YELLOW_COLOR
    printhyphen // printlnf("-");
    
    /* Status */
    BOLD_CYAN_COLOR
    printlnf(SCRIFT_STATUS);
    
    /* - */
    BOLD_BLUE_COLOR
    printhyphen // printlnf("-");
    
    /* VersionGenerator */
    BOLD_MAGENTA_COLOR
    printlnf(VersionGenerator().c_str());
    	
    /* Newline */
    slashn
    
    /* Copyright */
    BOLD_RED_COLOR
    printlnf("Copyright (c) 2020 ");
    	
    /* Author */
    BOLD_BLUE_COLOR
    printlnf("Ferhat Gecdogan \n");
    	
    BOLD_YELLOW_COLOR
    printlnf("All Rights Reserved. \n");
    
    BOLD_CYAN_COLOR
	printlnf("Distributed under the terms of the MIT License.");
	BLACK_COLOR
    slashn
}

/* Square root converter. */
int sqrti(int x) {
    union { float f; int x; } v;

    // convert to float
    v.f = (float)x;
    v.x  -= 1 << 23; // subtract 2^m
    v.x >>= 1;       // divide by 2
    v.x  += 1 << 29; // add ((b + 1) / 2) * 2^m
    
    return (int)v.f;
}

/* Factorial */
int factorial(int n) {
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

/* Integer to String */
std::string IntToString(int a) {
    std::ostringstream temp;
    temp << a;
    return temp.str();
}

/* For 'Happy new year' */
std::string FMain::Time() {
    // return "2020-01-01-12:34:67:00"; For Test.
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/*
	Terminal title.
*/
void
FMain::SetTitle() {
	std::cout << "\e]2; " << "Scrift: " << pass->pw_name << "@" << main_->_file_path_cd_function << "\a";
}

static void SetTitleAs(std::string _str) {
	std::cout << "\e]2; " << _str << "\a";
}

/*
	Cursor.
*/
void moveCursor(std::ostream& os, int col, int row) {
    os << "\033[" << col << ";" << row << "H";
}

/* ASCII Code generator for FreeBrain */
std::string AsciiGenFreeBrain(int len) {
	std::string rtr = "~";

	for(int i = 0; i != len; i++)
		rtr.append("+");
	
	return rtr;
}

/*
	Foreground color.
*/
void textbackground(int color) {
	printf ("%c[%dm", ESC, 40+color);
}

/* Username, emoji */
void PrintUsername() {
    BOLD_MAGENTA_COLOR
    printlnf("Welcome ");
    BOLD_CYAN_COLOR
    printlnf(pass->pw_name);
    BOLD_BLUE_COLOR
    std::cout << " " << emojiplusplus::EmojiString(runsyntax->FWelcomeEmoji());
    BLACK_COLOR
}


/*
	Uptime.
*/
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
		} else
			uptimeStream << WBOLD_LIGHT_CYAN_COLOR << uptimeHourWhole << WBOLD_CYAN_COLOR << "h " <<
                 WBOLD_LIGHT_MAGENTA_COLOR << uptimeMinutesWhole << WBOLD_MAGENTA_COLOR << "m" << WBLACK_COLOR;
	} else {
		uptimeMinutes = uptime/60;
		uptimeMinutesWhole = uptimeMinutes;
		uptimeStream << uptimeMinutesWhole << "m";
	}
	uptimeString = uptimeStream.str();
	return uptimeString;
	#endif
}

void CodeExecution(std::string arg) {
    history->WriteHistory(arg);
    
    if(arg.rfind(keywords.Scr, 0) == 0) {
        /*  scr
            scr echo hello
            Use Non-Scrift commands without conflict
        */
        arg = stringtools::EraseAllSubString(arg,
            keywords.Scr + " ");
        
        arg.pop_back();
        runfunction->RunFunction(arg);
        return;
    } else if(arg.rfind(keywords.Printlnf, 0) == 0){
        /*  printlnf
            printlnf Hello, world!
            printlnf #HOME

            Show output. Same as 'echo'
        */
        if(arg == keywords.Printlnf + " --h\n")
            std::cout << "Usage: printlnf variable\n" <<
                "printlnf #environment";
        else {
            arg = stringtools::EraseAllSubString(arg,
                keywords.Printlnf + " "); 
            
            arg.pop_back();
            main_->echo_printlnf(arg);
        }
        
        std::cout << "\n";
        return;
        } else if(arg.rfind(keywords.Echo, 0) == 0) {
        	/*  echo
                echo Hello, world!
                echo #HOME
                        
                Show output. Same as 'printlnf'
            */
            if(arg == keywords.Echo + " --h\n")
                std::cout << "Usage: echo variable\n" <<
                    "echo #environment";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Echo + " ");
                
                arg.pop_back();
                main_->echo_printlnf(arg);
            }
            
            std::cout << "\n";
            return;
        } else if(arg.rfind(keywords.Fpi, 0) == 0) {
		    /* 
                fpi --i || --install
                fpi --uni || --uninstall
            */
		    FInstall fetcheya_install;
		    fetcheya_install.FegeyaPackageInstaller(arg);
            return;
	    } else if(arg.rfind(keywords.FreeBrainGen, 0) == 0) {
            /* genfrbr
                genfrbr 3
                        
                Generate ASCII code for FreeBrain.
            */
            if(arg == keywords.FreeBrainGen + "\n") {} else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.FreeBrainGen + " ");
                                
                arg.pop_back();

                if(atoi(arg.c_str()) < 1)
                    /* Add negative value generator */
                    std::cout << "~";
                else
                    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), 
                        (AsciiGenFreeBrain(atoi(arg.c_str())) + "\n").c_str());
            }
            
            return;
        } else if(arg.rfind(keywords.Fr + " ", 0) == 0) {
            /*  fr
                fr /home
                fr ../../
                fr src

                Forward dir. Same as 'cd'
            */
            if(arg == keywords.Fr + " --h\n")
                std::cout << "Usage: fr path || dir\n";
            else if(arg == keywords.Fr + "\n" || arg == keywords.Fr + " #\n") {}
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Fr + " ");
                
                arg.pop_back();
                cdfunction->CDFunctionInit(arg);
            }
            
            return;
        } else if(arg.rfind(keywords.Cd, 0) == 0) {
            /*  cd
                cd /home
                cd ../../
                cd src

                Change dir. Same as 'fr'
            */
            if(arg == keywords.Cd + " --h\n")
          	    std::cout << "Usage: cd path || dir\n";
            else if(arg == keywords.Cd + "\n" || arg == keywords.Cd + " #\n") {} 
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Cd + " ");

                arg.pop_back();
                cdfunction->CDFunctionInit(arg);
            }
            
            return;
        } else if(arg.rfind(keywords.RunDotSlash, 0) == 0) {
            /*  ./
                ./make.scr 
                ./scrift 
                
                Command execution 
            */
            if(arg == keywords.RunDotSlash + "\n") {
                colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), 
                    "scrift : ./ : Is a directory.\n");
            } else if(strstr(arg.c_str(), ".scr")) {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.RunDotSlash);
                
                arg.pop_back(); /* Erase ./ and last character (newline) */
                scriftlang->ReadFunc(arg); 
            } else
                runfunction->RunFunction(arg);
                
            return;
        } else if(arg == keywords.Back + "\n") {
          	/*  back
                Same with fr || cd ..  

                Go to the previous directory. 
            */
        	
        	std::string path_string(main_->_file_path_cd_function);
        	std::size_t test = path_string.find_last_of("/\\");
        	std::string test_string = path_string.substr(0, test);

        	if(test_string == "")
        		test_string.append("/");
        	
        	std::strcpy(main_->_file_path_cd_function, test_string.c_str());
        	chdir(test_string.c_str());
		    main_function->SetTitle();
            
            path_string.erase();
            test_string.erase();
            
            return;
        } else if(arg.rfind(keywords.Lsf, 0) == 0) {
            /*  fls
                fls
                fls src 
                
                List only files.
            */
    		if(arg == keywords.Lsf + "\n")
          		main_->list_file(true, ".");
          	else if(arg == keywords.Lsf + " --h\n")
                std::cout << "Usage: fls || fls path\n";   
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Lsf + " ");
                
                arg.pop_back();
			    main_->list_file(true, arg);
          	}
            
            return;  
    	} else if(arg.rfind(keywords.Lsd, 0) == 0) {
            /*  dls
                dls
                dls src 

                List only directories.
            */ 
         	if(arg == keywords.Lsd + "\n")
          		main_->list_direc(true, ".");
          	else if(arg == keywords.Lsd + " --h\n")
                std::cout << "Usage: dls || dls path\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Lsd + " ");
                
                arg.pop_back();
          		main_->list_direc(true, arg);
          	}
            
            return;
        } else if(arg == keywords.LsObject + "\n") {
            /*  objls
                List /bin/
            */
    		
            listdirectoryfunction->ListObjectFunction();
            return;
    	} else if(arg.rfind(keywords.Find, 0) == 0) {
          	/*  ffind
                ffind sr

                Find file & folder on current directory
            */
            if(arg == keywords.Find + "\n") {} else {
                FFindFileFunction find;
                arg = stringtools::EraseAllSubString(arg, keywords.Find + " ");
                arg.pop_back();
   		        find.FindFile(arg);
            }
            
            return;
        } else if(arg.rfind(keywords.Output, 0) == 0) {
            /*  output
                output <command>

                Get output of inputted command
            */
            if(arg == keywords.Output + "\n") {}
            else {
                ExecutePlusPlus exec;
                arg = stringtools::EraseAllSubString(arg, keywords.Output + " ");
                arg.pop_back();
                std::cout << exec.ExecWithOutput(arg);
            }

            return;
        } else if(arg == keywords.Close + "\n" ||
            arg == keywords.Exit + "\n")  {
            /*  close, exit
                Exit.
            */
        	history->WriteAllHistory();
        	arg.erase();
          	
            exit(EXIT_SUCCESS);
            return;
        } else if(arg == keywords.Ls + "\n") {
            /*  ls
                ls 
                ls 

                List
            */
          	
          	listdirectoryfunction->LSFunction(".");
            return;
        } else if(arg.rfind(keywords.Ls, 0) == 0) {
            /*  ls
                ls 
                ls src

                List
            */
          	
            /*if(arg == keywords.Ls + "\n")
          		listdirectoryfunction->LSFunction(".");
                else 
            */
            
            if(arg == keywords.Ls + " --h\n")
                std::cout << "Usage: ls || ls path\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Ls + " ");
                
                arg.pop_back();
          		listdirectoryfunction->LSFunction(arg);
          	}
            
            return;                  
        } else if(arg.rfind(keywords.Scrift, 0) == 0) {
            /*  fscrift
                fscrift make 
                fscrift make.scr

                ScriftSL interpreter.
            */
        	if(arg == keywords.Scrift + "\n" || arg == keywords.Scrift + " --h\n") {
                std::cout << "Usage: fscrift file | file.scr\n";
            } else if(strstr(arg.c_str(), ".scr")) {
                arg = stringtools::EraseAllSubString(arg.erase(0, 7), " ");
                scriftlang->ReadFunc(arg);
            } else {
                arg = stringtools::EraseAllSubString(arg.erase(0, 7), " ");
                scriftlang->ReadFunc(arg + ".scr");
            }

            return;
        } else if(arg.rfind(keywords.MKDir, 0) == 0) {
        	/*  mkdir
                mkdir scrift
                Create directory
            */
            if(arg == keywords.MKDir + "\n") {} else {
                if(arg == keywords.MKDir + " --h\n")
                    std::cout << "Usage: mkdir dir\n";
                else {
                    arg = stringtools::EraseAllSubString(arg,
                        keywords.MKDir + " ");
                        
                    arg.pop_back();
                    mkdirfunction->MKDirFunctionInit(arg);
                }
            }

            return;
   	    } else if(arg.rfind(keywords.ReadText, 0) == 0) {
		    /*  readtext
                readtext file
                        
                Implementation of 'cat'.
            */
            if(arg == keywords.ReadText + "\n" || 
                arg == keywords.ReadText + " --h\n")
                std::cout << "Usage: readtext file\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.ReadText + " ");
            
                arg.pop_back();
          	    readfilefunction->ReadFileFunction(arg);
            }

            return;
	    } else if(arg.rfind(keywords.SetName, 0) == 0) {
		    /*  setname
                setname home_path

                Set environment name
            */
            if(arg == keywords.SetName + "\n" ||
                arg == keywords.SetName + " --h\n")
                std::cout << "Usage: setname environment_name\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.SetName + " ");
                
                arg.pop_back();
                SetNameString = arg;
            }

            return;
        } else if(arg.find(keywords.SetTo, 0) == 0) {
		    /*  setto
                setto /home/ferhatgec/

                Set environment value
            */
            if(arg == keywords.SetTo + "\n" ||
                arg == keywords.SetTo + " --h\n")
                std::cout << "Usage: setto environment_value\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.SetTo + " ");
                
                arg.pop_back();
		        SetNameToString = arg;
    		    setenv(SetNameString.c_str(), SetNameToString.c_str(), true);
            }

            return;
        } else if(arg.rfind(keywords.Random, 0) == 0) {
            /*  random
                random 15 

                pseudo random integer generator (rand) 
            */
            if(arg == keywords.Random + " --h\n"
                || arg == keywords.Random + "\n")
                
                std::cout << "Usage: random number\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Random + " ");
                
                arg.pop_back();
                std::cout << rand()%(atoi(arg.c_str())+1);
            }

            return;
    	} else if(arg == keywords.Help + "\n") {
        	/*  help
                List all commands.
            */
            helpstr->HelpFunction();
            
            return;
        } else if(arg == keywords.Version + "\n")  {
            /*  version
                Show Scrift's version.
            */
            PrintVersion();
            
            return;
        } else if(arg == keywords.Uptime + "\n") {
            /*  uptime
                Show uptime
            */
		    colorized::PrintWith(colorized::Colorize(BOLD, BLUE).c_str(), 
                (GetUptime() + "\n").c_str());
            
            return;
    	} else if(arg == keywords.Clear + "\n") {
      	  	/*  clear
                Clear terminal buffer
            */
            scrift_line = 0;
            std::cout << "\033c";
            
            return;
        } else if(arg.rfind(keywords.Title, 0) == 0) {
			/* title
				title Hello, terminal.

				Change title of terminal header bar (or titlebar)
			*/
			
			/* TODO:
				Support environments..
			*/
				
			if(arg != keywords.Title + "\n") { 
				arg = stringtools::EraseAllSubString(arg, 
					keywords.Title + " ");
			
				if(arg[0] == '#' || arg[0] == '$') {
					arg = arg.erase(0, 1);
					
					if(arg.length() > 1)
						arg.pop_back();
					
					const char* env = getenv(arg.c_str());
					
					if(env != NULL)
						arg = STR(env);						
				} else arg.pop_back();
				
				SetTitleAs(arg);
			}
			return;
		} else if(arg.rfind(keywords.RemoveFile, 0) == 0) {
   	        /*  rmvfile
                rmvfile Scrift.cpp
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.RemoveFile + " ");
            
            arg.pop_back();
            removefile->DeleteFile(arg);
            
            return;
        } else if(arg.rfind(keywords.SquareofNumber, 0) == 0) {
            /*  square
                Calculate square
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.SquareofNumber + " ");
   		    
            arg.pop_back();

            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), 
            std::to_string(atoi(arg.c_str()) * atoi(arg.c_str())).c_str());

            std::cout << "\n";
            
            return;
        } else if(arg.rfind(keywords.SquareRootofNumber, 0) == 0) {
            /*  sqrt
                Calculate square root
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.SquareRootofNumber + " ");
            
            arg.pop_back();
   		
            /* If statement */
            if(atoi(arg.c_str()) <= - 1) 
                std::cout << "Hmm.";
            else
                colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), 
            
            std::to_string(sqrti(atoi(arg.c_str()))).c_str());

            std::cout << "\n";
                
            return;
        } else if(arg == keywords.Clear_History + "\n") {
      		/*  rmvhistory
                Erase history file
            */
            history->ClearHistory();
            
            return;
        } else if(arg == keywords.History + "\n") {
        	/*  history
                Show history file.
            */
            readfilefunction->ReadHistoryFileFunction();
            
            return;
        } else if(arg == keywords.ClearLog + "\n") {
            /*  clear_log
                Clear FeLog
            */
            logsystem->WriteLog("Launching ClearLog function.. - ");
       		logsystem->ClearLog();
       		std::cout << "Done.\n";
            
            return;                       
        } else if(arg.rfind(keywords.Factorial, 0) == 0) {
          	/*  fact
                fact 4

                Calculate factorial 
            */
            if(arg == keywords.Factorial + "\n") {} else { 
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Factorial + " ");

                arg.pop_back();

          	    if(atoi(arg.c_str()) < 0)
			        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), 
                        "n must be > or = to 0");
          	    else
			        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), 
                
                std::to_string(factorial(atoi(arg.c_str()))).c_str());
            }

            std::cout << "\n";
            
            return;
    	} else if(arg == keywords.Clear_Settings + "\n") {
          	/*  rmvsettings
                Erase settings file.
            */
            std::unique_ptr<FClearFileFunction> clearfile(new FClearFileFunction);
          	clearfile->ClearSettingsFunction();
            
            return;
        } else if(arg == keywords.Settings + "\n") {
        	/*  settings
                Show settings
            */
            readfilefunction->ReadSettingsFunction();
            
            return;
        } else if(arg.rfind(keywords.LanguageTemplate, 0) == 0) {
            /*  template test.fls
                Create 'Hello, language' template.
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.LanguageTemplate + " ");
                
            arg.pop_back();

        	temp.LangTemplate(arg);
                
            return;
        } else if(arg.rfind(keywords.RandomizeString, 0) == 0) {
        	/*  rstr
                rstr 12
                Create and print randomize string
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.RandomizeString + " ");
                
            arg.pop_back();
            main_->_generated_hash_string(atoi(arg.c_str()));
            std::cout << "\n";
                
            return;
        } else if (arg == keywords.Home + "\n") {
        	/*  home
                Change directory as HOME environment
            */
            homefunction->GetHome();

            return;
        } else if(arg.rfind(keywords.AddText, 0) == 0) {
            /*  addtext      
                Append string to file
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.AddText + "\n");
        	
            fileaddtextfunction->AppendLine(arg);
        } else if(arg.rfind(keywords.Emoji, 0) == 0) {
       		/*  emoji
                emoji :thinking_face:
                        
                Print emoji.
            */
            if(arg == keywords.Emoji + "\n") {} else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Emoji + " ");
                
                arg.pop_back();
                std::cout << emojiplusplus::EmojiString(arg) << "\n";
            }
            
            return;
        } else if(arg.rfind(keywords.CreateText, 0) == 0) {
            /*
                TODO: Fix seg. fault.
            */
        	
            /*  ctxt
                ctxt hello
                Create text file
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.CreateText + " ");
            
            arg.pop_back();
            filefunction->CreateFileFunctionInit(arg);
            
            return;
        } else if(arg == keywords.FeLog + "\n") {
          	/* felog
                Show FeLog
            */
        	logsystem->WriteLog("Launching felog function.. - ");
        	readfilefunction->ReadFeLogFunction();
            
            return;
        }  /* else if(arg == keywords.Create) {
        	Use template.
        	filefunction->CreateScriftFile(arg);
        } */ else if(arg == keywords.KName + "\n") {
        	/*  kname
                Show kernel name
            */
            std::cout << main_->FName() << "\n";
            
            return;
        } else if(arg == keywords.Config + "\n") {
            /*  config
                Configure .scrift_settings file.
            */
            setup->Config();
        
            return;
        } else if(arg == keywords.GitLink + "\n") {
        	/*  gitlink
                Show project's GitHub link
            */
            helpstr->GitLink();
            
            return;
        } else if(arg == keywords.Username + "\n") {
		    /*  username
                Show username
            */
		    FGetUsername userhostname;
            BOLD_LIGHT_MAGENTA_COLOR
		    userhostname.InitUsername();
		    std::cout << "\n";
            BLACK_COLOR
                
            return;
        } else if(arg == keywords.Pause + "\n") {
        	/*  pause
                Wait for enter key input.
            */
            BOLD_BLUE_COLOR
        	std::cout << "Press enter to continue.";
        	
            returni:if(std::cin.get() == '\n') {
                	BOLD_GREEN_COLOR
                    std::cout << "Access - \n";
                    BLACK_COLOR
                } else
                	goto returni;
                
            return;
    	} if(arg.rfind(keywords.DeleteText, 0) == 0) {
        	/*  deletetext
                Remove text file
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.DeleteText + " ");
            
            fileaddtextfunction->DeleteLine(arg);
            return;
    	} else if(arg == keywords.Welcome + "\n") {
            /*  welcome
                Show welcome function
            */
      	  	helpstr->Welcome();
            
            return;                        
        } else if(arg == keywords.Contr + "\n") {
            /*  contr
                Show contributors
            */
		    FContributors contributors_lists;
        	contributors_lists.AllOfThem();
            slashn
            
            return;
        } else if(arg == keywords.Now + "\n") {
        	/*  now
                Show current time
            */
            BOLD_LIGHT_WHITE_COLOR
    		std::cout << main_function->Time() << "\n";
    		BLACK_COLOR
            
            return;                    
    	} else if(arg == keywords.IP + "\n") {
          	/*  ip
                Show local IP address
            */
            main_->getIPAddress();
            
            return;
        } else if(arg == keywords.Morse + "\n") {
     		/*  morse
                String-Morse to Morse-String generator
            */
		    EasyMorse::MainMorse();
            
            return;
        } else if(arg == keywords.MyASCIIArt + "\n") {
     		/*  asciiart
                Show ASCII Art
            */
     		readfilefunction->ReadASCIIFunction();
            
            return;
        } else if(arg == keywords.Uninstall + "\n") {
    		/*  uninstall
                Remove Scrift from PC
            */
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
        	} else
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "\nAborted.\n");
    	
            return;    
        } else {
        	FInstall _run;
            _run.Check(arg);
        }
}

/*
	Input && Interpreter.
*/
void InputFunction() {
    setlocale(LC_ALL, "");
    if(scrift_line >= runsyntax->Clear()) {
        std::cout << "\033c";
        terminalstr->Terminal();
        scrift_line = 0;
    }

	/* Foreground color */
	textbackground(runsyntax->BackgroundColor());
	std::string sign;
    struct termios t;
    int c;
    tcgetattr(0,&t);
    t.c_lflag&=~ECHO+~ICANON;
    tcsetattr(0,TCSANOW,&t);
    fflush(stdout);
    c = getchar(); /* Input per key */
    t.c_lflag|=ICANON+ECHO;
    tcsetattr(0,TCSANOW,&t);

    /* Cursor position */
    cursorpos.x = main_function->_h_str.length();

    /* Backspace, Enter detection. */
    if(c == BACKSPACE) {
	    if(cursorpos.x >= 1) {
		    cursorpos.x -= 1;
			// Under the Construction
     		main_function->_h_str.erase(main_function->_h_str.end() - 1);
     		std::cout << '\b' << " " << '\b';
		} else {}
		
        return;
    } else
        	main_function->_h_str.push_back(c);

	sign.push_back(c);

    if(kbhit()) {
        if(c == ARROW_RIGHT) {
     	    std::cout << "\033[1C";
     	    cursorpos.x += 1;
        } else if(c == ARROW_LEFT) {
     	    if(cursorpos.x >= 2) {
	            std::cout << "\033[1D";
	            cursorpos.x -= 1;
	        } else
	            return;        
	    }
    } 
    
    if(c == 32) {
		//printlnf(" ");
		space++;
	}
    
    if(c == '\n') {
		space = 0;
		input_value++;
        scrift_line++;
		cursorpos.x = 0;
		slashn
			
        if(main_function->_h_str != "\n")
            CodeExecution(main_function->_h_str);
                        
        main_function->_h_str.erase();
        terminalstr->Terminal();
        	
        return;
    } else {
		/* Color scheme option (Different with terminal's color.) */
        if(runsyntax->Theme() == "default")
			Space(space, sign, 0);
	    else if(runsyntax->Theme() == "classic")
	       	Space(space, sign, 1);
	    else if(runsyntax->Theme() == "halloween")
	    	Space(space, sign, 2);
	    else
	  	    Space(space, sign, 0);
	       		
        cursorpos.x += 1;
        
    	return;
    }
        
    sign.erase();
}

void
FMain::Shell() {
    readfilefunction->ReadFeLogFunctionWithoutPrint();
    InputFunction();
}

int main(integer argc, char** argv) {
    std::string copy_arg, reg; /* Get arg. */
    setlocale(LC_ALL, ""); /* Locale */

    /* Happy new year! */
    if(main_function->Time().substr(4, 6) == "-01-01") {
    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "Happy new year!");
    	std::cout << " " << emojiplusplus::EmojiString(":balloon:") << " - ";
    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "Scrift\n");
    }

    /*
	Copy.
    */
    if(argc > 1) {
	    for(int i = 1; i < argc; i++) {
		    std::string arg(argv[i]);
		    reg = argv[1];
		    copy_arg = arg;
	    }
    } else {
    	filefunction->CreateSettingsFileFunction(); /* Directory is "/home/<username>/<dot>scrift_settings" */

    	logsystem->AllofThem(); /* FeLog start signal. */

	    /* Customization & Setup instruction. */
	    if(runsyntax->Setup() == true) {
		    /* ExecutePlusPlus exec; */
		    setup->Config();
	    }

        if(runsyntax->Date() == true)
            date_tools->Date();

	    if(runsyntax->ASCIIColor() == -1) {} else {
    		std::unique_ptr<FASCIIFunction> ascii(new FASCIIFunction);
    		ascii->Allofthem();
	    }

		/* Welcome <username> (emoji) */
	    if(runsyntax->WelcomeMessage() == 1 || runsyntax->WelcomeMessage() == 2)  
	    	PrintUsername();

	    /* History start signal */
    	history->AllofThem();

	    /* Welcome message. */
	    if(runsyntax->WelcomeMessage() == 1) {
		    logsystem->WriteLog("Launching Welcome() function.. - ");
		    helpstr->Welcome();
	    }

	    /* Terminal. */
	    terminalstr->Terminal();

	    /* Dynamic titles. */
	    main_function->SetTitle();
    	while(argc = 2) {
	        /* InputFunction() */
    	    main_function->Shell();
    	}
	    
        /* Exit. */
    	history->WriteAllHistory();
    }

    if(reg.substr(0, 2) == "--") {
	    if(strstr(reg.c_str(), "--b")) /* Interpreter for Scrift's language. */
		    scriftlang->ReadFunc(copy_arg + ".scr");
	    else if(reg == "--help" || reg == "--h") { /* Print HelpFunction() */
		    BOLD_RED_COLOR
		    helpstr->HelpFunction();
		    BLACK_COLOR
		
            exit(EXIT_SUCCESS); /* exit */
	    } else if(reg == "--version" || reg == "--v") { /* Print Scrift's Version */
    		PrintVersion();
		    exit(EXIT_SUCCESS); /* exit */
	    }
    }

    return F_OK;
}
