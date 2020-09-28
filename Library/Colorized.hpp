/* MIT License
# Forked from https://github.com/FerhatGec/colorized
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef COLORIZED_HPP
#define COLORIZED_HPP

#include <iostream>
#include <cstring>
#include <sstream>

#define ESC 033 

// Default Background color definitions
#define DEFAULT 39
#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define LIGHT_BLACK 90
#define LIGHT_RED 91
#define LIGHT_GREEN 92
#define LIGHT_YELLOW 93
#define LIGHT_BLUE 94
#define LIGHT_MAGENTA 95
#define LIGHT_CYAN 96
#define LIGHT_WHITE 97

// Default Foreground Color Definitions
#define FDEFAULT 49
#define FBLACK 40
#define FRED 41
#define FGREEN 42
#define FYELLOW 43
#define FBLUE 44
#define FMAGENTA 45
#define FCYAN 46
#define FLIGHT_GRAY 47
#define FDARK_GRAY 100
#define FLIGHT_RED 101
#define FLIGHT_GREEN 102
#define FLIGHT_YELLOW 103
#define FLIGHT_BLUE 104
#define FLIGHT_MAGENTA 105
#define FLIGHT_CYAN 106
#define FWHITE 107   

// Default Set Type Definitions
#define SDEFAULT 0
#define BOLD 1
#define DIM 2
#define UNDERLINED 4
#define BLINK 5
#define REVERSE 7
#define HIDDEN 8

// Default Unset Type Definitions  
#define UALL 0
#define UBOLD 21
#define UDIM 22
#define UUNDERLINED 24
#define UBLINK 25
#define UREVERSE 27
#define UHIDDEN 28

#define DEFAULT 39
#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define LIGHT_BLACK 90
#define LIGHT_RED 91
#define LIGHT_GREEN 92
#define LIGHT_YELLOW 93
#define LIGHT_BLUE 94
#define LIGHT_MAGENTA 95
#define LIGHT_CYAN 96
#define LIGHT_WHITE 97


#define RED_COLOR printf("\033[0;31m");
#define GREEN_COLOR printf("\033[0;32m");
#define YELLOW_COLOR printf("\033[0;33m");
#define BLUE_COLOR printf("\033[0;34m");
#define MAGENTA_COLOR printf("\033[0;35m");
#define CYAN_COLOR printf("\033[0;36m");
#define LIGHT_BLACK_COLOR printf("\033[0;90m");
#define LIGHT_RED_COLOR printf("\033[0;91m");
#define LIGHT_GREEN_COLOR printf("\033[0;92m");
#define LIGHT_YELLOW_COLOR printf("\033[0;93m");
#define LIGHT_BLUE_COLOR printf("\033[0;94m");
#define LIGHT_MAGENTA_COLOR printf("\033[0;95m");
#define LIGHT_CYAN_COLOR printf("\033[0;96m");
#define LIGHT_WHITE_COLOR printf("\033[0;97m");

// Default bold** color definitions
#define BOLD_RED_COLOR printf("\033[1;31m");
#define BOLD_GREEN_COLOR printf("\033[1;32m");
#define BOLD_YELLOW_COLOR printf("\033[1;33m");
#define BOLD_BLUE_COLOR printf("\033[1;34m");
#define BOLD_MAGENTA_COLOR printf("\033[1;35m");
#define BOLD_CYAN_COLOR printf("\033[1;36m");
#define BOLD_LIGHT_BLACK_COLOR printf("\033[1;90m");
#define BOLD_LIGHT_RED_COLOR printf("\033[1;91m");
#define BOLD_LIGHT_GREEN_COLOR printf("\033[1;92m");
#define BOLD_LIGHT_YELLOW_COLOR printf("\033[1;93m");
#define BOLD_LIGHT_BLUE_COLOR printf("\033[1;94m");
#define BOLD_LIGHT_MAGENTA_COLOR printf("\033[1;95m");
#define BOLD_LIGHT_CYAN_COLOR printf("\033[1;96m");
#define BOLD_LIGHT_WHITE_COLOR printf("\033[1;97m");

// Reset (BLACK)
#define BLACK_COLOR printf("\033[0m");
#define WHITE_COLOR printf("\033[1;37m");

// Default color definitions without printlnf
#define WRED_COLOR "\033[0;31m"
#define WGREEN_COLOR "\033[0;32m"
#define WYELLOW_COLOR "\033[0;33m"
#define WBLUE_COLOR "\033[0;34m"
#define WMAGENTA_COLOR "\033[0;35m"
#define WCYAN_COLOR "\033[0;36m"
#define WLIGHT_BLACK_COLOR "\033[0;90m"
#define WLIGHT_RED_COLOR "\033[0;91m"
#define WLIGHT_GREEN_COLOR "\033[0;92m"
#define WLIGHT_YELLOW_COLOR "\033[0;93m"
#define WLIGHT_BLUE_COLOR "\033[0;94m"
#define WLIGHT_MAGENTA_COLOR "\033[0;95m"
#define WLIGHT_CYAN_COLOR "\033[0;96m"
#define WLIGHT_WHITE_COLOR "\033[0;97m"

// Default bold** color definitions without printlnf
#define WBOLD_RED_COLOR "\033[1;31m"
#define WBOLD_GREEN_COLOR "\033[1;32m"
#define WBOLD_YELLOW_COLOR "\033[01;33m"
#define WBOLD_BLUE_COLOR "\033[1;34m"
#define WBOLD_MAGENTA_COLOR "\033[1;35m"
#define WBOLD_CYAN_COLOR "\033[1;36m"
#define WBOLD_LIGHT_BLACK_COLOR "\033[1;90m"
#define WBOLD_LIGHT_RED_COLOR "\033[1;91m"
#define WBOLD_LIGHT_GREEN_COLOR "\033[1;92m"
#define WBOLD_LIGHT_YELLOW_COLOR "\033[1;93m"
#define WBOLD_LIGHT_BLUE_COLOR "\033[1;94m"
#define WBOLD_LIGHT_MAGENTA_COLOR "\033[1;95m"
#define WBOLD_LIGHT_CYAN_COLOR "\033[1;96m"
#define WBOLD_LIGHT_WHITE_COLOR "\033[1;97m"

#define WBOLD_WHITE_COLOR "\033[1;37m"

static std::string Markstr("m");
static std::string Semicolonstr(";");
static std::string Templatestr("\033[");

// Reset (BLACK)
#define WBLACK_COLOR "\033[0m"

namespace colorized {
    static void TextBackground(int color) {
	printf("%c[%dm", ESC, 40+color);
    }
        
    static std::string IntToString(int a) {
    	std::ostringstream temp;
    	temp << a;
    	return temp.str();
    }
    
    static void PrintWith(const char* color, const char* text) {
    	std::cout << color <<  text <<  WBLACK_COLOR;
    }

    static void PrintWhReset(const char* color, const char* text) {
    	std::cout << color << text;
    }

    static std::string Colorize(int type, int color) {
    	return Templatestr + IntToString(type) + Semicolonstr + IntToString(color) + Markstr;
    }
}

#endif // COLORIZED_HPP
