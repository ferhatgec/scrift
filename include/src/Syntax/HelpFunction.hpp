#include "CommandFunc.h"
#ifndef HELP_FUNCTION_HPP
#define HELP_FUNCTION_HPP

typedef struct {
public:
    virtual void help() {
        printlnf("Scrift \n"
            "help arguments: \n"
            "echo <arg> \n"
            "plus\n"
            "./<file> \n"
            "scr\n"
            "scr mkdir\n"
            "scr ls\n"
            "scr apt\n"
            "scr make\n"
            "cls || brk \n"
            "cd <folder>\n"
            "randomize || rstr\n"
            "username\n"
            "ls\n"
            "fetcheya\n"
            "clear || clear!!!\n"
            "set_locale_system || slcl_sys\n"
            "ip || myip\n");
    }
    virtual void hello() {
        printlnf("Welcome ScriftLang Terminal\n"
            "ScriftLang licensed with GPLv3\n"
            "Copyright (c) 2020 Ferhat Gecdogan\n");
    } 
} fhelp;

#endif // HELP_FUNCTION_HPP