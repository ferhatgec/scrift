/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef COMMAND_FUNC_H
#define COMMAND_FUNC_H
        
#include "../main.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>
#include <cstdlib>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>

#define MAIN_ALL 6
#define slash "/"
#define txt ".txt"

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



class FCommand { /* getting public variables and functions*/
public:
    FCommand();
    ~FCommand();
    void clear_shell();
    void _set_locale();

    // Directory
    void _run_all_func(std::string);
    void list_dir(boolean, boolean, boolean);
    void list_file(boolean);
    void list_direc(boolean);
    std::string chartostring(std::string const &, fchar * );
    void plus_num(uinteger64, uinteger64);
    void _generated_hash_string(integer);
    void _your_ip();
    void printerror(fchar *, integer8, fchar * );
    void _n_supported_();
    void echo_printlnf(std::string);
    void remove_character(char * , char );
    struct dirent *direntfunction;
    fchar *_file_path_cd_function = getenv("HOME");
    fchar *_home_dir = getenv("HOME");
};


#endif // COMMAND_FUNC_H
