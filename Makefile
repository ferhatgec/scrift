# MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
#

# Apps
SRCAPPSDIREC = ./Apps/

# Libraries
SRCLIBDIREC = ./Library/

# Scrift's Syntax
SRCSYNTAXDIREC = ./src/Syntax/

# Source
SRCDIREC = ./src/

# Prefix
PREFIX = /bin/

INCLUDELIB = ./Library/
INCLUDEDIR = ./include/

# Include flags etc.
CFLAGS   = -Wall -I$(INCLUDELIB) -I$(INCLUDEDIR)
CPPFLAGS = -Wno-unused-function -Wno-unused-value

GCC      = cc
CPP      = c++
STANDARD = -std=c++17

COMPILER = $(CPP) $(STANDARD)
COMP     = $(GCC)

# Clean all
CLEANALL = scrift

# Clean object files
CLEAN = *.o

# Scrift's Syntax objects
HEADERFILE = CommandFunc.o     \
             GetNameFunction.o \
             FileFunction.o    \
             RunFunction.o     \
             Log.o             \
             History.o         \
             Branch.o          \
             Template.o        \
             Settings.o        \
             HelpFunction.o    \
             ASCIIFunction.o   \
             Setup.o           \
             Tools.o           \
             Locale.o          \
             Alias.o           \
             Validation.o      \

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
all: fpm headersfile main datec clean

# Build & Install
install: fpmc headersfile mainc date clean

# Remove & Clean all
removeall: uninstall cleanall

# Build & Run
runall: all run

# For me & developers
gra: runall git

# Get Fpm (Fegeya Package Manager)
fpm:
	sh init/get_fpm.sh

# Install Fpm (Fegeya Package Manager)
fpmc:
	sh init/get_fpm.sh
	sh init/install_fpm.sh

# Git
git:
	git add .
	git commit -a
	git push origin master

push:
	git push origin master

# Only clean all
nall: cleanall

# Scrift's Core.
headersfile: $(HEADERFILE)

# Syntax
%.o: $(SRCSYNTAXDIREC)%.cpp
	$(COMPILER) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	echo [SUCCESS] $@
	
# Main Build
main: $(SRCDIREC)Scrift.cpp
	$(COMPILER) $(CFLAGS) $(CPPFLAGS) $< $(HEADERFILE) -o scrift
	echo [SUCCESS] Scrift

# Main Build & Install
mainc: $(SRCDIREC)Scrift.cpp
	$(COMPILER) $(CFLAGS) $(CPPFLAGS) $< $(HEADERFILE) -o /bin/scrift
	echo [SUCCESS] Scrift [bin]

# Calendar & Converter Build
# Calendar
datec: $(SRCAPPSDIREC)/FDate/FDate.cpp
	$(COMPILER)  $(SRCAPPSDIREC)/FDate/FDate.cpp -o fdate
	echo [SUCCESS] FDate
	
# Calendar & Converter & Build & Install
date: $(SRCAPPSDIREC)/FDate/FDate.cpp
	$(COMPILER)  $(SRCAPPSDIREC)/FDate/FDate.cpp -o $(PREFIX)fdate
	echo [SUCCESS] FDate[bin]
	
# Remove Scrift.
uninstall:
	rm -f /bin/scrift
	rm -f /bin/fdate

# Run Scrift
run:
	./scrift
	
# Clean object files
clean:
		$(CLEAN)

# Clean object files and Scrift.
cleanall:
		echo [SUCCESS] Clean
		$(CLEANALL)
