#include <stdio.h>
#include <stdlib.h>
#include <weighteddice.h>

int main(int argc, char **argv)
{
    WeightedDice dice1;

    /* Define weights*/
    double weights[] = {1, 1, 1, 1, 8, 1};

    int faces[] = {1, 2, 3, 4, 5, 6};

    int len = 6;

    /* Initialize the WeightedDice object */
    initializeWeightedDice(&dice1, len, weights);

    int *counter;
    counter = calloc(sizeof(int), len);
    if (counter == NULL)
    {
        return -1; // Memory allocation failed.
    }

    
    /* Throw the dice n times */
    int numThrows = 1000;

    for (int i=0; i<numThrows; i++)
    {
        counter[faces[throwWeightedDice(&dice1)] - 1] += 1;
    }

    for (int i=0; i<len; i++)
    {
        fprintf(stdout, "Face[%d] -> %.2f%%\n", faces[i], 100.0 * ((double)counter[i] / numThrows));
    }
    
    freeWeightedDice(&dice1);
    return 0;
}