#include <stdio.h>
#include <weighteddice.h>

int main(int argc, char **argv)
{
    WeightedDice dice1;

    /* Define weights*/
    double weights[] = {1, 1, 4, 1, 1, 1};

    int faces[] = {1, 2, 3, 4, 5, 6};

    /* Initialize the WeightedDice object */
    initializeWeightedDice(&dice1, 6, weights);

    /* Generate a sequency of 10 throws */
    for (int i=0; i<10; i++)
    {
        fprintf(stdout, "Throw [%d] -> %d\n", i, faces[throwWeightedDice(&dice1)]);
    }
    
    freeWeightedDice(&dice1);
    return 0;
}