CXX=g++
CXXFLAGS=-std=c++11

build: main.cpp prime.hpp
	@echo "\n\nBuilding..."
	$(CXX) $(CXXFLAGS) -o prime.out main.cpp

run: prime.out
	@echo "\n\nExecuting..."
	./prime.out

clean: prime.out
	@echo "\n\nCleaning..."
	rm prime.out

all: build run clean
