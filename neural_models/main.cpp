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

    std::cout << "\n\n --- Hardcoded XOR example --- \n\n";
    MultiLayerPerceptron mlp = MultiLayerPerceptron({2,2,1});
    mlp.set_weights({{{-10,-10,15},{15,15,-10}},{{10,10,-15}}});
    std::cout << "Hard coded weights:\n";
    mlp.print_weights();

    std::cout << "XOR: " << std::endl;
    std::cout << "0 0 = " << mlp.run({0,0})[0] << std::endl;
    std::cout << "0 1 = " << mlp.run({0,1})[0] << std::endl;
    std::cout << "1 0 = " << mlp.run({1,0})[0] << std::endl;
    std::cout << "1 1 = " << mlp.run({1,1})[0] << std::endl;


}