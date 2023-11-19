#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <math.h>

#define TERM 25

double calculate_repayments(double total, double deposit, double interest, double term)
{

    double mortgage = total - deposit;

    double monthly = 12.0;
    double r = interest / monthly;
    double N = monthly * term;

    double A = pow((1 + r), N);
    double monthly_payments = mortgage * r * A / (A - 1);
    double total_payments = (monthly_payments * N);

    return total_payments;
}

void calculate_how_much_left (double total, double deposit, double interest, double term)
{
    double mortgage = total - deposit;
    double monthly = 12.0;
    double r = interest / monthly;
    double N = monthly * term;

    double A = pow((1 + r), N);
    double monthly_payments = mortgage * r * A / (A - 1);
    double total_payments = (monthly_payments * N);
    double total_interest = mortgage * (1 + (N*r*A) - A) / (A - 1);

    double mortgage_left [TERM];
    double paid_yearly = 0;
    for (int i = 0; i < TERM; i++)
    {
        paid_yearly = (monthly_payments * 12) + paid_yearly;
        mortgage_left [i] = total_payments - paid_yearly;
        std::cout << "Year" << " " << i << " " << mortgage_left[i] << "\n";
    }

    return;
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

    calculate_how_much_left(total_mortgage_value, deposit, interest, term);
}