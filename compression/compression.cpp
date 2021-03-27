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
        file_vector.push_back(line);
    }

	return;	
}


unsigned char* compress(const char *pData)
{
	unsigned char *retval = NULL;

	unsigned long nDataSize = long(sizeof(pData));
	unsigned long nCompressedDataSize = nDataSize;
	unsigned char *pCompressedData = new unsigned char[nCompressedDataSize];
	
	const unsigned char *p2Data = (const unsigned char *)pData;

	int nResult = compress2(pCompressedData, &nCompressedDataSize, p2Data, nDataSize, 9);

	if (nResult == Z_OK)
	{
		retval = pCompressedData;
	}
	else 
	{
		std::cout << "horrible\n";
		retval = NULL;
	}
	delete [] pCompressedData;
	return retval;
}

int decompress(unsigned char *pCompressedData, unsigned char *pUncompressedData)
{
	// unsigned char * pUncompressedData = new unsigned char[nDataSize];
	// int nResult = uncompress(pUncompressedData, &nDataSize, pCompressedData, nCompressedDataSize);
	
	return 1;
}

int main(int argc, char* argv[])
{
	unsigned long nDataSize = 100;
	const char *pData = "This is just a really long string to see if the compression function works";
	unsigned char * pCompressedData = new unsigned char[nDataSize];
	//unsigned long nDataSize = long(sizeof(pData));

	//printf("Initial size: %lu\n", nDataSize);

	//unsigned long nCompressedDataSize = nDataSize;
	//unsigned char * pCompressedData = new unsigned char[nCompressedDataSize];
	
	//int nResult = compress2(pCompressedData, &nCompressedDataSize, pData, nDataSize, 9);

	unsigned char * str1 = compress(pData);

	if (str1 != NULL)
	{
		unsigned long nCompressedDataSize = (long)sizeof(str1);
		printf("Compressed size: %lu\n", nCompressedDataSize);

		unsigned char * pUncompressedData = new unsigned char[nDataSize];
		int nResult = uncompress(pUncompressedData, &nDataSize, str1, nCompressedDataSize);
		
		if (nResult == Z_OK)
		{
			//printf("Uncompressed size: %lu\n", nDataSize);
			//printf("Uncompressed string %s\n", pUncompressedData);
			
			// change for modern C++ string compare
			//if (memcmp(pUncompressedData, pData, nDataSize) == 0)
			//	printf("Success\n");
		}
		delete [] pUncompressedData;
	}
	delete [] pCompressedData;

	return 0;
}