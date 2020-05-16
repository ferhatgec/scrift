/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */

#include <iostream>
#include <iomanip>

using namespace std;

int getMonth()
{
   int month = 0;
   cout << "Enter a month number: ";
   cin >> month;

   while (month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n"
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
      cout << "Year must be 1758 or later.\n"
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
      cout << "January " << year << endl;
   else if (month == 2)
      cout << "February " << year << endl;
   else if (month == 3)
      cout << "March " << year << endl;
   else if (month == 4)
      cout << "April " << year << endl;
   else if (month == 5)
      cout << "May " << year << endl;
   else if (month == 6)
      cout << "June " << year << endl;
   else if (month == 7)
      cout << "July " << year << endl;
   else if (month == 8)
      cout << "August " << year << endl;
   else if (month == 9)
      cout << "September " << year << endl;
   else if (month == 10)
      cout << "October " << year << endl;
   else if (month == 11)
      cout << "November " << year << endl;
   else
      cout << "December " << year << endl;
   return;
}

void displayTable(int numDays, int offset, int year, int month)
{
   int day = 0;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   day = ((offset + 1) % 6);
   cout << setw((day - 2) * 4 + 6);

   for (int dayOfWeek = 1; dayOfWeek <= numDaysMonth(year, month); dayOfWeek++)
   {
      cout << "  " << setw(2) << dayOfWeek;
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


int main()
{
   int offset;
   int month;
   int year;

   month = getMonth();
   year = getYear();
   offset = computeOffset(year, month);

   display(year, month, offset);

   return 0;
}
