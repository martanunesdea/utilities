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

double MultiLayerPerceptron::backpropagation(std::vector<double> x, std::vector<double> y)
{
    // 1. Feed a sample to the network
    std::vector<double> output = run(x);

    // 2. Calculate MSE
    std::vector<double> error;
    double MSE = 0.0;
    for (int i = 0; i < y.size(); i++) {
        error.push_back(y[i] - output[i]);
        MSE += error[i] * error[i];
    }
    MSE /= layers.back(); // divide by total neurons in last layer

    // 3. Calculate the output error terms
    for (int i = 0; i < output.size(); i++)
        d.back()[i] = output[i] * (1 - output[i]) * (error[i]);
    
    // 4. Calculate the error term of each unit on each layer
    for (int i = network.size()-2; i > 0; i--)
        for (int h = 0; h < network[i].size(); h++) {
            double fwd_error = 0.0;
            for (int k = 0; k < layers[i+1]; k++)
                fwd_error += network[i+1][k].weights[h] * d[i+1][k];
            d[i][h] = values[i][h] * (1-values[i][h]) * fwd_error;
        }

    // 5. Calculate deltas
    // 6. Update weights
    for (int i = 1; i < network.size(); i++)
        for (int j = 0; j < layers[i]; j++)
            for (int k = 0; k < layers[i-1]+1; k++){
                double delta;
                if ( k == layers[i-1] )
                    delta = eta * d[i][j] * bias;
                else
                    delta = eta * d[i][j] * values[i-1][k];
                network[i][j].weights[k] += delta;
            }
    
    return MSE;
}