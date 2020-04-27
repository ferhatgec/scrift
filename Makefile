# GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
# 
#
LANGDIREC = ./Lang/
SRCSTTNGSDIREC = ./src/Settings/
SRCSYNTAXDIREC = ./src/Syntax/

SRCDIREC = ./src/
GPP = g++
COMP = g++ -c
HECOMP = g++ -c $< -std=gnu++2a -o
BUILDDIR = ./build/
# CLEAN
CLEANALL = scrift
CLEAN = *.o
HEADERFILE = DefaultSettings.o CommandFunc.o


LANGHEADERSFILE = Language.o Reader.o


ifeq ($(OS),Windows_NT)
	echo Windows_NT is not supported!
	#CLEAN := del $(CLEAN)
	#CLEANALL := del $(CLEANALL)
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(BUILDDIR)$(CLEANALL)
endif


all: langheadersfile headersfile headersfile main clean

allrun: langheadersfile headersfile headersfile main run clean

nall: cleanall


langheadersfile: $(LANGHEADERSFILE)

Language.o: $(LANGDIREC)Language.cpp
			$(HECOMP) Language.o
			echo Successfuly creating Language.o

Reader.o: $(LANGDIREC)Reader.cpp
			$(HECOMP) Reader.o
			echo Successfuly creating Reader.o

headersfile: $(HEADERFILE)


DefaultSettings.o:$(SRCSTTNGSDIREC)DefaultSettings.cpp
		$(HECOMP) DefaultSettings.o
		echo Successfuly creating DefaultSettings.o

CommandFunc.o:$(SRCSYNTAXDIREC)CommandFunc.cpp
		$(HECOMP) CommandFunc.o
		echo Successfuly creating CommandFunc.o

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
