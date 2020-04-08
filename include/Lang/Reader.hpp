#ifndef READER_HPP
#define READER_HPP
#include "Language.hpp"

class FReader {
public:
    FReader();
    ~FReader();
    virtual void ReadPrintFunc();
    virtual void ReadFunc();
    void Init();
};







#endif // READER_H