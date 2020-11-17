/*
Header file for neuron for a neural network
*/
#ifndef NEURON_H
#define NEURON_H

#define WEIGHTS 2

float sigmoid(float x);

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

float feedforward(int *neuron, int *input, int bias);

typedef struct
{
    int weights[2];
    int bias;
} neuron;

#endif