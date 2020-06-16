/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef HELP_FUNCTION_HPP
#define HELP_FUNCTION_HPP
#include "CommandFunc.h"
#include "Colors.hpp"
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
            "fls : List only files\n"
            "dls : List only folders\n"
            "ls : List folders and files\n"
            "fr <folder> : Going to <folder>\n"
            "mkdir <foldername> : Creates a folder\n"
            "ffind <value> : Finds files and directories in path\n"
            "rmvfile <folder or file> : Removes folder or file in path\n"
            "setname <name> : sets Environment's name\n"
            "setto <value> : sets Environment's value.\n"
            "back : Going to back directory\n\n");
            BOLD_MAGENTA_COLOR
            printlnf("username : Shows your username\n"
            "castle : Play Scrift's Castle Game!\n"
            "gitlink : Shows GitHub link.\n"
            "contr: Shows contributors\n"
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
        BOLD_BLUE_COLOR
        printlnf("Welcome to ");
        BOLD_GREEN_COLOR
        printlnf("Fegeya ");
        BOLD_BLUE_COLOR
        printlnf("Scrift");
        BOLD_CYAN_COLOR
        printlnf(" Terminal\n");
        BOLD_GREEN_COLOR
        printlnf("Fegeya ");
        BOLD_BLUE_COLOR
        printlnf("Scrift ");
        BOLD_YELLOW_COLOR
        printlnf("licensed with");
        BOLD_RED_COLOR
        printlnf(" MIT License\n");
        BOLD_MAGENTA_COLOR
        printlnf("Copyright (c) 2020");
        BOLD_CYAN_COLOR
        printlnf(" Ferhat Gecdogan\n");
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
