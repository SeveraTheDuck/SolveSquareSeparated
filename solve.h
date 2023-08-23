#ifndef solve_h
#define solve_h

TypeOfRoots SolveLinearEquation(double b, double c, double* x1);                            // linear equation case
TypeOfRoots SolveQuadraticEquation(double a, double b, double c, double* x1, double* x2);   // square equation case

#endif
