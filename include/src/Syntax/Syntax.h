/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#ifndef SYNTAX_H
#define SYNTAX_H

#include "../File/Path.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

class FSyntax {
public:
    FSyntax();
    ~FSyntax();
    virtual void FSyntaxFile(const char *syntax);
private:
    char *_syntax;
};

#endif //SYNTAX_H