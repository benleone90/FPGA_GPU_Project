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

float dot_product(float *u, float *v)
{
    float sum = 0;
    int n = sizeof(u) / sizeof(u[0]);
    for (int i = 0; i < n; i++)
    {
        sum += u[i] * v[i];
    }
    return sum;
}

float feedforward(float *neuron, float *input, int bias)
{
    float total = dot_product(neuron, input) + bias;
    return sigmoid(total);
}