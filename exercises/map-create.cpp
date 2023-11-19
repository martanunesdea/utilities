#include <string>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

void split(const string& s, char c, vector<string>& v) 
{
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) 
   {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);
      if (j == string::npos) 
         v.push_back(s.substr(i, s.length()));
   } 
}

void process_query (vector<string>& v)
{

}


int main() 
{
    // Get number of queries
    string s_query_no;
    getline (cin, s_query_no);
    int int_query_no = stoi (s_query_no);

    // Process query as it comes
    string input;
    char separator = ' ';
    vector<string> v_query;
    for (int i = 0; i < int_query_no; i++)
    {
        // Get query & split into vector of strings
        getline (cin, input);
        split(input, separator, v_query);

        // Process query
        process_query(v_query);
    }


    for (int i = 0; i < v.size(); ++i) 
        cout << v[i] << '\n';
}