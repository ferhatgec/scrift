#ifndef LANGUAGE_H
#define LANGUAGE_H
#include "Reader.hpp"
#include "../src/main.h"
class FLanguage {
public:
    FLanguage();
    ~FLanguage();
    char *_file_;
    char *_pr_key;
    char *_func_key;
    virtual void var(int,char *,char *);
    virtual void Init(char *);
    virtual void String(char *);
    virtual void Print(char *,char *);
    virtual void Func(char *, char *, char *, char *);
    void CreateScriftFile(char *, char *, char *);

};








#endif // LANGUAGE_H