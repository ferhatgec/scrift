/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
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

void
FHelpFunction::HelpFunction(slocale_t &locale) {
	BOLD_GREEN_COLOR
    std::cout << "Scrift Functions && Arguments\n\n";
	
	BOLD_LIGHT_BLUE_COLOR
    printlnf("[General]\n");
	BOLD_CYAN_COLOR
	
	std::cout << 
	" * username       : " << locale.cmd_username   << 
    " * config         : " << locale.cmd_config     <<
    " * castle         : " << locale.cmd_castle     <<
    " * gitlink        : " << locale.cmd_gitlink	<<
    " * welcome        : " << locale.cmd_welcome	<<
    " * contr          : " << locale.cmd_contr	    <<
    " * fscrift <file> : " << locale.cmd_fscrift    <<
    " * clear_log      : " << locale.cmd_clearlog   <<
    " * history        : " << locale.cmd_history	<<
    " * rmvhistory     : " << locale.cmd_rmvhistory <<
    " * rmvsettings    : " << locale.cmd_rmvsttngs  <<
    " * settings       : " << locale.cmd_settings   <<
    " * fetcheya       : " << locale.cmd_fetcheya   <<
    " * version        : " << locale.cmd_version    <<
    " * now            : " << locale.cmd_now        <<
	" * uptime         : " << locale.cmd_uptime     <<
	" * asciiart       : " << locale.cmd_asciiart   <<
    " * template       : " << locale.cmd_template   <<
    " * fdate          : " << locale.cmd_calendar   <<
    " * readtext <file>: " << locale.cmd_readtext   <<
    " * felog          : " << locale.cmd_felog	    <<
    " * edifor         : " << locale.cmd_edifor	    <<
	" * addtext <file> : " << locale.cmd_addtext	<<
    " * ctxt <name>    : " << locale.cmd_ctxt	    <<
    " * pause          : " << locale.cmd_pause	    <<
    " * cls || exit    : " << locale.cmd_cls        <<
    " * clear          : " << locale.cmd_clear 	    <<
    " * ip             : " << locale.cmd_ip;
	
	BOLD_LIGHT_YELLOW_COLOR
	printlnf("[Output]\n");
	BOLD_GREEN_COLOR
	printlnf(" * printlnf || echo <arg> : Shows <arg> [#environment]\n"
        " * output <command> : Print output of inputted command.\n"
        " * title <string> : Change title of terminal header-bar (title-bar).\n" 
	    " * emoji <arg> : Show <emoji> (e.g: :thinking_face:)\n\n");
	BOLD_LIGHT_MAGENTA_COLOR
	printlnf("[Execute]\n");
	BOLD_RED_COLOR
	printlnf(" * scr <argument> : Execute <argument>\n"
            " * fpm <arg> <app> : Run Fegeya Package Manager\n\n");
	BOLD_LIGHT_RED_COLOR
	printlnf("[Path]\n");
        BOLD_YELLOW_COLOR
        printlnf(" * home : /home/<username>\n"
	    " * create <name> : Create <name>scr file\n"
        " * objls : List installed objects\n"
        " * fls : List only files (#<env>)\n"
        " * dls : List only folders (#<env>)\n"
        " * ls <folder> : List dir (#<env>)\n"
        " * fr || cd <folder> : Change dir (#<env>)\n"
        " * mkdir <foldername> : Create folder\n"
        " * ffind <file, folder> : Find files and directories in path\n"
        " * rmvfile <file, folder> : Remove file, folder in path\n"
        " * setname <name> : Set environment name\n"
        " * setto <value> : Set environment value.\n"
        " * back : Going to back directory\n\n");
	BOLD_LIGHT_CYAN_COLOR
	printlnf("[Generate]\n");
	BOLD_LIGHT_MAGENTA_COLOR
	printlnf(" * genfrbr <value> : Generate FreeBrain keycode\n"
	    " * morse : Generate morse, string\n"
	    " * rstr <number> : Generate random string\n\n");
	BOLD_LIGHT_GREEN_COLOR
	printlnf("[Math]\n");
	BOLD_CYAN_COLOR
	printlnf(" * fact : Print factorial\n"
	    " * sqrt : Print Square root\n"
	    " * square : Print Square\n");
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
    colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "Copyright (c)");
    colorized::PrintWhReset(colorized::Colorize(BOLD, MAGENTA).c_str(), " 2020 ");
    colorized::PrintWith(colorized::Colorize(BOLD, YELLOW).c_str(), "Ferhat Gecdogan\n");
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
	printlnf("Select (ESC to cancel) : ");
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
