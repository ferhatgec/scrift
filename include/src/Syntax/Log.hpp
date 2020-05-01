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
    virtual boolean IsExist();
};





#endif // LOG_HPP 