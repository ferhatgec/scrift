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

    void CreateFile();

    void ClearHistory();

    void AllofThem();

    void WriteInHistory(const std::string &element);
};


#endif // HISTORY_HPP
