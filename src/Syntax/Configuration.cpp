/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <Syntax/Configuration.hpp>
#include <Syntax/FileFunction.hpp>

FConfiguration::FConfiguration()
{

}

FConfiguration::~FConfiguration()
{
    
}

boolean
FConfiguration::JamExists()
{
      const std::string jam_path = "/usr/local/bin/jam";
      file_exist.FileExist(jam_path);
}


func
FConfiguration::JamConfiguration(std::string name)
{
    if (JamExists() == true)
    {
          run_jam_function->RunJamFunction(name);
    } else {
        exit(EXIT_SUCCESS); // cls and brk command
      }
}
