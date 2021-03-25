/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <string>
#include <filesystem>

#include <src/Syntax/Log.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Syntax/ASCIIFunction.hpp>

// C++20 STL standards are not supports 'constexpr basic_string' yet.
#define scrift_ascii_filename ".scrift_ascii"

// Library
bool FASCIIFunction::InitFile() {
   return std::filesystem::exists(std::basic_string(getenv("HOME")) + "/" + std::basic_string(scrift_ascii_filename));
}

void 
FASCIIFunction::GenerateString()  {
    // TODO: Clean-up.
    if(InitFile()) {
	   FeLog logfunc;
	   logfunc.WriteLog("ASCIIFile is exists! Nice - ");
   }
   else {
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
