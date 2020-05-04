/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */
#include <Syntax/Linker.hpp>

FMain *main_string = new FMain();

using namespace FLinker;



FLinkerAndSign::FLinkerAndSign()
{

}


FLinkerAndSign::~FLinkerAndSign()
{

}

boolean
FLinkerAndSign::AndAndSignExists()
{
   if(main_string->_h_str.rfind(andsign, 0) == 0)
   {
       std::cout << "Found\n";
       return true;
   } else {
       return false;
   }

}


fchar 
FLinkerAndSign::AndAndSign()
{

}

// For Testing