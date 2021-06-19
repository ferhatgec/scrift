/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SETUP_HPP
#define SETUP_HPP

#include <iostream>
#include <cstring>

#define FPM_REPOSITORY "https://github.com/ferhatgec/fpm.git"

class FSetup {
public:
    void Stage1();

    void Config(); /* Settings (.scrift_settings) */
};

#endif // SETUP_HPP
