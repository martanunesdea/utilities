
CXX=clang++
CXXFLAGS = -Wall 

LIBRARIES = ./zlib

#CXXFLAGS += -fpermissive
LFLAGS += -L$(LIBRARIES)

# Settings for the apps  
testOBJS = compression.cpp
testAPP = compression

all: compression

compression: compression.cpp
	$(CXX) $(CXXFLAGS) $(testOBJS) -o $(testAPP) $(LFLAGS) -lz

clean: 
	rm -rf $(testAPP)