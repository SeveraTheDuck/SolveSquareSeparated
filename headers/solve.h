#ifndef solve_h
#define solve_h

/**
    \brief This function calls for SolveLinearEquation or SolveQuadraticEquation
    depending on coefficient before x^2;
*/

TypeOfRoots SolveGivenEquation(const struct CoefficientsStruct equation_coefficients,
                                struct RootsStruct* equation_roots);

/**
    \brief This function solves the linear equation and
    returns number of its roots.
*/
TypeOfRoots SolveLinearEquation(const struct CoefficientsStruct equation_coefficients,
                                struct RootsStruct* equation_roots);

/**
    \brief This function solves the quadratic equation and
    returns number of its roots.
*/
TypeOfRoots SolveQuadraticEquation(const struct CoefficientsStruct equation_coefficients,
                                struct RootsStruct* equation_roots);

#endif
