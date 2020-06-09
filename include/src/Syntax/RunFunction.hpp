/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef RUN_FUNCTION_HPP_
#define RUN_FUNCTION_HPP_

#define RUN_FUNCTION_DIRECTORY "/usr/bin/"

#include <iostream>

class FRunFunction {
public:
    FRunFunction();
    ~FRunFunction();
    virtual void RunJamFunction(std::string); // For Fusion
    virtual void RunGMakeFunction(std::string);
    virtual void RunBinFunction(std::string);
    virtual void RunFunction(std::string);
};

#endif // RUN_FUNCTION_HPP_
