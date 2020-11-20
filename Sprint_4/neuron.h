/*
Header file for neuron for a neural network
*/
#ifndef NEURON_H
#define NEURON_H

#define W1 0
#define W2 1
#define BIAS 0
#define SAMPLES 50

float sigmoid(float x);

float dot_product(float *u, float *v);

float feedforward(float *neuron, float *input, int bias);

struct neuron
{
    int weights[2];
    int bias;
};

#endif // NEURON_H