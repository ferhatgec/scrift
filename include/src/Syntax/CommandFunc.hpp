/* MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef COMMAND_FUNC_HPP
#define COMMAND_FUNC_HPP


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

#include <unistd.h>
#define GetCurrentDir getcwd

class FCommand {
public:
    FCommand();
    ~FCommand();

    void _set_locale();

    // FName
    std::string FName();

    // Directory
    void list_file(boolean, std::string);
    void list_direc(boolean, std::string);
    std::string chartostring(std::string const &, fchar * );
    void plus_num(uinteger64, uinteger64);
    void _generated_hash_string(integer);
    void getIPAddress();
    void printerror(fchar *, integer8, fchar * );
    void _n_supported_();
    void echo_printlnf(std::string);
    void remove_character(char * , char );
    struct dirent *direntfunction;
    char *_file_path_cd_function = getenv("PWD");
    char *_home_dir = getenv("HOME");
};


#endif // COMMAND_FUNC_HPP
