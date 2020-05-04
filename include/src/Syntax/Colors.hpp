/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef COLORS_HPP
#define COLORS_HPP

#include "../main.h"

// Default color definitions
#define RED_COLOR printlnf("\033[0;31m");
#define GREEN_COLOR printlnf("\033[0;32m");
#define YELLOW_COLOR printlnf("\033[0;33m");
#define BLUE_COLOR printlnf("\033[0;34m");
#define MAGENTA_COLOR printlnf("\033[0;35m");
#define CYAN_COLOR printlnf("\033[0;36m");


// Default bold** color definitions
#define BOLD_RED_COLOR printlnf("\033[1;31m");
#define BOLD_GREEN_COLOR printlnf("\033[1;32m");
#define BOLD_YELLOW_COLOR printlnf("\033[01;33m");
#define BOLD_BLUE_COLOR printlnf("\033[1;34m");
#define BOLD_MAGENTA_COLOR printlnf("\033[1;35m");
#define BOLD_CYAN_COLOR printlnf("\033[1;36m");

// Reset (BLACK)
#define BLACK_COLOR printlnf("\033[0m");







#endif // COLORS_HPP