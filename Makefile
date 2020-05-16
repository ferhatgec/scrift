# GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
#
GCFLAGS=-std=c++11 -O2 -g -Wall $(shell pkg-config --cflags ncursesw)
GLDFLAGS=$(shell pkg-config --libs ncursesw)
SRCAPPSDIREC = ./src/Apps/
PREFIX = /bin/
SRCSYNTAXDIREC = ./src/Syntax/
INCLUDEDIR = ./include/src/
CFLAGS = -c -Wall -I$(INCLUDEDIR)
GAMESDIREC = ./src/Games/
SRCDIREC = ./src/
GPP = g++
COMP = g++ -c
HECOMP = g++ -c $< -std=gnu++17 -o
# CLEAN
CLEANALL = scrift /src/Games/Castle/castle
CLEAN = *.o
HEADERFILE = CommandFunc.o GetNameFunction.o FileFunction.o RunFunction.o Linker.o \
Log.o History.o Configuration.o

ifeq ($(OS),Windows_NT)
	echo Windows_NT is not supported!
	#CLEAN := del $(CLEAN)
	#CLEANALL := del $(CLEANALL)
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(CLEANALL)
endif


all: headersfile main clean

allp: headersfile mainc castle buildc fetcheya date clean 

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

headersfile: $(HEADERFILE)


%.o: $(SRCSYNTAXDIREC)%.cpp
	$(GPP) $(CFLAGS) -c $< -o $@


main: $(SRCDIREC)Scrift.cpp
	$(GPP) $< $(HEADERFILE) -o scrift
	echo Scrift building successfully!

mainc: $(SRCDIREC)Scrift.cpp
	$(GPP) $< $(HEADERFILE) -o /bin/scrift
	echo Scrift building successfully in Bin Directory!

buildc:
	$(GPP) $(SRCDIREC)Edifor.cpp -o /bin/edifor
	echo Edifor building successfully in Bin Directory!



castle: $(GAMESDIREC)/Castle/Castle.hpp
	g++ $(GCFLAGS) $(GAMESDIREC)/Castle/Castle.cpp -o /bin/castle $(GLDFLAGS)

date: $(SRCAPPSDIREC)/Date/Date.cpp
	g++  $(SRCAPPSDIREC)/Date/Date.cpp -o $(PREFIX)fdate 


fetcheya: $(SRCSYNTAXDIREC)Fetcheya.cpp
	$(GPP) $(SRCSYNTAXDIREC)Fetcheya.cpp -o $(PREFIX)fetcheya
	echo Fetcheya building successfully in Bin Directory!


clean:
	rm -f castle
	rm -f fetcheya

uninstall:
	rm -f /bin/scrift
	rm -f /bin/edifor
	rm -f /bin/castle
	rm -f /src/Games/Castle/castle
	rm -f /bin/fdate
	
run:
	./scrift
clean:
		$(CLEAN)

cleanall:
		echo Cleaning build directory!
		$(CLEANALL)
