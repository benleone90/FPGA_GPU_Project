#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "neuron.h"
int main()
{
    float w1, w2, w3, w4, w5, w6;
    int b1, b2, b3;

    int learn_rate = 0.1;
    int epochs = 1000;

    struct neuron h1 = {{w1, w2}, b1};
    struct neuron h2 = {{w3, w4}, b2};
    struct neuron o1 = {{w5, w6}, b3};
}