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


double simPi(int numSimulations)
{
    double xr, yr;
    int    i;
    int    nbPoints;

    nbPoints = 0;

    for (i = 0; i < numSimulations; i++)
    {
        xr = uniform(0, 1);
        yr = uniform(0, 1);

        if ( (xr*xr) + (yr*yr) <= 1)
        {
            nbPoints++;
            printf("(%f, %f, 'Accepted'),\n", xr, yr);
        }
        else
        {
            printf("(%f, %f, 'Rejected'),\n", xr, yr); 
        }
    }

    return 4. * ((double) nbPoints/numSimulations);
}