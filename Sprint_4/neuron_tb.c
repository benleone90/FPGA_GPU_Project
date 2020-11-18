#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "neuron.h"

int main()
{
    FILE *inp1;
    int val1;

    int test[SAMPLES];

    /* Test if data file is open */
    inp1 = fopen("test.dat", "r");
    if (inp1 == NULL)
    {
        printf("File Not Found!\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("File Open!\n");
    }

    for (size_t i = 0; i < SAMPLES; i++)
    {
        fscanf(inp1, "%d\n", &val1);
        test[i] = val1;
    }

    fclose(inp1);
    for (size_t i = 0; i < 1; i++)
    {
        int weights[WEIGHTS] = {test[i], test[i + 1]};
        int bias = test[i + 2];
        int inputs[WEIGHTS] = {test[i + 3], test[i + 4]};
        struct neuron n1 = {*weights, bias};
        printf("%.20f\n", feedforward(n1.weights, inputs, n1.bias));
    }
    return EXIT_SUCCESS;
}
