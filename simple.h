#ifndef simple_h
#define simple_h

/**
    \brief This function finds and returns discriminant of the
    quadratic equation using 3 coefficients.
*/
double FindDiscriminant(double a, double b, double c);

/**
    \brief This function finds and returns the first root of the
    quadratic equation.
*/
double FindFirstRoot(double sqrt_D, double a, double b);

/**
    \brief This function finds and returns the second root of the
    quadratic equation.
*/
double FindSecondRoot(double sqrt_D, double a, double b);

/**
    \brief This function compares two doubles and returns whether
    they are equal or not.
*/
bool CompareEquality(const double a, const double b);

#endif
