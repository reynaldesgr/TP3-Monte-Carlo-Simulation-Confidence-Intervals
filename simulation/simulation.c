/**
 * @file simulation.c
 * 
 * @brief This file contains functions for performing simulations 
 * and generate pseudo-random numbers.
 * 
*/

#include <stdio.h>
#include "../mt/matsumoto.h"

/**
 * @brief Generate a pseudo-random number between a and b: [a, b].
 * 
 * @param a Lower bound (minimum value that the random number can take).
 * @param b Upper bound (maximum value that the random number can take).
 * 
 * @return A pseudo-random number in the specified range [a, b].
 */

double uniform(double a, double b)
{
    double r = genrand_real1();
    
    return a + (b - a) * r;
}


/**
 * @brief Approximate the value of Pi using the Monte Carlo method.
 * 
 * This function uses the Monte Carlo method to estimate the value of Pi.
 * It generate a specified number of random points (numSimulations points) within
 * a square and counts how many fall inside into the first quarter of a unit circle
 * inscribed in that square.
 * 
 * The ratio of points inside the circle to the total number of points
 * is used to estimate Pi.
 * 
 * @param numSimulations Number of simulations to run, each simulation draw a random point.
 * 
 * @return The estimated value of Pi.
*/

double simPi(int numSimulations)
{
    double xr, yr;
    int    i;
    double nbPointsInCircle;

    // Initialize the count of points in the circle to zero.
    nbPointsInCircle = 0.;

    for (i = 0; i < numSimulations; i++)
    {
        xr = genrand_real1();
        yr = genrand_real1();

        // Check if the point (xr, yr) is inside the unit circle (radius = 1)
        if ( (xr*xr) + (yr*yr) <= 1)
        {
            // Increment the count if the point is inside
            nbPointsInCircle++;
        }
    }

    // Calculate an estimate of pi
    return 4. * ( (double) (nbPointsInCircle / numSimulations) );
}