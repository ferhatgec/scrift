/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# UNIX Time Conversions added by Ali Sancakli <github.com/TerabyteForever>
#
# */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>

#include "../../include/src/Scrift.hpp"

// Library
#include "../../Library/Colorized.hpp"

int getEpochDifference();
bool isLeapYear(int);

void UNIXTimeToNormalTime(time_t epoch){
   std::cout << "Converting UNIX Time to normal time...\n"; 

   struct tm UTCTime; /* struct tm is a structure used to hold the time and date. */

   char buffer[80];
   UTCTime = *localtime(&epoch); /* The value of timer is broken up into the structure tm and expressed in the local time zone. */
   strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &UTCTime);
   
   std::cout << "Your epoch belongs to this date : (DD/MM/YYYY HH:MM:SS) " << buffer << "\n";
}

int NormalTimeToUNIXTime(int day,int month, int year, int hour, int minute, int second){
   return (((year-1970) * 31104000)+((month)*2592000)+((day)*86400)+((hour)*3600)+((minute)*60)+(second));
}

int getMonth() {
   int month = 0;
   std::cout << "Enter a month number: ";
   std::cin >> month;

   if (month < 1 || month > 12) {
	std::cout << WBOLD_RED_COLOR << "Month must be between 1 and 12.\n";
        exit(EXIT_SUCCESS);
   }

   return month;
}


int getYear() {
   int year = 0;
   std::cout << "Enter year: ";
   std::cin >> year;

   if (year < 1758) {
   	std::cout << WBOLD_RED_COLOR << "Year must be 1758 or later.\n";
        exit(EXIT_SUCCESS);
   } 
   
   return year;
}


bool isLeapYear(int year) {
   return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}


int numDaysYear(int year) {
   return (365 + isLeapYear(year));
}


int numDaysMonth(int year, int month) {
   int daysMonth = 0;
   if (month == 2 && isLeapYear(year))
      daysMonth = 29;
   else if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12)
      daysMonth = 31;
   else if (month == 4 || month == 6 || month == 9 || month == 11)
      daysMonth = 30;
   else
      daysMonth = 28;

   return daysMonth;
}


int computeOffset(int year, int month) {
   int offset = 0;
   int count = 0;;
   for (int iYear = 1758; iYear < year; iYear++) {
     count += (365 + isLeapYear(iYear));
     /*offset = (offset + 365 + isLeapYear(year - 1)) % 7;*/
   }

   /* std::cout << count << "\n"; */

   offset = count;

   count = 0;
   for (int iMonth = 1; iMonth < month; iMonth++) {
     count += numDaysMonth(year, iMonth);
     /*offset = (offset + numDaysMonth(year, iMonth)) % 7;*/
   }
   // std::cout << count;

   offset += count;
   return (offset % 7);
}


void displayHeader(int year, int month) {
   std::cout << "\n";
   if (month == 1)
      std::cout << WBOLD_YELLOW_COLOR << "January " << year << "\n";
   else if (month == 2)
      std::cout << WBOLD_RED_COLOR << "February " << year << "\n";
   else if (month == 3)
      std::cout << WBOLD_GREEN_COLOR << "March " << year << "\n";
   else if (month == 4)
      std::cout << WBOLD_BLUE_COLOR << "April " << year << "\n";
   else if (month == 5)
      std::cout << WBOLD_GREEN_COLOR << "May " << year << "\n";
   else if (month == 6)
      std::cout << WBOLD_YELLOW_COLOR << "June " << year << "\n";
   else if (month == 7)
      std::cout << WBOLD_YELLOW_COLOR << "July " << year << "\n";
   else if (month == 8)
      std::cout << WBOLD_BLUE_COLOR <<  "August " << year << "\n";
   else if (month == 9)
      std::cout << WBOLD_MAGENTA_COLOR << "September " << year << "\n";
   else if (month == 10)
      std::cout << WBOLD_CYAN_COLOR << "October " << year << "\n";
   else if (month == 11)
      std::cout << WBOLD_RED_COLOR << "November " << year << "\n";
   else
      std::cout << WBOLD_GREEN_COLOR << "December " << year << "\n";
   return;
}

