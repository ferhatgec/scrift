/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#ifndef VALUE_HPP
#define VALUE_HPP

#include <cstring>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "../../main.h"
class VM;

enum class TypeFunction {
    NUL,
    STRING,
    NUMBER,
    BOOL,
    REFERENCE,
    FUNCTION,
    CLASS,
    NAME,
};

class Value {
    typedef Value* (*Method)(Value*, std::vector<Value*>);
    typedef std::unordered_map<std::string, Method> Methods;
    protected:
        union  
        {
           double number;
           std::string* strvalue;
           Methods* methods;
           Method single_method;
        } data;
        
    public:
        TypeFunction type;
        Value();
        Value(TypeFunction);
        Value(TypeFunction, std::string);
        Value(TypeFunction, double);

        virtual void SetTypeFunc(TypeFunction);
        std::string Print(boolean  printtype = false);
        Value* CloneValue();

        std::string GetString();
        double GetNumber();
        boolean GetBoolean();

        void Init() {};

        Value* exec_method(std:string,
        std::vecotr<Value*>);

        func AddMethod(std::string, Method);
        boolean HasMethod(std::string);
};

#endif // VALUE_HPP