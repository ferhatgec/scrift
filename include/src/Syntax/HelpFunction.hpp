#include "CommandFunc.h"
#ifndef HELP_FUNCTION_HPP
#define HELP_FUNCTION_HPP

typedef struct {
public:
    virtual void help() {
        printlnf("Scrift \n"
            "help arguments: \n"
            "printlnf <arg> \n"
            "scr <argument>\n"
            "home || default\n"
            "lsf || lsfile\n"
            "lsd || lsdir\n"
            "scr mkdir\n"
            "scr ls\n"
            "scr apt\n"
            "scr make\n"
            "cls || brk \n"
            "cd <folder>\n"
            "rstr <number>\n"
            "username\n"
            "ls\n"
            "ctxt <name>\n"
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