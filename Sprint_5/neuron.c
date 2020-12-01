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

float deriv_sigmoid(float x)
{
    // Derivative of sigmoid: f'(x) = f(x) * (1 - f(x))
    float fx = sigmoid(x);
    return fx * (1 - fx);
}

float dot_product(float u[2], float v[2])
{
    // Dot product function
    float sum = 0;
    for (int i = 0; i < 2; i++)
    {
        sum += u[i] * v[i];
    }
    return sum;
}

float feedforward(float neuron[2], float input[2], int bias)
{
    float total = dot_product(neuron, input) + bias;
    return sigmoid(total);
}

float mse(float a[4], float b[4], int size)
{
    // Mean-squared error function
    float error = 0;
    for (int i = 0; i < size; i++)
    {
        error += pow((a[i] - b[i]), 2);
    }
    return error / size;
}