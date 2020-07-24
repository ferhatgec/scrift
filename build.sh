#!/bin/sh
g++ -s -I./include/src/ ./src/Syntax/CommandFunc.cpp ./src/Syntax/FileFunction.cpp ./src/Syntax/GetNameFunction.cpp \
./src/Syntax/History.cpp ./src/Syntax/Log.cpp ./src/Syntax/RunFunction.cpp ./src/Syntax/Template.cpp ./src/Scrift.cpp -o scrift
