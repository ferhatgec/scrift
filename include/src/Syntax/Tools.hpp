/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <string>
#include <bits/stdc++.h>

typedef struct {
    unsigned width, height;
} res_t;

class FTools {
    /* constexpr :^) */ std::vector<std::string> ext = {
        ".jpg",
        ".jpeg",
        ".png"
    };
public:
    void Clock();
    void Date();

    void ResolutionSizeInfo(std::string file);

    res_t JPEGInfo(std::string& file);
    res_t PNGInfo (std::string& file);
};

#endif // TOOLS_HPP
