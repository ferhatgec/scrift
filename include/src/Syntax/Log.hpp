#pragma once
#ifndef LOG_HPP
#define LOG_HPP

#include "../main.h"



fclass FeLog {
public:
    FeLog();
    ~FeLog();
    fvirt func CreateFile();
    fvirt func InitFile();
    virtual boolean IsExist();
};





#endif // LOG_HPP 