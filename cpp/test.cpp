#include "../headers/header.h"
#include "../headers/output.h"
#include "../headers/solve.h"
#include "../headers/simple.h"
#include "../headers/test.h"

int TestEquation (struct TestsStruct* test_container,
                    struct RootsStruct* equation_roots,
                    const int test_number)
{
    MYASSERT(test_container != NULL);
    MYASSERT(equation_roots != NULL);

    equation_roots->x1 = 0;
    equation_roots->x2 = 0;

    TypeOfRoots number_of_roots = SolveGivenEquation(&(test_container->equation_coefficients), equation_roots);

    if (!CompareEquality(equation_roots->x1, test_container->equation_roots_ref.x1) ||
        !CompareEquality(equation_roots->x2, test_container->equation_roots_ref.x2) ||
        number_of_roots != test_container->number_of_roots_ref)
    {
        printf("\033[31;1mFAILED TEST NUMBER %3d:\033[0m ", test_number);
        printf("x1 = %10lf, x2 = %10lf, \n", equation_roots->x1, equation_roots->x2);
        printf("number of roots = %d\n", number_of_roots);
        printf("EXPECTED:               x1 = %10lf, x2 = %10lf, \n", test_container->equation_roots_ref.x1, test_container->equation_roots_ref.x2);
        printf("number of roots = %d\n", test_container->number_of_roots_ref);
        printf("Let's head to your own equation!\n");
        return 0;
    }

    return 1;

}

void UnitTests(struct RootsStruct* equation_roots)
{

    MYASSERT(equation_roots        != NULL);

    struct TestsStruct test_container = {.equation_coefficients.a = 0,
                                        .equation_coefficients.b = 0,
                                        .equation_coefficients.c = 0,
                                        .equation_roots_ref.x1 = 0, .equation_roots_ref.x2 = 0,
                                        .number_of_roots_ref = SS_NO_ROOTS};
    char test_selector = 'n';
    printf("Do you want to run prepared tests? [y/n]\n");
    scanf("%c", &test_selector);

    if (test_selector == 'y')
    {
        FILE* fp = fopen("../tests.txt", "r");
        if (fp == NULL)
        {
            printf("Unnable to open file.\nAutomaticly skipping to your own equation.\n");
            return;
        }

        int number_of_tests = 0, number_of_success = 0;

        fscanf(fp, "%d", &number_of_tests);
        for (int i = 0; i < number_of_tests; i++)
        {
            if (!GetTestFileInput(fp, &test_container))
            {
                printf("tests.txt has an error. Automaticly skipping to your own equation.\n");
                return;
            }
            number_of_success += TestEquation(&test_container, equation_roots, i + 1);
        }

        if (number_of_success == number_of_tests)
        {
            printf("\033[32;1mOK!\033[0m ");
        }
        else
        {
            printf("\033[33;1mSome tests are failed.\033[0m ");
        }
        printf("Succes: %d\n", number_of_success);
        fclose(fp);
        return;
    }

    else if (test_selector != 'n')
    {
        printf("Wrong letter selected. Automaticly skipping to your own equation.\n");
        return;
    }
    else
    {
        printf("OK. Automaticly skipping to your own equation.\n");
    }
}
