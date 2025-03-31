#ifndef WEIGHTEDDICE_H
#define WEIGHTEDDICE_H

#include <stdbool.h>

struct {
    int len;
    bool isInitialized;
    double *sumWeights;
}typedef WeightedDice;

int initializeWeightedDice(WeightedDice *dice, int len, double *weights);

int throwWeightedDice(WeightedDice *dice);

void freeWeightedDice(WeightedDice *dice);

#endif // WEIGHTEDDICE_H