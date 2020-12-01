#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "neuron.h"

int main()
{
    float a[4] = {1, 0, 0, 1};
    float b[4] = {0, 0, 0, 0};

    printf("%f\n", mse(a, b, 4));
}
