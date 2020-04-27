# GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
# 
#
SRCSYNTAXDIREC = ./src/Syntax/

SRCDIREC = ./src/
GPP = g++
COMP = g++ -c
HECOMP = g++ -c $< -std=gnu++17 -o
BUILDDIR = ./build/
# CLEAN
CLEANALL = scrift
CLEAN = *.o
HEADERFILE = CommandFunc.o GetNameFunction.o



ifeq ($(OS),Windows_NT)
	echo Windows_NT is not supported!
	#CLEAN := del $(CLEAN)
	#CLEANALL := del $(CLEANALL)
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(BUILDDIR)$(CLEANALL)
endif


all: headersfile headersfile main clean

runall: headersfile headersfile main run clean

nall: cleanall

headersfile: $(HEADERFILE)

CommandFunc.o:$(SRCSYNTAXDIREC)CommandFunc.cpp
		$(HECOMP) CommandFunc.o
		echo Successfuly creating CommandFunc.o

GetNameFunction.o:$(SRCSYNTAXDIREC)GetNameFunction.cpp
		$(HECOMP) GetNameFunction.o
		echo Successfuly creating GetNameFunction.o


main: $(SRCDIREC)main.cpp
	g++  $< $(HEADERFILE) -o $(BUILDDIR)scrift 
	echo Scrift building successfuly!

run: 
	cd build && ./scrift
clean: 
		$(CLEAN)

cleanall:
		echo Cleaning build directory! 
		$(CLEANALL)
