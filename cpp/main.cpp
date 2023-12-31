#include "header.h"
#include "arg.h"
#include "test.h"

int main(int argc, char** argv)
{
    struct CoefficientsStruct equation_coefficients = {.a = 0, .b = 0, .c = 0};
    struct RootsStruct equation_roots = {.x1 = 0, .x2 = 0};
    #ifdef _DEBUG
        UnitTests(&equation_roots);
    #endif
    printf("Let us solve your quadratic equation!\n");

    if (argc == 1) // no input from command line, standart coefficients input
    {
        ConsoleInput(&equation_coefficients, &equation_roots);
        return 0;
    }

    if (argc > 3) // Not yet implemented :)
    {
        printf("Too many arguments from the command line");
        return 0;
    }

    if (!strcmp(argv[1], "--file")) // input from input.txt file
    {
        FileInput(&equation_coefficients, &equation_roots, argv);
        return 0;
    }

    printf("Wrong command line input.");
    return 0;
}
