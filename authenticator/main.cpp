#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <map>
#include <functional>
#include <fstream>
#include "json.hpp"

// for convenience
using json = nlohmann::json;

typedef struct  {
    std::string username;
    std::string password;
} credentials;
credentials credentials_dict[2];

bool valid_credentials(std::string username,std::string password)
{
    bool is_valid = false;


    for ( int i = 0; i < 2; ++i)
    {
        if ( username == credentials_dict[i].username && password == credentials_dict[i].password)
        {
            is_valid = true;
        }
    }
    return is_valid;
}

void hash_credentials(credentials *user)
{
    std::size_t h1 = std::hash<std::string>{}(user->username);
    std::size_t h2 = std::hash<std::string>{}(user->password);
    user->password = h1 ^ (h2 << 1);
    return; 
}

void load_credentials()
{
    std::cout << "Loading json\n";
    std::ifstream input;    
    std::ifstream file_handle("config.json");
    if ( !file_handle.is_open() )
    {
        std::cout << "Error: Couldn't open file\n";
        return;
    }
    
    std::string line;
    
    while (std::getline(file_handle, line))
    {
        char start = line[0];
        if ( start == '{' )
        {
            std::cout << "Looks like json\n\n";
        }
    }
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

    credentials login = {username, password};
    hash_credentials(&login);

    if ( valid_credentials(login.username, login.password) )
    {
        std::cout << "You're in\n\n";
    }

}