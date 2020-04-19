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
    void echo_str(fchar *);
    void get_username(fchar *);
    void _os_kernel_name(fchar *);
    void _set_locale();
    void list_dir(const fchar *);
    void plus_num(uinteger64, uinteger64);
    void _generated_hash_string(integer);
    void _your_ip();
    void error_undfnd(fchar *);
    void _file_path(fchar *);
    void _term_(fchar *);
    void help();
    void cd_func(fchar *);
    void hello();
    void printerror(fchar *err_str, integer8);
    void _n_supported_();
    void error_syntax(fchar *, integer8);
    void get_hostname();
private:
    fchar *_hello_str = "help arguments:\n"
    "echo <arg>\n"
    "intnumber plus intnumber\n"
    "./<file>\n"
    "brk || cls -> Close Scrift Shell \n"
    "cd <folder> \n"
    "ls -> List\n"
    "-f || fetcheya -> System info ";
    fchar *_help_str = "Welcome ScriftLang Terminal\n"
    "ScriftLang licensed with GPLv3'\n"
    "Copyright (c) 2020 Ferhat Gecdogan\n";
};


#endif // COMMAND_FUNC_H
