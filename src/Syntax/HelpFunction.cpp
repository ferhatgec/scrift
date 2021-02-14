/* MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>

#include <src/Scrift.hpp>
#include <src/synflang.hpp>
#include <src/Syntax/RunFunction.hpp>
#include <src/Syntax/CommandFunc.h>
#include <src/Syntax/HelpFunction.hpp>
#include <src/Syntax/Locale.hpp>

// Library
#include <Colorized.hpp>

#define PUT_COMMAND(color, command, description)                    \
    std::cout << color << " * " << command << WLIGHT_WHITE_COLOR << " : " << WBOLD_LIGHT_WHITE_COLOR << description; \
    RESETW

void
FHelpFunction::HelpFunction(slocale_t &locale) {
    BOLD_GREEN_COLOR
    std::cout << locale.header_help;
    
    BOLD_LIGHT_BLUE_COLOR 
    std::cout << locale.header_general; 
    
    PUT_COMMAND(WBOLD_CYAN_COLOR, "username       ", locale.cmd_username)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "config         ", locale.cmd_config)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "castle         ", locale.cmd_castle)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "gitlink        ", locale.cmd_gitlink)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "welcome        ", locale.cmd_welcome)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "contr          ", locale.cmd_contr)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "fscrift <file> ", locale.cmd_fscrift)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "clear_log      ", locale.cmd_clearlog)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "history        ", locale.cmd_history)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "rmvhistory     ", locale.cmd_rmvhistory)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "rmvsettings    ", locale.cmd_rmvsttngs)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "settings       ", locale.cmd_settings)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "fetcheya       ", locale.cmd_fetcheya)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "version        ", locale.cmd_version)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "now            ", locale.cmd_now)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "uptime         ", locale.cmd_uptime)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "asciiart       ", locale.cmd_asciiart)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "template       ", locale.cmd_template)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "fdate          ", locale.cmd_calendar)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "readtext <file>", locale.cmd_readtext)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "felog          ", locale.cmd_felog)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "edifor         ", locale.cmd_edifor)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "addtext <file> ", locale.cmd_addtext)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "ctxt <name>    ", locale.cmd_ctxt)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "pause          ", locale.cmd_pause)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "cls || exit    ", locale.cmd_cls)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "clear          ", locale.cmd_clear)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "ip             ", locale.cmd_ip)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "incognito      ", locale.cmd_incognito)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "res <file>     ", locale.cmd_res)
    PUT_COMMAND(WBOLD_CYAN_COLOR, "alias          ", "Set or change aliases.\n\n")
    
    BOLD_LIGHT_YELLOW_COLOR
    std::cout << locale.header_output; 
 
    PUT_COMMAND(WBOLD_GREEN_COLOR, "printlnf | echo <arg>", locale.cmd_echo)
    PUT_COMMAND(WBOLD_GREEN_COLOR, "output <command>     ", locale.cmd_output)
    PUT_COMMAND(WBOLD_GREEN_COLOR, "title <string>       ", locale.cmd_title) 
    PUT_COMMAND(WBOLD_GREEN_COLOR, "emoji <arg>          ", locale.cmd_emoji)
    
    BOLD_LIGHT_MAGENTA_COLOR
    std::cout << locale.header_execute;

    PUT_COMMAND(WBOLD_RED_COLOR, "scr <argument>  ", locale.cmd_scr)
    PUT_COMMAND(WBOLD_RED_COLOR, "fpm <arg> <pack>", locale.cmd_fpm)
    PUT_COMMAND(WBOLD_RED_COLOR, "!!              ", locale.cmd_previous)
    
    BOLD_LIGHT_RED_COLOR
    std::cout << locale.header_path;

    PUT_COMMAND(WBOLD_YELLOW_COLOR, "home                  ", "/home/<username>\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "create <name>         ", "Create <name>scr file\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "objls                 ", "List installed objects\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "fls                   ", "List only files (#<env>)\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "dls                   ", "List only folders (#<env>)\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "ls <folder>           ", "List dir (#<env>)\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "fr || cd <folder>     ", "Change dir (#<env>)\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "mkdir <foldername>    ", "Create folder\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "ffind <file, folder>  ", "Find files and directories in path\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "rmvfile <file, folder>", "Remove file, folder in path\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "setname <name>        ", "Set environment name\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "setto <value>         ", "Set environment value.\n")
    PUT_COMMAND(WBOLD_YELLOW_COLOR, "back                  ", "Going to back directory\n\n")
        
    BOLD_LIGHT_CYAN_COLOR
    std::cout << "[Generate]\n";

    PUT_COMMAND(WBOLD_LIGHT_MAGENTA_COLOR, "genfrbr <value>", "Generate FreeBrain keycode\n")
    PUT_COMMAND(WBOLD_LIGHT_MAGENTA_COLOR, "morse          ", "Generate morse, string\n")
    PUT_COMMAND(WBOLD_LIGHT_MAGENTA_COLOR, "rstr <number>  ", "Generate random string\n\n")
        
    BOLD_LIGHT_GREEN_COLOR
    std::cout << "[Math]\n";
    
    PUT_COMMAND(WBOLD_CYAN_COLOR, "fact  ", "Print factorial\n")
    PUT_COMMAND(WBOLD_CYAN_COLOR, "sqrt  ", "Print square root\n")
    PUT_COMMAND(WBOLD_CYAN_COLOR, "square", "Print square\n")
        
    BLACK_COLOR
}

void 
FHelpFunction::Welcome() {
    colorized::PrintWhReset(colorized::Colorize(BOLD, BLUE).c_str(), "Welcome to ");
    colorized::PrintWhReset(colorized::Colorize(BOLD, GREEN).c_str(), "Fegeya ");
    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "Scrift ");
    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_CYAN).c_str(), "Terminal \n");
    colorized::PrintWhReset(colorized::Colorize(BOLD, GREEN).c_str(), "Fegeya ");
    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "Scrift ");
    colorized::PrintWhReset(colorized::Colorize(BOLD, YELLOW).c_str(), "licensed with ");
    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_GREEN).c_str(), "MIT License \n");
    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "Copyright (c) ");
    colorized::PrintWhReset(colorized::Colorize(BOLD, MAGENTA).c_str(), COPYRIGHT_YEAR);
    colorized::PrintWith(colorized::Colorize(BOLD, YELLOW).c_str(), " Ferhat Geçdoğan\n");
}

void 
FHelpFunction::GitLink() {
    BOLD_YELLOW_COLOR
    printlnf("[1] https://github.com/ferhatgec\n");
    BOLD_BLUE_COLOR
    printlnf("[2] https://github.com/ferhatgec/scrift-lang\n");
    BOLD_GREEN_COLOR
    printlnf("[3] https://github.com/ferhatgec/fetcheya\n");
    BOLD_CYAN_COLOR
    printlnf("[4] https://github.com/ferhatgec/edifor\n");
	BLACK_COLOR       	
	/*BOLD_MAGENTA_COLOR
	printlnf("Select (ESC to cancel)");
	int a = getchar();
	FRunFunction fn;
	if(a == '1') {
		fn.RunFunction("xdg-open https://github.com/ferhatgec");
	} else if(a == '2') {
		fn.RunFunction("xdg-open https://github.com/ferhatgec/scrift-lang");
	} else if(a == '3') {
		fn.RunFunction("xdg-open https://github.com/ferhatgec/fetcheya");
	} else if(a == '4') {
		fn.RunFunction("xdg-open https://github.com/ferhatgec/edifor");
	} else { }
	}*/
}
