/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef HELP_FUNCTION_HPP
#define HELP_FUNCTION_HPP

#include <iostream>

#include <src/Syntax/Locale.hpp>

class FHelpFunction {
public:
    void HelpFunction(slocale_t &locale);

    void Welcome();

    void GitLink();
};

#endif // HELP_FUNCTION_HPP
