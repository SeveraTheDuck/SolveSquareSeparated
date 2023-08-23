#include "../headers/header.h"

//структуры
//makefile

int main(int argc, char** argv)
{
    double a = 0, b = 0, c = 0;                                                // a, b, c - square equation sort of ax^2 + bx + c = 0
    double x1 = 0, x2 = 0;                                                    // x1 & x2 - roots of the equation
    TypeOfRoots number_of_roots = TypeOfRoots::SS_NO_ROOTS;

    printf("Let us solve the quadratic equation!\n");
    UnitTests();

    if (!GetInput(&a, &b, &c))                                                 // input and check coefficients
    {
        printf("Please, check the input type");
        return 1;
    }

    number_of_roots = SolveGivenEquation(a, b, c, &x1, &x2);

    PrintOutput(number_of_roots, x1, x2);
    return 0;
}
