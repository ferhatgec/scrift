CFLAGS=-std=c++11 -O2 -g -Wall $(shell pkg-config --cflags ncursesw)
LDFLAGS=$(shell pkg-config --libs ncursesw)
OBJECTS=Castle.o

all: castle

castle: Castle.hpp
	g++ $(CFLAGS) Castle.cpp -o castle $(LDFLAGS)

clean:
	rm  castle

install:
	cp castle /bin/castle

uninstall:
	rm /bin/castle
