/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
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
        printlnf("Scrift Functions && Arguments\n");
            GREEN_COLOR
            printlnf("printlnf <arg> \n");
            BOLD_RED_COLOR
            printlnf("scr <argument>\n"
            "scr mkdir\n"
            "[For Scrift Developers] lmake\n"
            "[For Scrift Developers] lgit\n"
            "[For Scrift Developers] devs\n"
            "scr ls\n"
            "scr apt\n"
            "scr make\n"
            "scrlang\n"
            "scrp\n"
            "create_scrift_project <name>\n");
            YELLOW_COLOR
            printlnf("home || default\n"
            "lsf || lsfile\n"
            "lsd || lsdir\n"
            "ls\n"
            "fr <folder>\n"
            "back\n");
            BOLD_MAGENTA_COLOR
            printlnf("[For Scrift Developers] getdev <boolean>\n"
            "[For Scrift Developers] felog\n"
            "gitlink || scrift_link || fusionlink\n"
            "contr || cont || contributors\n"
            "[For Scrift Developers] clear_log || felog_clear\n"
            "[In Development Status] clear_settings\n"
            "[In Development Status] settings\n"
            "fetcheya\n"
            "readtext <file>\n"
            "[If your default shell is Scrift] edifor\n"
            "[If your default shell is Scrift] edifor <filename>\n"
            "username\n");
            BOLD_GREEN_COLOR
            printlnf("addtext <file>\n"
            "nanoaddtext <file>\n"
            "ctxt <name>\n");
            BOLD_BLUE_COLOR
            printlnf("pause || stop\n"
            "cls || brk \n"
            "rstr <number>\n"
            "clear || clear!!!\n"
            "[For Development Status] set_locale_system || slcl_sys\n"
            "ip || myip\n");
        BLACK_COLOR
    }
    virtual func hello() {
        BOLD_BLUE_COLOR
        printlnf("Welcome to ");
        BOLD_GREEN_COLOR
        printlnf("ScriftLang");
        BOLD_BLUE_COLOR
        printlnf(" Terminal\n");
        BOLD_GREEN_COLOR
        printlnf("ScriftLang "); 
        BOLD_YELLOW_COLOR
        printlnf("licensed with");
        BOLD_RED_COLOR
        printlnf(" GPLv3\n");
        BOLD_MAGENTA_COLOR
        printlnf("Copyright (c) 2020");
        BOLD_CYAN_COLOR
        printlnf(" Ferhat Gecdogan\n");
        BLACK_COLOR
    } 

    virtual func GitLink() {
        YELLOW_COLOR
        printlnf("https://github.com/FerhatGec\n");
        BOLD_BLUE_COLOR
        printlnf("https://github.com/FerhatGec/scrift-lang\n");
        GREEN_COLOR
        printlnf("https://github.com/FerhatGec/fusion-os\n");
        BLACK_COLOR // reset
    }
} fhelp;

#endif // HELP_FUNCTION_HPP