void displayTable(int numDays, int offset, int year, int month) {
   int day = 0;
   std::cout << WBOLD_GREEN_COLOR  << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   day = ((offset + 1) % 6);
   std::cout << std::setw((day - 2) * 4 + 6);

   for (int dayOfWeek = 1; dayOfWeek <= numDaysMonth(year, month); dayOfWeek++) {
      std::cout << "  " << WBOLD_MAGENTA_COLOR << std::setw(2) << dayOfWeek;
      ++day;
      if (day == 8) {
         std::cout << "\n";
         day = 1;
      }
   }
   return;
}


void display(int year, int month, int offset) {
   int numDays = numDaysMonth(year, month);
   displayHeader(year, month);
   displayTable(numDays, offset, year, month);
   std::cout << "\n";   
}

int getEpochDifference() { /* Returns the epoch value between current date and 1/1/1970. Simple. */
   return time(NULL);
}

/*
	--currentUNIX
	--fromUNIX
	--toUNIX
*/
int main(int argc, char* argv[]) {
   std::cout << WBOLD_GREEN_COLOR << "Welcome to FDate!\n\n";

   if(strcmp(argv[argc-1],"--currentUNIX") == 0){
      std::cout << WBOLD_RED_COLOR << "Current UNIX Time is : " << getEpochDifference() << "\n\n" << 
      	WBOLD_MAGENTA_COLOR << "Run FDate with --help parameter to see all available parameters.\n\n";

      exit(EXIT_SUCCESS);
   } else if(strcmp(argv[argc-1],"--fromUNIX") == 0){
         int unixTimestamp;
         std::cout << WBOLD_YELLOW_COLOR << "Enter the UNIX time that you want to convert to real date.\n";
         std::cin >> unixTimestamp;
         UNIXTimeToNormalTime(unixTimestamp);
         exit(EXIT_SUCCESS);
   } else if(strcmp(argv[argc-1],"--toUNIX") == 0){
         int dd,mm,yyyy,hh,minute,ss;
         std::cout << WBOLD_CYAN_COLOR << "Enter the date that you want to convert to UNIX date. (DD/MM/YYYY) \n";
         std::cout << "Day : ";
         std::cin >> dd;
         
	 if(dd < 1 || dd > 31) {
        	std::cout << WBOLD_RED_COLOR << "Day entry is wrong. Aborted.\n";
         	exit(0);
   	 }
         std::cout << "Month : ";
         std::cin >> mm;
         if(mm < 1 || mm > 12) {
         	std::cout<<WBOLD_RED_COLOR<<"Month entry is wrong. Aborted.\n";
        	exit(0);
   	 }
         std::cout << "Year : ";
         std::cin >> yyyy;
         if(yyyy < 1970 || yyyy >= 2038) {
         	std::cout << WBOLD_RED_COLOR << "Year entry is wrong. Aborted.\n";
         	exit(0);
   	 }
         std::cout << "Hour : ";
         std::cin >> hh;
         if(hh < 0 || hh > 23) {
         	std::cout << WBOLD_RED_COLOR << "Hour entry is wrong. Aborted.\n";
         	exit(0);
   	 }
         std::cout << "Minute : ";
         std::cin >> mm;
         if(mm < 0 || mm > 59) {
         	std::cout << WBOLD_RED_COLOR << "Minute entry is wrong. Aborted.\n";
         	exit(0);
   	 }
         std::cout << "Second : ";
         std::cin >> ss;
         if(ss < 0 || ss > 59) {
         	std::cout << WBOLD_RED_COLOR << "Seconds entry is wrong. Aborted\n";
         	exit(0);
   	 }
         
	 std::cout << "The date you entered belongs to this epoch : " << NormalTimeToUNIXTime(dd,mm,yyyy,hh,minute,ss) << "\n";
         exit(EXIT_SUCCESS);
   	} else if(strcmp(argv[argc-1],"--help") == 0){
         	std::cout << "\n";
         	std::cout << "Available parameters are : \n-toUNIX (converts UTC clock to UNIX clock.)\n" << 
			"-fromUNIX (converts UNIX Clock to UTC.)\n-currentUNIX (displays current UNIX Clock.)\n\n" << WBOLD_YELLOW_COLOR <<
			"You can launch the FDate without parameters also. That will display a calendar of the month that you've entered.\n";
         	exit(EXIT_SUCCESS);
   	}

   	int offset, month, year;

   	month = getMonth();
   	year = getYear();
   	offset = computeOffset(year, month);

   	display(year, month, offset);

   	return 0;
}
