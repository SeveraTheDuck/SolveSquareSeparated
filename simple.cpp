#include "header.h"

double FindDiscriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

double FindFirstRoot(double sqrt_D, double a, double b)
{
    return (-b + sqrt_D) / (2 * a);
}

double FindSecondRoot(double sqrt_D, double a, double b)
{
    return (-b - sqrt_D) / (2 * a);
}

bool CompareEquality(const double a, const double b)
{
    if (fabs(a - b) < EPS) return true;
    return false;
}
