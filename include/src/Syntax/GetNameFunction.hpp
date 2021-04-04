/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef GET_NAME_FUNCTION_HPP
#define GET_NAME_FUNCTION_HPP

#include "Settings.hpp"

class FGetUsername {
public:
    FGetUsername() = default;
    ~FGetUsername()= default;

    void InitUsername();

    void InitHostname();
};


class FStructure {
    FSettings customize;
public:
    FStructure() = default;
    ~FStructure()= default;

    void Terminal(bool incognito);
};

#endif // GET_NAME_FUNCTION_HPP
