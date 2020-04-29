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

