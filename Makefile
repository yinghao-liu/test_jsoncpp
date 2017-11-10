CXXFLAGS=-g
CC=g++

main:main.o jsoncpp.o

clean:
	@rm -rf *.o main
