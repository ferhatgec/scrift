#ifndef GET_NAME_FUNCTION_HPP
#define GET_NAME_FUNCTION_HPP

#include "../main.h"

class FGetUsername {
public:
    virtual func InitUsername();
    virtual func GetUsername();
    virtual func InitHostname();
};


class FStructure : public FGetUsername {
public:
    FStructure();
    ~FStructure();
    virtual func Terminal();
    virtual func FuncKill();
};
#endif // GET_NAME_FUNCTION_HPP