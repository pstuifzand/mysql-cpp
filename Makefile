LIBS=-lmysqlclient -lstdc++
CXXFLAGS=-std=c++11

.PHONY: all clean

all:

test: test.o
	gcc $^ -o $@ $(LIBS)

.o:.cpp
	gcc $< -o $@ $(CXXFLAGS)


clean:
	rm -rf test
	rm -rf test.o
