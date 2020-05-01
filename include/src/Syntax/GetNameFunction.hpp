#ifndef GET_NAME_FUNCTION_HPP
#define GET_NAME_FUNCTION_HPP

#include "../main.h"

fclass FGetUsername {
public:
    fvirt func InitUsername();
    fvirt func GetUsername();
    fvirt func InitHostname();
};


fclass FStructure : public FGetUsername {
public:
    FStructure();
    ~FStructure();
    fvirt func Terminal();
    fvirt func FuncKill();
};
#endif // GET_NAME_FUNCTION_HPP