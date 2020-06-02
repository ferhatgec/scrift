/****************************************************
# GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# 
*****************************************************/

#include "../include/Library/FConio.h"

struct textinfo text={0, 0};

int getche()
{
        struct termios t;
        int c;

	tcgetattr(0,&t);
        t.c_lflag&=~ICANON;
        tcsetattr(0,TCSANOW,&t);
        fflush(stdout);
        c=getchar();
        t.c_lflag|=ICANON;
        tcsetattr(0,TCSANOW,&t);
        return c;
}

int getch()
{
        struct termios t;
        int c;

        tcgetattr(0,&t);
        t.c_lflag&=~ECHO+~ICANON;
        tcsetattr(0,TCSANOW,&t);
        fflush(stdout);
        c=getchar();
        t.c_lflag|=ICANON+ECHO;
        tcsetattr(0,TCSANOW,&t);
        return c;
}

void gotoxy(int x, int y)
{
printf("%c[%d;%dH", ESC, y, x);
text.curx = x;
text.cury = y;
}

void clreol()
{
printf("%c[K", ESC);
}

void clrscr()
{
printf("%c[2J", ESC);
gotoxy(0, 0);
}

void textcolor(int color)
{
if(color >= BLACK && color <= LIGHTGRAY ) /* dark color */
 printf ("%c[0;%dm", ESC, 30+color);
else	
 printf("%c[1;%dm", ESC, 30+(color-8));
}

void textbackground(int color)
{
printf ("%c[%dm", ESC, 40+color);
}
 
int wherex(void)
{
 return text.curx;
}

int wherey(void)
{
 return text.cury;
}
