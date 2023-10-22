/**
 * @file tests.c
 * 
 * @brief Tests for approximating pi using Monte Carlo methods.
 * 
 * This file contains functions to test and approximate the value of pi.
 * 
*/
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "../simulation/simulation.h"
#include "../imath/math_utility.h"
#include "tests.h"

/**
 * @brief Array of critical values for the Student's t-distribution 
 * at 99.9% confidence (alpha = 0.01)
 * 
 * This array contains critical values associated with the Student's t-distribution
 * for various sample sizes.
 * If the sample size / number of replicates is greater than the size of the array (= 30)
 * then the value is approximated for n which tends towards infinity (= 2.576 for alpha = 0.01)
 * 
*/

const double alpha_0_01_values[] = {
    63.657, 9.925, 5.841, 4.604, 4.032, 3.707, 3.499, 3.355, 3.250, 3.169,
    3.106, 3.055, 3.012, 2.977, 2.947, 2.921, 2.898, 2.878, 2.861, 2.845,
    2.831, 2.819, 2.807, 2.797, 2.787, 2.779, 2.771, 2.763, 2.756, 2.750
};


/**
 * @brief Test the estimation of Pi with different number of simulations.
 * 
 * This function tests the estimation of Pi using simPi() function with
 * different numbers of simulations and then displays the results.
 * 
*/

void testSimPi()
{
    int    numSimulations[] = {1000, 1000000, 1000000000};
    double estimatedPi;

    printf("\n -- Pi Approximation by Monte Carlo method --\n");

    for (int i = 0; i < 3; i++)
    {
        estimatedPi = simPi(numSimulations[i]);
        printf("\n * Estimation with %d points : estimated PI = %f\n",  numSimulations[i], estimatedPi);
    }
    
}

/**
 * @brief Perform multiple simulations to estimate the value of pi using a Monte Carlo method in 3D space.
 *
 * This function performs multiple simulations to estimate the value of pi using a Monte Carlo method
 * in a 3D space. It uses different numbers of random points to calculate pi estimates for each simulation.
 *
 * @details It prints the estimated values of pi for each simulation.
 */

void testSimPi3D()
{
    int    numSimulations[] = {1000, 1000000, 1000000000};
    double estimatedPi;

    printf("\n -- Pi Approximation by Monte Carlo method (in 3-Dimension) --\n");

    for (int i = 0; i < 3; i++)
    {
        estimatedPi = simPi(numSimulations[i]);
        printf("\n * Estimation with %d points : estimated PI = %f\n",  numSimulations[i], estimatedPi);
    }
    
}


/**
 * @brief Test and perform multiple independent replicates to obtain the mean
 * estimate of pi.
 * 
 * This function runs multiple independent experiments, each using simPi() function,
 * and compute the mean estimate of Pi along with absolute and relative errors.
 * 
 * @param numExperiments The number of independ experiments to perform.
 * 
*/

void testMeanPi(int numExperiments)
{
    double estimatedPi;
    double absoluteError;
    double relativeError;

    // Number of simulations to perform
    int    numSimulations[] = {1000, 1000000, 1000000000};
    double meanPi[3]        = {0.};

    printf ("\n-- Computing independent experiments and obtaining the mean\n");

    int i, j;
    
    for (i = 0; i < 3; i++)
    {
        // Compute numExperiments times numSimulations
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
        printf("* Mean estimation of PI with %d simulations and %d experiments/replicates : %f\n", numSimulations[i], numExperiments, estimatedPi);
        printf("-- Absolute error : %f\n", absoluteError);
        printf("-- Relative error : %f\n", relativeError);
       
    }

}

/**
 * @brief Calculate the mean estimate, estimated standard deviation, and finally 
 * the confidence interval of pi.
 * 
 * This function calculates the mean estimate of pi, its standard deviation, and a confidence
 * interval for the estimate using the specified number of replicates (n).
 * 
*/

void testConfidenceInterval()
{
    double SEM;

    double estimatedPi[NMAX];
    double estimatedStdDeviation;

    double criticalValue;
    double confidenceValue;

    double meanPi;

    // Variables for user input
    int    numReplicates;
    int    numSimulations = 1000;

    // Prompt the user to enter the number of replicates (experiments)
    printf("Enter the number of replicates (experiments) : ");
    scanf("%d", &numReplicates);

    int i;

    for (i = 0; i < numReplicates; i++)
    {
        estimatedPi[i] = simPi(numSimulations);
        meanPi      += estimatedPi[i];
    }
        
    // Compute the mean Pi
    meanPi = meanPi / numReplicates;

    // Calculate the estimated standard deviation
    estimatedStdDeviation = calculateEstimatedVariance(estimatedPi, meanPi, numReplicates);
        
    // Determine the critical value based on the number of replicates
    if (numReplicates < 30)
    {
        criticalValue = alpha_0_01_values[numReplicates - 1];
    }
    else
    {
        criticalValue = 2.576; // A critical value for large n (infinity)
    }

    // Calculate the confidence value using the critical value and standard deviation
    confidenceValue = criticalValue * sqrt(estimatedStdDeviation / numReplicates);

    // Calculate the standard error (SEM)
    SEM             = estimatedStdDeviation / sqrt(numReplicates);
    
    // Output the results
    printf("\n -- Mean Estimation with %d simulations and %d replicates: %f\n", numSimulations, numReplicates, meanPi);
    printf("\n* Estimated standard Deviation: %f\n", estimatedStdDeviation);
    printf("\n* Standard error (SEM) : %f", SEM);
    printf("\n* 99%% Confidence Interval: [%f - %f] \n", meanPi - confidenceValue, meanPi + confidenceValue);

}
