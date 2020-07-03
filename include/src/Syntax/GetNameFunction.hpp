/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef GET_NAME_FUNCTION_HPP
#define GET_NAME_FUNCTION_HPP

#include "../Scrift.hpp"

class FGetUsername {
public:
    void InitUsername();
    void GetUsername();
    void InitHostname();
};


class FStructure : public FGetUsername {
public:
    FStructure();
    ~FStructure();
    void Terminal();
};
#endif // GET_NAME_FUNCTION_HPP
