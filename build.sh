#!/bin/sh
g++ -s -I./include/src/ ./src/Syntax/CommandFunc.cpp ./src/Syntax/FileFunction.cpp ./src/Syntax/GetNameFunction.cpp \
./src/Syntax/History.cpp ./src/Syntax/Log.cpp ./src/Syntax/RunFunction.cpp ./src/Syntax/Template.cpp ./src/Scrift.cpp -o /bin/scrift

g++ -I./include/src/ -I./Library/ ./src/Fetcheya/Logos.cpp ./src/Fetcheya/Fetcheya.cpp -o fetcheya
