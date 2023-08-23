#ifndef solve_h
#define solve_h

/**
    \brief This function calls for SolveLinearEquation or SolveQuadraticEquation
    depending on coefficient before x^2;
*/

TypeOfRoots SolveGivenEquation(const double a, const double b, const double c,
                                double* x1, double* x2);

/**
    \brief This function solves the linear equation and
    returns number of its roots.
*/
TypeOfRoots SolveLinearEquation(const double b, const double c, double* x1);

/**
    \brief This function solves the quadratic equation and
    returns number of its roots.
*/
TypeOfRoots SolveQuadraticEquation(const double a, const double b, const double c, double* x1, double* x2);

#endif
