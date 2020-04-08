/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef COMMAND_FUNC_H
#define COMMAND_FUNC_H

#include "../Settings/DefaultSettings.h"            
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


class FCommand {
public:
    FCommand();
    ~FCommand();
    void echo_str(char *);
    void get_username(char *);
    void _os_kernel_name(char *);
    void _set_locale();
    void list_dir(const char *);
    void plus_num(uint64_t, uint64_t);
    void _generated_hash_string(int);
    void _your_ip();
    void error_undfnd(char *);
    void _file_path(char *);
    void _term_(char *);
    void help();
    void cd_func(char *);
    void hello();
    void printerror(char *err_str, int8_t);
    void _n_supported_();
    void error_syntax(char *, int8_t);
private:
    char *_hello_str = "help arguments:\n"
    "echo <arg>\n"
    "intnumber plus intnumber\n"
    "./<file>\n"
    "brk || cls -> Close Scrift Shell \n"
    "cd <folder> \n"
    "ls -> List\n"
    "-f || fetcheya -> System info ";
    char *_help_str = "Welcome ScriftLang Terminal\n"
    "ScriftLang licensed with GPLv3'\n"
    "Copyright (c) 2020 Ferhat Gecdogan\n";
};


#endif // COMMAND_FUNC_H
