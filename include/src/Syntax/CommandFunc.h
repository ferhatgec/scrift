/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef COMMAND_FUNC_H
#define COMMAND_FUNC_H


#include "../Scrift.hpp"
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
#define scrift ".scr"

class FCommand { /* getting public variables and functions*/
public:
    FCommand();
    ~FCommand();
    void clear_shell();
    void _set_locale();

    // Directory
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
    fchar *_file_path_cd_function = getenv("PWD");
    fchar *_home_dir = getenv("HOME");
};


#endif // COMMAND_FUNC_H
