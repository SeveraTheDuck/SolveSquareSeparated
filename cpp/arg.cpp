#include "../headers/header.h"
#include "../headers/solve.h"
#include "../headers/output.h"
#include "../headers/arg.h"

void ConsoleInput(struct CoefficientsStruct* equation_coefficients,
                    struct RootsStruct* equation_roots)
{
    TypeOfRoots number_of_roots = TypeOfRoots::SS_NO_ROOTS;

    if (!GetInput(equation_coefficients))
    {
        printf("Please, check the input type\n");
        return;
    }
    number_of_roots = SolveGivenEquation(equation_coefficients, equation_roots);

    PrintOutput(number_of_roots, equation_roots);
}

void FileInput(struct CoefficientsStruct* equation_coefficients,
                    struct RootsStruct* equation_roots,
                    char** argv)
{
    TypeOfRoots number_of_roots = TypeOfRoots::SS_NO_ROOTS;
    FILE *fp = fopen(argv[2], "r");
    MYASSERT(fp != NULL);
    int ch = getc(fp);

    while(ch != EOF)
    {
        ungetc(ch, fp);
        if(!GetFileInput(fp, equation_coefficients))
        {
            printf("Please, check the input type\n");
            return;
        }
        number_of_roots = SolveGivenEquation(equation_coefficients, equation_roots);

        PrintOutput(number_of_roots, equation_roots);
        ch = getc(fp);
        ch = getc(fp);
    }
    fclose(fp);
}
