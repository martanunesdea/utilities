#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <time.h>

class Perceptron {
    public:
    vector<double> weights;
    double bias;
    Perceptron(int inputs, double bias=1.0);
    void set_weights(vector<double> w_init);
    double sigmoid(double x);
}


