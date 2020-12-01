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

float deriv_sigmoid(float x);

float dot_product(float u[2], float v[2]);

float feedforward(float neuron[2], float input[2], int bias);

float mse(float a[4], float b[4], int size);

struct neuron
{
    float weights[2];
    int bias;
};

#endif // NEURON_H