# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
#

GCFLAGS=-std=c++11 -O2 -g -Wall $(shell pkg-config --cflags ncursesw)
GLDFLAGS=$(shell pkg-config --libs ncursesw)

# PATHS 
SRCAPPSDIREC = ./Apps/
SRCLIBDIREC = ./Library/
SRCSYNTAXDIREC = ./src/Syntax/
SRCFETCHEYADIREC = ./src/Fetcheya/
SRCEDIFORDIREC = ./src/Edifor/
GAMESDIREC = ./Games/
SRCDIREC = ./src/
PREFIX = /bin/

INCLUDELIB = ./Library/
INCLUDEDIR = ./include/
CFLAGS = -Wall -I$(INCLUDELIB) -I$(INCLUDEDIR)

GCC = gcc
GPP = g++ -std=c++17
COMP = g++ -c

# CLEAN
CLEANALL = scrift /Games/Castle/castle
CLEAN = *.o
HEADERFILE = CommandFunc.o GetNameFunction.o FileFunction.o RunFunction.o \
Log.o History.o Branch.o Template.o Settings.o HelpFunction.o ASCIIFunction.o

FETCHEYAFILE = Logos.o Fetcheya.o

# Platform
ifeq ($(OS),Windows_NT)
	echo Windows_NT is not supported!
	#CLEAN := del $(CLEAN)
	#CLEANALL := del $(CLEANALL)
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(CLEANALL)
endif

# Build
all: conio headersfile fetchfile edifor main clean

# Build & Install
allp: headersfile fetchfile mainc ediforc date clean 

removeall: uninstall cleanall


runall: all run

gra: runall git

git:
	git add .
	git commit -a
	git push origin master

push:
	git push origin master

nall: cleanall

# Scrift's Core.
headersfile: $(HEADERFILE)

# Integrated Fetcheya into Scrift's Core
fetchfile: $(FETCHEYAFILE)

conio: $(SRCLIBDIREC)FConio.c
	$(GCC) -c -Wno-unused-function -Wno-unused-value $(SRCLIBDIREC)FConio.c -o fconio.o

%.o: $(SRCSYNTAXDIREC)%.cpp
	$(GPP) -Wno-unused-function -Wno-unused-value $(CFLAGS) -c $< -o $@

%.o: $(SRCFETCHEYADIREC)%.cpp
	$(GPP) -Wno-unused-function -Wno-unused-value $(CFLAGS) -c $< -o $@

# Main Build
main: $(SRCDIREC)Scrift.cpp
	$(GPP) $(CFLAGS) -Wno-unused-function -Wno-unused-value $< $(HEADERFILE) $(FETCHEYAFILE) -o scrift
	echo Scrift building successfully!

# Main Build & Install
mainc: $(SRCDIREC)Scrift.cpp
	$(GPP) $(CFLAGS) -Wno-unused-function -Wno-unused-value $< $(HEADERFILE) $(FETCHEYAFILE) -o /bin/scrift
	echo Scrift building successfully in Bin Directory!

# Edifor Build
edifor:
	$(GCC) $(CFLAGS) $(SRCEDIFORDIREC)Edifor.c -o edifor
	echo Edifor building successfully!

# Edifor Build & Install
ediforc:
	$(GCC) $(CFLAGS) $(SRCEDIFORDIREC)Edifor.c -o /bin/edifor
	echo Edifor building successfully in Bin Directory!

# Castle
castle: $(GAMESDIREC)/Castle/Castle.hpp
	$(GPP) $(GCFLAGS) $(GAMESDIREC)/Castle/Castle.cpp -o $(PREFIX)castle $(GLDFLAGS)
	echo Castle building successfully in Bin Directory

# TicTacToe
tictactoe: $(GAMESDIREC)/TicTacToe/TicTacToeMain.cpp
	$(GPP) -Wall $(GAMESDIREC)/TicTacToe/TicTacToeMain.cpp $(GAMESDIREC)/TicTacToe/tictactoe.cpp -o $(PREFIX)tictactoe 
	echo TicTacToe building successfully in Bin Directory!
	
# Pong	
pong: $(GAMESDIREC)/Pong/Pong.cpp
	$(GPP) -Wall $(GAMESDIREC)/Pong/Pong.cpp -o $(PREFIX)pong -lncurses
	echo Pong building successfully in Bin Directory!

# Calendar
date: $(SRCAPPSDIREC)/FDate/FDate.cpp
	$(GPP)  $(SRCAPPSDIREC)/FDate/FDate.cpp -o $(PREFIX)fdate 
	echo FDate building successfully in Bin Directory!

# Fetcheya Build
#fetcheya: $(SRCFETCHEYADIREC)Fetcheya.cpp
#	$(GPP) $(CFLAGS) $(SRCFETCHEYADIREC)Logos.cpp $(SRCFETCHEYADIREC)Fetcheya.cpp -o fetcheya
#	echo Fetcheya building successfully!

# Fetcheya Build & Install
#fetcheyac: $(SRCFETCHEYADIREC)Fetcheya.cpp
#	$(GPP) $(CFLAGS) $(SRCFETCHEYADIREC)Logos.cpp $(SRCFETCHEYADIREC)Fetcheya.cpp -o $(PREFIX)fetcheya
#	echo Fetcheya building successfully in Bin Directory!

uninstall:
	rm -f /bin/scrift
	rm -f /bin/edifor
	rm -f /bin/castle
	rm -f /src/Games/Castle/castle
	rm -f /bin/fdate
	rm -f /bin/pong
	rm -f /bin/tictactoe
	
run:
	./scrift
clean:
		$(CLEAN)

cleanall:
		echo Cleaning build directory!
		$(CLEANALL)
