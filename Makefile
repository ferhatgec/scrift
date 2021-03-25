# MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
#

SOURCE       = ./src/
INSTALLATION = /bin/
OUTPUT       = scrift

# Apps
SRCAPPSDIREC = ./Apps/

# Libraries
SRCLIBDIREC = ./library/

# Scrift's Syntax
SRCSYNTAXDIREC = $(SOURCE)Syntax/

INCLUDELIB = $(SRCLIBDIREC)
INCLUDEDIR = ./include/

# Include flags etc.
CPPFLAGS   = -I$(INCLUDELIB) -I$(INCLUDEDIR)

GCC      = cc
CPP      = c++
STANDARD = -std=c++17

COMPILER = $(CPP) $(STANDARD)
COMP     = $(GCC)

# Clean all
CLEANALL = $(OUTPUT)

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
ifeq ($(OS), Windows_NT)
	echo Windows_NT is not supported!
else
	CLEAN    := rm -f $(CLEAN)
	CLEANALL := rm -f $(CLEANALL)
endif

# Build
all:     fpm  headersfile main  clean

# Build & Install
install: fpmc headersfile mainc clean

# Remove & Clean all
removeall: uninstall cleanall

# Build & Run
runall:    all run

# Get Fpm (Fegeya Package Manager)
fpm:
	sh init/get_fpm.sh

# Install Fpm (Fegeya Package Manager)
fpmc: fpm
	sh init/install_fpm.sh

# Scrift's Core.
headersfile: $(HEADERFILE)

# Syntax
%.o: $(SRCSYNTAXDIREC)%.cpp
	$(COMPILER) $(CPPFLAGS) -c $< -o $@
	echo $@
	
# Main Build
main: $(SOURCE)Scrift.cpp
	$(COMPILER) $(CPPFLAGS) $< $(HEADERFILE) -o $(OUTPUT)
	echo Scrift.cpp

# Main Build & Install
mainc: $(SOURCE)Scrift.cpp
	$(COMPILER) $(CPPFLAGS) $< $(HEADERFILE) -o $(INSTALLATION)$(OUTPUT)
	echo Scrift [Install]

# Remove Scrift.
uninstall:
	rm -f $(INSTALLATION)$(OUTPUT)

# Run Scrift
run:
	./$(OUTPUT)

# Clean object files
clean:
	$(CLEAN)

# Clean object files and Scrift.
cleanall:
	echo Clean
	$(CLEANALL)
