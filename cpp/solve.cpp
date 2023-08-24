#include "../headers/header.h"

TypeOfRoots SolveGivenEquation(const struct CoefficientsStruct* equation_coefficients,
                                struct RootsStruct* equation_roots)
{
    if (CompareEquality(equation_coefficients->a, 0))
    {
        return SolveLinearEquation(equation_coefficients, equation_roots);
    }
    else
    {
        return SolveQuadraticEquation(equation_coefficients, equation_roots);
    }
}

TypeOfRoots SolveLinearEquation(const struct CoefficientsStruct* equation_coefficients,
                                struct RootsStruct* equation_roots)
{
    assert(equation_roots != NULL);

    if (CompareEquality(equation_coefficients->b, 0) && !CompareEquality(equation_coefficients->c, 0))
    {
        return TypeOfRoots::SS_NO_ROOTS;
    }
    else if (CompareEquality(equation_coefficients->b, 0))
    {
        return TypeOfRoots::SS_INF_ROOTS;
    }
    else
    {
        equation_roots->x1 = - equation_coefficients->c / equation_coefficients->b;
        assert(isfinite(equation_roots->x1));

        return TypeOfRoots::SS_ONE_ROOT;
    }
}

TypeOfRoots SolveQuadraticEquation(const struct CoefficientsStruct* equation_coefficients,
                                struct RootsStruct* equation_roots)
{
    assert(equation_roots != NULL);

    double D = FindDiscriminant(equation_coefficients);
    if (D <= -EPS)
    {
        return TypeOfRoots::SS_NO_ROOTS;
    }
    else if (CompareEquality(D, 0))
    {
        equation_roots->x1 = - equation_coefficients->b / (2 * equation_coefficients->a);
        return TypeOfRoots::SS_ONE_ROOT;
    }
    else
    {
        double sqrt_D = sqrt(D);
        equation_roots->x1 = FindFirstRoot(sqrt_D, equation_coefficients);
        equation_roots->x2 = FindSecondRoot(sqrt_D, equation_coefficients);
        return TypeOfRoots::SS_TWO_ROOTS;
    }
}
