/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef PRINT_ERROR_FUNCTION_HPP
#define PRINT_ERROR_FUNCTION_HPP

#include "../synflang.hpp"
#include "../Scrift.hpp"
#include "Colors.hpp"

typest {
public:
    FMain *mainfunc = new FMain();    
    func PrintError(fchar* error_name) {
        BOLD_YELLOW_COLOR
        printlnf(error_name, sizeof(error_name));
        BLACK_COLOR
    }
    func PrintCriticalError(fchar* error_name) {
        printlnf(error_name, sizeof(error_name));
        slashn
        BOLD_RED_COLOR
        printlnf("Critical Error there is ->", mainfunc->str);
        BLACK_COLOR
        //exit(-1);
    }
    func PrintBugError(fchar* error_name) {
        printlnf(error_name, sizeof(error_name));
        slashn
        BOLD_MAGENTA_COLOR
        printlnf("Bug there is ->", mainfunc->str);
        slashn
        BOLD_RED_COLOR
        printlnf("Please report.");
        slashn
        BOLD_GREEN_COLOR
        printlnf("https://github.com/FerhatGec/scrift-lang");
        BLACK_COLOR
        slashn
    }
} fprinterror;



#endif // PRINT_ERROR_FUNCTION_HPP
