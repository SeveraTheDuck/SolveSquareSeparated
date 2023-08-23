#ifndef simple_h
#define simple_h

/**
    \brief This function finds and returns discriminant of the
    quadratic equation using 3 coefficients.
*/
double FindDiscriminant(const double a, const double b, const double c);

/**
    \brief This function finds and returns the first root of the
    quadratic equation.
*/
double FindFirstRoot(const double sqrt_D, const double a, const double b);

/**
    \brief This function finds and returns the second root of the
    quadratic equation.
*/
double FindSecondRoot(const double sqrt_D, const double a, const double b);

/**
    \brief This function compares two doubles and returns whether
    they are equal or not.
*/
bool CompareEquality(const double a, const double b);

#endif
