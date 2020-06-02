/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef KEYWORDS_HPP
#define KEYWORDS_HPP

#include "../src/Scrift.hpp"
#include "../src/synflang.hpp"

struct FKeyword {
    FMain *main_input = new FMain();
public:
    virtual void EndWithUser()
    {
        printlnf(getenv("USER")); // This is not portable!
    }
    virtual void EndWithPath()
    {
    	printlnf(getenv("PWD")); // This is not portable!
    }
};

#endif // KEYWORDS_HPP
