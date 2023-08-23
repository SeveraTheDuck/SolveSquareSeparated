#include "../headers/header.h"

int TestEquation (const double a, const double b, const double c,
                    const double x1_ref, const double x2_ref,
                    const int number_of_roots_ref, const int test_number)
{
    double x1 = 0, x2 = 0;
    TypeOfRoots number_of_roots = SolveGivenEquation(a, b, c, &x1, &x2);

    if (!CompareEquality(x1, x1_ref) || !CompareEquality(x2, x2_ref) || number_of_roots != number_of_roots_ref)
    {
        printf("FAILED TEST NUMBER %3d: x1 = %10lf, x2 = %10lf, \n", test_number, x1, x2);
        printf("number of roots = %d\n", number_of_roots);
        printf("EXPECTED:               x1 = %10lf, x2 = %10lf, \n", x1_ref, x2_ref);
        printf("number of roots = %d\n", number_of_roots_ref);
        printf("Let's head to your own equation!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

void UnitTests()
{
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

        int number_of_tests = 0, number_of_success = 0, number_of_roots_ref = SS_NO_ROOTS;
        double a = 0, b = 0, c = 0, x1_ref, x2_ref;

        fscanf(fp, "%d", &number_of_tests);
        for (int i = 0; i < number_of_tests; i++)
        {
            if (!GetFileInput(fp, &a, &b, &c, &x1_ref, &x2_ref, &number_of_roots_ref))
            {
                printf("tests.txt has an error. Automaticly skipping to your own equation.\n");
                return;
            }
            number_of_success += TestEquation(a, b, c, x1_ref, x2_ref, number_of_roots_ref, i + 1);
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
