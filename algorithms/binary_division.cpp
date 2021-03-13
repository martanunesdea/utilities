#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <math.h>

#define MAX 2147483648 // 2^31 
#define MIN -2147483648

int divide(double dividend, double divisor) {
    // check if dividend or divisor are negative 
    int sign = ((dividend < 0) ^  (divisor < 0)) ? -1 : 1;
 
    dividend = abs(dividend);
    divisor = abs(divisor);
 
    // Initialize the quotient
    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }
 
  return sign * quotient;
}
 
// Driver code
int main() {
    double dividend = 0;
    double divisor = 0;

    while (true)
    {
        std::cout << "Enter dividend: ";
        std::cin >> dividend;


        std::cout << "Enter divisor: ";
        std::cin >> divisor;
        if ( (MAX >= dividend) && (dividend >= MIN) && (MAX >= divisor) && (divisor >= MIN) 
            && (divisor != 0) )
        {
            break;
        }
        else std::cout << "Enter numbers within range of 2^31 and not null\n"; 
    }


  std::cout << divide(dividend, divisor) << "\n";
 
  return 0;
}
