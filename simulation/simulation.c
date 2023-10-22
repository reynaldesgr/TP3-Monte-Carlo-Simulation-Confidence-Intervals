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
 * @param numPointsToDraw Number of points to draw.
 * 
 * @return The estimated value of Pi.
*/

double simPi(int numPointsToDraw)
{
    double xr, yr;
    int    i;
    double nbPointsInCircle;
    double estimatedPi;

    // Initialize the count of points in the circle to zero.
    nbPointsInCircle = 0.;

    for (i = 0; i < numPointsToDraw; i++)
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
    estimatedPi = 4. * ( (double) (nbPointsInCircle / numPointsToDraw) );
    
    return estimatedPi;
}



/**
 * @brief Estimates the value of pi using a Monte Carlo simulation in 3D space.
 *
 * This function estimates the value of pi by generating random points in a 3D space
 * and checking how many of these points fall within a sphere inscribed in a cube.
 * The ratio of points inside the sphere to the total number of points is used to
 * estimate pi.
 *
 * @param numPointsToDraw The number of random points to generate and check.
 * @return An estimated value of pi.
 */

double simPi3D(int numPointsToDraw) 
{

    double x;
    double y;
    double z;

    double sphereVolume;
    double estimatedPi;

    // Initialize the count of points inside the sphere to zero.
    int nbPointsInSphere = 0;

    nbPointsInSphere = 0;

    for (int i = 0; i < numPointsToDraw; i++) 
    {
        // Generate random coordinates in the range [-1, 1]
        x = genrand_real1() * 2 - 1;
        y = genrand_real1() * 2 - 1;
        z = genrand_real1() * 2 - 1;

        // Check if the point is inside the inscribed sphere
        if ( (x * x) + (y * y) + (z * z) <= 1) 
        {
            nbPointsInSphere++;
        }
    }

    // Calculate the volume of the sphere using the ratio of the points inside.
    sphereVolume = (double) nbPointsInSphere / numPointsToDraw * 8;

    // Calculate the estimated value of pi
    estimatedPi = sphereVolume / (4.0 / 3.0);

    return estimatedPi;
}