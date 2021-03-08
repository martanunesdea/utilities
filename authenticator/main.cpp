#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <map>
#include <functional>
#include <fstream>
#include <sstream>
#include <istream> // for getline
#include "cryptopp840/cryptlib.h"
#include "cryptopp840/sha.h"
#include "cryptopp840/hex.h"
#include "cryptopp/files.h"  

typedef struct  {
    std::string username;
    std::string password;
} credentials;

std::map<std::string, std::string> dict_creds;

bool valid_credentials(std::string username,std::string password)
{
    bool is_valid = false;
    for (const auto [key, value] : dict_creds) {
        if (value == password && key == username) {
            is_valid = true;
        }
    }
    std::cout << std::endl;
    return is_valid;
}

std::string hash_credentials(std::string password)
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

    // std::cout << "hashed password: " << output << std::endl; 

    return output; 
}

void print_credentials_file(const std::map<std::string, std::string> dict_creds)
{
    for (const auto [key, value] : dict_creds) {
        std::cout << key << " = " << value << "\n";
    }
}

void load_credentials_file()
{
    std::cout << "Loading config\n";

    std::ifstream file_handle("config.txt");
    if ( !file_handle.is_open() )
    {
        std::cout << "Error: Couldn't open file\n";
        return;
    }
    
    std::string aline;
    std::string word;
    credentials temp;
    bool first_word;

    while (std::getline(file_handle, aline))
    {
        std::istringstream line(aline);
        first_word = true;
        while (std::getline(line, word, ','))
        {
            if ( first_word )
            {  
                temp.username = word;
                first_word = false;
            }
            else 
            {
                temp.password = word;
            }
        }
        dict_creds[temp.username] = temp.password;
        
    }

    return;
}

int main(){
    /* Read in stored credentials */ 
    load_credentials();


    /* Ask user for credentials */
    std::string password;
    std::string username;

    std::cout << "\nEnter username: ";
    std::cin >> username;

    std::cout << "\nEnter password: \n";
    std::cin >> password;

    /* Get hash of password and validate with stored credentials */
    std::string hash = hash_credentials(password);

    if (valid_credentials(username, hash)) 
        std::cout << "You're in\n\n";
    else 
        std::cout << "Sorry, no\n\n";

}