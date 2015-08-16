CC=clang
CXX=clang++
FLAGS=-std=c++11 -O3
DBGFLAGS=-std=c++11 -O0 -g -ggdb
OBJ=./test
SRC=test.cc

all:
	$(CXX) $(FLAGS) -o $(OBJ) $(SRC)

debug:
	$(CXX) $(DBGFLAGS) -o $(OBJ) $(SRC)

clean:
	rm -f $(OBJ)
