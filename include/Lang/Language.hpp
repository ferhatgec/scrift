#ifndef LANGUAGE_H
#define LANGUAGE_H
#include "Reader.hpp"
#include "../src/main.h"
class FLanguage {
public:
    FLanguage();
    ~FLanguage();
    fchar *_file_;
    fchar *_pr_key;
    fchar *_func_key;
    virtual void var(integer,fchar *,fchar *);
    virtual void Init(fchar *);
    virtual void String(fchar *);
    virtual void Print(fchar *,fchar *);
    virtual void Func(fchar *, fchar *, fchar *, fchar *);
    void CreateScriftFile(fchar *, fchar *, fchar *);

};








#endif // LANGUAGE_H