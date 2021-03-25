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

    void RunFunction(std::string command);
};

#endif // RUN_FUNCTION_HPP
