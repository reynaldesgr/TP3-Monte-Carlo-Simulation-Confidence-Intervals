#include <stdio.h>

#include "test/tests.h"
#include "mt/matsumoto.h"

int main (void)
{
    // Toujours initialiser le générateur
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    // 1 - SimPi function
    //testSimPi();

    // 2 - Independent experiments
    // Simulation = 1000
    testMeanPi(1000);
    // Simulation = 1000 000
    //testMeanPi(1000000);
    // Simulation = 1000 000 000
    //testMeanPi(1000000000);

    return 0;
}