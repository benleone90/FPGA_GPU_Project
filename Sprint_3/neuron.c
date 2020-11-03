#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

float dot_product(int *u, int *v)
{
    float sum = 0;
    int n = sizeof(u) / sizeof(u[0]);
    for (size_t i = 0; i < n; i++)
    {
        sum += u[i] * v[i];
    }
    return sum;
}

float feedforward(int *neuron, int *input, int bias)
{
    float total = dot_product(neuron, input) + bias;
    return sigmoid(total);
}

struct neuron
{
    int weights[2];
    int bias;
};

int main()
{
    struct neuron n1 = {{0, 1}, 4}; // w1 = 0, w2 = 1, b = 4
    int inputs[2] = {2, 3};         // x1 = 2, x2 = 3
    printf("%.20f\n", feedforward(n1.weights, inputs, n1.bias));
    return EXIT_SUCCESS;
}