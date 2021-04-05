
CXX=clang++
CXXFLAGS = -Wall -std=c++17 

all: main

main: main.o perceptron.o
	$(CXX) $(CXXFLAGS) -o main main.o perceptron.o

main.o: main.cpp perceptron.h
	$(CXX) $(CXXFLAGS) -c main.cpp

perceptron.o: perceptron.cpp perceptron.h
	$(CXX) $(CXXFLAGS) -c perceptron.cpp

clean: 
	rm -rf $(testAPP)