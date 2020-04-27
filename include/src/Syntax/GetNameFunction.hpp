#include "../main.h"
#ifndef GET_NAME_FUNCTION_HPP
#define GET_NAME_FUNCTION_HPP

class FGetUsername {
public:
    virtual void InitUsername();
    virtual void GetUsername();
    virtual void InitHostname();
private:
    fchar* username;
};


class FStructure : public FGetUsername {
public:
    FStructure();
    ~FStructure();
    virtual void Terminal();
    virtual void FuncKill();
};
#endif 