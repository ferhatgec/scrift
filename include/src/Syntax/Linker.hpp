/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef LINKER_HPP
#define LINKER_HPP
#include "../synflang.hpp"
#include "../Scrift.hpp"

namespace FLinker {
class FLinkerAndSign {
public:
    FLinkerAndSign();
    ~FLinkerAndSign();
    boolean AndAndSignExists();
    virtual fchar AndAndSign();
private:
    fchar* andsign = "&&"; 
};
};

#endif // LINKER_HPP
