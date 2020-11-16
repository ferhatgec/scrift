/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef GET_HPP
#define GET_HPP

#include <iostream>
#include <cstring>

#define DEFAULT_FPI_REPOSITORY "https://github.com/ferhatgec/repository.git"

class FGet {
public:
	void FetchRepositoryData(std::string repository);
};

#endif // GET_HPP
