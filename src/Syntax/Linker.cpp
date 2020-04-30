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


