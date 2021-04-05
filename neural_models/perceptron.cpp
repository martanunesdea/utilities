#include "perceptron.h"
#include <vector>

double frand(){
    return ( 2.0*(double)rand() / RAND_MAX - 1.0);
}

Perceptron::Perceptron(int inputs, double bias){
    this->bias = bias;
    weights.resize(inputs+1);
    std::generate(weights.begin(), weights.end(), frand);
}

double Perceptron::run(std::vector<double> x){
    x.push_back(bias);
    double sum = inner_product(x.begin(), x.end(), weights.begin(), (double)0.0);
    return sigmoid(sum);
}

void Perceptron::set_weights(std::vector<double> w_init)
{
    this->weights = w_init;
}

double Perceptron::sigmoid(double x)
{
    return ( 1.0 / (1.0 + exp(-x)));
}

MultiLayerPerceptron::MultiLayerPerceptron(std::vector<int> layers, double bias, double eta) {
    this->layers = layers;
    this->bias = bias;
    this->eta = eta;

    for ( int i = 0; i < layers.size(); i++ )
    {
        values.push_back(std::vector<double>(layers[i],0.0));
        network.push_back(std::vector<Perceptron>());
        if ( i > 0 ) 
            for (int j = 0; j < layers[i]; j++)
                network[i].push_back(Perceptron(layers[i-1],bias));
    }
}

void MultiLayerPerceptron::set_weights(std::vector<std::vector<std::vector<double> > > w_init) {
    for ( int i = 0; i < w_init.size(); i++ )
    {
        for ( int j = 0; j < w_init[i].size(); j++ )
        {
            network[i+1][j].set_weights(w_init[i][j]);
        }
    }
}

void MultiLayerPerceptron::print_weights(){
    std::cout << "\n\n";

    for ( int i = 1; i < network.size(); i++ )
    {
        for ( int j = 0; j < layers[i]; j++ )
        {
            std::cout << "Layer " << i+1 << " Neuron " << j << ": ";
            for (auto &it: network[i][j].weights)
                std::cout << it << "    ";
            std::cout << std::endl;
        }

    }
    std::cout << std::endl;

}

std::vector<double> MultiLayerPerceptron::run(std::vector<double> x) {
    values[0] = x;

    for ( int i = 1; i < network.size(); i++ )
        for ( int j = 0; j < layers[i]; j++ )
            values[i][j] = network[i][j].run(values[i-1]);

    return values.back();
}