/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef INTELLIGENTUI_HPP
#define INTELLIGENTUI_HPP

#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <string>
#include <thread>

namespace IntelligenTUI {
	void ProgressBar(std::ostream& os, int time, std::string message, std::string symbol) {
    	static const auto bar_length = 60;
    	
    	if (message.length() >= bar_length) {
        	os << message << '\n';
        	message.clear();
    	};
 	   	

    	const auto progress_level = 100.0 / (bar_length - message.length());

    	std::cout << message;

	    for (double percentage = 0; percentage <= 100; percentage += progress_level) {
    	    message += symbol + ">";
    	    os << "\r[" << std::setw(3) << static_cast<int>(percentage) << "%] " << message << std::flush;
        	std::this_thread::sleep_for(std::chrono::milliseconds(time));
    	
    		message.pop_back();
    	}
    
		os << "]\n";
	}
}

#endif // INTELLIGENTUI_HPP
