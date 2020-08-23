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
	/*
		welcome message, local git branches etc.
	*/
	bool WelcomeMessage();
	bool GitBranch();

	/*
		theme, path etc.
	*/
	std::string Path();
	std::string InputCustomize();
	std::string Theme();
	std::string FWelcomeEmoji();
	
	/*
		color option etc.
	*/	
	int BackgroundColor();
	int ASCIIColor();
	int color();
	int random(int, int);
	int FeLogCleaner();
};

#endif // SETTINGS_HPP
