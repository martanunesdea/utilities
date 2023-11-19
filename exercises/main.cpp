#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>


void load_file(std::vector<std::string>& file_vector){
	std::cout << "Loading file\n";
    std::ifstream file_handle("file.txt");
    if ( !file_handle.is_open() )
    {
        std::cout << "Error: Couldn't open file\n";
        return;
    }

    std::string line;
    while (std::getline(file_handle, line))
    {
        file_vector.push_back(line);
    }

	return;	
}