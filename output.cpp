#include "header.h"

bool GetInput(double* a, double* b, double* c)
{
    printf("Please, type the coefficients: ");
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b);
    assert(a != c);
    assert(b != c);

    if (scanf("%lf", a) != 1) return false;
    if (scanf("%lf", b) != 1) return false;
    if (scanf("%lf", c) != 1) return false;

    assert(isfinite(*a));
    assert(isfinite(*b));
    assert(isfinite(*c));

    assert(!isnan(*a));
    assert(!isnan(*b));
    assert(!isnan(*c));

    return true;
}

void PrintOutput(const TypeOfRoots number_of_roots, const double x1, const double x2)
{
    switch(number_of_roots)
    {
        case TypeOfRoots::SS_NO_ROOTS:
            printf("Cannot be solved");
            break;
        case TypeOfRoots::SS_ONE_ROOT:
            printf("The only root is %lf", x1);
            break;
        case TypeOfRoots::SS_TWO_ROOTS:
            printf("The quadratic equation has two roots:\nx1 = %lf and x2 = %lf", x1, x2);
            break;
        case TypeOfRoots::SS_INF_ROOTS:
            printf("Infinite number of roots");
            break;
        default:
            printf("Something went wrong");
            break;
    }
    return;
}
