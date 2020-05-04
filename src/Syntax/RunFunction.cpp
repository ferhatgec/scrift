/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include <main.h>
#include <Syntax/RunFunction.hpp>
#include <Syntax/Language.hpp>
#include <pwd.h>
#include <Syntax/CommandFunc.h>

std::string directory;
FRunFunction::FRunFunction()
{

}


FRunFunction::~FRunFunction()
{
    
}


void
FRunFunction::RunFunction(std::string name)
{
    directory = "/usr/bin/" + name;
    system(directory.c_str());
}
