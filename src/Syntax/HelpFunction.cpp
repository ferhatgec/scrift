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

// Library
#include <Colorized.hpp>

void
FHelpFunction::HelpFunction() {
	BOLD_GREEN_COLOR
        printlnf("Scrift Functions && Arguments\n\n");
	BOLD_LIGHT_BLUE_COLOR
        printlnf("[General]\n");
	BOLD_CYAN_COLOR
	printlnf(" * username : Show username\n"
            " * castle : Scrift game.\n"
            " * gitlink : Show GitHub link.\n"
            " * welcome : Show welcome message\n"
            " * contr : Show contributors\n"
            " * fscrift <file> : Interpret <file>\n"
            " * clear_log : Clear FeLog\n"
            " * history : Show Scrift history.\n"
            " * rmvhistory : Clear Scrift history\n"
            " * rmvsettings : Clear settings\n"
            " * settings : Show settings\n"
            " * fetcheya : Show system-info-tool\n"
            " * version : Show version and license\n"
            " * now : Show time\n"
	    " * uptime : Show uptime\n"
	    " * asciiart : Show ASCII Art\n"
            " * template : Create language template\n"
            " * fdate : Show calendar\n"
            " * readtext <file> : Read <file>\n"
     	    " * felog : Show your FeLog.\n"
            " * edifor : Open Edifor\n"
	    " * addtext <file> : Add text in <file>\n"
            " * ctxt <name> : Create text file\n"
            " * pause : Stop Scrift\n"
            " * cls || exit : Close Scrift\n"
            " * clear : Clear Scrift buffer\n"
            " * ip : Show local-IP\n\n");
	BOLD_LIGHT_YELLOW_COLOR
	printlnf("[Output]\n");
        BOLD_GREEN_COLOR
        printlnf(" * printlnf || echo <arg> : Shows <arg> [#environment]\n"
	    " * emoji <arg> : Show <emoji> (e.g: :thinking_face:)\n\n");
	BOLD_LIGHT_MAGENTA_COLOR
	printlnf("[Execute]\n");
        BOLD_RED_COLOR
        printlnf(" * scr <argument> : Execute <argument>\n"
            " * fpi <arg> <app> : Run Fegeya Package Installer\n\n");
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
        colorized::PrintWhReset(colorized::Colorize(BOLD, YELLOW).c_str(), "Ferhat Gecdogan\n");
        BLACK_COLOR
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
