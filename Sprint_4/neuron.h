/*
Header file for neuron for a neural network
*/
#ifndef NEURON_H
#define NEURON_H

#define WEIGHTS 2
#define SAMPLES 5

float sigmoid(float x);

float dot_product(int *u, int *v);

float feedforward(int *neuron, int *input, int bias);

struct neuron
{
    int weights[WEIGHTS];
    int bias;
};

#endif