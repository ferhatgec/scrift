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

    if(time == "01" || time == "13")
        if(_half_time >= 30)
            std::cout << "🕜";
        else 
            std::cout << "🕐";
    else if(time == "02" || time == "14")
        if(_half_time >= 30)
            std::cout << "🕝";
        else 
            std::cout << "🕑";
    else if(time == "03" || time == "15")
        if(_half_time >= 30)
            std::cout << "🕞";
        else
            std::cout << "🕒";
    else if(time == "04" || time == "16")
        if(_half_time >= 30)
            std::cout << "🕟";
        else
            std::cout << "🕓";
    else if(time == "05" || time == "17")
        if(_half_time >= 30)
            std::cout << "🕠";
        else 
            std::cout << "🕔";
    else if(time == "06" || time == "18")
        if(_half_time >= 30)
            std::cout << "🕡";
        else 
            std::cout << "🕕";
    else if(time == "07" || time == "19")
        if(_half_time >= 30)
            std::cout << "🕢";
        else 
            std::cout << "🕖";
    else if(time == "08" || time == "20")
        if(_half_time >= 30)
            std::cout << "🕣";
        else 
            std::cout << "🕗";
    else if(time == "09" || time == "21")
        if(_half_time >= 30)
            std::cout << "🕤";
        else 
            std::cout << "🕘";
    else if(time == "10" || time == "22")
        if(_half_time >= 30)
            std::cout << "🕥";
        else 
            std::cout << "🕙";
    else if(time == "11" || time == "23")
        if(_half_time >= 30)
            std::cout << "🕦";
        else 
            std::cout << "🕚";
    else if(time == "00" || time == "12")
        if(_half_time >= 30)
            std::cout << "🕧";
        else 
            std::cout << "🕛";
    else std::cout << "";
}
