/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef COLORS_HPP
#define COLORS_HPP

#include "../Scrift.hpp"

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


// Default color definitions without printlnf
#define WRED_COLOR "\033[0;31m"
#define WGREEN_COLOR "\033[0;32m"
#define WYELLOW_COLOR "\033[0;33m"
#define WBLUE_COLOR "\033[0;34m"
#define WMAGENTA_COLOR "\033[0;35m"
#define WCYAN_COLOR "\033[0;36m"


// Default bold** color definitions without printlnf
#define WBOLD_RED_COLOR "\033[1;31m"
#define WBOLD_GREEN_COLOR "\033[1;32m"
#define WBOLD_YELLOW_COLOR "\033[01;33m"
#define WBOLD_BLUE_COLOR "\033[1;34m"
#define WBOLD_MAGENTA_COLOR "\033[1;35m"
#define WBOLD_CYAN_COLOR "\033[1;36m"

// Reset (BLACK)
#define WBLACK_COLOR "\033[0m"


#endif // COLORS_HPP
