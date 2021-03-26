/* MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdarg>
#include <thread>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>

#ifndef __FreeBSD__
	#include <sys/sysinfo.h>
#endif

/* Source */
#include <src/Syntax/CommandFunc.hpp> /* For rstr, printlnf etc. */
#include <src/Scrift.hpp> /* Scrift main */
#include <src/Keywords/ScriftKeywords.hpp> /* Shell keywords */
#include <src/synflang.hpp> /* Some definitions */
#include <src/Syntax/Log.hpp> /* FeLog */
#include <src/Syntax/FileFunction.hpp> /* All file I/O functions, variables. */
#include <src/Syntax/HelpFunction.hpp> /* HelpFunction(), Welcome() etc. */
#include <src/Syntax/GetNameFunction.hpp> /* Terminal */
#include <src/Syntax/RunFunction.hpp> /* Command execution */
#include <src/Syntax/ASCIIFunction.hpp> /* ASCII */
#include <src/Syntax/Contributors.hpp> /* Contributors etc. */
#include <src/Syntax/Settings.hpp> /* Settings */
#include <src/Syntax/History.hpp> /* History */
#include <src/Syntax/Template.hpp> /* 'Hello world' example for a lot of languages */
#include <src/Syntax/Setup.hpp> /* Scrift Configuration & Setup */
#include <src/Syntax/Tools.hpp>
#include <src/Syntax/Locale.hpp>
#include <src/Syntax/Alias.hpp>
#include <src/Syntax/Validation.hpp>


// Libraries
#include <EmojiPlusPlus.h> /* Emoji? */
#include <Colorized.hpp> /* Color library */
#include <EasyMorse.hpp> /* Morse-String to String-Morse converter library. */
#include <ExecutePlusPlus.hpp> /* Command execution library */
#include <FileSystemPlusPlus.h> /* File I/O library. */
#include <StringTools.h> /* Functions for STL String */

/* FileFunction namespace */
using namespace FileFunction;

// Variables
const std::string compilation_time = __TIME__;

/* Definitions */
#define ESC 033

/* For Environment */
static std::string SetNameToString, 
                   SetNameString,
                   previous_command;
char c;
bool incognito = false;

static struct termios oldtio,
                      newtio;
 
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
std::unique_ptr<FHistory> history(new FHistory);
std::unique_ptr<FHelpFunction> helpstr(new FHelpFunction);
std::unique_ptr<FSetup> setup(new FSetup);
std::unique_ptr<FTools> date_tools(new FTools);
std::unique_ptr<FLocale> set_locale(new FLocale);
std::unique_ptr<FAlias> alias(new FAlias);
std::unique_ptr<FValidation> validation(new FValidation);

/* Structures */
std::unique_ptr<faddtextfunction> fileaddtextfunction(new faddtextfunction);
std::unique_ptr<fhomefunction> homefunction(new fhomefunction);

/* Keywords */
ScriftKeywords keywords;
FTemplate temp;


unsigned line = 0;

/*
	Get username.
*/

uid_t fuid = geteuid();
struct passwd *pass = getpwuid(fuid);

typedef struct CursorPos {
    int x = 0;
} cursorp;

cursorp cursorpos;

FMain::FMain() = default;


FMain::~FMain() = default;

int space = 0, input_value = 0, scrift_line = 0;

std::string ftime(compilation_time); // Convert

std::string VersionGenerator() {
    return "scriftv" + stringtools::EraseAllSubString(ftime, ":");
}

/* For input colorizing */
void Space(int space, const std::string& sign, unsigned theme) {
    if(theme == 1) /* Classic (White & Black) theme */
        colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_WHITE), sign.c_str());
    else if(theme == 2) { /* Halloween theme */
		RESETW
        if(space % 2) printfc({255, 154, 0}, sign);
        else if(space % 3) printfc({247, 95, 28}, sign);
        else printfc({0, 0, 0}, sign);
	} else /* Colorized theme */
        if(space == 1 || space % 1)      colorized::PrintWith(colorized::Colorize(BOLD, RED), sign.c_str());
        else if(space % 2 || space == 2) colorized::PrintWith(colorized::Colorize(BOLD, MAGENTA), sign.c_str());
        else if(space % 3 || space == 3) colorized::PrintWith(colorized::Colorize(BOLD, BLUE), sign.c_str());
        else if(space % 4 || space == 4) colorized::PrintWith(colorized::Colorize(BOLD, YELLOW), sign.c_str());
        else if(space % 5)               colorized::PrintWith(colorized::Colorize(BOLD, GREEN), sign.c_str());
        else if(space % 6 || space == 6) colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), sign.c_str());
        else if(space % 7 || space == 7) colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN), sign.c_str());
        else if(space % 7 || space == 7) colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), sign.c_str());
        else if(space == 0)
            std::cout << WBOLD_CYAN_COLOR << sign << WBLACK_COLOR;
}

