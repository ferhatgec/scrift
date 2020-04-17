# GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
# 
#
LANGDIREC = ./Lang/
SRCFILEDIREC = ./src/File/
SRCSTTNGSDIREC = ./src/Settings/
SRCSYNTAXDIREC = ./src/Syntax/

COREDIREC = ./core/
SRCDIREC = ./src/
FUSION_CONF_DIREC = ./fusion_conf/
GPP = g++
COMP = g++ -c
HECOMP = g++ -c $< -o
BUILDDIR = ./build/
# CLEAN
CLEANALL = scrift
CLEAN = *.o
HEADERFILE = Path.o Syntax.o Sync.o File.o \
Directory.o DefaultSettings.o CommandFunc.o

COREHEADERSFILE = Core.o 
LANGHEADERSFILE = Language.o Reader.o


ifeq ($(OS),Windows_NT)
	CLEAN := del $(CLEAN)
	CLEANALL := del $(CLEANALL)
	echo Windows_NT
else
	CLEAN := rm -f $(CLEAN)
	CLEANALL := rm -f $(BUILDDIR)$(CLEANALL)
endif


all: langheadersfile headersfile coreheadersfile main clean

nall: cleanall

coreheadersfile: $(COREHEADERSFILE)

Core.o: $(COREDIREC)Core.cpp
		$(HECOMP) Core.o
		echo Successfuly creating Core.o

langheadersfile: $(LANGHEADERSFILE)

Language.o: $(LANGDIREC)Language.cpp
			$(HECOMP) Language.o
			echo Successfuly creating Language.o

Reader.o: $(LANGDIREC)Reader.cpp
			$(HECOMP) Reader.o
			echo Successfuly creating Reader.o

headersfile: $(HEADERFILE)


Path.o: $(SRCFILEDIREC)Path.cpp
		$(HECOMP) Path.o
		echo Successfuly creating Path.o

Syntax.o: $(SRCSYNTAXDIREC)Syntax.cpp
		$(HECOMP) Syntax.o
		echo Successfuly creating Syntax.o 
	
Sync.o: $(SRCFILEDIREC)Sync.cpp
		$(HECOMP) Sync.o
		echo Successfuly creating Sync.o

File.o: $(SRCFILEDIREC)File.cpp
		$(HECOMP) File.o
		echo Successfuly creating File.o


Directory.o: $(SRCFILEDIREC)Directory.cpp
		$(HECOMP) Directory.o
		echo Successfuly creating Directory.o

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
