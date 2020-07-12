/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef HELP_FUNCTION_HPP
#define HELP_FUNCTION_HPP

#include "CommandFunc.h"
// Library
#include "../../../Library/Colorized.hpp"

typest {
public:
    virtual func help() {
        BOLD_GREEN_COLOR
            printlnf("Scrift Functions && Arguments\n\n");
            BOLD_GREEN_COLOR
            printlnf("printlnf <arg> (e.g. : #USER, #PATH, Environment) : Shows <arg> \n");
            BOLD_RED_COLOR
            printlnf("scr <argument> : Launch /bin/<argument>\n"
            "scr mkdir : Launch mkdir (Object)\n"
            "scr ls\n"
            "scr apt\n"
            "scr make\n"
            "create <name> : Creates <name><dot>scr file\n\n");
            BOLD_YELLOW_COLOR
            printlnf("home : Going to /home/<username>\n"
            "objls : List installed objects\n"
            "fls : List only files with input or environment value (#<env>)\n"
            "dls : List only folders with input or environment value (#<env>)\n"
            "ls : List folders and files with input or environment value (#<env>)\n"
            "fr <folder> : Going to <folder> or environment value (#<env>)\n"
            "mkdir <foldername> : Creates a folder\n"
            "ffind <value> : Finds files and directories in path\n"
            "rmvfile <folder or file> : Removes folder or file in path\n"
            "setname <name> : sets Environment's name\n"
            "setto <value> : sets Environment's value.\n"
            "genfrbr <value> : Generates FreeBrain key code with input number\n"
            "back : Going to back directory\n\n");
            BOLD_MAGENTA_COLOR
            printlnf("username : Shows your username\n"
            "castle : Play Scrift's Castle Game!\n"
            "gitlink : Shows GitHub link.\n"
            "welcome : Shows Welcome message\n"
            "contr : Shows contributors\n"
            "morse : Generates string or morse code to morse code or string\n"
            "fscrift <file> : Interprets <file>.scr\n"
            "clear_log : Clear your FeLog\n"
            "history : Shows your Scrift History.\n"
            "rmvhistory : Clear your Scrift History\n"
            "rmvsettings : Clear your Settings\n"
            "settings : Shows your Settings\n"
            "fetcheya : Shows your system\n"
            "emoji : Shows your inputted emoji (e.g: :thinking_face:)\n"
            "version : Shows version and license\n"
            "now : Shows time.\n"
	    "uptime : Shows uptime.\n"
	    "asciiart : Shows your ASCII Art with selected color (ascii_art_color)\n"
            "template : Creates a language example. (Hello Language)\n"
            "[If your default shell is Scrift] fdate : Shows calendar\n"
            "readtext <file> : Reads <file>\n"
     	    "[For Scrift Developers] felog : Shows your FeLog.\n"
            "[If your default shell is Scrift] edifor : Open Edifor\n"
            "[If your default shell is Scrift] edifor <filename> : Open Edifor with File\n\n");
            BOLD_GREEN_COLOR
            printlnf("addtext <file> : Add text in <file>\n"
            "ctxt <name> : Creates Text file\n\n");
            BOLD_BLUE_COLOR
            printlnf("pause : Stops your Scrift shell\n"
            "cls : Close Scrift (with Terminal)\n"
            "rstr <number> : Generated random string\n"
            "clear : Clear Scrift inputs\n"
            "ip  Show your IP and info\n");
        BLACK_COLOR
    }
    virtual func hello() {
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

    virtual func GitLink() {
        BOLD_YELLOW_COLOR
        printlnf("https://github.com/FerhatGec\n");
        BOLD_BLUE_COLOR
        printlnf("https://github.com/FerhatGec/scrift-lang\n");
        BOLD_GREEN_COLOR
        printlnf("https://github.com/FerhatGec/elite-build\n");
        BOLD_CYAN_COLOR
        printlnf("https://github.com/FerhatGec/fresh-gui\n");
        BLACK_COLOR // reset
    }
} fhelp;

#endif // HELP_FUNCTION_HPP
