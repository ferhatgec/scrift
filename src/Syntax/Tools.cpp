/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <arpa/inet.h>

#include <src/Scrift.hpp>
#include <src/Syntax/Tools.hpp>

#include <Colorized.hpp>

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

void FTools::Date() {
    FMain main;
    std::string time = main.Time().substr(0, 10);

    time = time.erase(0, 5);


    BOLD_LIGHT_WHITE_COLOR
    if(time == "10-12")
        std::cout << "Today, Dennis Ritchie's death date.\n";
    else if(time == "04-04")
        std::cout << "Today, Microsoft's foundation date.\n";
    else if(time == "05-02")
        std::cout << "Today, Ferhat Gecdogan's born date.\n";
    else if(time == "06-07")
        std::cout << "Today, Alan Turing's death date.\n";
    else if(time == "06-23")
        std::cout << "Today, Alan Turing's born date.\n";
    else if(time == "12-30")
        std::cout << "Today, Bjarne Stroustrup's born date.\n";
    else if(time == "03-16")
        std::cout << "Today, Richard Stallman's born date.\n";
    else if(time == "12-28")
        std::cout << "Today, Linus B. Torvald's born date.\n";
    else if(time == "05-11")
        std::cout << "Today, Richard Feynman's born date.\n";
    else if(time == "02-15")
        std::cout << "Today, Richard Feynman's death date.\n";
    else if(time == "02-01")
        std::cout << "Today, Werner Heisenberg's death date.\n";
    else if(time == "01-04")
        std::cout << "Today, Erwin Schrodinger's death date.\n";
    else if(time == "03-14")
        std::cout << "Today, Albert Einstein's born date.\n";
    else if(time == "04-18")
        std::cout << "Today, Albert Einstein's death date.\n";

    BLACK_COLOR
}

void FTools::ResolutionSizeInfo(std::string file) {
    std::string extension = std::filesystem::path(file).extension();

    auto iter = std::find(ext.begin(), ext.end(), extension);

    if(iter != ext.end()) {
        res_t data_info;

        /* :& */
        if(extension == ".jpg"
            || extension == ".jpeg") data_info = JPEGInfo(file);
        else if(extension == ".png") data_info = PNGInfo(file);

        BOLD_LIGHT_YELLOW_COLOR std::cout << "Width: ";
        BOLD_LIGHT_RED_COLOR    std::cout << data_info.width;

        BOLD_LIGHT_YELLOW_COLOR std::cout << "\nHeight: ";
        BOLD_LIGHT_RED_COLOR    std::cout << data_info.height << "\n";
    }
}

res_t FTools::JPEGInfo(std::string& file) {
    std::ifstream readfile(file, std::ifstream::binary);

    res_t data_info;

    std::string data((std::istreambuf_iterator<char>(readfile)),
                    (std::istreambuf_iterator<char>()));

    auto* marker = reinterpret_cast<unsigned char*>(&data[0]);

    unsigned i = 0;

    for(;;) {
        if((unsigned short)marker[i] == 0xFF && (unsigned short)marker[i + 1] == 0xC0) break;

        ++i;
    }

    data_info.width  = static_cast<unsigned short>(marker[i + 8]);
    data_info.height = static_cast<unsigned short>(marker[i + 6]);

    return data_info;
}

res_t FTools::PNGInfo (std::string& file) {
    std::ifstream readfile(file);

    res_t data_info;

    readfile.seekg(16);
    readfile.read(reinterpret_cast<char *>(&data_info.width), 4);
    readfile.read(reinterpret_cast<char *>(&data_info.height), 4);

    data_info.width = ntohl(data_info.width);
    data_info.height= ntohl(data_info.height);

    return data_info;
}
