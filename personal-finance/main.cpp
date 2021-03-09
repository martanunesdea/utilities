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

double FIRST_THRESHOLD = 12500;
double SECOND_THRESHOLD = 50000;
double THIRD_THRESHOLD = 150000;

double NI_THRESHOLD_1 = 9504;
double NI_THRESHOLD_DEDUCTION_VALUE = 0.12;
double NI_THRESHOLD_2 = 50000;
double NI_ADV_THRESHOLD_DEDUCTION_VALUE = 0.02;

void print_tax_deductions(double basic_rate_deduction, double higher_rate_deduction, double advanced_rate_deduction,
            double ni_deduction, double ni_advanced_deduction, double pension, double salary )
{
    std::cout << "Sacrificed salary:" << "\t" << salary << std::endl;
    std::cout << "Pension:" << "\t\t" << pension << std::endl;
    
    if ( basic_rate_deduction )
        std::cout << "Income Tax basic:" << "\t" << basic_rate_deduction << std::endl;

    if ( higher_rate_deduction )
        std::cout << "Income Tax higher:" << "\t" << higher_rate_deduction << std::endl;
    
    if ( advanced_rate_deduction )
        std::cout << "Income Tax advanced:" << "\t" << advanced_rate_deduction << std::endl;
    
    if ( ni_deduction  )
        std::cout << "NI base:" << "\t\t" << ni_deduction << std::endl;
    
    if ( ni_advanced_deduction )
        std::cout << "NI advanced:" << "\t\t" << ni_advanced_deduction << std::endl;


}

double calculate_tax(double salary, double pension, bool log)
{
    /* subtract pension */
    pension = pension * 12;
    salary -= pension;

    double basic_rate_deduction = 0;
    double higher_rate_deduction = 0;
    double advanced_rate_deduction = 0;
    double ni_deduction = 0;
    double ni_advanced_deduction = 0;

    /* INCOME TAX */
    if ( ( salary ) > FIRST_THRESHOLD){
        basic_rate_deduction = salary - FIRST_THRESHOLD;
        basic_rate_deduction *= 0.2;
    }
    
    if ( salary > SECOND_THRESHOLD ) {
        higher_rate_deduction = salary - SECOND_THRESHOLD;
        higher_rate_deduction *= 0.4;
    }
        
    if ( salary > THIRD_THRESHOLD ) {
        advanced_rate_deduction = salary - THIRD_THRESHOLD;
        advanced_rate_deduction *= 0.45;
    }

    /* NATIONAL INSURANCE */
    if ( salary > NI_THRESHOLD_1 )
    {
        double above_threshold1 = salary - NI_THRESHOLD_1;
        ni_deduction = above_threshold1 * NI_THRESHOLD_DEDUCTION_VALUE;
    }
    if ( salary > NI_THRESHOLD_2 )
    {
        double above_threshold2 = salary - NI_THRESHOLD_2;
        ni_advanced_deduction = above_threshold2 * NI_ADV_THRESHOLD_DEDUCTION_VALUE;
    }

    salary = salary - basic_rate_deduction - higher_rate_deduction - advanced_rate_deduction
            - ni_deduction - ni_advanced_deduction;

    if ( log )
    {
        print_tax_deductions(basic_rate_deduction, higher_rate_deduction, advanced_rate_deduction,
            ni_deduction, ni_advanced_deduction, pension, salary );
    }

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

    std::cout << "Enter pension contribution (pounds, per month): \n";
    std::cin >> pension_contribution;

    double taxed = calculate_tax(salary, pension_contribution, true);

    std::cout << "Salary is " << taxed << std::endl;
    
}