void PrintVersion() {
    BOLD_MAGENTA_COLOR
    std::cout << "Fegeya Scrift Version: ";
    	
    /* Version */
    BOLD_GREEN_COLOR
    std::cout << SCRIFT_VERSION;
    
	/* - */
    BOLD_YELLOW_COLOR
    printhyphen // printlnf("-");
    
    /* Status */
    BOLD_CYAN_COLOR
    std::cout << SCRIFT_STATUS;
    
    /* - */
    BOLD_BLUE_COLOR
    printhyphen // printlnf("-");
    
    /* VersionGenerator */
    BOLD_MAGENTA_COLOR
    std::cout << VersionGenerator();
    	
    /* Newline */
    slashn
    
    /* Copyright */
    BOLD_RED_COLOR
    std::cout << "Copyright (c) " << COPYRIGHT_YEAR << " ";

    /* Author */
    BOLD_BLUE_COLOR
    std::cout << "Ferhat Geçdoğan ";
    	
    BOLD_YELLOW_COLOR
    std::cout << "All Rights Reserved. \n";
    
    BOLD_CYAN_COLOR
	std::cout << "Distributed under the terms of the MIT License.";
	BLACK_COLOR

    slashn
}

/* Square root converter. */
int sqrti(int x) {
    union { float f; int x; } v{};

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

/* For 'Happy new year' */
std::string FMain::Time() {
    // return "2020-01-01-12:34:67:00"; For Test.
    time_t     now = time(nullptr);
    struct tm  tstruct{};
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/* Read specific line from history */
std::string GetSpecificHistoryLine(unsigned line) {
	std::ifstream history_file(STR(getenv("HOME")) + STR("/.scrift_history"));
	
	unsigned _line = 0;
	
	std::string data;
	
	while(getline(history_file, data)) {
		if(line == _line) {
			return data;
		}
		
		_line++;
	}

	history_file.close();
	return data;
}

unsigned GetTotalHistoryLine() {
	std::ifstream history_file(STR(getenv("HOME")) + STR("/.scrift_history"));
	
	std::string line;
	unsigned i;
	for (i = 0; std::getline(history_file, line); ++i)
    ;

	history_file.close();    
    return i;
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
    std::cout << WBMAGENTA
              << "Welcome "
              << WBCYAN
              << pass->pw_name
              << WBBLUE
              << " "
              << emojiplusplus::EmojiString(runsyntax->FWelcomeEmoji());

    BLACK_COLOR
}


/* TODO:
	- Use TimePlusPlus library.
	
	Uptime.
*/
std::string GetUptime() {
	#ifdef __FreeBSD__
		return "null";
	#else
	
    double uptime, uptimeMinutes, uptimeHour, uptimeDay;
	int uptimeMinutesWhole, uptimeHourWhole, uptimeDayWhole;
	
    std::string uptimeString;
	std::stringstream uptimeStream;
	
    struct sysinfo info{};
	
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

/* TODO:
   * Use StringTools::Find()
*/
void CodeExecution(std::string arg, slocale_t &locale) {
    std::string command = stringtools::GetFirstArg(arg);

    if(command == keywords.Scr) {
        /*  scr
            scr echo hello
            Use Non-Scrift commands without conflict
        */
        arg = stringtools::EraseAllSubString(arg,
            keywords.Scr + " ");
        
        runfunction->RunFunction(arg);
        return;
    } else if(command == keywords.Printlnf){
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
            
            main_->echo_printlnf(arg);
        }
        
        std::cout << "\n";
        return;
        } else if(command == keywords.Echo) {
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

                main_->echo_printlnf(arg);
            }
            
            std::cout << "\n";
            return;
        } else if(command == keywords.Fpi) {
		    /* 
                fpi --i || --install
                fpi --uni || --uninstall
            */
            std::cout << "Fpi is deprecated, use 'fpm' instead.\n";
            
            if(!fsplusplus::IsExistFile("/bin/fpm")) {
            	std::cout << "Oops! Fpm is not to be installed!\n";
            }
            
            return;
	    } else if(command == keywords.FreeBrainGen) {
            /* genfrbr
                genfrbr 3
                        
                Generate ASCII code for FreeBrain.
            */
            if(arg == keywords.FreeBrainGen) {} else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.FreeBrainGen + " ");
                                
                if(atoi(arg.c_str()) < 1)
                    /* Add negative value generator */
                    std::cout << "~";
                else
                    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE),
                        (AsciiGenFreeBrain(atoi(arg.c_str()))) + "\n");
            }
            
            return;
        } else if(command == keywords.Fr + " ") {
            /*  fr
                fr /home
                fr ../../
                fr src

                Forward dir. Same as 'cd'
            */
            if(arg == keywords.Fr + " --h\n")
                std::cout << "Usage: fr path || dir\n";
            else if(arg == keywords.Fr || arg == keywords.Fr + " #\n") {}
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Fr + " ");
                
                cdfunction->CDFunctionInit(arg, locale);
            }
            
            return;
        } else if(command == keywords.Cd) {
            /*  cd
                cd /home
                cd ../../
                cd src

                Change dir. Same as 'fr'
            */
            if(arg == keywords.Cd + " --h\n")
          	    std::cout << "Usage: cd path || dir\n";
            else if(arg == keywords.Cd || arg == keywords.Cd + " #\n") {}
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Cd + " ");


                cdfunction->CDFunctionInit(arg, locale);
            }
            
            return;
        } else if(command == keywords.RunDotSlash) {
            /*  ./
                ./make.scr 
                ./scrift 
                
                Command execution 
            */
            if(arg == keywords.RunDotSlash) {
                colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED),
                    "scrift : ./ : Is a directory.\n");
            } /*else if(strstr(arg.c_str(), ".scr")) {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.RunDotSlash);

                scriftlang->ReadFunc(arg);
            } */else
                runfunction->RunFunction(arg);
                
            return;
        } else if(arg == keywords.Back) {
          	/*  back
                Same with fr || cd ..  

                Go to the previous directory. 
            */
        	
        	std::string path_string(main_->_file_path_cd_function);
        	std::size_t test = path_string.find_last_of("/\\");
        	std::string test_string = path_string.substr(0, test);

        	if(test_string.empty())
        		test_string.append("/");
        	
        	main_->_file_path_cd_function = test_string;

        	chdir(test_string.c_str());
		    main_function->SetTitle();
            
            path_string.erase();
            test_string.erase();
            
            return;
        } else if(command == keywords.Lsf) {
            /*  fls
                fls
                fls src 
                
                List only files.
            */
    		if(arg == keywords.Lsf)
          		main_->list_file(true, ".");
          	else if(arg == keywords.Lsf + " --h\n")
                std::cout << "Usage: fls || fls path\n";   
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Lsf + " ");
                
			    main_->list_file(true, arg);
          	}
            
            return;  
    	} else if(command == keywords.Lsd) {
            /*  dls
                dls
                dls src 

                List only directories.
            */ 
         	if(arg == keywords.Lsd)
          		main_->list_direc(true, ".");
          	else if(arg == keywords.Lsd + " --h\n")
                std::cout << "Usage: dls || dls path\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Lsd + " ");

          		main_->list_direc(true, arg);
          	}
            
            return;
        } else if(arg == keywords.LsObject) {
            /*  objls
                List /bin/
            */
    		
            listdirectoryfunction->ListObjectFunction();
            return;
    	} else if(command == keywords.Find) {
          	/*  ffind
                ffind sr

                Find file & folder on current directory
            */
            if(arg == keywords.Find) {} else {
                FFindFileFunction find;
                arg = stringtools::EraseAllSubString(arg, keywords.Find + " ");

   		        find.FindFile(arg);
            }
            
            return;
        } else if(command == keywords.Output) {
            /*  output
                output <command>

                Get output of inputted command
            */
            if(arg == keywords.Output) {}
            else {
                ExecutePlusPlus exec;
                arg = stringtools::EraseAllSubString(arg, keywords.Output + " ");
                std::cout << exec.ExecWithOutput(arg);
            }

            return;
        } else if(arg == keywords.Close ||
            arg == keywords.Exit)  {
            /*  close, exit
                Exit.
            */
        	arg.erase();
          	
            exit(EXIT_SUCCESS);
        } else if(arg == keywords.Ls) {
            /*  ls
                ls 
                ls 

                List
            */
          	
          	listdirectoryfunction->LSFunction(".");
            return;
        } else if(command == keywords.Ls) {
            /*  ls
                ls 
                ls src

                List
            */
          	
            /*if(arg == keywords.Ls)
          		listdirectoryfunction->LSFunction(".");
                else 
            */
            
            if(arg == keywords.Ls + " --h\n")
                std::cout << "Usage: ls || ls path\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Ls + " ");
                
          		listdirectoryfunction->LSFunction(arg);
          	}
            
            return;                  
        } else if(command == keywords.Scrift) {
            /*  fscrift
                fscrift make 
                fscrift make.scr

                ScriftSL interpreter.

        	if(arg == keywords.Scrift || arg == keywords.Scrift + " --h\n") {
                std::cout << "Usage: fscrift file | file.scr\n";
            } else if(strstr(arg.c_str(), ".scr")) {
                arg = stringtools::EraseAllSubString(arg.erase(0, 7), " ");
                scriftlang->ReadFunc(arg);
            } else {
                arg = stringtools::EraseAllSubString(arg.erase(0, 7), " ");
                scriftlang->ReadFunc(arg + ".scr");
            }
            */
            std::cout << "Work-in-progress\n";

            return;
        } else if(command == keywords.MKDir) {
        	/*  mkdir
                mkdir scrift
                Create directory
            */
            if(arg == keywords.MKDir) {} else {
                if(arg == keywords.MKDir + " --h\n")
                    std::cout << "Usage: mkdir dir\n";
                else {
                    arg = stringtools::EraseAllSubString(arg,
                        keywords.MKDir + " ");
                        
                    mkdirfunction->MKDirFunctionInit(arg);
                }
            }

            return;
   	    } else if(command == keywords.Resolution) {
   	        /* res
   	           res file.(jpg, png)

               Resolution size information tool.
            */

            arg = stringtools::EraseAllSubString(arg, keywords.Resolution + " ");

            date_tools->ResolutionSizeInfo(arg);

            return;
   	    } else if(command == keywords.ReadText) {
		    /*  readtext
                readtext file
                        
                Implementation of 'cat'.
            */
            if(arg == keywords.ReadText ||
                arg == keywords.ReadText + " --h\n")
                std::cout << "Usage: readtext file\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.ReadText + " ");
            
          	    readfilefunction->ReadFileFunction(arg);
            }

            return;
	    } else if(command == keywords.SetName) {
		    /*  setname
                setname home_path

                Set environment name
            */
            if(arg == keywords.SetName ||
                arg == keywords.SetName + " --h\n")
                std::cout << "Usage: setname environment_name\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.SetName + " ");
                
                SetNameString = arg;
            }

            return;
        } else if(command == keywords.SetTo) {
		    /*  setto
                setto /home/ferhatgec/

                Set environment value
            */
            if(arg == keywords.SetTo ||
                arg == keywords.SetTo + " --h\n")
                std::cout << "Usage: setto environment_value\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.SetTo + " ");
                
		        SetNameToString = arg;
    		    setenv(SetNameString.c_str(), SetNameToString.c_str(), true);
            }

            return;
        } else if(command == keywords.Alias) {
            /* alias
               alias a='echo aaa'
               
               Set or change alias
            */
            if(arg == keywords.Alias) {
                readfilefunction->ReadAliasFunction();
            } else if(arg == keywords.Alias + " --h") {
                std::cout << "Usage: alias name='command'\n";
            } else {
                arg = stringtools::EraseAllSubString(arg, keywords.Alias + " ");
                
                std::string name, replacement;
                
                for(unsigned i = 0; arg[i] != '\0'; i++) {
                    if(arg[i] != '=') {
                        name.push_back((char)arg[i]);
                    } else {
                        break;
                    }
                }
                
                replacement = stringtools::GetBetweenString(arg, 
                    name + "='", "'");

                alias->AddAlias(name, replacement);
            }
            
            return;
        } else if(command == keywords.Random) {
            /*  random
                random 15 

                pseudo random integer generator (rand) 
            */
            if(arg == keywords.Random + " --h\n"
                || arg == keywords.Random)
                
                std::cout << "Usage: random number\n";
            else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Random + " ");

                // TODO: Use C++11's random library.
                std::cout << rand()%(atoi(arg.c_str())+1);
            }

            return;
    	} else if(arg == keywords.Help) {
        	/*  helpss
                List all commands.
            */
            helpstr->HelpFunction(locale);
            
            return;
        } else if(arg == keywords.Version)  {
            /*  version
                Show Scrift's version.
            */
            PrintVersion();
            
            return;
        } else if(arg == keywords.Previous) {
            /* !!
               Get & execute previous command
            */
            if(previous_command.empty()) {
                std::cout << previous_command << "\n";

                CodeExecution(previous_command, locale);
            }

            return;
        } else if(arg == keywords.Uptime) {
            /*  uptime
                Show uptime
            */
		    colorized::PrintWith(colorized::Colorize(BOLD, BLUE),
                (GetUptime()).c_str());
            
            std::cout << "\n";
            
            return;
    	} else if(arg == keywords.Clear) {
      	  	/*  clear
                Clear terminal buffer
            */
            scrift_line = 0;
            std::cout << "\033c";
            
            return;
        } else if(command == keywords.Title) {
			/* title
				title Hello, terminal.

				Change title of terminal header bar (or titlebar)
			*/
			
			/* TODO:
				Support environments..
			*/
				
			if(arg != keywords.Title) {
				arg = stringtools::EraseAllSubString(arg, 
					keywords.Title + " ");
			
				if(arg[0] == '#' || arg[0] == '$') {
					arg = arg.erase(0, 1);
					
					const char* env = getenv(arg.c_str());
					
					if(env != nullptr)
						arg = STR(env);						
				}
				
				SetTitleAs(arg);
			}
			return;
		} else if(command == keywords.RemoveFile) {
   	        /*  rmvfile
                rmvfile Scrift.cpp
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.RemoveFile + " ");

            removefile->DeleteFile(arg);
            
            return;
        } else if(command == keywords.SquareofNumber) {
            /*  square
                Calculate square
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.SquareofNumber + " ");

            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA),
            std::to_string(atoi(arg.c_str()) * atoi(arg.c_str())).c_str());

            std::cout << "\n";
            
            return;
        } else if(command == keywords.SquareRootofNumber) {
            /*  sqrt
                Calculate square root
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.SquareRootofNumber + " ");
   		
            /* If statement */
            if(atoi(arg.c_str()) <= - 1) 
                std::cout << "Hmm.";
            else
                colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA),
            
            std::to_string(sqrti(atoi(arg.c_str()))).c_str());

            std::cout << "\n";
                
            return;
        } else if(arg == keywords.Clear_History) {
      		/*  rmvhistory
                Erase history file
            */
            history->ClearHistory();
            
            return;
        } else if(arg == keywords.History) {
        	/*  history
                Show history file.
            */
            readfilefunction->ReadHistoryFileFunction();
            
            return;
        } else if(arg == keywords.ClearLog) {
            /*  clear_log
                Clear FeLog
            */
            logsystem->WriteLog("Launching ClearLog function.. - ");
       		logsystem->ClearLog();
       		std::cout << "Done.\n";
            
            return;                       
        } else if(command == keywords.Factorial) {
          	/*  fact
                fact 4

                Calculate factorial 
            */
            if(arg == keywords.Factorial) {} else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Factorial + " ");

          	    if(atoi(arg.c_str()) < 0)
			        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED),
                        "n must be > or = to 0");
          	    else
			        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA),
                
                std::to_string(factorial(atoi(arg.c_str()))).c_str());
            }

            std::cout << "\n";
            
            return;
    	} else if(arg == keywords.Clear_Settings) {
          	/*  rmvsettings
                Erase settings file.
            */
            std::unique_ptr<FClearFileFunction> clearfile(new FClearFileFunction);
          	clearfile->ClearSettingsFunction();
            
            return;
        } else if(arg == keywords.Settings) {
        	/*  settings
                Show settings
            */
            readfilefunction->ReadSettingsFunction();
            
            return;
        } else if(command == keywords.LanguageTemplate) {
            /*  template test.fls
                Create 'Hello, language' template.
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.LanguageTemplate + " ");

        	temp.LangTemplate(arg);
                
            return;
        } else if(command == keywords.RandomizeString) {
        	/*  rstr
                rstr 12
                Create and print randomize string
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.RandomizeString + " ");

            main_->_generated_hash_string(atoi(arg.c_str()));
            std::cout << "\n";
                
            return;
        } else if (arg == keywords.Home) {
        	/*  home
                Change directory as HOME environment
            */
            homefunction->GetHome();

            return;
        } else if(command == keywords.AddText) {
            /*  addtext      
                Append string to file
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.AddText);
        	
            fileaddtextfunction->AppendLine(arg);
        } else if(command == keywords.Emoji) {
       		/*  emoji
                emoji :thinking_face:
                        
                Print emoji.
            */
            if(arg == keywords.Emoji) {} else {
                arg = stringtools::EraseAllSubString(arg,
                    keywords.Emoji + " ");

                std::cout << emojiplusplus::EmojiString(arg) << "\n";
            }
            
            return;
        } else if(command == keywords.CreateText) {
            /*
                TODO: Fix seg. fault.
            */
        	
            /*  ctxt
                ctxt hello
                Create text file
            */
            arg = stringtools::EraseAllSubString(arg,
                keywords.CreateText + " ");
            
            filefunction->CreateFileFunctionInit(arg);
            
            return;
        } else if(command == keywords.Incognito) {
        	if(arg == keywords.Incognito) {
        		incognito = true;
        	} else {
        		arg = stringtools::EraseAllSubString(arg, keywords.Incognito + " ");

        		if(arg == "on") {
        			incognito = true;
        		} else if(arg == "off") {
        			incognito = false;
        		}
        	}
        	
        	return;
        } else if(arg == keywords.FeLog) {
          	/* felog
                Show FeLog
            */
        	logsystem->WriteLog("Launching felog function.. - ");
        	readfilefunction->ReadFeLogFunction();
            
            return;
        }  /* else if(arg == keywords.Create) {
        	Use template.
        	filefunction->CreateScriftFile(arg);
        } */ else if(arg == keywords.KName) {
        	/*  kname
                Show kernel name
            */
            std::cout << main_->FName() << "\n";
            
            return;
        } else if(arg == keywords.Config) {
            /*  config
                Configure .scrift_settings file.
            */
            setup->Config();
        
            return;
        } else if(arg == keywords.GitLink) {
        	/*  gitlink
                Show project's GitHub link
            */
            helpstr->GitLink();
            
            return;
        } else if(arg == keywords.Username) {
		    /*  username
                Show username
            */
		    FGetUsername userhostname;
            BOLD_LIGHT_MAGENTA_COLOR
		    userhostname.InitUsername();
		    std::cout << "\n";
            BLACK_COLOR
                
            return;
        } else if(arg == keywords.Pause) {
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
    	} else if(arg == keywords.Welcome) {
            /*  welcome
                Show welcome function
            */
      	  	helpstr->Welcome();
            
            return;                        
        } else if(arg == keywords.Contr) {
            /*  contr
                Show contributors
            */
		    FContributors contributors_lists;
        	contributors_lists.AllOfThem();
            slashn
            
            return;
        } else if(arg == keywords.Now) {
        	/*  now
                Show current time
            */
            BOLD_LIGHT_WHITE_COLOR
    		std::cout << main_function->Time() << "\n";
    		BLACK_COLOR
            
            return;                    
    	} else if(arg == keywords.IP) {
          	/*  ip
                Show local IP address
            */
            main_->getIPAddress();
            
            return;
        } else if(arg == keywords.Morse) {
     		/*  morse
                String-Morse to Morse-String generator
            */
		    EasyMorse::MainMorse();
            
            return;
        } else if(arg == keywords.MyASCIIArt) {
     		/*  asciiart
                Show ASCII Art
            */
     		readfilefunction->ReadASCIIFunction();
            
            return;
        } else if(arg == keywords.Uninstall) {
    		/*  uninstall
                Remove Scrift from PC
            */
            std::string option;
        	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), "Remove with tools? (Fetcheya, Edifor etc.) : ");
        	BOLD_CYAN_COLOR
        	std::cin >> option;
        	BLACK_COLOR
        	
            if(option == "y" || option == "Y") {
        		system("sudo rm -f /bin/fetcheya");
  			    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), "Fetcheya has been removed.\n");
        		system("sudo rm -f /bin/edifor");

        		system("sudo rm -f /bin/scrift");
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE), "Note: Select a shell and restart, because Scrift has been deleted\n");
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN), "Goodbye!\n");
        	} else if(option == "n" || option == "N") {
        		system("sudo rm -f /bin/scrift");
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_CYAN), "Note: Select a shell and restart, because Scrift has been deleted\n");
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN), "Goodbye!\n");
        	} else
        		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "\nAborted.\n");
    	
            return;    
        } else {
			if(alias->Parse(arg) != "error") {
			    arg = alias->Parse(arg);
                CodeExecution(arg, locale);
            } else
                runfunction->RunFunction(arg);
        }
}

