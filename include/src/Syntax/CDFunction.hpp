#ifndef CD_FUNCTION_HPP
#define CD_FUNCTION_HPP

#include "GetNameFunction.hpp"

class FCDFunction : public FGetUsername {
public:
    FCDFunction();
    ~FCDFunction();
    virtual void CDFunctionInit();
};

#endif // CD_FUNCTION_HPP