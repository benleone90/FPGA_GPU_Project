#include <stdio.h>
#include <math.h>

float sigmoid(float x)
{
    float exp_value;
    float return_value;

    // Exponential Calculation //
    exp_value = exp((double)-x);

    // Final Sigmoid Value //
    return_value = 1 / (1 + exp_value);

    return return_value;
}

int main()
{
    printf("%.6f\n", sigmoid(-6));
}