/*
	Input && Interpreter.
*/
void InputFunction(slocale_t &locale) {
    if(!fsplusplus::IsExistFile(STR(getenv("HOME")) + "/.scrift_settings")) setup->Config();
    	
    if(scrift_line >= runsyntax->Clear()) {
        std::cout << "\033c";
        terminalstr->Terminal(incognito);
        scrift_line = 0;
    }

	/* Foreground color */
	textbackground(runsyntax->BackgroundColor());
	std::string sign;
    
    tcgetattr(0, &oldtio);
    newtio = oldtio;
    newtio.c_lflag &= ~ICANON;
    newtio.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &newtio);
	fflush(stdout);
	c = getchar();

	if(c == 32) {
		space++;
		cursorpos.x += 1;
		std::cout << " " << std::flush;
		
		main_function->_h_str.append(" ");
	} else if(c == 127 || c == 8) {
	    if(main_function->_h_str.length() >= 1) {
			cursorpos.x -= 1;
		    main_function->_h_str.pop_back();

			std::cout << "\b \b" << std::flush;
     	}
    } else if(c == 27) {
        c = getchar();
        c = getchar();
            
		if(c == ARROW_UP) {
			if(line != 0) {
				line--;
			
				for(unsigned i = 0; i < main_function->_h_str.length(); i++) {
					std::cout << "\b \b" << std::flush;				
				}
				
				main_function->_h_str = GetSpecificHistoryLine(line);
				
				if(fsplusplus::IsExistFile("/bin/" + stringtools::GetFirstArg(main_function->_h_str))) {
					std::cout << WBOLD_GREEN_COLOR << main_function->_h_str;
				} else {
					std::cout << WBOLD_RED_COLOR  << main_function->_h_str;
				}
				
				BLACK_COLOR
			}
		}
		
		if(c == ARROW_DOWN) {
			if(line < GetTotalHistoryLine()) {
				line++;
			
				for(unsigned i = 0; i < main_function->_h_str.length(); i++) {
					std::cout << "\b \b" << std::flush;				
				}
				
				main_function->_h_str = GetSpecificHistoryLine(line);
			
				if(fsplusplus::IsExistFile("/bin/" + stringtools::GetFirstArg(main_function->_h_str))) {
					std::cout << WBOLD_GREEN_COLOR << main_function->_h_str;
				} else {
					std::cout << WBOLD_RED_COLOR   << main_function->_h_str;
				}
				
				BLACK_COLOR
			}
		}
		
		if(c == ARROW_LEFT) {
			//if(cursorpos.x >= 2) {
	        //    std::cout << "\033[1D";
	        //   cursorpos.x -= 1;
	        //}
		}
				
		if(c == ARROW_RIGHT) {
     	    //std::cout << "\033[1B";
     	    //cursorpos.x += 1;
		}
    } else if(c != 9) {
    	main_function->_h_str.push_back(c);
		sign.push_back(c);
		cursorpos.x += 1;
    }

	
    tcsetattr(0, TCSANOW, &oldtio);
	
    /* Cursor position */
    cursorpos.x = main_function->_h_str.length();
    
    if(c == '\n') {
		space = 0;
		input_value++;
        scrift_line++;
		cursorpos.x = 0;
		slashn
		
		/* Parse input */
		if(main_function->_h_str[0] == ' ') {
			main_function->_h_str = stringtools::ltrim(main_function->_h_str);
		}
		
        if(main_function->_h_str != "\n") {
            main_function->_h_str.pop_back();

            if(main_function->_h_str != "!!") {
                previous_command  = main_function->_h_str;
            }

            if(validation->Validate(main_function->_h_str) == WEBSITE) {
                /* TODO: Implement some of the xdg-utils */
                runfunction->RunFunction("xdg-open " + main_function->_h_str);

                BOLD_LIGHT_WHITE_COLOR
                std::cout << "Hmm, I guess '" + main_function->_h_str + "' was a website.\n";
                BLACK_COLOR
            } else {
                CodeExecution(main_function->_h_str, locale);
            
                if(!incognito)
                    history->WriteInHistory(main_function->_h_str + "\n");

			    line = GetTotalHistoryLine();
		    }
		}
		
        main_function->_h_str.erase();
        terminalstr->Terminal(incognito);
        	
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
}

