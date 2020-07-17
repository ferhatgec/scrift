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

using namespace std;
int getEpochDifference();
bool isLeapYear(int);
void UNIXTimeToNormalTime(time_t epoch){
   cout<<"Converting UNIX Time to normal time..."<<endl; 
   struct tm UTCTime; /*struct tm is a structure used to hold the time and date.*/
   char buffer[80];
   UTCTime = *localtime(&epoch); //The value of timer is broken up into the structure tm and expressed in the local time zone.
   strftime(buffer /*C style string that these infos will be copied to.*/, sizeof(buffer)/*Maximum number of characters to be copied to ptr, including the terminating null-character.*/, "%d-%m-%Y %H:%M:%S", &UTCTime);
   
   cout<<"Your epoch belongs to this date : (DD/MM/YYYY HH:MM:SS) "<<buffer<<endl;
}
int NormalTimeToUNIXTime(int gun=0,int ay=0, int yil=0, int saat=0, int dakika=0, int saniye=0){


   return (((yil-1970) * 31104000)+((ay)*2592000)+((gun)*86400)+((saat)*3600)+((dakika)*60)+(saniye));

}

int getMonth()
{
   int month = 0;
   cout << "Enter a month number: ";
   cin >> month;

   while (month < 1 || month > 12)
   {
      cout << WBOLD_RED_COLOR << "Month must be between 1 and 12.\n"
           << "Enter a month number: ";
      cin >> month;
   }
   
   return month;
}


int getYear()
{
   int year = 0;
   cout << "Enter year: ";
   cin >> year;

   while (year < 1758)
   {
      cout << WBOLD_RED_COLOR << "Year must be 1758 or later.\n"
           << "Enter year: ";
      cin >> year;
   }
   
   return year;
}


bool isLeapYear(int year)
{
   return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}


int numDaysYear(int year)
{
   return (365 + isLeapYear(year));
}


int numDaysMonth(int year, int month)
{
   int daysMonth = 0;
   if (month == 2 && isLeapYear(year))
   {
      daysMonth = 29;
   }
   
   else if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12)
   {
      daysMonth = 31;
   }
   
   else if (month == 4 || month == 6 || month == 9 || month == 11)
   {
      daysMonth = 30;
   }
   
   else
      daysMonth = 28;

   return daysMonth;
}


int computeOffset(int year, int month)
{
   int offset = 0;
   int count = 0;;
   for (int iYear = 1758; iYear < year; iYear++)
   {
     count += (365 + isLeapYear(iYear));
     /*offset = (offset + 365 + isLeapYear(year - 1)) % 7;*/
   }
   //cout << count << endl;

   offset = count;

   count = 0;
   for (int iMonth = 1; iMonth < month; iMonth++)
   {
     count += numDaysMonth(year, iMonth);
     /*offset = (offset + numDaysMonth(year, iMonth)) % 7;*/
   }
   //cout << count;

   offset += count;
   return (offset % 7);
}


void displayHeader(int year, int month)
{
   cout << endl;
   if (month == 1)
      cout << WBOLD_YELLOW_COLOR << "January " << year << endl;
   else if (month == 2)
      cout << WBOLD_RED_COLOR << "February " << year << endl;
   else if (month == 3)
      cout << WBOLD_GREEN_COLOR << "March " << year << endl;
   else if (month == 4)
      cout << WBOLD_BLUE_COLOR << "April " << year << endl;
   else if (month == 5)
      cout << WBOLD_GREEN_COLOR << "May " << year << endl;
   else if (month == 6)
      cout << WBOLD_YELLOW_COLOR << "June " << year << endl;
   else if (month == 7)
      cout << WBOLD_YELLOW_COLOR << "July " << year << endl;
   else if (month == 8)
      cout << WBOLD_BLUE_COLOR <<  "August " << year << endl;
   else if (month == 9)
      cout << WBOLD_MAGENTA_COLOR << "September " << year << endl;
   else if (month == 10)
      cout << WBOLD_CYAN_COLOR << "October " << year << endl;
   else if (month == 11)
      cout << WBOLD_RED_COLOR << "November " << year << endl;
   else
      cout << WBOLD_GREEN_COLOR << "December " << year << endl;
   return;
}

