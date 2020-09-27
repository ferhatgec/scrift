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
    std::string time = main.Time().erase(0, 11).substr(0, 2);
    int _half_time = atoi(main.Time().substr(14, 17).c_str());

    if(time == "01")
        if(_half_time >= 30)
            std::cout << "🕜";
        else 
            std::cout << "🕐";
    else if(time == "02")
        if(_half_time >= 30)
            std::cout << "🕝";
        else 
            std::cout << "🕑";
    else if(time == "03")
        if(_half_time >= 30)
            std::cout << "🕞";
        else
            std::cout << "🕒";
    else if(time == "04")
        if(_half_time >= 30)
            std::cout << "🕟";
        else
            std::cout << "🕓";
    else if(time == "05")
        if(_half_time >= 30)
            std::cout << "🕠";
        else 
            std::cout << "🕔";
    else if(time == "06")
        if(_half_time >= 30)
            std::cout << "🕡";
        else 
            std::cout << "🕕";
    else if(time == "07")
        if(_half_time >= 30)
            std::cout << "🕢";
        else 
            std::cout << "🕖";
    else if(time == "08")
        if(_half_time >= 30)
            std::cout << "🕣";
        else 
            std::cout << "🕗";
    else if(time == "09")
        if(_half_time >= 30)
            std::cout << "🕤";
        else 
            std::cout << "🕘";
    else if(time == "10")
        if(_half_time >= 30)
            std::cout << "🕥";
        else 
            std::cout << "🕙";
    else if(time == "11")
        if(_half_time >= 30)
            std::cout << "🕦";
        else 
            std::cout << "🕚";
    else if(time == "00")
        if(_half_time >= 30)
            std::cout << "🕧";
        else 
            std::cout << "🕛";
    else std::cout << "";
}