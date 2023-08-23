#include "../headers/header.h"

double FindDiscriminant(const struct CoefficientsStruct equation_coefficients)
{
    return equation_coefficients.b * equation_coefficients.b - 4 * equation_coefficients.a * equation_coefficients.c;
}

double FindFirstRoot(const double sqrt_D, const struct CoefficientsStruct equation_coefficients)
{
    return (-equation_coefficients.b + sqrt_D) / (2 * equation_coefficients.a);
}

double FindSecondRoot(const double sqrt_D, const struct CoefficientsStruct equation_coefficients)
{
    return (-equation_coefficients.b - sqrt_D) / (2 * equation_coefficients.a);
}

bool CompareEquality(const double a, const double b)
{
    if (fabs(a - b) < EPS) return true;
    return false;
}
