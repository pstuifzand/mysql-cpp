LIBS=-lmysqlclient -lstdc++
CXXFLAGS=-std=c++11

.PHONY: all clean check

all:

check: test
	./test

test: test.o
	gcc $^ -o $@ $(LIBS)

.o:.cpp
	gcc $< -o $@ $(CXXFLAGS)

test.o: test.cpp
test.cpp: mysql.hpp

clean:
	rm -rf test
	rm -rf test.o
