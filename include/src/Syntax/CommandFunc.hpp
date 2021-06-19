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
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cstddef>
#include <cstdlib>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>

#include <unistd.h>

#define GetCurrentDir getcwd

class FCommand {
public:
    FCommand();

    ~FCommand();

    // FName
    static std::string FName();

    // Directory
    void list_file(boolean, std::string);

    void list_direc(boolean, std::string);

    static void _generated_hash_string(integer);

    static void getIPAddress();

    void echo_printlnf(std::string);

    static void remove_character(char *, char);

    std::string _file_path_cd_function = getenv("PWD");

};


#endif // COMMAND_FUNC_HPP
