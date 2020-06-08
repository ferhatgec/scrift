/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef FCONIO_H
#define FCONIO_H

#ifndef _TERMIOS_H
#include <termios.h>
#endif
#ifndef _STDIO_H
#include <stdio.h>
#endif

#define ESC 033 

struct textinfo
{
 int curx;
 int cury; 
};

enum
{
 BLACK,
 RED,
 GREEN,
 BROWN,
 BLUE,
 MAGENTA,
 CYAN,
 LIGHTGRAY,
 DARKGRAY,
 LIGHTRED,
 LIGHTGREEN,
 YELLOW,
 LIGHTBLUE,
 LIGHTMAGENTA,
 LIGHTCYAN,
 WHITE,
};

int getche(void);
int getch(void);
void clreol(void);
void clrscr(void);
void gotoxy(int, int);
void textcolor(int);
void textbackground(int);
int wherex(void);
int wherey(void);

#endif /* FCONIO_H */

