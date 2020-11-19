#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "neuron.h"

int main()
{
    FILE *inp1, *inp2, *outp1;
    int val1;
    float val2;
    int inputs[SAMPLES * 2];
    float reference[SAMPLES];
    float result[SAMPLES];

    // TEST IF FILE IS DATA FILE IS FOUND //
    inp1 = fopen("../data/ref_input.dat", "r");
    inp2 = fopen("../data/ref_result.dat", "r");
    if (inp1 == NULL || inp2 == NULL)
    {
        printf("File Not Found!\n");
        return EXIT_FAILURE;
    }

    // LOAD INPUTS AND EXPECTED RESULTS INTO INPUTS ARRAY //
    for (size_t i = 0; i < SAMPLES * 2; i++)
    {
        fscanf(inp1, "%d\n", &val1);
        inputs[i] = val1;
    }
    fclose(inp1);
    for (size_t i = 0; i < SAMPLES; i++)
    {
        fscanf(inp2, "%f\n", &val2);
        reference[i] = val2;
    }
    fclose(inp2);

    // WRITE RESULTS TO FILE OR ARRAY //
    // outp1 = fopen("data/ref_result.dat", "w");
    struct neuron n1 = {{W1, W2}, BIAS};
    for (size_t i = 0; i < SAMPLES * 2; i++)
    {
        if (i % 2 == 0)
        {
            // printf("%d, %d\n", inputs[i], inputs[i + 1]);
            int test_inp[2] = {inputs[i], inputs[i + 1]};
            // printf("%.20f\n", feedforward(n1.weights, test_inp, n1.bias));
            fprintf(stdout, "%.20f\n", feedforward(n1.weights, test_inp, n1.bias));
        }
        else
        {
            continue;
        }
    }
    // fclose(outp1);
    return EXIT_SUCCESS;
}
