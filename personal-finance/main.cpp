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

double FIRST_THRESHOLD = 12509;
double SECOND_THRESHOLD = 50000;
double THIRD_THRESHOLD = 150000;

double NI_THRESHOLD_1 = 9500;
double NI_THRESHOLD_DEDUCTION_VALUE = 0.12;
double NI_THRESHOLD_2 = 50000;
double NI_ADV_THRESHOLD_DEDUCTION_VALUE = 0.02;


double calculate_tax(double salary, double pension)
{
    /* subtract pension */
    pension *= 12;
    salary -= pension;

    double basic_rate_deduction = 0;
    double higher_rate_deduction = 0;
    double advanced_rate_deduction = 0;
    double ni_deduction = 0;
    double ni_advanced_deduction = 0;

    /* INCOME TAX */
    if ( salary > FIRST_THRESHOLD){
        basic_rate_deduction = salary - FIRST_THRESHOLD;
        basic_rate_deduction *= 0.2;
        std::cout << "Income Tax 1: " << basic_rate_deduction << std::endl;
       //salary -= basic_rate_deduction;
    }
    
    if ( salary > SECOND_THRESHOLD ) {
        higher_rate_deduction = salary - SECOND_THRESHOLD;
        higher_rate_deduction *= 0.4;
        std::cout << "Income Tax 2: " << higher_rate_deduction << std::endl;
        //salary -= higher_rate_deduction;
    }
        
    if ( salary > THIRD_THRESHOLD ) {
        advanced_rate_deduction = salary - THIRD_THRESHOLD;
        advanced_rate_deduction *= 0.45;
        std::cout << "Income Tax 3: " << advanced_rate_deduction << std::endl;
        //salary -= advanced_rate_deduction;
    }

    /* NATIONAL INSURANCE */
    if ( salary > NI_THRESHOLD_1 )
    {
        double above_threshold1 = salary - NI_THRESHOLD_1;
        ni_deduction = above_threshold1 * NI_THRESHOLD_DEDUCTION_VALUE;
        std::cout << "NI Deduction: " << ni_deduction << std::endl;
    }
    if ( salary > NI_THRESHOLD_2 )
    {
        double above_threshold2 = salary - NI_THRESHOLD_2;
        ni_advanced_deduction = above_threshold2 * NI_ADV_THRESHOLD_DEDUCTION_VALUE;
        std::cout << "NI Deduction: " << ni_advanced_deduction << std::endl;

    }

    salary -= basic_rate_deduction - higher_rate_deduction - advanced_rate_deduction;
    salary -= ni_deduction - ni_advanced_deduction;

   return salary;
}


int main() {
    double salary;
    double pension_contribution;

    std::cout << "Enter your annual salary: \n";
    do {
        std::cin >> salary;
        if ( salary == 0 )
        {
            salary = 0;
            std::cin >> salary;
        }   
    } while ( salary == 0);

    std::cout << "Enter pension contribution: \n";
    std::cin >> pension_contribution;

    double taxed = calculate_tax(salary, pension_contribution);

    std::cout << "Salary is " << taxed << std::endl;
    
}