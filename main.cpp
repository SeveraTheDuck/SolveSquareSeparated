// doxygen
// github & git
// readme?
// bash для запуска флагов

#include "header.h"

int main(int argc, char** argv)
{
    double a = 1, b = 2, c = 1;                                                // a, b, c - square equation sort of ax^2 + bx + c = 0
    double x1 = -1, x2 = 0;                                                    // x1 & x2 - roots of the equation
    TypeOfRoots number_of_roots = TypeOfRoots::SS_NO_ROOTS;

    printf("Let us solve the quadratic equation!\n");
    printf("Please, type the coefficients: ");
    if (!GetInput(&a, &b, &c))                                                 // input and check coefficients
    {
        printf("Please, check the input type");
        return 1;
    }

    if (CompareEquality(a, 0))                                                 // linear equation case
    {
        number_of_roots = SolveLinearEquation(b, c, &x1);
    }
    else
    {
        number_of_roots = SolveQuadraticEquation(a, b, c, &x1, &x2);           // square equation case
    }

    PrintOutput(number_of_roots, x1, x2);
    return 0;
}
