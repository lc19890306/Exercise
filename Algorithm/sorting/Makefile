CC = clang
CXX = g++ #clang++
CXXFLAGS = -O3 -std=c++11
DBGFLAGS = -O0 -g -ggdb -std=c++11
OBJ = ./sort

all:	main rand_num_generator #selection_sort
	$(CXX) -o $(OBJ) *.o

debug:	main_debug rand_num_generator_debug #selection_sort_debug
	$(CXX) -o $(OBJ) *_debug.o

main:	main.cc
	$(CXX) -c $(CXXFLAGS) -o $@.o main.cc

main_debug:	main.cc
	$(CXX) -c $(DBGFLAGS) -o $@.o main.cc

rand_num_generator:	rand_num_generator.cc
	$(CXX) -c $(CXXFLAGS) -o $@.o rand_num_generator.cc

rand_num_generator_debug:	rand_num_generator.cc
	$(CXX) -c $(DBGFLAGS) -o $@.o rand_num_generator.cc

# selection_sort:	selection_sort.cc
# 	$(CXX) -c $(CXXFLAGS) -o $@.o selection_sort.cc

# selection_sort_debug:	selection_sort.cc
# 	$(CXX) -c $(DBGFLAGS) -o $@.o selection_sort.cc

clean:
	rm -f $(OBJ) *.o
