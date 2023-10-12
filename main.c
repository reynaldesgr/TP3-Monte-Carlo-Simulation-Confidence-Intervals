#include <stdio.h>

#include "test/tests.h"
#include "mt/matsumoto.h"

int main (void)
{
    // Always initialize the MT generator
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    // 1 - SimPi function
    testSimPi();

    /*// 2 - Independent experiments

    // Number of replicates = 10
    testMeanPi(10);

    // Number of replicates = 30
    testMeanPi(30);

    // Number of replicates = 40
    testMeanPi(40);

    // 3 - Confidence intervals
    testConfidenceInterval();*/

    return 0;
}