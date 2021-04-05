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

