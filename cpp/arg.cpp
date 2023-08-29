#include "header.h"
#include "solve.h"
#include "output.h"
#include "arg.h"

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
    if (fp == NULL)
    {
        printf("Unable to open file %s", argv[2]);
        return;
    }
    int ch = getc(fp);
//пересмотреть?
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
        ch = getc(fp); // double getc() serves to separate lf from eof
    }
    fclose(fp);
}
