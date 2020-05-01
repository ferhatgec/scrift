#ifndef HELP_FUNCTION_HPP
#define HELP_FUNCTION_HPP

#include <iostream>
#include "../synflang.hpp"


void PrintHelpFunction() 
{
    printlnf("ScriftLang\n"
    "Run a script -> ./scriftlang path/to/file.scr\n"
    "Commands:\n"
    "\t--help\n"
    "\t--version");
}

#endif // HELP_FUNCTION