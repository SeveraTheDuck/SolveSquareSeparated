#ifndef __SIMPLE_H
#define __SIMPLE_H

/**
    \brief This function fixes -0.000 bug caused by double.
*/
double IsZeroRoot(double x);

/**
    \brief This function finds and returns discriminant of the
    quadratic equation using 3 coefficients.

    It uses stucture to combine coefficients into group.
*/
double FindDiscriminant(const struct CoefficientsStruct* equation_coefficients);

/**
    \brief This function finds and returns the first root of the
    quadratic equation.

    It uses stucture to combine coefficients into group.
*/
double FindFirstRoot(const double sqrt_D, const struct CoefficientsStruct* equation_coefficients);

/**
    \brief This function finds and returns the second root of the
    quadratic equation.

    It uses stucture to combine coefficients into group.
*/
double FindSecondRoot(const double sqrt_D, const struct CoefficientsStruct* equation_coefficients);

/**
    \brief This function compares two doubles and returns whether
    they are equal or not.
*/
bool CompareEquality(const double a, const double b);

#endif
