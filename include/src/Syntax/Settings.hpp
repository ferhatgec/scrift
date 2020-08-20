/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <cstring>
#include <iostream>

class FSettings {
public:
	std::string Path();
	std::string InputCustomize();
	std::string Theme();
	std::string FWelcomeEmoji();
	int BackgroundColor();
	int ASCIIColor();
	int color();
	int random(int, int);
	int FeLogCleaner();
};

#endif // SETTINGS_HPP
