/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */


#ifndef SYNFLANG_HPP
#define SYNFLANG_HPP

#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdio>

#define F_OK 0

#include <clocale>

typedef bool boolean;
typedef int integer;
typedef char fchar;
typedef va_list vlist;

template<typename Str>

#undef printlnf
static integer
printlnf(Str *format, ...) {
    vlist arg;
    integer done;

    va_start (arg, format);
    done = vfprintf(stdout, format, arg);
    va_end (arg);
    return done;
}


#endif // SYNFLANG_HPP
