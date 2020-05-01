/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#pragma once
#ifndef LOG_HPP
#define LOG_HPP

#include "../main.h"

class FeLog {
public:
    FeLog();
    ~FeLog();
    virtual func CreateFile();
    virtual func InitFile();
    const std::string TimeFunction();
    virtual func WriteLog(fstr);
    virtual boolean IsExist();
    virtual func AllofThem();
};





#endif // LOG_HPP 