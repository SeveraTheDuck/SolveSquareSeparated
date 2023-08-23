#ifndef solve_h
#define solve_h

/**
    \brief This function solves the linear equation and
    returns number of its roots.
*/
TypeOfRoots SolveLinearEquation(double b, double c, double* x1);

/**
    \brief This function solves the quadratic equation and
    returns number of its roots.
*/
TypeOfRoots SolveQuadraticEquation(double a, double b, double c, double* x1, double* x2);   // square equation case

#endif
