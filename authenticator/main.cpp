#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <map>
#include <functional>
#include <fstream>
#include <istream> // for getline
#include "cryptopp840/cryptlib.h"
#include "cryptopp840/sha.h"
#include "cryptopp840/hex.h"
#include "cryptopp/files.h"  

typedef struct  {
    std::string username;
    std::string password;
} credentials;
credentials credentials_dict[2];
std::map<std::string, std::string> dict_creds;

bool valid_credentials(std::string username,std::string password)
{
    bool is_valid = false;

    for (const auto [key, value] : dict_creds) {
        if ((password == value)) {
            is_valid = true;
        }
    }

    return is_valid;
}

std::string hash_credentials(std::string username, std::string password)
{
    CryptoPP::SHA256 hash;
    CryptoPP::byte digest[ CryptoPP::SHA256::DIGESTSIZE ];
    std::string msg = password;

    hash.CalculateDigest( digest, (CryptoPP::byte*) msg.c_str(), msg.length() );

    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    std::cout << output << std::endl; 

    return output; 
}

void print_credentials(const std::map<std::string, std::string>& dict_creds)
{
    for (const auto& [key, value] : dict_creds) {
        std::cout << key << " = " << value << "\n";
    }
}

void load_credentials()
{
    std::cout << "Loading config\n";

    std::ifstream file_handle("config.txt");
    if ( !file_handle.is_open() )
    {
        std::cout << "Error: Couldn't open file\n";
        return;
    }
    
    std::string word;
    int i = 0;
    std::string creds[2];

    while (std::getline(file_handle, word, ','))
    {
        if ( i == 0 )
        {
            creds[0] = word;
            i++;
        }
        else if ( i == 1) 
        {
            creds[1] = word;
            i = 0;
            std::string key = std::string(creds[0]);
            dict_creds[creds[0]] = creds[1];
        }
        
    }
    print_credentials(dict_creds);
    return;
}



int main(){
    /* Read in stored credentials */ 
    load_credentials();

    
    std::string password;
    std::string username;

    std::cout << "enter username: \n";
    std::cin >> username;

    std::cout << "enter password: \n";
    std::cin >> password;

    std::string hashed = hash_credentials(username, password);

    if ( valid_credentials(password, hashed) )
    {
        std::cout << "You're in\n\n";
    }

}