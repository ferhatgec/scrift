/* MIT License
#
# Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <string>

#include <src/Syntax/Validation.hpp>

SCRIFT_VALIDATION
FValidation::Validate(std::string command) {
    /* :& */
    if(command.substr(0, 8) == "https://") {
        return WEBSITE;
    }

    return COMMAND;
}