void displayTable(int numDays, int offset, int year, int month)
{
   int day = 0;
   cout << WBOLD_GREEN_COLOR  << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   day = ((offset + 1) % 6);
   cout << setw((day - 2) * 4 + 6);

   for (int dayOfWeek = 1; dayOfWeek <= numDaysMonth(year, month); dayOfWeek++)
   {
      cout << "  " << WBOLD_MAGENTA_COLOR << setw(2) << dayOfWeek;
      ++day;
      if (day == 8)
      {
         cout << endl;
         day = 1;
      }
   }
   return;
}


void display(int year, int month, int offset)
{
   int numDays = numDaysMonth(year, month);
   displayHeader(year, month);
   displayTable(numDays, offset, year, month);
   cout << endl;   
}
int getEpochDifference(){ //Returns the epoch value between current date and 1/1/1970. Simple.

   return time(NULL);

}

int main(int argc, char* argv[])
{
   cout<<WBOLD_GREEN_COLOR<<"Welcome to FDate!"<<endl<<endl;

   if(strcmp(argv[argc-1],"-currentUNIX") == 0){

      cout<<WBOLD_RED_COLOR<<"Current UNIX Time is : "<<getEpochDifference()<<endl<<endl;

      cout<<WBOLD_MAGENTA_COLOR<<"Run FDate with -help parameter to see all available parameters."<<endl<<endl;
      exit(EXIT_SUCCESS);

   }
   else if(strcmp(argv[argc-1],"-fromUNIX") == 0){

         int unixTimestamp;
         cout<<WBOLD_YELLOW_COLOR<<"Enter the UNIX time that you want to convert to real date."<<endl;
         cin>>unixTimestamp;
         UNIXTimeToNormalTime(unixTimestamp);
         exit(EXIT_SUCCESS);


   }
   else if(strcmp(argv[argc-1],"-toUNIX") == 0){
         int dd,mm,yyyy,hh,minute,ss;
         cout<<WBOLD_CYAN_COLOR<<"Enter the date that you want to convert to UNIX date. (DD/MM/YYYY) "<<endl;
         cout<<"Day : ";
         cin>>dd;
            if(dd < 1 || dd > 31){

         cout<<WBOLD_RED_COLOR<<"Day entry is wrong. Aborting."<<endl;
         exit(0);
   }
         cout<<"Month : ";
         cin>>mm;
            if(mm < 1 || mm > 12){

         cout<<WBOLD_RED_COLOR<<"Month entry is wrong. Aborting."<<endl;
         exit(0);
   }
         cout<<"Year : ";
         cin>>yyyy;
            if(yyyy < 1970 || yyyy >= 2038){

         cout<<WBOLD_RED_COLOR<<"Year entry is wrong. Aborting."<<endl;
         exit(0);
   }
         cout<<"Hour : ";
         cin>>hh;
            if(hh < 0 || hh > 23){

         cout<<WBOLD_RED_COLOR<<"Hour entry is wrong. Aborting."<<endl;
         exit(0);
   }
         cout<<"Minute : ";
         cin>>mm;
            if(mm < 0 || mm > 59){

         cout<<WBOLD_RED_COLOR<<"Minute entry is wrong. Aborting."<<endl;
         exit(0);
   }
         cout<<"Second : ";
         cin>>ss;
            if(ss < 0 || ss > 59){

         cout<<WBOLD_RED_COLOR<<"Seconds entry is wrong. Aborting."<<endl;
         exit(0);
   }
         cout<<"The date you entered belongs to this epoch : "<<NormalTimeToUNIXTime(dd,mm,yyyy,hh,minute,ss)<<endl;
         exit(EXIT_SUCCESS);

   }
   else if(strcmp(argv[argc-1],"-help") == 0){

         cout<<endl<<"***************FDate Help***************"<<endl<<endl<<endl;
         cout<<"Available parameters are : "<<endl<<"-toUNIX (converts UTC clock to UNIX clock.)"<<endl<<"-fromUNIX (converts UNIX Clock to UTC.)"<<endl<<"-currentUNIX (displays current UNIX Clock.)"<<endl<<endl;
         cout<<WBOLD_YELLOW_COLOR<<"You can launch the FDate without parameters also. That will display a calendar of the month that you've entered."<<endl;

         exit(EXIT_SUCCESS);
   }

   int offset;
   int month;
   int year;

   month = getMonth();
   year = getYear();
   offset = computeOffset(year, month);

   display(year, month, offset);

   return 0;
}
