#include <ctype.h>

#include "header.h"
#include "output.h"
#include "solve.h"
#include "simple.h"
#include "test.h"

int TestEquation (struct TestsStruct* test_container,
                  struct RootsStruct* equation_roots,
                  const int test_number)
{
    MYASSERT(test_container != NULL);
    MYASSERT(equation_roots != NULL);

    equation_roots->x1 = 0;
    equation_roots->x2 = 0;

    TypeOfRoots number_of_roots
        = SolveGivenEquation(&(test_container->equation_coefficients), equation_roots);

    if (!CompareEquality(equation_roots->x1, test_container->equation_roots_ref.x1) ||
        !CompareEquality(equation_roots->x2, test_container->equation_roots_ref.x2) ||
        number_of_roots != test_container->number_of_roots_ref)
    {
        PrintWrongTestOutput(test_container, equation_roots, test_number, number_of_roots);
        return 0;
    }
    return 1;
}

void UnitTests(struct RootsStruct* equation_roots)
{
    MYASSERT(equation_roots != NULL);

    struct TestsStruct test_container = {.equation_coefficients.a = 0,
                                         .equation_coefficients.b = 0,
                                         .equation_coefficients.c = 0,
                                         .equation_roots_ref.x1   = 0,
                                         .equation_roots_ref.x2   = 0,
                                         .number_of_roots_ref     = SS_NO_ROOTS};
    char test_selector = 'n';
    printf("Do you want to run prepared tests? [y/n]\n");
    test_selector = (char)toupper(getchar());

    int skipper = getchar();
    while (skipper != '\n')
    {
        skipper = getchar();
    }

    if (test_selector == 'Y')
    {
        char input_file_name[50] = "";
        printf("From what file?\n");
        scanf("%s", input_file_name);
        FILE* fp = fopen(input_file_name, "r");
        if (fp == NULL)
        {
            printf("Unable to open file %s\n"
                   "Automaticly skipping to your own equation.\n", input_file_name);
            return;
        }

        int number_of_tests = 0;
        int number_of_success = 0;

        fscanf(fp, "%d", &number_of_tests);
        for (int i = 0; i < number_of_tests; i++)
        {
            if (!GetTestFileInput(fp, &test_container))
            {
                printf("../tests.txt has an error. Automaticly skipping to your own equation.\n");
                return;
            }
            number_of_success += TestEquation(&test_container, equation_roots, i + 1);
        }

        if (number_of_success == number_of_tests)
        {
            printf(__GREEN_TEXT__("OK! "));
        }
        else
        {
            printf(__YELLOW_TEXT__("Some tests are failed. "));
        }
        printf("Succes: %d\n", number_of_success);
        fclose(fp);
        return;
    }

    else if (test_selector != 'N')
    {
        printf("Wrong letter selected. Automaticly skipping to your own equation.\n");
        return;
    }
    else
    {
        printf("OK. Automaticly skipping to your own equation.\n");
    }
}
