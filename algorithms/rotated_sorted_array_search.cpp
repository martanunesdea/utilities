/* Problem statement is as follows: 
 * Given a sorted array that has been rotated at an unknown pivot index
 * Return the index of target if target is in the array, 
 * or -1 if target is not in the array.
 * Modern Cpp solution: use custom version of find
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template<class InputIt, class T>
constexpr long find_index(InputIt first, InputIt last, const T& value){
    auto begin_ = first;
    for (; first != last; ++first) {
        if (*first == value) {
            long result = distance(begin_, first);
            return result;
        }
    }
    return -1;
}

int main()
{
    int n1 = 3;
    int n2 = 5;
    int target = 0;
    std::vector<int> v{5, 6, 0, 1, 2, 3, 4};
    
    std::cout << "Enter target to find in nums: ";
    std::cin >> target;

    auto result = find_index(std::begin(v), std::end(v), target);
    std::cout << result << std::endl;

}