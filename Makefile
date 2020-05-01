# GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
# 
#
SRCLANGUAGEDIREC = ./src/Language/
SRCSYNTAXDIREC = ./src/Syntax/
INCLUDEDIR = ./include/src/
CFLAGS = -c -Wall  -I$(INCLUDEDIR)
SRCDIREC = ./src/
GPP = g++
COMP = g++ -c
HECOMP = g++ -c $< -std=gnu++17 -o
BUILDDIR = ./build/
# CLEAN
CLEANALL = scrift
CLEAN = *.o

HEADERFILE = CommandFunc.o GetNameFunction.o FileFunction.o RunFunction.o Linker.o \
Log.o

LANGUAGEFILE = RunFunction.o  

ifeq ($(OS),Windows_NT)
	echo Windows_NT is not supported!
	#CLEAN := del $(CLEAN)
	#CLEANALL := del $(CLEANALL)
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(BUILDDIR)$(CLEANALL)
endif


all: headersfile  languagefile main clean

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
languagefile: $(LANGUAGEFILE)

%.o: $(SRCLANGUAGEDIREC)%.cpp
	$(GPP) $(CFLAGS) -c $< -o $@

%.o: $(SRCSYNTAXDIREC)%.cpp
	$(GPP) $(CFLAGS) -c $< -o $@

main: $(SRCDIREC)main.cpp
	$(GPP) $< $(HEADERFILE) -o $(BUILDDIR)scrift 
	echo Scrift building successfuly!

run: 
	cd build && ./scrift
clean: 
		$(CLEAN)

cleanall:
		echo Cleaning build directory! 
		$(CLEANALL)
