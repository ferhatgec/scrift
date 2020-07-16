/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef STRING_TOOLS_H
#define STRING_TOOLS_H

#include <iostream>
#include <cstring>

namespace stringtools {
	static std::string EraseAllSubString(std::string & mainString, const std::string & erase) {
    		size_t pos = std::string::npos;
   		while((pos = mainString.find(erase)) != std::string::npos) {
        		mainString.erase(pos, erase.length());
  		}
  		return mainString;
  	}
  	
  	static int IntConverter(const char *s) {
  		int sum = 0;
  		char ch;
  		char sign = *s;
 		if (*s == '-' || *s == '+') s++;
  		while ((ch = *s++) >= '0' && ch <= '9') {
    			sum = sum * 10 - (ch - '0');
  		}
  		if (sign != '-') {
    			sum = -sum;
  		}
  		return sum;
	}
	
	static int IntConverterWithWhitespace(char* s) {
		int sum = 0;
  		char ch;
  		std::string conv(s); 
  		s = const_cast<char*>(EraseAllSubString(conv, " ").c_str());
 		char sign = *s;
 		if (*s == '-' || *s == '+') s++;
  		while ((ch = *s++) >= '0' && ch <= '9') {
    			sum = sum * 10 - (ch - '0');
  		}
  		if (sign != '-') {
    			sum = -sum;
  		}
  		return sum;
	}
	
	static std::string GetBetweenString(std::string oStr, std::string sStr1, std::string sStr2) {  
    		int start = oStr.find(sStr1);   
    		if (start >= 0) {       
     			std::string tstr = oStr.substr(start + sStr1.length());        
      			int stop = tstr.find(sStr2);      
      			if (stop >1)          
        			return oStr.substr(start + sStr1.length(), stop);
      			else
        			return "error";  
    		}
    		else
       		return "error"; 
	}	
	
	
}

#endif // STRING_TOOLS_H
