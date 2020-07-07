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
    bool IsExist();   
    const std::string TimeFunction();
    void CreateFile();
    void WriteAllHistory();
    void WriteHistory(fstr);
    void ClearHistory();
    void AllofThem();
};





#endif // HISTORY_HPP
