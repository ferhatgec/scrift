/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef LOG_HPP
#define LOG_HPP

#include "../Scrift.hpp"

/* TODO:
   * Clear.
*/
class FeLog {
public:
    FeLog();
    ~FeLog();

    void CreateFile();
    void InitFile();
    void WriteLog(fstr);
    void ClearLog();
    void AllofThem();

    const std::string TimeFunction();

    bool IsExist();
};

#endif // LOG_HPP 
