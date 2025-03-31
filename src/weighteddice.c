#include <stdlib.h>
#include <time.h>

#include <weighteddice.h>

int initializeWeightedDice(WeightedDice *dice, int len, double *weights)
{
  /* array of weights must be of lenght len, and it must
   * be the same size as the faces array.                */

  /* Define an array of partial sum of weights */
  dice->sumWeights = malloc(sizeof(double) * len);
  if (dice->sumWeights == NULL) {
    return -1; // Memory allocation failed
  }

  /* Sum all the weights */
  double sum = 0;

  /* Randomize seed from RNG */
  srand(time(NULL));
  
  for (int i=0; i<len; i++)
  {
    sum += weights[i];
    dice->sumWeights[i] = sum;
  }

  /* Normalize the sumWeight vector */
  for (int i=0; i<len; i++)
  {
    dice->sumWeights[i] /= sum;
  }

  dice->len = len;
  dice->isInitialized = true;

  return 0;
}

int throwWeightedDice(WeightedDice *dice)
{
  if (!dice->isInitialized) {
    return -1; // Dice not initialized
  }

  /* Generate a random number between 0 and 1 */
  double randomValue = (double)rand() / (double)RAND_MAX;

  /* Find the index of the first element in sumWeights that is greater than or equal to randomValue */
  for (int i=0; i<dice->len; i++)
  {
    if (randomValue <= dice->sumWeights[i])
    {
      return i;
    }
  }

  return -1; // This should never happen if weights are valid
}

void freeWeightedDice(WeightedDice *dice)
{
  if (dice->isInitialized) {
    free(dice->sumWeights);
    dice->isInitialized = false;
  }
}



