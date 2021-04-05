#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <time.h>

class Perceptron {
    public:
    std::vector<double> weights;
    double bias;

    Perceptron(int inputs, double bias=1.0);
    void set_weights(std::vector<double> w_init);
    double sigmoid(double x);
    double run(std::vector<double> x);
};