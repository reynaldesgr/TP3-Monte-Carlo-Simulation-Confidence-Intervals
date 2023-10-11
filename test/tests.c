#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "../simulation/simulation.h"
#include "tests.h"

const double alpha_0_01_values[] = {
    63.657, 9.925, 5.841, 4.604, 4.032, 3.707, 3.499, 3.355, 3.250, 3.169,
    3.106, 3.055, 3.012, 2.977, 2.947, 2.921, 2.898, 2.878, 2.861, 2.845,
    2.831, 2.819, 2.807, 2.797, 2.787, 2.779, 2.771, 2.763, 2.756, 2.750
};

void testSimPi()
{
    int    numSimulations[] = {1000, 1000000, 10000000};
    double estimatedPi;

    printf("\n -- Approximation de PI par Monte Carlo --\n");

    for (int i = 0; i < 3; i++)
    {
        estimatedPi = simPi(numSimulations[i]);
        printf("\n * Estimation with %d points : estimated PI = %f\n",  numSimulations[i], estimatedPi);
    }
    
}



void testMeanPi(int numExperiments)
{
    double estimatedPi;
    double absoluteError;
    double relativeError;

    int    numSimulations[] = {1000, 1000000, 10000000};
    double meanPi[3]        = {0.};

    printf ("\n-- Computing independent experiments and obtaining the mean\n");

    int i, j;
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < numExperiments; j++)
        {
            estimatedPi = simPi(numSimulations[i]);
            meanPi[i]   += estimatedPi;
        }
    
        // Compute the mean
        meanPi[i] = meanPi[i] / numExperiments;

        // Absolute and relative errors
        absoluteError = fabs(meanPi[i] - M_PI);
        relativeError = absoluteError / M_PI;

        // Display tests results
        printf("\n* Mean estimation of PI with %d simulations and %d experiments : %f\n", numSimulations[i], numExperiments, estimatedPi);
        printf("-- Absolute error : %f \n", absoluteError);
        printf("-- Relative error : %f\n", relativeError);  
    }

}


void testConfidenceInterval()
{
    double estimatedPi[NMAX];
    double estimatedStdDeviation;

    double criticalValue;
    double confidenceValue;

    double meanPi;

    int    numReplicates;
    int    numSimulations = 1000;

    printf("Enter the number of replicates (experiments) : ");
    scanf("%d", &numReplicates);

    int i;
    for (i = 0; i < numReplicates; i++)
    {
        estimatedPi[i] = simPi(numSimulations);
        meanPi      += estimatedPi[i];
    }
    
    // Compute the mean
    meanPi = meanPi / numReplicates;

    estimatedStdDeviation = calculateEstimatedVariance(estimatedPi, meanPi, numReplicates);
    
    if (numReplicates <= 30)
    {
        criticalValue = alpha_0_01_values[numReplicates - 1];
    }
    else
    {
        criticalValue = 2.576; // for n -> infinity
    }

    confidenceValue = criticalValue * sqrt(estimatedStdDeviation / numReplicates);

    printf("\n -- Mean Estimation with %d simulations and %d replicates: %f\n", numSimulations, numReplicates, meanPi);
    printf("\n* Estimated standard Deviation: %f\n", estimatedStdDeviation);
    printf("\n* 99%% Confidence Interval: [%f-%f] %%\n", meanPi - confidenceValue, meanPi + confidenceValue);
}

double calculateEstimatedVariance(double * X, double meanX, int n)
{
    double sum = 0;
    double estimatedVariance;

    for (int i = 0; i < n; i++)
    {
        sum += (X[i] - meanX) * (X[i] - meanX);
    }
    estimatedVariance = sum / (n - 1);

    return estimatedVariance;
}