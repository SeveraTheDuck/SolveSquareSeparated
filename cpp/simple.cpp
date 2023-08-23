#include "../headers/header.h"

double FindDiscriminant(const double a, const double b, const double c)
{
    return b * b - 4 * a * c;
}

double FindFirstRoot(const double sqrt_D, const double a, const double b)
{
    return (-b + sqrt_D) / (2 * a);
}

double FindSecondRoot(const double sqrt_D, const double a, const double b)
{
    return (-b - sqrt_D) / (2 * a);
}

bool CompareEquality(const double a, const double b)
{
    if (fabs(a - b) < EPS) return true;
    return false;
}
