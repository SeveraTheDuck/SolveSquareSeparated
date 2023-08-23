#include "../headers/header.h"

TypeOfRoots SolveGivenEquation(const double a, const double b, const double c,
                                double* x1, double* x2)
{
    if (CompareEquality(a, 0))                                                 // linear equation case
    {
        return SolveLinearEquation(b, c, x1);
    }
    else
    {
        return SolveQuadraticEquation(a, b, c, x1, x2);           // square equation case
    }
}

TypeOfRoots SolveLinearEquation(const double b, const double c, double* x1)
{
    assert(x1 != NULL);

    if (CompareEquality(b, 0) && !CompareEquality(c, 0))                       // no roots
    {
        return TypeOfRoots::SS_NO_ROOTS;
    }
    else if (CompareEquality(b, 0))                                            // inf roots
    {
        return TypeOfRoots::SS_INF_ROOTS;
    }
    else                                                                       // one root
    {
        *x1 = - c / b;
        assert(isfinite(*x1));
        return TypeOfRoots::SS_ONE_ROOT;
    }
}

TypeOfRoots SolveQuadraticEquation(const double a, const double b, const double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double D = FindDiscriminant(a, b, c);                                          // no roots
    if (D <= -EPS)
    {
        return TypeOfRoots::SS_NO_ROOTS;
    }
    else if (CompareEquality(D, 0))                                                          // one root
    {
        *x1 = - b / (2 * a);
        return TypeOfRoots::SS_ONE_ROOT;
    }
    else                                                                       // two roots
    {
        double sqrt_D = sqrt(D);
        *x1 = FindFirstRoot(sqrt_D, a, b);
        *x2 = FindSecondRoot(sqrt_D, a, b);
        return TypeOfRoots::SS_TWO_ROOTS;
    }
}
