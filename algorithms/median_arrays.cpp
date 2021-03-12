
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <random>
#include <functional>


void log(std::vector<int> v1, std::vector<int> v2, std::vector<int> dst)
{
    // output sorted v1
    std::cout << "v1 : ";
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    // output sorted v2
    std::cout << "v2 : ";
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    // output merged
    std::cout << "merged sorted: ";
    std::copy(dst.begin(), dst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}


auto find_median(std::vector<int> v1, std::vector<int> v2)
{
    // sort
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    // merge
    std::vector<int> dst;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));
    // find median          
    auto results = std::minmax_element(dst.begin(), dst.end()); 
    
    log(v1, v2, dst);

    return (*results.second + *results.first)/2;
}

int main()
{
    // fill the vectors with random numbers
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 5);
 
    std::vector<int> v1(5), v2(5);
    std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
    std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));
 
    auto median = find_median(v1, v2);

    // output median
    std::cout  << "Median is " << median << std::endl;

}