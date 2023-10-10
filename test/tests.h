#ifndef __TESTS_H__
#define __TESTS_H__

void testSimPi();
void testMeanPi(int numSimulations);
void testConfidenceInterval();

double calculateEstimatedVariance(double * X, double meanX, int n);

#endif