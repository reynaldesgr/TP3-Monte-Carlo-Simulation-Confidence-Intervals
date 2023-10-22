#ifndef __TESTS_H__
#define __TESTS_H__

void testSimPi                   (void);
void testSimPi3D                 (void);
void testMeanPi                  (int numSimulations);
void testConfidenceInterval      (void);

double calculateEstimatedVariance(double * X, double meanX, int n);

#endif