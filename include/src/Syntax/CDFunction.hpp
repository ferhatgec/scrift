#ifndef CD_FUNCTION_HPP
#define CD_FUNCTION_HPP

#include "GetNameFunction.hpp"

class FCDFunction : public FGetUsername {
public:
    FCDFunction();
    ~FCDFunction();
    virtual void CDFunctionInit();
    virtual bool FileExists(const std::string &);
};

#endif // CD_FUNCTION_HPP