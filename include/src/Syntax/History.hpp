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
    void WriteHistory(std::string element);
   
    void ClearHistory();
    void AllofThem();
    
    void WriteInHistory(std::string element);
};





#endif // HISTORY_HPP
