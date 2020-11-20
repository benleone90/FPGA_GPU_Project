#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "neuron.h"
int main()
{
    struct neuron n1 = {{W1, W2}, BIAS};
    struct neuron n2 = {{W1, W2}, BIAS};
    struct neuron o1 = {{W1, W2}, BIAS};

    float test_inp[2] = {2, 3};

    float out1 = feedforward(n1.weights, test_inp, n1.bias);
    float out2 = feedforward(n2.weights, test_inp, n2.bias);

    float new_inp[2] = {out1, out2};

    float out3 = feedforward(o1.weights, new_inp, o1.bias);

    printf("%.20f\n", out3);
}