#include "zlib/zlib.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream> // for getline

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
        file_text.push_back(line);
    }

	return;	
}

int main(int argc, char* argv[])
{
	std::vector<std::string> file_vector;
	load_file(file_vector);

	const unsigned char pData[] = {
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220,
		123, 34, 37, 83, 24, 2, 98, 178, 57, 220
	};
	unsigned long nDataSize = 100;

	printf("Initial size: %lu\n", nDataSize);

	unsigned long nCompressedDataSize = nDataSize;
	unsigned char * pCompressedData = new unsigned char[nCompressedDataSize];
	
	int nResult = compress2(pCompressedData, &nCompressedDataSize, pData, nDataSize, 9);

	if (nResult == Z_OK)
	{
		printf("Compressed size: %lu\n", nCompressedDataSize);

		unsigned char * pUncompressedData = new unsigned char[nDataSize];
		nResult = uncompress(pUncompressedData, &nDataSize, pCompressedData, nCompressedDataSize);
		if (nResult == Z_OK)
		{
			printf("Uncompressed size: %lu\n", nDataSize);
			if (memcmp(pUncompressedData, pData, nDataSize) == 0)
				printf("Great Success\n");
		}
		delete [] pUncompressedData;
	}

	delete [] pCompressedData;

	return 0;
}