#ifndef GET_NAME_FUNCTION_HPP
#define GET_NAME_FUNCTION_HPP

#include "../main.h"

class FGetUsername {
public:
    virtual void InitUsername();
    virtual void GetUsername();
    virtual void InitHostname();
};


class FStructure : public FGetUsername {
public:
    FStructure();
    ~FStructure();
    virtual void Terminal();
    virtual void FuncKill();
};
#endif // GET_NAME_FUNCTION_HPP