void
FMain::Shell(slocale_t &locale) {
    InputFunction(locale);
}

int main(integer argc, char** argv) {
    std::string copy_arg, reg; /* Get arg. */
	slocale_t locale = set_locale->Set();
	
    /* Happy new year! */
    if(main_function->Time().substr(4, 6) == "-01-01") {
    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE), "Happy new year!");
    	std::cout << " " << emojiplusplus::EmojiString(":balloon:") << " - ";
    	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_YELLOW), "Scrift\n");
    }

    /*
	Copy.
    */
    if(argc > 1) {
	    for(int i = 1; i < argc; i++) {
		    std::string arg(argv[i]);
		    reg = argv[1];
        }
    } else {
    	filefunction->CreateSettingsFileFunction(); /* Directory is "/home/<username>/<dot>scrift_settings" */

    	logsystem->AllofThem(); /* FeLog start signal. */

	    /* Customization & Setup instruction. */
	    if(runsyntax->Setup()) {
		    /* ExecutePlusPlus exec; */
		    setup->Config();
	    }

        if(runsyntax->Date()) {
            date_tools->Date();
		}
		
	    if(runsyntax->ASCIIColor() != -1) {
    		std::unique_ptr<FASCIIFunction> ascii(new FASCIIFunction);
    		ascii->Allofthem();
	    }

		/* Welcome <username> (emoji) */
	    if(runsyntax->WelcomeMessage() == 1 || runsyntax->WelcomeMessage() == 2) {  
	    	PrintUsername();
		}
		
	    /* History start signal */
    	history->AllofThem();

        /* Get total line of history */
		line = GetTotalHistoryLine();
		
        /* Initialize aliases */
		alias->Init();

	    /* Welcome message. */
	    if(runsyntax->WelcomeMessage() == 1) {
		    logsystem->WriteLog("Launching Welcome() function.. - ");
		    helpstr->Welcome();
	    }

	    /* Get latest command from .scrift_history */
	    if(line > 1) {
	        previous_command = GetSpecificHistoryLine(line - 1);
        }

	    /* Terminal. */
	    terminalstr->Terminal(incognito);

	    /* Dynamic titles. */
	    main_function->SetTitle();
	    
    	while(argc) {
	        /* InputFunction() */
    	    main_function->Shell(locale);
    	}
    }

    if(reg.substr(0, 2) == "--") {
	    if(reg == "--help" || reg == "--h") { /* Print HelpFunction() */
		    BOLD_RED_COLOR
		    helpstr->HelpFunction(locale);
		    BLACK_COLOR
		
            exit(EXIT_SUCCESS); /* exit */
	    } else if(reg == "--version" || reg == "--v") { /* Print Scrift's Version */
    		PrintVersion();
		    exit(EXIT_SUCCESS); /* exit */
	    }
    }

    return F_OK;
}
