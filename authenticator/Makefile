
# If you use clang++, make sure the following line does not start with a comment (#)
CXX=clang++
# If you use g++, uncomment the following line
#CXX=g++

# Set default compiler parameters
# -Wall 	shows all warnings when compiling, always use this!
# -std=c++17 	enables the C++17 standard mode
CXXFLAGS = -Wall -std=c++17

# Use the directory that *contains* the boost directory
CRYPTO_LIBRARIES = ./cryptopp840

CXXFLAGS += -fpermissive
LFLAGS += -L$(CRYPTO_LIBRARIES)

# Settings for the apps  
testOBJS = main.cpp
testAPP = main

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) $(testOBJS) -o $(testAPP) $(LFLAGS) -lcryptopp

clean: 
	rm -rf $(testAPP)