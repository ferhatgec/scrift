/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include <main.h>
#include <Syntax/RunFunction.hpp>

std::string directory;


FRunFunction::FRunFunction()
{

}


FRunFunction::~FRunFunction()
{

}


void
FRunFunction::RunFunctionInit()
{

}   


boolean
FRunFunction::RunFunctionExists()
{

}

void
FRunFunction::RunFunction(std::string name)
{
    directory.append("/usr/bin/");
    directory.append(name);
    system(directory.c_str());
}

