# GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
# 
#

SRCDIREC = ./src/
FUSION_CONF_DIREC = ./fusion_conf/
GPP = g++
COMP = g++ -c
HECOMP = g++ -c $< -o
BUILDDIR = ./build/
# CLEAN
CLEAN = *.o
HEADERFILE = Path.o Syntax.o
ifeq ($(OS), Linux)
	CLEAN := rm -f $(CLEAN)
	echo Linux
endif

ifeq ($(OS), Windows_NT)
	CLEAN := del $(CLEAN)
	echo Windows_NT
endif

all: headersfile main


headersfile: $(HEADERFILE)

Path.o: $(SRCDIREC)Path.cpp
		$(HECOMP) Path.o
		echo Successfuly creating Path.o

Syntax.o: $(SRCDIREC)Syntax.cpp
		$(HECOMP) Syntax.o
		echo Successfuly creating Syntax.o 
	

main: $(SRCDIREC)main.cpp
	g++  $< $(HEADERFILE) -o $(BUILDDIR)scrift 
	echo Scrift building successfuly

