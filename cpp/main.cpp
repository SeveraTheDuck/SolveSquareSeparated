#include "../headers/header.h"

//makefile

int main(int argc, char** argv)
{
    struct CoefficientsStruct equation_coefficients = {0, 0, 0};
    struct RootsStruct equation_roots = {0, 0};
    TypeOfRoots number_of_roots = TypeOfRoots::SS_NO_ROOTS;

    printf("Let us solve the quadratic equation!\n");
    UnitTests(&equation_coefficients, &equation_roots);

    if (!GetInput(&equation_coefficients))
    {
        printf("Please, check the input type");
        return 1;
    }

    number_of_roots = SolveGivenEquation(&equation_coefficients, &equation_roots);

    PrintOutput(number_of_roots, &equation_roots);
    return 0;
}
