#include "../headers/header.h"
#include "../headers/solve.h"
#include "../headers/output.h"
#include "../headers/test.h"

//readme

int main(int /*argc*/, char** /*argv*/)
{
    struct CoefficientsStruct equation_coefficients = {.a = 0, .b = 0, .c = 0};
    struct RootsStruct equation_roots = {.x1 = 0, .x2 = 0};
    TypeOfRoots number_of_roots = TypeOfRoots::SS_NO_ROOTS;
    #ifdef _DEBUG
        UnitTests(&equation_coefficients, &equation_roots);
    #endif
    printf("Let us solve your quadratic equation!\n");

    if (!GetInput(&equation_coefficients))
    {
        printf("Please, check the input type\n");
        return 1;
    }

    number_of_roots = SolveGivenEquation(&equation_coefficients, &equation_roots);

    PrintOutput(number_of_roots, &equation_roots);
    return 0;
}
