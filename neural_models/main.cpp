#include <iostream>
#include "perceptron.h"

int main() {
    srand(time(NULL));
    rand();

    std::cout << "\n\n EXAMPLE\n\n";

    Perceptron *p = new Perceptron(2);

    p->set_weights({10, 10, -15}); 

    std::cout << "Gate: " << std::endl;
    std::cout << p->run({0,0}) << std::endl;
    std::cout << p->run({0,1}) << std::endl;
    std::cout << p->run({1,0}) << std::endl;
    std::cout << p->run({1,1}) << std::endl;


}