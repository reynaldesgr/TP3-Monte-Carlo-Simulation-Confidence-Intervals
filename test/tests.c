#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "tests.h"
#include "../simulation/simulation.h"


/**
 * @brief Calculate the mean of an array of values.
 * 
 * This function calculates the mean of a given array of values.
 * 
 * @param array The array of values.
 * @param size The size of the array.
 * 
 * @return The mean of the values in the array.
 */

double calculateMean(double * array, int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum+=array[i];
    }

    return sum / size;
}

void testSimPi()
{
    int    numSimulations;
    double pi;

    printf("\n -- Approximation de PI par Monte Carlo --\n");
    numSimulations = 1000;
    printf("\n -- Simulations = 1 000\n");
    pi = simPi(numSimulations);
    printf("\n * PI = %f", pi);

    numSimulations = 1000000;
    printf("\n -- Simulations = 1 000 000\n");
    pi = simPi(numSimulations);
    printf("\n * PI = %f", pi);

    numSimulations = 1000000000;
    printf("\n -- Simulations = 1 000 000 000\n");
    pi = simPi(numSimulations);
    printf("\n * PI = %f", pi);


}



void testMeanPi(int numSimulations)
{
    double array1[10];
    double array2[40];

    double estimatedPi;
    double meanPi;

    printf ("\n-- Computing independent experiments and obtaining the mean\n");
    printf("\n-- Simulations = %d\n", numSimulations);

    for (int i = 0; i < 10; i++)
    {
        estimatedPi = simPi(numSimulations);
        array1[i]   = estimatedPi;   
    }

    meanPi = calculateMean(array1, 10);
    printf("\n* Average (out of 10 experiments) : %f \n", meanPi);
    printf("\n* Difference with M_PI : %f \n", fabs(M_PI - meanPi));

    for (int i = 0; i < 40; i++)
    {
        estimatedPi = simPi(numSimulations);
        array2[i]   = estimatedPi;
    }

    meanPi = calculateMean(array2, 40);
    printf("\n* Average (out of 10 experiments) : %f \n", meanPi);
    printf("\n* Difference with M_PI : %f \n", fabs(M_PI - meanPi));

}