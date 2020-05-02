/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef PRINT_ERROR_FUNCTION_HPP
#define PRINT_ERROR_FUNCTION_HPP

#include "../synflang.hpp"
#include "../main.h"
          

typest {
public:
    FMain *mainfunc = new FMain();    
    func PrintError(fchar* error_name) {
        printlnf(error_name, sizeof(error_name));
    }
    func PrintCriticalError(fchar* error_name) {
        printlnf(error_name, sizeof(error_name));
        slashn
        printlnf("Critical Error there is ->", mainfunc->str);
        exit(-1);
    }
    func PrintBugError(fchar* error_name) {
        printlnf(error_name, sizeof(error_name));
        slashn
        printlnf("Bug there is ->", mainfunc->str);
        slashn
        printlnf("Please report.");
        slashn
        system("<mybrowser> https://github.com/FerhatGec/scrift-lang");
        slashn
    }
} fprinterror;



#endif // PRINT_ERROR_FUNCTION_HPP