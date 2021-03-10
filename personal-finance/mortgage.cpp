#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <math.h>

double calculate_repayments(double total, double deposit, double interest, double term)
{

    double mortgage = total - deposit;

    double total_interest_added;
    double n = 12;

    double first_term = 1 + (interest/n);
    double second_term = n * term;
    total_interest_added = mortgage *  pow( first_term, second_term );

    return total_interest_added;

}


int main() {
    double deposit = 0;
    double total_mortgage_value;
    char interest_rate;

    std::cout << "Enter deposit available: \n";
    std::cin >> deposit;
    
    if ( deposit == 0 )
    {
        std::cout << "Error: Option entered is not valid. \n";
    }

    std::cout << "Enter total mortage value: \n";
    std::cin >> total_mortgage_value;

    std::cout << "Choose options a-e for an interest rate.\n";
    std::cout << "a. 3%   \n";
    std::cout << "b. 3.5% \n";
    std::cout << "c. 4%   \n";
    std::cout << "d. 5%   \n";
    std::cout << "e. 6%   \n";

    std::cin >> interest_rate;
    if ( interest_rate < 'a' || interest_rate > 'e' )
    {
        std::cout << "Error: Option entered is not valid. \n";
    }

    double interest;
    switch (interest_rate) {
        case 'a':
            interest = 0.03;
            break;
        case 'b':
            interest = 0.035;
            break;
        case 'c':
            interest = 0.04;
            break;
        case 'd':
            interest = 0.05;
            break;
        case 'e':
            interest = 0.06;
            break;
        default:
            interest = 0.03;
            break;
    }

    double term = 25;
    std::cout << "Mortgage term: Assumed to be 25 years\n";

    double monthly_repayments = calculate_repayments(total_mortgage_value, deposit, interest, term);
    std::cout << "Total mortgage is " << monthly_repayments << std::endl;
}