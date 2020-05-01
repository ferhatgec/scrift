#ifndef PRINT_ERROR_FUNCTION_HPP
#define PRINT_ERROR_FUNCTION_HPP

#include "../synflang.hpp"
#include "../main.h"

FMain *mainfunc = new FMain();              

typest {
public:
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