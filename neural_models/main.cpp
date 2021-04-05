#include <iostream>
#include "perceptron.h"

void single_perceptron(void)
{
    std::cout << "\n\n EXAMPLE\n\n";

    Perceptron *p = new Perceptron(2);

    p->set_weights({10, 10, -15}); 

    std::cout << "Gate: " << std::endl;
    std::cout << p->run({0,0}) << std::endl;
    std::cout << p->run({0,1}) << std::endl;
    std::cout << p->run({1,0}) << std::endl;
    std::cout << p->run({1,1}) << std::endl;

}

void multi_layer_perceptron(void)
{  
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

void multi_layer_training(void)
{
    std::cout << "\n\n --- Trained XOR Example --- \n\n";
    MultiLayerPerceptron mlp = MultiLayerPerceptron({2,2,1});

    double MSE;
    for (int i = 0; i < 3000; i++){
        MSE = 0.0;
        MSE += mlp.backpropagation({0,0},{0});
        MSE += mlp.backpropagation({0,1},{1});
        MSE += mlp.backpropagation({1,0},{1});
        MSE += mlp.backpropagation({1,1},{0});
        MSE = MSE / 4.0;
        if ( i % 100 == 0)
            std::cout << "MSE = " << MSE << std::endl;
    }

    std::cout << "\n Trained weights: \n \n";
    mlp.print_weights();

    std::cout << "XOR: " <<  std::endl;
    std::cout << "0 0 = " << mlp.run({0,0})[0] << std::endl;
    std::cout << "0 1 = " << mlp.run({0,1})[0] << std::endl;
    std::cout << "1 0 = " << mlp.run({1,0})[0] << std::endl;
    std::cout << "1 1 = " << mlp.run({1,1})[0] << std::endl;



}

int main() {
    srand(time(NULL));
    rand();

    single_perceptron();
    multi_layer_perceptron();

    multi_layer_training();
 

}