/**
 * @file math_utility.c
 * 
 * @brief Mathematical utility functions for various calculations.
 * 
 * This file contains mathematical utility function(s).
 * 
*/

#include <stdio.h>

#include "math_utility.h"

/**
 * @brief Calculate the estimated variance of a dataset
 * 
 * This function calculates the estimated variance of a dataset based 
 * on the provided data and its mean.
 * 
 * The estimated variance is computed using the formula for sample variance,
 * which divides the sum of square differences from the mean by (n - 1) where
 * "n" is the number of data points.
 * 
 * @param X Array of data values.
 * @param meanX Mean of the data.
 * @param n Number of data points in the dataset.
 * 
 * @return The estimated variance of the dataset.
*/

double calculateEstimatedVariance(double * X, double meanX, int n)
{
    double sum = 0;
    double estimatedVariance;

    for (int i = 0; i < n; i++)
    {
        // For each element, calculate the square of the difference between a element and the mean
        sum += (X[i] - meanX) * (X[i] - meanX);
    }

    // Calculate the estimated variance by dividing the sum by (n - 1)
    estimatedVariance = sum / (n - 1);
    
    return estimatedVariance;
}