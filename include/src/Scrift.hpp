/* MIT License
#
# Copyright (c) 2020-2022 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SCRIFT_HPP
#define SCRIFT_HPP

#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <string>

#include "synflang.hpp"

#include "Keywords/ScriftKeywords.hpp"

#include "Syntax/CommandFunc.hpp"
#include "Syntax/Locale.hpp"

#define COPYRIGHT_YEAR "2020-2022"

#define slashn printlnf("\n");

#define fstr std::string

#define printhyphen printlnf("-");

#define SCRIFT_VERSION "0.1.9"
#define SCRIFT_STATUS "beta-1"

// Input Definitions
enum {
    ARROW_UP = 65,
    ARROW_DOWN,
    ARROW_RIGHT,
    ARROW_LEFT,
    BACKSPACE = 127,
    TAB = 9,

    LIMIT = 512
};


#define WBRED      "\033[1;31m"
#define WBGREEN    "\033[1;32m"
#define WBYELLOW   "\033[01;33m"
#define WBBLUE     "\033[1;34m"
#define WBMAGENTA  "\033[1;35m"
#define WBCYAN     "\033[1;36m"

// Light colors
#define WBLBLACK   "\033[1;90m"
#define WBLRED     "\033[1;91m"
#define WBLGREEN   "\033[1;92m"
#define WBLYELLOW  "\033[1;93m"
#define WBLBLUE    "\033[1;94m"
#define WBLMAGENTA "\033[1;95m"
#define WBLCYAN    "\033[1;96m"
#define WBLWHITE   "\033[1;97m"

#define WBWHITE    "\033[1;37m"

#define FCHAR char

inline std::string STR(const char* _ch) {
    return (std::string) _ch;
}


class FMain {
    bool is_similar = false;
public:
    FMain();

    ~FMain();

    bool CommandMatch(std::string command, std::string token) noexcept;

    void CodeExecution(std::string arg, slocale_t &locale);

    /* Dynamic titles. */
    void SetTitle();

    /* Shell */
    void Shell(slocale_t &locale);

    static std::string Time();

    // Input, directory variables.
    std::string header_string;
    std::string str;
    std::string _h_str;
    std::string strfor_h_str;
    bool _home{};
};

#endif // SCRIFT_HPP
