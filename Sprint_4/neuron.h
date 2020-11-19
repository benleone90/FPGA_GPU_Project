/*
Header file for neuron for a neural network
*/
#ifndef NEURON_H
#define NEURON_H

#define W1 0
#define W2 1
#define BIAS 4
#define SAMPLES 50

float sigmoid(float x);

float dot_product(int *u, int *v);

float feedforward(int *neuron, int *input, int bias);

struct neuron
{
    int weights[2];
    int bias;
};

#endif // NEURON_H