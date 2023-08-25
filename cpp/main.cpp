#include "../headers/header.h"
#include "../headers/arg.h"
#include "../headers/test.h"

// imaginarium
// auto-collect files to compile @< $(wildcard ....)

int main(int argc, char** argv)
{
    struct CoefficientsStruct equation_coefficients = {.a = 0, .b = 0, .c = 0};
    struct RootsStruct equation_roots = {.x1 = 0, .x2 = 0};
    #ifdef _DEBUG
        UnitTests(&equation_roots);
    #endif
    printf("Let us solve your quadratic equation!\n");

    if (argc == 1)
    {
        ConsoleInput(&equation_coefficients, &equation_roots);
        return 0;
    }

    if (argc > 3)
    {
        printf("Too many arguments from the command line");
        return 0;
    }

    if (!strcmp(argv[1], "--file"))
    {
        FileInput(&equation_coefficients, &equation_roots, argv);
        return 0;
    }

    printf("Wrong command line input.");
    return 0;
}
