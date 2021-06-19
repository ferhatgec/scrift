/* MIT License
#
# Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>

enum SCRIFT_VALIDATION {
    WEBSITE = 0,
    COMMAND,
};

class FValidation {
public:
    SCRIFT_VALIDATION Validate(const std::string &command);
};

#endif // VALIDATION_HPP
