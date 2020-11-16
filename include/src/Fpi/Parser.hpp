/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <cstring>

class FParser {
public:
	std::string app_name,
				app_desc,
				app_author,
				app_license,
				app_exec,
				app_repo,
				app_folder;
				
	void ParseRepositoryFile(std::string arg);
};

#endif // PARSER_HPP
