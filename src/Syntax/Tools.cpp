/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>

#include <src/Scrift.hpp>
#include <src/Syntax/Tools.hpp>

void FTools::Clock() {
    FMain main;
    std::string time = main.Time();
    time = time.erase(0, 11);
    time = time.substr(0, 2);

    if(time == "01")
        std::cout << "🕐";
    else if(time == "02")
        std::cout << "🕑";
    else if(time == "03")
        std::cout << "🕒";
    else if(time == "04")
        std::cout << "🕓";
    else if(time == "05")
        std::cout << "🕔";
    else if(time == "06")
        std::cout << "🕕";
    else if(time == "07")
        std::cout << "🕖";
    else if(time == "08")
        std::cout << "🕗";
    else if(time == "09")
        std::cout << "🕘";
    else if(time == "10")
        std::cout << "🕙";
    else if(time == "11")
        std::cout << "🕚";
    else if(time == "00")
        std::cout << "🕛";
    else std::cout << "";
}

