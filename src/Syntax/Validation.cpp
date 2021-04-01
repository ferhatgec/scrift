/* MIT License
#
# Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <string>
#include <regex>
#include <src/Syntax/Validation.hpp>

SCRIFT_VALIDATION
FValidation::Validate(const std::string& command) {
    if(std::regex_match(command, std::regex(".*://.*"))) {
        return WEBSITE;
    }

    return COMMAND;
}
