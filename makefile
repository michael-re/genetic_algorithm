CXX       = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic

INCLUDE = -I include/
SOURCE  = src/*.cpp
OUT     = genetic_solver.out

all:
	$(CXX) $(CXXFLAGS) $(SOURCE) $(INCLUDE) -o $(OUT)

clean:
	rm -rf $(OUT)
