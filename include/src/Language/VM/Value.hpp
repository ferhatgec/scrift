/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef VALUE_HPP
#define VALUE_HPP

#include <cstring>
#include <sstream>
#include <unordered_map>
#include <vector>

class VM;

enum class TypeFunction {
    NUL,
    STRING,
    NUMBER,
    BOOL,
    REFERENCE,
    FUNCTION,
    CLASS,
    NAME,
};

#endif // VALUE_HPP