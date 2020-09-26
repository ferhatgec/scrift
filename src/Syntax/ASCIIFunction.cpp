/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>
#include <pwd.h>

#include <src/Syntax/FileFunction.hpp>
#include <src/Syntax/ASCIIFunction.hpp>
#include <src/synflang.hpp>
#include <src/Scrift.hpp>
#include <src/Syntax/Log.hpp>

/* Library */
#include <Colorized.hpp>

inline bool 
FASCIIFunction::InitFile() {
   struct stat buffer;
   std::string path;
   path.append(getenv("HOME"));
   path.append("/");
   path.append(".scrift_ascii");   
   return (stat (path.c_str(), &buffer) == 0); 
}

void 
FASCIIFunction::GenerateString()  {
   if(InitFile() == true) {
	   FeLog logfunc;	
	   logfunc.WriteLog("ASCIIFile is exists! Nice - ");
   } else {
	   FileFunction::FCreateFileFunction createfilefunc;
   	createfilefunc.CreateASCIIFileFunction();
   }
}  

void 
FASCIIFunction::Allofthem() {
   FileFunction::FReadFileFunction readfilefunc;
   GenerateString();
   readfilefunc.ReadASCIIFunction();    
}
