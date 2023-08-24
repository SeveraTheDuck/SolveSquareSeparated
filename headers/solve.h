#ifndef __SOLVE_H
#define __SOLVE_H

/**
    \brief This function calls for SolveLinearEquation or SolveQuadraticEquation
    functions.

    The choice between them depends on coefficient a (before x^2).
*/
TypeOfRoots SolveGivenEquation(const struct CoefficientsStruct* equation_coefficients,
                                struct RootsStruct* equation_roots);

/**
    \brief This function solves the linear equation and
    returns number of its roots.

    It is being called if coefficient a (before x^2) equals to zero.
*/
TypeOfRoots SolveLinearEquation(const struct CoefficientsStruct* equation_coefficients,
                                struct RootsStruct* equation_roots);

/**
    \brief This function solves the quadratic equation and
    returns number of its roots.

    It is being called if coefficient a (before x^2) doesn't equal to zero.
*/
enum TypeOfRoots SolveQuadraticEquation(const struct CoefficientsStruct* equation_coefficients,
                                struct RootsStruct* equation_roots);

#endif
