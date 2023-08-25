#include "../headers/header.h"
#include "../headers/simple.h"

double FindDiscriminant(const struct CoefficientsStruct* equation_coefficients)
{
    MYASSERT(equation_coefficients != NULL);

    return equation_coefficients->b * equation_coefficients->b - 4 * equation_coefficients->a * equation_coefficients->c;
}

double FindFirstRoot(const double sqrt_D, const struct CoefficientsStruct* equation_coefficients)
{
    MYASSERT(equation_coefficients != NULL);

    return (-equation_coefficients->b + sqrt_D) / (2 * equation_coefficients->a);
}

double FindSecondRoot(const double sqrt_D, const struct CoefficientsStruct* equation_coefficients)
{
    MYASSERT(equation_coefficients != NULL);

    return (-equation_coefficients->b - sqrt_D) / (2 * equation_coefficients->a);
}

bool CompareEquality(const double a, const double b)
{
    return fabs(a - b) < EPS;
}
