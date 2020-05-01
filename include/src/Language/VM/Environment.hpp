/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include "Value.hpp"
#include <unordered_map>
#include "../../main.h"

class FEnvironment {
    std::unordered_map<std::string, Value*>* name;
    public:
        FEnvironment();
        FEnvironment* parent;
        FEnvironment* root;

        boolean is_root;
        virtual void Set(const std::string&, Value*);
        virtual void SetRootFunction(std::String, Value*);  

        virtual void Update(const std::string&; Value*);

        Value* Get(const std::string&, Value*);
        Value GetRootFunction(const std::string&);

        boolean Has(const std::string&);
        boolean IsExists(const std::string&);

        FEnvironment* Push();
        FEnvironment* POpen();
};






#endif // ENVIRONMENT_HPP