#include "../headers/header.h"

int TestEquation (struct TestsStruct test_container,
                    struct CoefficientsStruct* equation_coefficients,
                    struct RootsStruct* equation_roots,
                    const int test_number)
{
    equation_coefficients->a = test_container.a;
    equation_coefficients->b = test_container.b;
    equation_coefficients->c = test_container.c;
    equation_roots->x1 = 0;
    equation_roots->x2 = 0;

    TypeOfRoots number_of_roots = SolveGivenEquation(*equation_coefficients, equation_roots);

    if (!CompareEquality(equation_roots->x1, test_container.x1_ref) ||
        !CompareEquality(equation_roots->x2, test_container.x2_ref) ||
        number_of_roots != test_container.number_of_roots_ref)
    {
        printf("FAILED TEST NUMBER %3d: x1 = %10lf, x2 = %10lf, \n", test_number, equation_roots->x1, equation_roots->x2);
        printf("number of roots = %d\n", number_of_roots);
        printf("EXPECTED:               x1 = %10lf, x2 = %10lf, \n", test_container.x1_ref, test_container.x2_ref);
        printf("number of roots = %d\n", test_container.number_of_roots_ref);
        printf("Let's head to your own equation!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

void UnitTests(struct CoefficientsStruct* equation_coefficients,
                struct RootsStruct* equation_roots)
{
    struct TestsStruct test_container;
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
            if (!GetFileInput(fp, &test_container))
            {
                printf("tests.txt has an error. Automaticly skipping to your own equation.\n");
                return;
            }
            number_of_success += TestEquation(test_container, equation_coefficients, equation_roots, i + 1);
        }

        printf("OK! Succes: %d\n", number_of_success);
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
