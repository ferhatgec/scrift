/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#ifndef SYNFLANG_HPP
#define SYNFLANG_HPP

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>

#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>

#include <locale.h>
	typedef uint8_t     uinteger8;
	typedef  int8_t     integer8;
	typedef uint16_t    uinteger16;
	typedef  int16_t    integer16;
	typedef uint32_t    unsigned32;
	typedef  int32_t    integer32;
	typedef uint64_t    uinteger64;
	typedef  int64_t    integer64;

typedef int integer;
typedef char fchar;

template<typename Str>

#undef printlnf
static integer
printlnf (Str *format, ...) 
{
  va_list arg;
  int done;

  va_start (arg, format);
  done = vfprintf (stdout, format, arg);
  va_end (arg);
  return done;
}


#endif // SYNFLANG_HPP