/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include "../include/src/Scrift.hpp"
#include "../include/src/synflang.hpp"
#include "../include/src/Syntax/Language.hpp"
#include "../include/src/Syntax/FileFunction.hpp"
#include "../include/src/Syntax/RunFunction.hpp"
#include <iostream>
#include <ctype.h>
#include <memory>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdio.h>

FLanguage *lang = new FLanguage();

int main(int argc, char** argv)
{
    if (argc > 1) 
    {
		for (int i = 1; i < argc; i++) 
		{
			std::string arg(argv[i]);

			if (arg.substr(0, 2) == "--") 
			{
				if (arg == "--version") {
					BOLD_MAGENTA_COLOR
    					printlnf("Fegeya ScriftLang Interpreter Version: ");
    					BOLD_GREEN_COLOR
    					printlnf(SCRIFT_VERSION);
    					BOLD_YELLOW_COLOR
    					printlnf(hyphen);
    					BOLD_CYAN_COLOR
    					printlnf(SCRIFT_STATUS);
    					slashn
    					BOLD_RED_COLOR
    					printlnf("Copyright (c) 2020 ");
    					BOLD_BLUE_COLOR
    					printlnf("Ferhat Gecdogan \n");
    					BOLD_YELLOW_COLOR
    					printlnf("All Rights Reserved. \n");
    					BOLD_CYAN_COLOR
					printlnf("Distributed under the terms of the GPLv3 License.");
					BLACK_COLOR
    					slashn
				} else {
					lang->ReadFunc(arg);
				}
			} 
			else 
			{
				printlnf("null");
			}
		}
	} 
	else 
	{
		printlnf("scriftip <filename>");
		//exit(0);
	}
    return 0;
}
