/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef ALIAS_HPP
#define ALIAS_HPP

#include <iostream>
#include <vector>

class FAlias {
public:
    std::string Parse(std::string inputted_command);

    void AddAlias(const std::string &name, const std::string &replacement);

    void Init();
};

#endif // ALIAS_HPP
