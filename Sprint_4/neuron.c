#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "neuron.h"

float sigmoid(float x)
{
    float exp_value;
    float return_value;

    // Exponential Calculation //
    exp_value = exp((double)-x);

    // Final Sigmoid Value //
    return_value = 1 / (1 + exp_value);

    return return_value;
}

float feedforward(int *neuron, int *input, int bias)
{
    float total = dot_product(neuron, input) + bias;
    return sigmoid(total);
}

struct neuron
{
    int weights[WEIGHTS];
    int bias;
};