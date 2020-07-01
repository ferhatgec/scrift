/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef HISTORY_HPP
#define HISTORY_HPP

#include "../Scrift.hpp"

class FHistory {
public:
    FHistory();
    ~FHistory();
    virtual func CreateFile();
    virtual func InitFile();
    const std::string TimeFunction();
    virtual func WriteHistory(fstr);
    virtual boolean IsExist();
    virtual func ClearHistory();
    virtual func AllofThem();
};





#endif // HISTORY_HPP
