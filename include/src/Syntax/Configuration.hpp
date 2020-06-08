/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "CommandFunc.h"
#include "FileFunction.hpp"
#include "RunFunction.hpp"

class FConfiguration {
    FRunFunction *run_jam_function;
    FCommand *command_configuration;
    FileFunction::faddtextfunction file_exist;
  public:
    FConfiguration();
    ~FConfiguration();
    virtual func JamConfiguration(std::string);
    virtual boolean JamExists();
};

#endif // CONFIGURATION_HPP
